//
// Created by sajith on 3/8/22.
//

#ifndef UNTITLED10_BINARY_SEMAPHORE_H
#define UNTITLED10_BINARY_SEMAPHORE_H

#include "base.h"
#include "semphr.h"

SemaphoreHandle_t xBinarySemaphore;

void redLedControllerTask(void *)
{
    xSemaphoreGive(xBinarySemaphore);
    while (1)
    {
        xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
        Serial.println("This is Red Task");
        xSemaphoreGive(xBinarySemaphore);
        vTaskDelay(1);
        digitalWrite(RED, digitalRead(RED) ^ 1);
    }
}

void greenLedControllerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
        Serial.println("This is Green Task");
        xSemaphoreGive(xBinarySemaphore);
        vTaskDelay(1);
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
    }
}

void yellowLedControllerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
        Serial.println("This is Yellow Task");
        xSemaphoreGive(xBinarySemaphore);
        vTaskDelay(1);
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
    }
}

void SetUp()
{
    xBinarySemaphore = xSemaphoreCreateBinary();
    xTaskCreate(redLedControllerTask, "Red LED Task", 100, nullptr, 1, nullptr);
    xTaskCreate(greenLedControllerTask, "Green LED Task", 100, nullptr, 1, nullptr);
    xTaskCreate(yellowLedControllerTask, "Yellow LED Task", 100, nullptr, 1, nullptr);
}

#endif //UNTITLED10_BINARY_SEMAPHORE_H
