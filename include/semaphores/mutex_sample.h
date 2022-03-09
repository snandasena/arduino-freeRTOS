//
// Created by sajith on 3/8/22.
//

#ifndef UNTITLED10_MUTEX_SAMPLE_H
#define UNTITLED10_MUTEX_SAMPLE_H

#include "base.h"
#include "semphr.h"

SemaphoreHandle_t xMutex;

void printer(const char *pcString)
{
    xSemaphoreTake(xMutex, portMAX_DELAY);
    Serial.println(pcString);
    xSemaphoreGive(xMutex);
}

void outputTask(void *pvParams)
{
    char *pcStringToPrint;
    pcStringToPrint = (char *) pvParams;
    while (1)
    {
        printer(pcStringToPrint);
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


void SetUp()
{
    xMutex = xSemaphoreCreateMutex();
    xTaskCreate(outputTask, "Printer Task 1", 100, "Task 1 ############################ Task1 \r\n", 1, nullptr);
    xTaskCreate(outputTask, "Printer Task 2", 100, "Task 2 ---------------------------- Task2 \r\n", 2, nullptr);
}


#endif //UNTITLED10_MUTEX_SAMPLE_H
