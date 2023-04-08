/**
 **************************************************
 *
 * @file        AdvancedPWM.ino
 * @brief       Example of the fading LED with PWM using a function to send each PWM value.
 *              If you want to use a built-in fading function, see the BasicPwm example.
 *
 *              For this example you will need any Dasduino board, a USB-c cable, Button and LED with easyC, and easyC cable. 
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              You will see the fading LED.
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
    // Initialize Button & LED board
    // Start I2C communication on default address (0x30)
    myBtnLed.begin();

    // If you want another I2C address, enter it in the bracket
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino
    // myBtnLed.begin(0x31);
}

void loop()
{
    // Increasing the brightness
    for (int i = 0; i < 255; ++i)
    {
        myBtnLed.ledOn(i); // Set PWM to the LED
        // NOTE: In the BasicPwm example, you pass this delay value to the function.
        // Also, the delay value in the for loop below.
        delay(5); // A little delay only to better see changes
    }

    // Wait a bit before decreasing the PWM value
    delay(500);
    // NOTE: In the built-in function to fade (BasicPwm example) 
    // this delay cannot be configured, it doesn't exist.

    // Decreasing the brightness
    for (int i = 255; i >= 0; --i)
    {
        myBtnLed.ledOn(i); // Set PWM to the LED
        delay(5);          // A little delay only to better see changes
    }

    // Wait a bit before increasing the PWM value
    delay(500);
}
