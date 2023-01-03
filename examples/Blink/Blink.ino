/**
 **************************************************
 *
 * @file        Blink.ino
 * @brief       The basic example of the blinking LED.
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
    myBtnLed.ledOn(); // Turn the LED on
    delay(1000);      // Delay between turning on and off

    myBtnLed.ledOff(); // Turn the LED off
    delay(1000);       // Delay between turning on and off
}
