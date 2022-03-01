#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define RED 8
#define GREEN 7
#define YELLOW 6

void redLedControllerTask(void *)
{
    pinMode(RED, OUTPUT);
    while (1)
    {
        digitalWrite(RED, digitalRead(RED) ^ 1);
    }


}

void greenLedControllerTask(void *)
{
    pinMode(GREEN, OUTPUT);
    while (1)
    {
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
    }
}

void yellowLedControllerTask(void *)
{
    pinMode(YELLOW, OUTPUT);
    while (1)
    {
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
    }
}

void setup()
{
// write your initialization code here
    xTaskCreate(redLedControllerTask, "RED LED TASK", 128, NULL, 1, NULL);
    xTaskCreate(greenLedControllerTask, "GREEN LED TASK", 128, NULL, 1, NULL);
    xTaskCreate(yellowLedControllerTask, "BLUE LED TASK", 128, NULL, 1, NULL);
}


void loop()
{
// write your code here
}