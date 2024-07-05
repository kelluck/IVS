/*
 * DrvAdc.c
 *
 *  Created on: 2024. 6. 28.
 *      Author: user
 */

#include "DrvAdc.h"
#include "IfxVadc.h"
#include "IfxVadc_Adc.h"

typedef struct
{
        IfxVadc_Adc vadc; /* VADC handle */
        IfxVadc_Adc_Group adcGroup;
} App_VadcAutoScan;

static void DrvAdc_Group4Init(void);
static void DrvAdc_Group4ChannelInit(uint8 param_ChNum);

App_VadcAutoScan g_VadcAutoScan;

IfxVadc_Adc_Channel adc4Channel[ADC_GROUP4_MAX];

uint32 stSensorAdcRaw;

void DrvAdcInit(void)
{
    DrvAdc_Group4Init();
}

static void DrvAdc_Group4Init(void)
{
    IfxVadc_Adc_Config adcConfig;
    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

    IfxVadc_Adc_initModule(&g_VadcAutoScan.vadc, &adcConfig);

    IfxVadc_Adc_GroupConfig adcGroupConfig;
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &g_VadcAutoScan.vadc);

    adcGroupConfig.groupId = IfxVadc_GroupId_4;
    adcGroupConfig.master = adcGroupConfig.groupId;

    adcGroupConfig.arbiter.requestSlotScanEnabled = TRUE;

    adcGroupConfig.scanRequest.autoscanEnabled = TRUE;

    adcGroupConfig.scanRequest.triggerConfig.gatingMode = 1;

    IfxVadc_Adc_initGroup(&g_VadcAutoScan.adcGroup, &adcGroupConfig);

    DrvAdc_Group4ChannelInit(ADC_GROUP4_CH7);

    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);
}

static void DrvAdc_Group4ChannelInit(uint8 param_ChNum)
{
    IfxVadc_Adc_ChannelConfig adcChannelConfigInfo;
    uint32 ulTemp = ((uint32)1u << param_ChNum);

    IfxVadc_Adc_initChannelConfig(&adcChannelConfigInfo, &g_VadcAutoScan.adcGroup);

    adcChannelConfigInfo.channelId = (IfxVadc_ChannelId)(param_ChNum);
    adcChannelConfigInfo.resultRegister = (IfxVadc_ChannelResult)(param_ChNum);

    IfxVadc_Adc_initChannel(&adc4Channel[param_ChNum], &adcChannelConfigInfo);

    IfxVadc_Adc_setScan(&g_VadcAutoScan.adcGroup, ulTemp, ulTemp);
}

void DrvAdc_GetAdcRawGroup4(void)
{
    Ifx_VADC_RES conversionResult;

    conversionResult = IfxVadc_Adc_getResult(&adc4Channel[ADC_GROUP4_CH7]);
    stSensorAdcRaw = conversionResult.B.RESULT;

    IfxVadc_Adc_startScan(&g_VadcAutoScan.adcGroup);
}

