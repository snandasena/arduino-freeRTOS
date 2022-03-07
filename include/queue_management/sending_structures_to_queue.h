//
// Created by sajith on 3/7/22.
//

#ifndef UNTITLED10_SENDING_STRUCTURES_TO_QUEUE_H
#define UNTITLED10_SENDING_STRUCTURES_TO_QUEUE_H

#include "base.h"
#include "queue.h"


TaskProfiler SenderTaskProfiler;
TaskProfiler ReceiverTaskProfiler;

typedef enum
{
    eSender1,
    eSender2
} DataSource_t;

typedef struct
{
    uint8_t ucValue;
    DataSource_t eDatasource;
} Data_t;

static const Data_t xStructToSend[2] = {
    {100, eSender1},
    {50,  eSender2}
};

QueueHandle_t xQueue;

void vSenderTask(void *pvParams)
{
    BaseType_t qSatatus;
    const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
    while (1)
    {
        qSatatus = xQueueSend(xQueue, pvParams, xTicksToWait);
        if (qSatatus != pdPASS)
        {
            Serial.println("Could not send to the queue ");
        }
    }
}

void vReceiveTask(void *pvParams)
{
    Data_t xReceivedStruture;
    BaseType_t qStatus;
    while (1)
    {
        qStatus = xQueueReceive(xQueue, &xReceivedStruture, 0);
        if (qStatus == pdPASS)
        {
            if (xReceivedStruture.eDatasource == eSender1)
            {
                Serial.print("This is from sender 1 : ");
                Serial.println(xReceivedStruture.ucValue);
            }else
            {
                Serial.print("This is from sender 2: ");
                Serial.println(xReceivedStruture.ucValue);
            }
        }
        else
        {
            Serial.println("Could not receive data from the queue ");
        }
    }
}


void SetUp()
{
    xQueue = xQueueCreate(3, sizeof(Data_t));
    xTaskCreate(vSenderTask, "Sender Task 1", 100, &(xStructToSend[0]), 2, NULL);
    xTaskCreate(vSenderTask, "Sender Task 2", 100, &(xStructToSend[1]), 2, NULL);

    xTaskCreate(vReceiveTask, "Receiver Task", 100, NULL, 1, NULL);
}

#endif //UNTITLED10_SENDING_STRUCTURES_TO_QUEUE_H
