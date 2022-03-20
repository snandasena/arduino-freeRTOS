//
// Created by sajith on 3/13/22.
//

#ifndef UNTITLED10_EVENT_GROUP_DEMO2_H
#define UNTITLED10_EVENT_GROUP_DEMO2_H

#include "base.h"
#include "event_groups.h"

EventGroupHandle_t xEventGroup;


#define TASK1_BIT (1UL<<0UL)
#define TASK2_BIT (1UL<<1UL)
#define TASK3_BIT (1UL<<2UL)

const TickType_t xDelay500ms = pdMS_TO_TICKS(500);

void inputTask1(void *)
{
    while (1)
    {
        xEventGroupSetBits(xEventGroup, TASK1_BIT);
        vTaskDelay(xDelay500ms);
    }
}

void inputTask2(void *)
{

    while (1)
    {
        xEventGroupSetBits(xEventGroup, TASK2_BIT);
        vTaskDelay(xDelay500ms);
    }
}

void inputTask3(void *)
{
    while (1)
    {
        xEventGroupSetBits(xEventGroup, TASK3_BIT);
        vTaskDelay(xDelay500ms);
    }
}

void outputTask(void *)
{
    const EventBits_t xBitsToWaitFor = (TASK1_BIT | TASK2_BIT | TASK3_BIT);
    EventBits_t xEventGroupValue;
    while (1)
    {
        xEventGroupValue = xEventGroupWaitBits(xEventGroup, xBitsToWaitFor, pdTRUE, pdTRUE, portMAX_DELAY);
        if ((xEventGroupValue & TASK1_BIT) != 0)
        {
            digitalWrite(RED, digitalRead(RED) ^ 1);
        }

        if ((xEventGroupValue & TASK2_BIT) != 0)
        {
            digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        }

        if ((xEventGroupValue & TASK3_BIT) != 0)
        {
            digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        }
    }

}

void SetUp()
{
    xEventGroup = xEventGroupCreate();
    xTaskCreate(inputTask1, "Input Task1", 100, nullptr, 1, nullptr);
    xTaskCreate(inputTask2, "Input Task2", 100, nullptr, 1, nullptr);
    xTaskCreate(inputTask3, "Input Task3", 100, nullptr, 1, nullptr);
    xTaskCreate(outputTask, "Out Task", 100, nullptr, 1, nullptr);
}

#endif //UNTITLED10_EVENT_GROUP_DEMO2_H
