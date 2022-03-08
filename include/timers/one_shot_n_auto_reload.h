//
// Created by sajith on 3/7/22.
//

#ifndef
UNTITLED10_ONE_SHOT_N_AUTO_RELOAD_H
#define
    UNTITLED10_ONE_SHOT_N_AUTO_RELOAD_H

#include

"base.h"

#include

"timers.h"

#define
ONE_SHOT_TIMER_PERIOD (pdMS_TO_TICKS(500)
)
#define
AUTO_RELOAD_TIMER_PERIOD (pdMS_TO_TICKS(300)
)

TimerHandle_t xTimer1;
TimerHandle_t xTimer2;

BaseType_t xTimer1Started;
BaseType_t xTimer2Started;


void prvOneShotTimerCallback(TimerHandle_t xTimer)
{
    static TickType_t xTimeNow;
    xTimeNow = xTaskGetTickCount();
    Serial.print("One-shot timer callback execution : ");
    Serial.println(xTimeNow);
}


void prvAutoReloadCallback(TimerHandle_t xTimer)
{
    static TickType_t xTimeNow;
    xTimeNow = xTaskGetTickCount();
    Serial.print("Auto-reload timer callback execution : ");
    Serial.println(xTimeNow);
}

void SetUp()
{
    xTimer1 = xTimerCreate("One Shot", ONE_SHOT_TIMER_PERIOD, pdFALSE, 0, prvOneShotTimerCallback);
    xTimer2 = xTimerCreate("Auto reload", AUTO_RELOAD_TIMER_PERIOD, pdTRUE, 0, prvAutoReloadCallback);

    if (xTimer1 != nullptr && xTimer2 != nullptr)
    {
        xTimer1Started = xTimerStart(xTimer1, 0);
        xTimer2Started = xTimerStart(xTimer2, 0);
    }

    while (xTimer1Started != pdPASS && xTimer2Started != pdPASS)
    {
    }
}


#endif //UNTITLED10_ONE_SHOT_N_AUTO_RELOAD_H
