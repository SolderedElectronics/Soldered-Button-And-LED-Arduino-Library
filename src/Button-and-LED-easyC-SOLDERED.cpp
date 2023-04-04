/**
 **************************************************
 *
 * @file        Button-and-LED-easyC-SOLDERED.cpp
 * @brief       Functions for button & LED breakout.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/


#include "Button-and-LED-easyC-SOLDERED.h"

/**
 * @brief                   Button & LED constructor.
 */
ButtonAndLED::ButtonAndLED()
{
    native = 0;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void ButtonAndLED::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   Function to turn on the LED.
 */
void ButtonAndLED::ledOn()
{
    byte data[2];
    data[0] = 1;
    data[1] = pwm;
    sendData(data, 2);
}

/**
 * @brief                   Function to turn on the LED with PWM value.
 *
 * @param _pwmValue         PWM value from 0 to 255.
 */
void ButtonAndLED::ledOn(byte _pwmValue)
{
    pwm = _pwmValue;

    byte data[2];
    data[0] = 2;
    data[1] = pwm;
    sendData(data, 2);
}

/**
 * @brief                   Function to turn off the LED.
 */
void ButtonAndLED::ledOff()
{
    byte data[2];
    data[0] = 0;
    data[1] = pwm;
    sendData(data, 2);
}

/**
 * @brief                   Function to get button state.
 *
 * @return                  1 if the button is pressed, 0 if not.
 */
byte ButtonAndLED::getBtnState()
{
    byte btn;
    readData(&btn, 1);
    
    return btn;
}