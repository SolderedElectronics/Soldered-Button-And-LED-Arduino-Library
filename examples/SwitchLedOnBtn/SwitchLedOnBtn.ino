/**
 **************************************************
 *
 * @file        SwitchLedOnBtn.ino
 * @brief       Example of button press and turn on the LED. The LED will be on TIMEOUT_MS milliseconds after the button
 *              is released.
 *
 *              For this example you need Dasduino, Button & LED board, and easyC cable.
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              When the button is pressed, LED is turned on. When the button is released, the LED will keep on state
 *              until timeout.
 *
 * @link        solde.red/333182
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

// Include Soldered library
#include "Button-and-LED-easyC-SOLDERED.h"

// Create Button & LED object
ButtonAndLED myBtnLed;

// Define a timeout in milliseconds to hold LED on after releasing the button
#define TIMEOUT_MS 1000

// Variables for measuring time
unsigned long time1, time2;

void setup()
{
    // Initialize Button & LED board
    myBtnLed.begin();
}

void loop()
{

    time1 = millis();           // time1 holds the current time

    if (myBtnLed.getBtnState()) // If the button is pressed
    {
        myBtnLed.ledOn(); // Turn on the LED
        time2 = millis(); // Store time when LED is pressed

        // When the button is released, in time2 variable is the time when the button is pressed last time.
        // So, when the button is not pressed, time2 doesn't count time
    }
    else
    {
        // Here is part of the code running when the button is released        
        if ((time1 - time2) > TIMEOUT_MS)
        {
            // Turn off the LED when the timeout expires
            myBtnLed.ledOff();
        }
    }
}
