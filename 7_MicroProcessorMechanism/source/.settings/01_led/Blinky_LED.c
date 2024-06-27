/*
 * Blinky_LED.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "IfxPort.h" // 포트 정의 위함
#include "Bsp.h" //waitTime 사용위함

#define LED &MODULE_P10,2
#define WAIT_TIME 500

void initLED(void) //초기화!
{
    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    IfxPort_setPinLow(LED);
}

void blinkLED(void)
{
    IfxPort_togglePin(LED);
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));
}

