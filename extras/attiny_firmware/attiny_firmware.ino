/**
 **************************************************
 *
 * @file        attiny_firmware.ino
 * @brief       Firmware for attiny404. 
 *
 *
 * @authors     Karlo Leksic for soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;

#define BTN_PIN PA2
#define LED_PIN PA5

byte data[2];
byte ledState;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    pinMode(BTN_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
}

void loop()
{
    if (data[0] == 0)
    {
        // Want to turn off LED
        digitalWrite(LED_PIN, LOW);
    }

    if (data[0] == 1)
    {
        // Want to turn on LED
        digitalWrite(LED_PIN, HIGH);
    }

    if (data[0] == 2)
    {
        // Want to turn on LED, but with PWM
        analogWrite(LED_PIN, data[1]);
    }

    delay(10);
}


void receiveEvent(int howMany)
{
    // We receive 2 bytes, the first is to select mode, and the second is the PWM value if needed
    
    if (Wire.available() == 2)
    {
        Wire.readBytes(data, 2);
    }
}

void requestEvent()
{
    // Read btn state and send it
    byte btn = digitalRead(BTN_PIN);
    Wire.write(btn);
}
