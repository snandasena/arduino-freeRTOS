//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_QUEUE_SENDER_FROM_DIFFERENT_TASK_H
#define UNTITLED10_QUEUE_SENDER_FROM_DIFFERENT_TASK_H

#include "base.h"
#include "queue.h"


TaskProfiler SenderTaskProfiler;
TaskProfiler ReceiverTaskProfiler;

QueueHandle_t yearQueue;

void vSenderTask(void *pvParams)
{
    BaseType_t qStatus;
    int32_t valueToSend;
    valueToSend = (int32_t) pvParams;
    while (1)
    {
        qStatus = xQueueSend(yearQueue, &valueToSend, 0);
        if (qStatus != pdPASS)
        {
            Serial.println("Could not send to the queue");
        }
        digitalWrite(RED, HIGH);
    }
}

void vReceiveTask(void *pvParams)
{
    BaseType_t qStatus;
    int32_t valueReceived;
    const TickType_t xTickToWait = pdMS_TO_TICKS(100);
    while (1)
    {
        qStatus = xQueueReceive(yearQueue, &valueReceived, xTickToWait);
        if (qStatus != pdPASS)
        {
            Serial.print("Data received successfully: ");
            Serial.println(valueReceived);
        }
        else
        {
            Serial.println("Could not receive from queue ");
        }
        digitalWrite(RED, LOW);
    }
}

void SetUp()
{
    yearQueue = xQueueCreate(5, sizeof(int32_t));

    xTaskCreate(vSenderTask, "Sender Task 1", 100, 1999, 1, NULL);
    xTaskCreate(vSenderTask, "Sender Task 2", 100, 2019, 1, NULL);
    xTaskCreate(vReceiveTask, "Receiver Task", 100, NULL, 2, NULL);

}


#endif //UNTITLED10_QUEUE_SENDER_FROM_DIFFERENT_TASK_H
