//
// Created by sajith on 3/20/22.
//

#ifndef UNTITLED10_SYNCING_TASK_WITH_EVENT_GROUPS_H
#define UNTITLED10_SYNCING_TASK_WITH_EVENT_GROUPS_H

#include "base.h"
#include "event_groups.h"


#define TASK1_BIT (1UL<<0UL)
#define TASK2_BIT (1UL<<1UL)
#define TASK3_BIT (1UL<<2UL)

EventGroupHandle_t xEventGroup;
EventBits_t allSyncBits = (TASK1_BIT | TASK2_BIT | TASK3_BIT);

void taskA(void *)
{
    EventBits_t uxReturn;
    while (1)
    {
        uxReturn = xEventGroupSync(xEventGroup, TASK1_BIT, allSyncBits, portMAX_DELAY);

        if ((uxReturn & allSyncBits) == allSyncBits)
        {
            digitalWrite(RED, digitalRead(RED) ^ 1);
            vTaskDelay(pdMS_TO_TICKS(50));
        }
    }
}

void taskB(void *)
{
    EventBits_t uxReturn;
    while (1)
    {
        uxReturn = xEventGroupSync(xEventGroup, TASK2_BIT, allSyncBits, portMAX_DELAY);

        if ((uxReturn & allSyncBits) == allSyncBits)
        {
            digitalWrite(GREEN, digitalRead(GREEN) ^ 1);
            vTaskDelay(pdMS_TO_TICKS(50));
        }
    }
}

void taskC(void *)
{
    EventBits_t uxReturn;
    while (1)
    {
        uxReturn = xEventGroupSync(xEventGroup, TASK3_BIT, allSyncBits, portMAX_DELAY);

        if ((uxReturn & allSyncBits) == allSyncBits)
        {
            digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
            vTaskDelay(pdMS_TO_TICKS(50));
        }
    }
}

void SetUp()
{
    xEventGroup = xEventGroupCreate();
    xTaskCreate(taskA, "Task A", 100, nullptr, 1, nullptr);
    xTaskCreate(taskB, "Task B", 100, nullptr, 1, nullptr);
    xTaskCreate(taskC, "Task C", 100, nullptr, 1, nullptr);
}

#endif //UNTITLED10_SYNCING_TASK_WITH_EVENT_GROUPS_H
