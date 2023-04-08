/**
 **************************************************
 *
 * @file        attiny_firmware.ino
 * @brief       Firmware for attiny404.
 *
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include needed libraries and files
#include "OneButton.h"
#include "Wire.h"
#include "easyC.h"

int addr = DEFAULT_ADDRESS; // 0x30

// Define pins for button and LED
#define BTN_PIN PA2
#define LED_PIN PA5

// Define all modes of LED
#define LED_OFF         0
#define LED_ON          1
#define LED_PWM         2
#define LED_FADING      3
#define LED_ON_AND_HOLD 4

// Setup a OneButton on pin PA2
OneButton button(BTN_PIN, true);

// Variables for mode, parameter, and button state
uint8_t mode;
uint32_t parameter;
byte buttonState;

// Variables for keeping tracking time
uint32_t timeOn, lastTimeChanged;

// Index for fading LED and flag which tells increasing or decreasing that index
int i;
bool increase = 1;

void setup()
{
    // Set the select address switches as inputs and get the I2C address
    initDefault();
    addr = getI2CAddress();

    // Init I2C communication
    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    // Set LED pin as output
    pinMode(LED_PIN, OUTPUT);

    // Link the button functions
    button.attachClick(click1);
    button.attachDoubleClick(doubleclick1);
    button.attachLongPressStop(longPressStop1);
    button.attachDuringLongPress(longPress1);
}

void loop()
{
    // Keep watching the push button
    button.tick();

    // See which mode is currently and do what need for each mode
    switch (mode)
    {
    case LED_OFF: // Want to turn off LED
        digitalWrite(LED_PIN, LOW);
        break;

    case LED_ON: // Want to turn on LED
        digitalWrite(LED_PIN, HIGH);
        break;

    case LED_PWM: // Want to turn on LED, but with PWM
        analogWrite(LED_PIN, (uint8_t)parameter);
        break;

    case LED_FADING: // Want to fade the LED
        // Write the current PWM to the LED
        analogWrite(LED_PIN, i);

        // Change the index at a certain time and change it depending on increase flag
        if (millis() - lastTimeChanged > parameter)
        {
            // Remember the time when the index changed
            lastTimeChanged = millis();

            // Change index depending on the flag
            if (increase)
                i++;
            else
                i--;

            // When the index reaches 255 or 0, change changing direction
            if (i > 255 || i < 0)
                increase = !increase;
        }
        break;

    case LED_ON_AND_HOLD: // Want to keep LED on a certain time and then turns it off
        // If it's passed time that the LED needs to be on, turn it off
        if (millis() - timeOn > parameter)
        {
            digitalWrite(LED_PIN, LOW);
        }
        break;
    }
}

// When the breakout receives the data over I2C, this function is executing
void receiveEvent(int howMany)
{
    // We receive 5 bytes, the first is to select mode, and the other 4 is its value if it's needed

    if (Wire.available() == 5)
    {
        // Read the mode
        mode = Wire.read();

        // If the mode is that it's needed to turn led off after some time, remember currect time and set flag to turn
        // led on
        if (mode == LED_ON_AND_HOLD)
        {
            timeOn = millis();
            digitalWrite(LED_PIN, HIGH);
        }

        // Read the raw parameter (4 bytes) and convert it to uint32_t
        uint8_t parameterRaw[4];
        Wire.readBytes(parameterRaw, 4);
        parameter = *(uint32_t *)parameterRaw;
    }
}

// This function will be executed when Dasduino requests data from the breakout
void requestEvent()
{
    // Send the button state
    Wire.write(buttonState);
    buttonState = 0;
}

// This function will be called when the button was pressed 1 time
void click1()
{
    buttonState = 1;
}

// This function will be called when the button was pressed 2 times in a short timeframe
void doubleclick1()
{
    buttonState = 2;
}

// This function will be called often, while the button is pressed for a long time
void longPress1()
{
    buttonState = 3;
}

// This function will be called once, when the button is released after beeing pressed for a long time
void longPressStop1()
{
    buttonState = 4;
}
