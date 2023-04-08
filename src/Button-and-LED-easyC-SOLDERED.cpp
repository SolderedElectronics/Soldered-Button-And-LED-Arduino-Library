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
    uint8_t mode = LED_ON;

    // Send those values to the breakout
    // No needed parameter for turning on the LED so send 0
    sendValues(mode, 0);
}

/**
 * @brief                   Function to turn on the LED with PWM value.
 *
 * @param _pwmValue         PWM value from 0 to 255.
 */
void ButtonAndLED::ledOn(byte _pwmValue)
{
    uint8_t mode = LED_PWM;
    sendValues(mode, (uint32_t)_pwmValue); // Send those values to the breakout
}

/**
 * @brief                   Function to turn off the LED.
 */
void ButtonAndLED::ledOff()
{
    uint8_t mode = LED_OFF;

    // Send those values to the breakout
    // No needed parameter for turning on the LED
    sendValues(mode, 0);
}

/**
 * @brief                   Function to get button state.
 *
 * @return                  0 or BUTTON_IDLE constant if the button is not pressed.
 *                          1 or BTN_CLICK constant if the button is pressed once.
 *                          2 or BTN_DOUBLE_CLICK constant is the button is pressed twice.
 *                          3 or BTN_LONG_PRESS constant if the button is long pressed.
 *                          4 or BTN_LONG_RELEASE constant when the button is released after a long press.
 */
byte ButtonAndLED::getBtnState()
{
    byte btn;
    readData(&btn, 1);

    return btn;
}

/**
 *  @brief                  Function to tell breakout to fade LED with the delay passed in the function.
 *
 * @param uint32_t _delay   The delay between increasing and decreasing the PWM steps.
 */
void ButtonAndLED::ledFading(uint32_t _delay)
{
    uint8_t mode = LED_FADING;
    sendValues(mode, _delay); // Send those values to the breakout
}

/**
 * @brief                   Function to tell breakout to turn led on and hold that state some _time and then turn it
 * off.
 *
 * @param uint32_t _time    A time that holds the LED on.
 */
void ButtonAndLED::turnLedOnAndHold(uint32_t _time)
{
    uint8_t mode = LED_ON_AND_HOLD;
    sendValues(mode, _time); // Send those values to the breakout
}

/**
 * @brief                   Function to send data to the breakout.
 *
 * @param uint8_t _mode     Breakout mode:
 *                          0 or LED_OFF
 *                          1 or LED_ON
 *                          2 or LED_PWM
 *                          3 or LED_FADING
 *                          4 or LED_ON_AND_HOLD
 *
 * @param uint32_t _parameter Some modes need parameters and this is that parameter. Usually delay in milliseconds.
 */
void ButtonAndLED::sendValues(uint8_t _mode, uint32_t _parameter)
{
    uint8_t *parameterRaw = (uint8_t *)&_parameter; // Convert parameter from uint32_t to 4 bytes/uint8_t

    // Send values to the breakout
    Wire.beginTransmission(address);
    Wire.write(_mode);
    Wire.write(parameterRaw, 4);
    Wire.endTransmission();
}