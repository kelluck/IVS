/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "AppScheduling.h"
#include "Driver_Stm.h"
#include "uart.h"
#include "Blinky_LED.h"

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
//    _out_uart3(50 * stTestCnt.u32nuCnt50ms);
//    _out_uart3('\n');
}

static void AppTask500ms(void)
{
    stTestCnt.u32nuCnt500ms++;
    //blinkLED();
}

void AppScheduling(void)
{
    if(stSchedulingInfo.u8nuScheduling50msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling50msFlag == 0u;
        AppTask50ms();

        if(stSchedulingInfo.u8nuScheduling500msFlag == 1u)
        {
            stSchedulingInfo.u8nuScheduling500msFlag == 0u;
            AppTask500ms();
        }
    }
}
