/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "AppScheduling.h"
#include "Driver_Stm.h"
#include "GtmTomPwmHl.h"
#include "ConfigurationIsr.h"

uint8 stSensorAdcRaw0;
uint8 stSensorAdcRaw1;
uint8 stSensorAdcRaw2;

typedef struct
{
        uint32 u32nuCnt1ms;
}TestCnt;

static void AppTask1ms(void);

TestCnt stTestCnt;

uint32 t = 0;
float32 duty[2];

static void AppTask1ms(void)
{
    stTestCnt.u32nuCnt1ms++;
    if(stTestCnt.u32nuCnt1ms % 1000 == 0)
    {
        t++;
    }

    if(t <= 5)
    {
        duty[0] = 0;
    }
    else if(t > 5 && t < 11)
    {
        duty[0] = 0.3;
    }
    else if(t >= 11)
    {
        duty[0] = 0;
    }
    g_GtmTomPwmHl.tOn[0] = duty[0];

    GtmTomPwmHl_run();
}


void AppScheduling(void)
{
    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
        AppTask1ms();
    }
}