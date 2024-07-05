/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "AppScheduling.h"
#include "Driver_Stm.h"
#include "Blinky_LED.h"
#include "DrvAdc.h"
#include "uart.h"

uint8 stSensorAdcRaw0;
uint8 stSensorAdcRaw1;
uint8 stSensorAdcRaw2;

typedef struct
{
        uint32 u32nuCnt1ms;
}TestCnt;

static void AppTask1ms(void);

TestCnt stTestCnt;

static void AppTask1ms(void)
{
    stTestCnt.u32nuCnt1ms++;
    DrvAdc_GetAdcRawGroup4();//ADC value 0~5V 0~4095
    blinkLED(stSensorAdcRaw);
    stSensorAdcRaw0 = (stSensorAdcRaw & 15);
    stSensorAdcRaw1 = ((stSensorAdcRaw >> 4) & 15);
    stSensorAdcRaw2 = ((stSensorAdcRaw >> 8) & 15);

    _out_uart3(stSensorAdcRaw2 + '0');
    _out_uart3('\n');
    _out_uart3(stSensorAdcRaw1 + '0');
    _out_uart3('\n');
    _out_uart3(stSensorAdcRaw0 + '0');
    _out_uart3('\n');
    _out_uart3('\n');
}


void AppScheduling(void)
{
    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
        AppTask1ms();
    }
}
