/** @file task_delay.h
*
* @brief @todo A description of the module’s purpose.
*
* @par
* COPYRIGHT NOTICE: (c) 2017 John Fritz
* All rights reserved.
*/

#ifndef _TASK_DELAY_H
#define _TASK_DELAY_H

#include <atmel_start.h>

inline void task_delay_ms(uint16_t ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

#endif // _TASK_DELAY_H
