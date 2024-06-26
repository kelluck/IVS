/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "AppScheduling.h"
#include "Driver_Stm.h"
#include "Blinky_LED.h"
#include "uart.h"

typedef struct
{
        uint32 u32nuCnt50ms;
        uint32 u32nuCnt500ms;
}TestCnt;

static void AppTask50ms(void);
static void AppTask500ms(void);

TestCnt stTestCnt;

static void AppTask50ms(void)
{
    stTestCnt.u32nuCnt50ms++;
    blinkLED();
}

static void AppTask500ms(void)
{
    stTestCnt.u32nuCnt500ms++;
    _out_uart3('a');
    _out_uart3('\n');
}

void AppScheduling(void)
{
    if(stSchedulingInfo.u8nuScheduling50msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling50msFlag = 0u;
        AppTask50ms();

        if(stSchedulingInfo.u8nuScheduling500msFlag == 1u)
        {
            stSchedulingInfo.u8nuScheduling500msFlag = 0u;
            AppTask500ms();
        }
    }
}
