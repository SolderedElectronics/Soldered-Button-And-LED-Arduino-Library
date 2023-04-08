/**
 **************************************************
 *
 * @file        LedHoldOn.ino
 * @brief       Example of button press and turn on the LED. 
 *              The LED will be on for some time and then it will turn off.
 *
 *              For this example you will need any Dasduino board, a USB-c cable, Button and LED with easyC, and easyC cable. 
 *              Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
 *              Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/
 *
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              If you press the button once, the LED will turn on and after one second it will turn off.
 *              If you press the button twice, the LED will turn on and after 5 seconds it will turn off.
 *              You can set any time for the LED to stay on.
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

    // On single press hold led on 1 second.
    // NOTE: It won't be instant because the breakout expects another click to detect 
    // a double click if the button is pressed twice
    if (state == BTN_CLICK)
    {
        myBtnLed.turnLedOnAndHold(1000); // 1000 milliseconds
    }

    // On double click, hold led on 5 second
    if (state == BTN_DOUBLE_CLICK)
    {
        myBtnLed.turnLedOnAndHold(5000); // 5000 milliseconds
    }    
}
