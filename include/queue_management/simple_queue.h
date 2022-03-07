//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_SIMPLE_QUEUE_H
#define UNTITLED10_SIMPLE_QUEUE_H

#include "base.h"
#include "queue.h"

QueueHandle_t yearQueue;

void vSenderTask(void *pvParams)
{
    BaseType_t qStatus;
    int32_t valueToSend = 2018;
    while (1)
    {
        qStatus = xQueueSend(yearQueue, &valueToSend, 0);
    }
}

void vReceiveTask(void *pvParams)
{
    int32_t valueReceived;
    const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
    BaseType_t qStatus;
    while (1)
    {
        xQueueReceive(yearQueue, &valueReceived, xTicksToWait);
        Serial.print("Received Value: ");
        Serial.println(valueReceived);
        vTaskDelay(1);
    }
}

void SetUp()
{
    yearQueue = xQueueCreate(5, sizeof(int32_t));
    xTaskCreate(vSenderTask, "Sender Task", 100, NULL, 1, NULL);
    xTaskCreate(vReceiveTask, "Receiver Task", 100, NULL, 1, NULL);
}

#endif //UNTITLED10_SIMPLE_QUEUE_H
