/**
 * \file IfxPsi5_Psi5.c
 * \brief PSI5 PSI5 details
 *
 * \version iLLD_1_0_1_17_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPsi5_Psi5.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPsi5_Psi5_deInitModule(IfxPsi5_Psi5 *psi5)
{
    Ifx_PSI5 *psi5SFR = psi5->psi5;

    IfxPsi5_Psi5_resetModule(psi5SFR);
}


void IfxPsi5_Psi5_enableModule(Ifx_PSI5 *psi5)
{
    psi5->CLC.U = 0x00000000;
}


uint32 IfxPsi5_Psi5_getFracDivClock(Ifx_PSI5 *psi5)
{
    uint32 result;
    uint32 fPsi5 = IfxScuCcu_getSpbFrequency();

    switch (psi5->FDR.B.DM)
    {
    case IfxPsi5_DividerMode_spb:
        result = fPsi5;
        break;
    case IfxPsi5_DividerMode_normal:
        result = fPsi5 / (IFXPSI5_STEP_RANGE - psi5->FDR.B.STEP);
        break;
    case IfxPsi5_DividerMode_fractional:
        result = (fPsi5 * IFXPSI5_STEP_RANGE) / psi5->FDR.B.STEP;
        break;
    case IfxPsi5_DividerMode_off:
        result = 0;
        break;
    default:
        result = 0;
    }

    return result;
}


boolean IfxPsi5_Psi5_initChannel(IfxPsi5_Psi5_Channel *channel, const IfxPsi5_Psi5_ChannelConfig *config)
{
    uint32       wdtIdx;
    boolean      status = TRUE;

    uint16       passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);

    Ifx_PSI5    *psi5   = config->module->psi5;
    Ifx_PSI5_CH *psi5Ch = &psi5->CH[config->channelId];
    channel->channel   = psi5Ch;
    channel->module    = (IfxPsi5_Psi5 *)config->module;
    channel->channelId = config->channelId;

    Ifx_PSI5_CH_PGC tempPGC;
    tempPGC.B.PLEN = config->pulseGeneration.pulseLength;
    tempPGC.B.DEL  = config->pulseGeneration.delayLength;
    tempPGC.B.TBS  = config->pulseGeneration.timeBaseSelect;
    tempPGC.B.ETB  = config->pulseGeneration.externalTimeBaseSelect;
    tempPGC.B.ETS  = config->pulseGeneration.externalTriggerSelect;
    tempPGC.B.BOT  = config->pulseGeneration.blankoutTime;

    switch (config->pulseGeneration.periodicOrExternalOrBypass)
    {
    case IfxPsi5_TriggerType_periodic:
        tempPGC.B.PTE = TRUE;
        tempPGC.B.ETE = FALSE;
        tempPGC.B.BYP = FALSE;
        break;

    case IfxPsi5_TriggerType_external:
        tempPGC.B.PTE = FALSE;
        tempPGC.B.ETE = TRUE;
        tempPGC.B.BYP = FALSE;
        break;

    case IfxPsi5_TriggerType_bypass:
        tempPGC.B.PTE = FALSE;
        tempPGC.B.ETE = FALSE;
        tempPGC.B.BYP = TRUE;
        break;
    }

    psi5Ch->PGC.U = tempPGC.U;

    Ifx_PSI5_CH_CTV tempCTV;
    tempCTV.B.CTV = config->channelTrigger.channelTriggerValue;
    tempCTV.B.CTC = config->channelTrigger.channelTriggerCounter;
    psi5Ch->CTV.U = tempCTV.U;

    for (wdtIdx = 0; wdtIdx < IFXPSI5_NUM_WDTS; wdtIdx++)
    {
        psi5Ch->WDT[wdtIdx].U = config->watchdogTimerLimit[wdtIdx];
    }

    Ifx_PSI5_CH_RCRA tempRCRA;
    tempRCRA.B.PDL0 = config->receiveControl.payloadLength[0];
    tempRCRA.B.PDL1 = config->receiveControl.payloadLength[1];
    tempRCRA.B.PDL2 = config->receiveControl.payloadLength[2];
    tempRCRA.B.PDL3 = config->receiveControl.payloadLength[3];
    tempRCRA.B.PDL4 = config->receiveControl.payloadLength[4];
    tempRCRA.B.PDL5 = config->receiveControl.payloadLength[5];
    tempRCRA.B.ASYN = config->receiveControl.asynchronousModeSelected;
    tempRCRA.B.AVBS = config->receiveControl.verboseForAsynchronousMode;
    psi5Ch->RCRA.U  = tempRCRA.U;

    Ifx_PSI5_CH_RCRB tempRCRB;
    tempRCRB.B.MSG0 = config->receiveControl.messagingBitsPresence[0];
    tempRCRB.B.MSG1 = config->receiveControl.messagingBitsPresence[1];
    tempRCRB.B.MSG2 = config->receiveControl.messagingBitsPresence[2];
    tempRCRB.B.MSG3 = config->receiveControl.messagingBitsPresence[3];
    tempRCRB.B.MSG4 = config->receiveControl.messagingBitsPresence[4];
    tempRCRB.B.MSG5 = config->receiveControl.messagingBitsPresence[5];
    tempRCRB.B.CRC0 = config->receiveControl.crcOrParity[0];
    tempRCRB.B.CRC1 = config->receiveControl.crcOrParity[1];
    tempRCRB.B.CRC2 = config->receiveControl.crcOrParity[2];
    tempRCRB.B.CRC3 = config->receiveControl.crcOrParity[3];
    tempRCRB.B.CRC4 = config->receiveControl.crcOrParity[4];
    tempRCRB.B.CRC5 = config->receiveControl.crcOrParity[5];
    tempRCRB.B.FEC0 = config->receiveControl.frameExpectation[0];
    tempRCRB.B.FEC1 = config->receiveControl.frameExpectation[1];
    tempRCRB.B.FEC2 = config->receiveControl.frameExpectation[2];
    tempRCRB.B.FEC3 = config->receiveControl.frameExpectation[3];
    tempRCRB.B.FEC4 = config->receiveControl.frameExpectation[4];
    tempRCRB.B.FEC5 = config->receiveControl.frameExpectation[5];
    tempRCRB.B.VBS0 = config->receiveControl.verbose[0];
    tempRCRB.B.VBS1 = config->receiveControl.verbose[1];
    tempRCRB.B.VBS2 = config->receiveControl.verbose[2];
    tempRCRB.B.VBS3 = config->receiveControl.verbose[3];
    tempRCRB.B.VBS4 = config->receiveControl.verbose[4];
    tempRCRB.B.VBS5 = config->receiveControl.verbose[5];
    psi5Ch->RCRB.U  = tempRCRB.U;

    Ifx_PSI5_CH_RCRC tempRCRC;
    tempRCRC.B.BRS = config->receiveControl.baudrateSelect;
    tempRCRC.B.TSP = config->receiveControl.pulseTimestampSelect;
    tempRCRC.B.TSF = config->receiveControl.frameTimestampSelect;
    tempRCRC.B.TSR = config->receiveControl.receiveDataRegisterTimestamp;
    psi5Ch->RCRC.U = tempRCRC.U;

    Ifx_PSI5_RFC    tempRFC;
    tempRFC.B.FWL                  = config->receiveControl.fifoWarningLevel;
    psi5->RFC[config->channelId].U = tempRFC.U;

    Ifx_PSI5_CH_SCR tempSCR;
    tempSCR.B.PLL = config->sendControl.payloadLength;
    tempSCR.B.EPS = config->sendControl.enhancedProtocolSelected;
    tempSCR.B.BSC = config->sendControl.bitStuffingEnabled;
    tempSCR.B.SSL = config->sendControl.ssrPayloadLength;
    tempSCR.B.SOL = config->sendControl.sorPayloadLength;
    tempSCR.B.CRC = config->sendControl.crcGenerationEnabled;
    tempSCR.B.STA = config->sendControl.startSequenceGenerationEnabled;
    tempSCR.B.INH = config->sendControl.inhibitingAutomaticTransferEnabled;
    psi5Ch->SCR.U = tempSCR.U;

    Ifx_PSI5_CH_IOCR tempIOCR;
    tempIOCR.B.DEPTH = config->inputOutputControl.digitalInputFilterDepth;
    tempIOCR.B.OIE   = config->inputOutputControl.outputInverterEnabled;
    tempIOCR.B.IIE   = config->inputOutputControl.inputInverterEnabled;
    psi5Ch->IOCR.U   = tempIOCR.U;

    psi5->GCR.U     |=
        ((IFXPSI5_ENABLE_CHANNELTRIGGER << config->channelId) | (IFXPSI5_ENABLE_CHANNEL << config->channelId));

    IfxScuWdt_setCpuEndinit(passwd);

    const IfxPsi5_Psi5_PinsConfig *pins = config->pinsConfig;

    if (pins != NULL_PTR)
    {
        const IfxPsi5_Rx_In *rx = pins->in;

        if (rx != NULL_PTR)
        {
            IfxPsi5_initRxPin(rx, pins->inMode, pins->pinDriver);
        }

        const IfxPsi5_Tx_Out *tx = pins->out;

        if (tx != NULL_PTR)
        {
            IfxPsi5_initTxPin(tx, pins->outMode, pins->pinDriver);
        }
    }

    return status;
}


void IfxPsi5_Psi5_initChannelConfig(IfxPsi5_Psi5_ChannelConfig *config, IfxPsi5_Psi5 *psi5)
{
    IfxPsi5_Psi5_ChannelConfig IfxPsi5_Psi5_defaultChannelConfig = {
        .channelId       = IfxPsi5_ChannelId_0,
        .module          = NULL_PTR,
        .pulseGeneration = {
            .pulseLength                = 5,
            .delayLength                = 1,
            .timeBaseSelect             = IfxPsi5_TimeBase_internal,
            .externalTimeBaseSelect     = IfxPsi5_Trigger_0,
            .periodicOrExternalOrBypass = IfxPsi5_TriggerType_periodic,
            .externalTriggerSelect      = IfxPsi5_Trigger_0,
            .blankoutTime               = 5
        },
        .channelTrigger                         = {
            .channelTriggerValue   = 0x150,
            .channelTriggerCounter = 0x130
        },
        .watchdogTimerLimit[0] = 0x0,
        .watchdogTimerLimit[1] = 0x0,
        .watchdogTimerLimit[2] = 0x0,
        .watchdogTimerLimit[3] = 0x0,
        .watchdogTimerLimit[4] = 0x0,
        .watchdogTimerLimit[5] = 0x0,
        .watchdogTimerLimit[6] = 0x0,
        .receiveControl        = {
            .payloadLength[0]             = 8,
            .payloadLength[1]             = 8,
            .payloadLength[2]             = 8,
            .payloadLength[3]             = 8,
            .payloadLength[4]             = 8,
            .payloadLength[5]             = 8,
            .asynchronousModeSelected     = FALSE,
            .verboseForAsynchronousMode   = IfxPsi5_Verbose_off,
            .messagingBitsPresence[0]     = IfxPsi5_MessagingBits_absent,
            .messagingBitsPresence[1]     = IfxPsi5_MessagingBits_absent,
            .messagingBitsPresence[2]     = IfxPsi5_MessagingBits_absent,
            .messagingBitsPresence[3]     = IfxPsi5_MessagingBits_absent,
            .messagingBitsPresence[4]     = IfxPsi5_MessagingBits_absent,
            .messagingBitsPresence[5]     = IfxPsi5_MessagingBits_absent,
            .crcOrParity[0]               = IfxPsi5_CRCorParity_parity,
            .crcOrParity[1]               = IfxPsi5_CRCorParity_parity,
            .crcOrParity[2]               = IfxPsi5_CRCorParity_parity,
            .crcOrParity[3]               = IfxPsi5_CRCorParity_parity,
            .crcOrParity[4]               = IfxPsi5_CRCorParity_parity,
            .crcOrParity[5]               = IfxPsi5_CRCorParity_parity,
            .frameExpectation[0]          = IfxPsi5_FrameExpectation_notExpected,
            .frameExpectation[1]          = IfxPsi5_FrameExpectation_notExpected,
            .frameExpectation[2]          = IfxPsi5_FrameExpectation_notExpected,
            .frameExpectation[3]          = IfxPsi5_FrameExpectation_notExpected,
            .frameExpectation[4]          = IfxPsi5_FrameExpectation_notExpected,
            .frameExpectation[5]          = IfxPsi5_FrameExpectation_notExpected,
            .verbose[0]                   = IfxPsi5_Verbose_off,
            .verbose[1]                   = IfxPsi5_Verbose_off,
            .verbose[2]                   = IfxPsi5_Verbose_off,
            .verbose[3]                   = IfxPsi5_Verbose_off,
            .verbose[4]                   = IfxPsi5_Verbose_off,
            .verbose[5]                   = IfxPsi5_Verbose_off,
            .baudrateSelect               = IfxPsi5_BaudRate_125,
            .pulseTimestampSelect         = IfxPsi5_TimestampRegister_a,
            .frameTimestampSelect         = IfxPsi5_TimestampRegister_a,
            .receiveDataRegisterTimestamp = IfxPsi5_ReceiveDataRegisterTimestamp_pulse,
            .fifoWarningLevel             = 16
        },
        .sendControl                            = {
            .payloadLength                      = 32,
            .enhancedProtocolSelected           = FALSE,
            .bitStuffingEnabled                 = FALSE,
            .ssrPayloadLength                   = 32,
            .sorPayloadLength                   = 32,
            .crcGenerationEnabled               = FALSE,
            .startSequenceGenerationEnabled     = FALSE,
            .inhibitingAutomaticTransferEnabled = FALSE
        },
        .inputOutputControl                     = {
            .digitalInputFilterDepth = IfxPsi5_DigitalInputFilterDepth_0,
            .outputInverterEnabled   = FALSE,
            .inputInverterEnabled    = FALSE
        }
    };
    *config        = IfxPsi5_Psi5_defaultChannelConfig;
    config->module = psi5;
}


boolean IfxPsi5_Psi5_initModule(IfxPsi5_Psi5 *psi5, const IfxPsi5_Psi5_Config *config)
{
    boolean   status  = TRUE;
    Ifx_PSI5 *psi5SFR = config->psi5;

    psi5->psi5 = psi5SFR;

    uint16    passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    IfxPsi5_Psi5_enableModule(psi5SFR);

    if (IfxPsi5_Psi5_initializeClock(psi5SFR, &config->fracDiv) == 0)
    {
        status = FALSE;

        return status;
    }
    else
    {}

    if (IfxPsi5_Psi5_initializeClock(psi5SFR, &config->slowClock) == 0)
    {
        status = FALSE;

        return status;
    }
    else
    {}

    if (IfxPsi5_Psi5_initializeClock(psi5SFR, &config->fastClock) == 0)
    {
        status = FALSE;

        return status;
    }
    else
    {}

    if (IfxPsi5_Psi5_initializeClock(psi5SFR, &config->timestampClock) == 0)
    {
        status = FALSE;

        return status;
    }
    else
    {}

    IfxScuWdt_setCpuEndinit(passwd);

    return status;
}


void IfxPsi5_Psi5_initModuleConfig(IfxPsi5_Psi5_Config *config, Ifx_PSI5 *psi5)
{
    uint32 spbFrequency = IfxScuCcu_getSpbFrequency();

    config->psi5                                     = psi5;
    config->fracDiv.frequency                        = spbFrequency;
    config->fracDiv.mode                             = IfxPsi5_DividerMode_normal;
    config->fracDiv.type                             = IfxPsi5_ClockType_fracDiv;
    config->slowClock.frequency                      = IFXPSI5_DEFAULT_SLOWCLOCK_FREQ;
    config->slowClock.mode                           = IfxPsi5_DividerMode_fractional;
    config->slowClock.type                           = IfxPsi5_ClockType_slowClock_125;
    config->fastClock.frequency                      = IFXPSI5_DEFAULT_FASTCLOCK_FREQ;
    config->fastClock.mode                           = IfxPsi5_DividerMode_fractional;
    config->fastClock.type                           = IfxPsi5_ClockType_fastClock_189;
    config->timestampClock.frequency                 = IFXPSI5_DEFAULT_TIMESTAMP_FREQ;
    config->timestampClock.mode                      = IfxPsi5_DividerMode_normal;
    config->timestampClock.type                      = IfxPsi5_ClockType_timeStamp;
    config->timestampCounterA.externalTimeBaseSelect = IfxPsi5_Trigger_0;
    config->timestampCounterA.timeBaseSelect         = IfxPsi5_TimeBase_internal;
    config->timestampCounterB.externalTimeBaseSelect = IfxPsi5_Trigger_0;
    config->timestampCounterB.timeBaseSelect         = IfxPsi5_TimeBase_internal;
    config->timestampCounterC.externalTimeBaseSelect = IfxPsi5_Trigger_0;
    config->timestampCounterC.timeBaseSelect         = IfxPsi5_TimeBase_internal;
}


uint32 IfxPsi5_Psi5_initializeClock(Ifx_PSI5 *psi5, const IfxPsi5_Psi5_Clock *clock)
{
    uint64              step           = 0;
    uint32              result         = 0;
    IfxPsi5_DividerMode divMode        = clock->mode;
    IfxPsi5_ClockType   clockType      = clock->type;
    uint32              clockFrequency = clock->frequency;
    uint32              fInput;
    Ifx_PSI5_FDR        tempFDR, tempFDRL, tempFDRH, tempFDRT;

    if (clockType == IfxPsi5_ClockType_fracDiv)
    {
        fInput = IfxScuCcu_getSpbFrequency();
    }
    else
    {
        fInput = IfxPsi5_Psi5_getFracDivClock(psi5);

        if (fInput == 0)
        {
            result = 0;

            return result;
        }
        else
        {}
    }

    switch (divMode)
    {
    case IfxPsi5_DividerMode_normal:
        step = IFXPSI5_STEP_RANGE - (fInput / clockFrequency);

        if (step > (IFXPSI5_STEP_RANGE - 1))
        {
            step = IFXPSI5_STEP_RANGE - 1;
        }
        else
        {
            /* do nothing */
        }

        result = (uint32)(fInput / (IFXPSI5_STEP_RANGE - step));
        break;

    case IfxPsi5_DividerMode_fractional:
        step = (uint64)((uint64)clockFrequency * IFXPSI5_STEP_RANGE) / fInput;

        if (step > (IFXPSI5_STEP_RANGE - 1))
        {
            step = IFXPSI5_STEP_RANGE - 1;
        }
        else
        {
            /* do nothing */
        }

        result = (uint32)((uint64)((uint64)fInput * step)) / IFXPSI5_STEP_RANGE;
        break;

    case IfxPsi5_DividerMode_off:
    default:
        step   = 0;
        result = 0;
        break;
    }

    if (result != 0)
    {
        switch (clockType)
        {
        case IfxPsi5_ClockType_fracDiv:
            tempFDR.U      = 0;
            tempFDR.B.DM   = divMode;
            tempFDR.B.STEP = (uint32)step;
            psi5->FDR.U    = tempFDR.U;
            break;

        case IfxPsi5_ClockType_slowClock_125:
            tempFDRL.U      = 0;
            tempFDRL.B.DM   = divMode;
            tempFDRL.B.STEP = (uint32)step;
            psi5->FDRL.U    = tempFDRL.U;
            break;

        case IfxPsi5_ClockType_fastClock_189:
            tempFDRH.U      = 0;
            tempFDRH.B.DM   = divMode;
            tempFDRH.B.STEP = (uint32)step;
            psi5->FDRH.U    = tempFDRH.U;
            break;

        case IfxPsi5_ClockType_timeStamp:
            tempFDRT.U      = 0;
            tempFDRT.B.DM   = divMode;
            tempFDRT.B.STEP = (uint32)step;
            psi5->FDRT.U    = tempFDRT.U;
            break;
        }
    }

    return result;
}


