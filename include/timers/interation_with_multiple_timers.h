//
// Created by sajith on 3/8/22.
//

#ifndef UNTITLED10_INTERATION_WITH_MULTIPLE_TIMERS_H
#define UNTITLED10_INTERATION_WITH_MULTIPLE_TIMERS_H

#include "base.h"
#include "timers.h"

#define GREEN_TIMER_PERIOD (pdMS_TO_TICKS(120))
#define RED_TIMER_PERIOD (pdMS_TO_TICKS(300))

TimerHandle_t xGreenTimer;
TimerHandle_t xRedTimer;

uint32_t greenExecutionCount;

void prvTimerCallback(TimerHandle_t xTimer)
{
    TickType_t xTimeNow;
    xTimeNow = xTaskGetTickCount();

    if (xTimer == xGreenTimer)
    {
        ++greenExecutionCount;
        Serial.print("Green Timer execution : ");
        Serial.println(xTimeNow);
        digitalWrite(GREEN, digitalRead(GREEN) ^ 1);

        if (greenExecutionCount == 100)
        {
            xTimerStop(xGreenTimer, 0);
        }
    }
    else
    {
        Serial.print("Red timer execution : ");
        Serial.println(xTimeNow);
        digitalWrite(RED, digitalRead(RED) ^ 1);
    }
}

void SetUp()
{
    BaseType_t xGreenTimerStarted;
    BaseType_t xRedTimerStarted;

    xGreenTimer = xTimerCreate("Green Timer", GREEN_TIMER_PERIOD, pdTRUE, 0, prvTimerCallback);
    xRedTimer = xTimerCreate("Red Timer", RED_TIMER_PERIOD, pdTRUE, 0, prvTimerCallback);

    if (xGreenTimer != nullptr && xRedTimer != nullptr)
    {
        xGreenTimerStarted = xTimerStart(xGreenTimer, 0);
        xRedTimerStarted = xTimerStart(xRedTimer, 0);

        while (xGreenTimerStarted != pdPASS && xRedTimerStarted != pdPASS) {}
    }

}

#endif //UNTITLED10_INTERATION_WITH_MULTIPLE_TIMERS_H
