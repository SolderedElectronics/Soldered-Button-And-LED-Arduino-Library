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

// Setup a OneButton on pin PA2
OneButton button(BTN_PIN, true);

// Variables for  
byte data[2];
byte buttonState;

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

    if (data[0] == 0)
    {
        // Want to turn off LED
        digitalWrite(LED_PIN, LOW);
    }

    if (data[0] == 1)
    {
        // Want to turn on LED
        digitalWrite(LED_PIN, HIGH);
    }

    if (data[0] == 2)
    {
        // Want to turn on LED, but with PWM
        analogWrite(LED_PIN, data[1]);
    }
}

// When the breakout receives the data over I2C, this function is executing
void receiveEvent(int howMany)
{
    // We receive 2 bytes, the first is to select mode, and the second is the PWM value if needed

    if (Wire.available() == 2)
    {
        Wire.readBytes(data, 2);
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
