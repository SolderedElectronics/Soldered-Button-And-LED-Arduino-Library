/**
 **************************************************
 *
 * @file        BtnSerial.ino
 * @brief       The basic example of the button press.
 *
 *              For this example you need Dasduino, Button & LED board, and easyC cable.
 *              Connect Button & LED board to your Dasduino with easyC and upload this example.
 *              Open Serial monitor on 115200 baud.
 *              When the button is pressed, the serial monitor print "Button is pressed!", when not, prints
 *              "Button is not pressed!".
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
    // Begin serial communication
    Serial.begin(115200);

    // Initialize Button & LED board
    myBtnLed.begin();
}

void loop()
{
    // The getBtnState function returns 1 if the button is pressed
    if (myBtnLed.getBtnState())
    {
        // Print message on the serial monitor
        Serial.println("Button is pressed!");
    }
    else
    {
        // Print message on the serial monitor
        Serial.println("Button is not pressed!");
    }

    // Delay between prints
    delay(200);
}
