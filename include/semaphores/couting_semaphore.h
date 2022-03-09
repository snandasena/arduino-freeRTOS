//
// Created by sajith on 3/8/22.
//

#ifndef UNTITLED10_COUTING_SEMAPHORE_H
#define UNTITLED10_COUTING_SEMAPHORE_H

#include "base.h"
#include "semphr.h"

SemaphoreHandle_t xCountingSemaphore;

void redLedControllerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
        digitalWrite(RED, digitalRead(RED) ^ 1);
        Serial.println("Red task ");
        xSemaphoreGive(xCountingSemaphore);
        vTaskDelay(1);
    }
}

void greenLedControllerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        Serial.println("Green task ");
        xSemaphoreGive(xCountingSemaphore);
        vTaskDelay(1);
    }
}

void yellowLedControllerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        Serial.println("Yellow task ");
        xSemaphoreGive(xCountingSemaphore);
        vTaskDelay(1);
    }
}

void SetUp()
{
    xCountingSemaphore = xSemaphoreCreateCounting(1, 0);
    xTaskCreate(redLedControllerTask, "Red LED Task", 100, nullptr, 1, nullptr);
    xTaskCreate(greenLedControllerTask, "Green LED Task", 100, nullptr, 1, nullptr);
    xTaskCreate(yellowLedControllerTask, "Yellow LED Task", 100, nullptr, 1, nullptr);
    xSemaphoreGive(xCountingSemaphore);
}

#endif //UNTITLED10_COUTING_SEMAPHORE_H
