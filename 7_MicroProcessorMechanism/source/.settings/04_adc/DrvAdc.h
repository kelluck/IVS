/*
 * DrvAdc.h
 *
 *  Created on: 2024. 6. 28.
 *      Author: user
 */

#ifndef DRVADC_H_
#define DRVADC_H_

#include "Ifx_Types.h"

typedef enum
{
    ADC_GROUP4_CH0 = 0u,
    ADC_GROUP4_CH1,
    ADC_GROUP4_CH2,
    ADC_GROUP4_CH3,
    ADC_GROUP4_CH4,
    ADC_GROUP4_CH5,
    ADC_GROUP4_CH6,
    ADC_GROUP4_CH7,
    ADC_GROUP4_MAX
}ADC_GROUP4;

extern uint32 stSensorAdcRaw; // 받고 싶은 센싱 변수

extern void DrvAdcInit(void);
extern void DrvAdc_GetAdcRawGroup4(void);

#endif /* DRVADC_H_ */
