/**
 **************************************************
 *
 * @file        BasicPWM.ino
 * @brief       Example of the fading LED with PWM using a built-in function for led fading.
 *              If you want to manually send PWM values, see the AdvancedPWM example.
 *
 *              For this example you will need any Dasduino board, a USB-c cable, Button and LED with easyC, and easyC cable. 
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              The LED will turn off, and when you press the button once, the LED will fade with a 1ms delay between changing 
 *              the PWM value. If you press the button twice, the delay between changing PWM will increase to 5 ms. 
 *              On double click, you will turn off the LED.
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

    // Turn the LED off
    myBtnLed.ledOff();
}

void loop()
{

    // getBtnState() function returns the current state of the button
    // It MUST BE in the loop() and run constantly to get proper readings
    byte state = myBtnLed.getBtnState();

    // On single press fade led with 1 ms delay between changing PWM value
    if (state == BTN_CLICK)
    {
        myBtnLed.ledFading(1);
    }

    // On double click, set delay between changing PWM value to 5 ms
    if (state == BTN_DOUBLE_CLICK)
    {
        myBtnLed.ledFading(5);
    }

    // On long press turn the LED off
    if(state == BTN_LONG_PRESS)
    {
        myBtnLed.ledOff();
    }
}
