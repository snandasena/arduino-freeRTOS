//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_QUEUE_SETS_H
#define UNTITLED10_QUEUE_SETS_H

#include "base.h"
#include "queue.h"


QueueHandle_t xQueue1;
QueueHandle_t xQueue2;

QueueSetHandle_t xQueueSet;

void vSenderTask1(void *pvParams)
{
    const TickType_t xBlockTime = pdMS_TO_TICKS(100);
    const char *const messageToSend = "Message from Sender 1 ";
    while (1)
    {
        vTaskDelay(xBlockTime);
        xQueueSend(xQueue1, &messageToSend, 0);
    }
}

void vSenderTask2(void *pvParams)
{
    const TickType_t xBlockTime = pdMS_TO_TICKS(200);
    const char *const messageToSend = "Hello from Sender 2 ";
    while (1)
    {
        vTaskDelay(xBlockTime);
        xQueueSend(xQueue2, &messageToSend, 0);
    }
}

void vReceiverTask(void *)
{
    QueueHandle_t xQueueThatContaineData;
    char *pcReceivedString;
    while (1)
    {
        xQueueThatContaineData = (QueueHandle_t) xQueueSelectFromSet(xQueueSet, portMAX_DELAY);
        xQueueReceive(xQueueThatContaineData, &pcReceivedString, 0);
        Serial.println(pcReceivedString);
    }
}

void SetUp()
{
    pinMode(RED, OUTPUT);
    digitalWrite(RED, HIGH);
    xQueue1 = xQueueCreate(1, sizeof(char *));
    xQueue2 = xQueueCreate(1, sizeof(char *));

    xQueueSet = xQueueCreateSet(1 * 2);
    xQueueAddToSet(xQueue1, xQueueSet);
    xQueueAddToSet(xQueue2, xQueueSet);

    xTaskCreate(vSenderTask1, "Sender Task 1 ", 100, nullptr, 1, nullptr);
    xTaskCreate(vSenderTask2, "Sender Task 2 ", 100, nullptr, 1, nullptr);
    xTaskCreate(vReceiverTask, "Receiver Task", 100, nullptr, 2, nullptr);
}

#endif //UNTITLED10_QUEUE_SETS_H
