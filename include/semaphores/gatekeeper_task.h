//
// Created by sajith on 3/10/22.
//

#ifndef UNTITLED10_GATEKEEPER_TASK_H
#define UNTITLED10_GATEKEEPER_TASK_H

#include "base.h"
#include "semphr.h"

static const char *pcStringToPrint[] = {
    "Task 1 ####################################### Task 1  \r\n",
    "Task 1 --------------------------------------- Task 1  \r\n",
};

QueueHandle_t xPrintQueue;

void outputTask(void *pvParams)
{
    int indexToString;
    indexToString = (int) pvParams;
    while (1)
    {
        xQueueSend(xPrintQueue, &(pcStringToPrint[0]), 0);
    }
}

void gateKeeper(void *)
{
    char *pcMessageToPrint;
    while (1)
    {
        xQueueReceive(xPrintQueue, &pcMessageToPrint, portMAX_DELAY);
    }
}

void SetUp()
{
    xPrintQueue = xQueueCreate(5, sizeof(char *));
    xTaskCreate(outputTask, "Printer 1", 100, (void *) 0, 1, nullptr);
    xTaskCreate(outputTask, "Printer 2", 100, (void *) 1, 2, nullptr);
    xTaskCreate(gateKeeper, "Gatekeeper", 100, nullptr, 0, nullptr);
}

#endif //UNTITLED10_GATEKEEPER_TASK_H
