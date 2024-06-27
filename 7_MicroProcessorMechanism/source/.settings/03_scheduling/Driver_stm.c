/*
 * Driver_stm.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: user
 */

#include "Driver_Stm.h"
#include "IfxPort.h"
#include "IfxPort_PinMap.h"

typedef struct
{
        Ifx_STM              *stmSfr;
        IfxStm_CompareConfig stmConfig;
}App_Stm;

App_Stm g_Stm;
uint32 u32nuCounter50ms = 0;
SchedulingFlag stSchedulingInfo;

void Driver_Stm_Init(void)
{
    boolean interruptState = IfxCpu_disableInterrupts(); //초기화시에는 인터럽트 방해없게 하려고 끔

    IfxStm_enableOcdsSuspend(&MODULE_STM0);

    g_Stm.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&g_Stm.stmConfig);

    g_Stm.stmConfig.triggerPriority = 100u; //Interrupt 우선순위
    g_Stm.stmConfig.typeOfService = IfxSrc_Tos_cpu0;
    g_Stm.stmConfig.ticks = 2000000000u; //10만번 counting했을 때 1ms 계산!!!!!!!!!!!

    IfxStm_initCompare(g_Stm.stmSfr, &g_Stm.stmConfig);

    IfxCpu_restoreInterrupts(interruptState); //인터럽트 다시 켜기
}

IFX_INTERRUPT(STM_Int0Handler, 0, 100);
void STM_Int0Handler(void)
{
    IfxCpu_enableInterrupts();

    IfxStm_clearCompareFlag(g_Stm.stmSfr, g_Stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_Stm.stmSfr, g_Stm.stmConfig.comparator, 2000000000u); //계산!!!!!

    u32nuCounter50ms++;

    if((u32nuCounter50ms % 1) == 0u)
    {
        stSchedulingInfo.u8nuScheduling50msFlag = 1u;
    }

    if((u32nuCounter50ms % 10) == 0u)
    {
        stSchedulingInfo.u8nuScheduling500msFlag = 1u;
    }


}
