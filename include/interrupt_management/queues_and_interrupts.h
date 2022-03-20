//
// Created by sajith on 3/20/22.
//

#ifndef UNTITLED10_QUEUES_AND_INTERRUPTS_H
#define UNTITLED10_QUEUES_AND_INTERRUPTS_H

#include "base.h"
#include "queue.h"
#include "semphr.h"


QueueHandle_t xIntegerQueue;
QueueHandle_t xStringQueue;

int timer_counter;

void interruptInit()
{
    noInterrupts();
    TCCR1A = 0;
    TCCR1B = 0;

    timer_counter = 34286;

    TCNT1 = timer_counter;
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1 << TOIE1);
    interrupts();
}

void vIntegerGenerator(void *)
{
    TickType_t xLastExecutionTime;
    const TickType_t xDelay200ms = pdMS_TO_TICKS(200);
    uint32_t valueToSet = 0;

    xLastExecutionTime = xTaskGetTickCount();
    while (1)
    {
        vTaskDelayUntil(&xLastExecutionTime, xDelay200ms);
        for (int i = 0; i < 5; ++i)
        {
            xQueueSendToBack(xIntegerQueue, &valueToSet, 0);
            ++valueToSet;
        }
    }
}

void vStringGenerator(void *)
{
    char *pcString;
    while (1)
    {
        xQueueReceive(xStringQueue, &pcString, portMAX_DELAY);
        Serial.println(pcString);
    }
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = timer_counter;
    uint32_t receivedNumber;
    static const char *pcString[] = {
        "Hello\r\n",
        "Hi\r\n",
        "I\r\n",
        "am\r\n",
        "here\r\n"
    };

    xQueueReceiveFromISR(xIntegerQueue, &receivedNumber, pdFALSE);
    receivedNumber &= 0x03;
    xQueueSendToBackFromISR(xStringQueue, &pcString[receivedNumber], pdFALSE);
}

void SetUp()
{
    xTaskCreate(vIntegerGenerator, "Integer Generator", 100, nullptr, 1, nullptr);
    xTaskCreate(vStringGenerator, "String Printer", 100, nullptr, 1, nullptr);
    xIntegerQueue = xQueueCreate(10, sizeof(uint32_t));
    xStringQueue = xQueueCreate(10, sizeof(char *));
    interruptInit();
}


#endif //UNTITLED10_QUEUES_AND_INTERRUPTS_H
