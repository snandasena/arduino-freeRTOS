//
// Created by sajith on 3/20/22.
//

#ifndef UNTITLED10_SYNCING_TASK_AND_ISR_USING_SEMAPHORES_H
#define UNTITLED10_SYNCING_TASK_AND_ISR_USING_SEMAPHORES_H

#include "base.h"
#include "semphr.h"

SemaphoreHandle_t xBinarySemaphore;
int timer_counter;

void vHandlerTask(void *)
{
    while (1)
    {
        xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);
        digitalWrite(YELLOW, digitalRead(YELLOW) ^ 1);
    }
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = timer_counter;
}

void InterrupInit()
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

void SetUp()
{
    xBinarySemaphore = xSemaphoreCreateBinary();
    xTaskCreate(vHandlerTask, "Handler", 100, nullptr, 3, nullptr);
    InterrupInit();
}

#endif //UNTITLED10_SYNCING_TASK_AND_ISR_USING_SEMAPHORES_H