boolean IfxPsi5_Psi5_readChannelFrame(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Psi5_Frame *frame)
{
    if (channel->module->psi5->INTSTATA[channel->channelId].B.RDI == TRUE)
    {
        frame->rdm.lowWord                                    = channel->channel->RDRL.U;
        frame->rdm.highWord                                   = channel->channel->RDRH.U;

        channel->module->psi5->INTCLRA[channel->channelId].U |= (IFX_PSI5_INTCLRA_RDI_MSK << IFX_PSI5_INTCLRA_RDI_OFF) | (IFX_PSI5_INTCLRA_RSI_MSK << IFX_PSI5_INTCLRA_RSI_OFF);

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


boolean IfxPsi5_Psi5_readChannelSerialMessage(IfxPsi5_Psi5_Channel *channel, IfxPsi5_Slot slot, IfxPsi5_Psi5_SerialMessage *message)
{
    message->rds.value = channel->channel->SDS[slot].U;

    return TRUE;
}


void IfxPsi5_Psi5_resetModule(Ifx_PSI5 *psi5)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    psi5->KRST1.B.RST = 1;      /* Only if both Kernel reset bits are set a reset is executed */
    psi5->KRST0.B.RST = 1;

    while (psi5->KRST0.B.RSTSTAT == 0)
    {
        /* Wait until reset is executed */
    }

    psi5->KRSTCLR.B.CLR = 1;    /* Clear Kernel reset status bit */
    IfxScuWdt_setSafetyEndinit(passwd);
}


boolean IfxPsi5_Psi5_sendChannelData(IfxPsi5_Psi5_Channel *channel, uint64 data)
{
    uint32 dataLowWord  = (uint32)(data & 0xFFFFFFFF);
    uint32 dataHighWord = (uint32)((data >> 32) & 0xFFFFFFFF);
    channel->channel->SDRL.U = dataLowWord;
    channel->channel->SDRH.U = dataHighWord;

    if (channel->module->psi5->INTSTATA[channel->channelId].B.TPOI)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
