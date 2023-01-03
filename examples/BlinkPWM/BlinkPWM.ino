/**
 **************************************************
 *
 * @file        BlinkPWM.ino
 * @brief       The basic example of the blinking LED with PWM.
 *
 *              For this example you need Dasduino, Button & LED board, and easyC cable.
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
    myBtnLed.begin();
}

void loop()
{
    // Increasing the brightness
    for (int i = 0; i < 255; ++i)
    {
        myBtnLed.ledOn(i); // Set PWM to the LED
        delay(5);          // A little delay only to better see changes
    }

    delay(500);

    // Decreasing the brightness
    for (int i = 255; i >= 0; --i)
    {
        myBtnLed.ledOn(i); // Set PWM to the LED
        delay(5);          // A little delay only to better see changes
    }

    delay(500);
}
