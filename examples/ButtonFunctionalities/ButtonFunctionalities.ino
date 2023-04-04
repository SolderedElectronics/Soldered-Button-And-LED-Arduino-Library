/**
 **************************************************
 *
 * @file        ButtonFunctionalities.ino
 * @brief       Example of the button press functions for Button and LED with easyC breakout.
 *
 *              For this example you will need any Dasduino board, a USB-c cable, Button and LED with easyC, and easyC cable. 
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              This example will show you all the possibilities of the button. The button can detect single press,
 *              double press, long press, and release after a long button press. Upload the code and open the Serial Monitor 
 *              at 115200 baud rate to see what's happening.
 *
 * @link        solde.red/333182
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library
#include "Button-and-LED-easyC-SOLDERED.h"

// Create Button & LED object
ButtonAndLED myBtnLed;

void setup()
{
    // Init serial communication
    Serial.begin(115200);

    // Start I2C communication on default address (0x30)
    myBtnLed.begin();

    // If you want another I2C address, enter it in the bracket
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino
    // myBtnLed.begin(0x31);

    // Print a message on serial
    Serial.println("Press the button");
}

void loop()
{
    // getBtnState() function returns the current state of the button
    // It MUST BE in the loop() and run constantly to get proper readings
    byte state = myBtnLed.getBtnState();

    // If the state is zero or BUTTON_IDLE constant, the button is not pressed
    if (state != BUTTON_IDLE)
    {
        switch (state)
        {
        case BTN_CLICK:
            // The button is pressed once
            Serial.println("Button single click");
            break;
        case BTN_DOUBLE_CLICK:
            // The button is double-pressed
            Serial.println("Button double click");
            break;
        case BTN_LONG_PRESS:
            // The button is long pressed
            Serial.println("Button long click");
            break;
        case BTN_LONG_RELEASE:
            // When the long-pressed button is released
            Serial.println("Button long click release");
            break;
        }
    }
}
