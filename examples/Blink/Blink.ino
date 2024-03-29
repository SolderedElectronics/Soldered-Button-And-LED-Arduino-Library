/**
 **************************************************
 *
 * @file        Blink.ino
 * @brief       The basic example of the blinking LED.
 * 
 *              For this example you will need any Dasduino board, a USB-c cable, Button and LED with easyC, and easyC cable. 
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              You will see the blinking LED.
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
    myBtnLed.ledOn(); // Turn the LED on
    delay(1000);      // Delay between turning on and off

    myBtnLed.ledOff(); // Turn the LED off
    delay(1000);       // Delay between turning on and off
}
