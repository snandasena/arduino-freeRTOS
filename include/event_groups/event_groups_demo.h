//
// Created by sajith on 3/12/22.
//

#ifndef UNTITLED10_EVENT_GROUPS_DEMO_H
#define UNTITLED10_EVENT_GROUPS_DEMO_H

#include "base.h"
#include "event_groups.h"

EventGroupHandle_t xEventGroup;


#define TASK1_BIT (1UL<<0UL)
#define TASK2_BIT (1UL<<1UL)

void eventGroupSettingTask(void *)
{
    const TickType_t xDelay500ms = pdMS_TO_TICKS(500);
    while (1)
    {
        xEventGroupSetBits(xEventGroup, TASK1_BIT);
        vTaskDelay(xDelay500ms);
        xEventGroupSetBits(xEventGroup, TASK2_BIT);
    }
}

void eventGroupReadingTask(void *)
{
    const EventBits_t xBitsToWaitFor = (TASK1_BIT | TASK2_BIT);
    EventBits_t xEventGroupValue;
    while (1)
    {
        xEventGroupValue = xEventGroupWaitBits(xEventGroup, xBitsToWaitFor, pdTRUE, pdTRUE, portMAX_DELAY);
        if (xEventGroupValue && TASK1_BIT != 0)
        {
            digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
        }

        if (xEventGroupValue && TASK2_BIT != 0)
        {
            digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
        }
    }
}

void SetUp()
{
    xEventGroup = xEventGroupCreate();

    xTaskCreate(eventGroupSettingTask, "Bit Setter", 100, nullptr, 1, nullptr);
    xTaskCreate(eventGroupReadingTask, "Bit Reader", 100, nullptr, 1, nullptr);
}

#endif //UNTITLED10_EVENT_GROUPS_DEMO_H
