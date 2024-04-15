/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*pvCallBack)(void) = NULL;


void MADC_voidInit(void)
{
    #if     (MADC_ON_OFF == MADC_ON)
        MADC_voidEnableADC();
    #elif   (MADC_ON_OFF == MADC_OFF)
        MADC_voidDisableADC();
    #else
        #error "ADC MADC_ON_OFF, Configuration Error"
    #endif

    #if ((MADC_PRESCALER_CLK == MADC_PCLK2_DIVIDED_BY_2) || (MADC_PRESCALER_CLK == MADC_PCLK2_DIVIDED_BY_4) || (MADC_PRESCALER_CLK == MADC_PCLK2_DIVIDED_BY_6) || (MADC_PRESCALER_CLK == MADC_PCLK2_DIVIDED_BY_8))
        MADC_voidSetADCPrescaler(MADC_PRESCALER_CLK);
    #else
        #error "ADC MADC_PRESCALER_CLK, Configuration Error"
    #endif

    #if ((MADC_RESOLUTION == MADC_12_BIT_RESOLUTION) || (MADC_RESOLUTION == MADC_10_BIT_RESOLUTION) || (MADC_RESOLUTION == MADC_08_BIT_RESOLUTION) || (MADC_RESOLUTION == MADC_06_BIT_RESOLUTION))
        MADC_voidSetResolution(MADC_RESOLUTION);
    #else
        #error "ADC MADC_RESOLUTION, Configuration Error"
    #endif

    #if ((MADC_ALIGNMENT == MADC_RIGHT_ALIGNMENT) || (MADC_ALIGNMENT == MADC_LEFT_ALIGNMENT))
        MADC_voidSetDataAlignment(MADC_ALIGNMENT);
    #else
        #error "ADC MADC_ALIGNMENT, Configuration Error"
    #endif

    #if     (MADC_INTERRUPT == MADC_ENABLE_INTERRUPT)
        MADC_voidEnableAllInterrupts();
    #elif   (MADC_INTERRUPT == MADC_DISABLE_INTERRUPT)
        MADC_voidDisableAllInterrupts();
    #else
        #error "ADC MADC_INTERRUPT, Configuration Error"
    #endif

    MADC_voidClearAllFlags();
}

u8 MADC_u8GetFlagStatus(u8 Copy_u8FlagName)
{
    /* Use : Flags Name */
    u32 Local_u32RegisterValue;
    u8 Local_u8FlagValue = 0;
    Local_u32RegisterValue = GET_REG(ADC1->SR);
    Local_u8FlagValue = GET_BIT(Local_u32RegisterValue, Copy_u8FlagName);
    return Local_u8FlagValue;
}

void MADC_voidClearFlag(u8 Copy_u8FlagName)
{
    /* Use : Flags Name */
    SET_MASK((ADC1->SR), MASK_1_BIT, Copy_u8FlagName);
}

void MADC_voidClearAllFlags(void)
{
    MADC_voidClearFlag(ANALOG_WATCHDOG_FLAG);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(INJECTED_START_FLAG);
    MADC_voidClearFlag(REGULAR_START_FLAG);
    MADC_voidClearFlag(OVER_RUN_FLAG);
}

void MADC_voidEnableInterrupt(u8 Copy_u8InterruptName)
{
    /* Use : Interrupt Name */
    SET_WORD((ADC1->CR1), ENABLE_INTERRUPT, Copy_u8InterruptName);
}

void MADC_voidDisableInterrupt(u8 Copy_u8InterruptName)
{
    /* Use : Interrupt Name */
    SET_MASK((ADC1->CR1), MASK_1_BIT, Copy_u8InterruptName);
}

void MADC_voidEnableAllInterrupts(void)
{
    MADC_voidEnableInterrupt(REGULAR_END_OF_CONVERSION_INTERRUPT);
    MADC_voidEnableInterrupt(ANALOG_WATCHDOG_INTERRUPT);
    MADC_voidEnableInterrupt(INJECTED_END_OF_CONVERSION_INTERRUPT);
    MADC_voidEnableInterrupt(OVER_RUN_INTERRUPT);
}

void MADC_voidDisableAllInterrupts(void)
{
    MADC_voidDisableInterrupt(REGULAR_END_OF_CONVERSION_INTERRUPT);
    MADC_voidDisableInterrupt(ANALOG_WATCHDOG_INTERRUPT);
    MADC_voidDisableInterrupt(INJECTED_END_OF_CONVERSION_INTERRUPT);
    MADC_voidDisableInterrupt(OVER_RUN_INTERRUPT);
}

void MADC_voidSetResolution(u8 Copy_u8ResolutionValue)
{
    /* Use : Resolution Value */
    SET_MASK((ADC1->CR1), MASK_2_BIT, CR1_RES);
    SET_WORD((ADC1->CR1), Copy_u8ResolutionValue, CR1_RES);
}

void MADC_voidSetAnalogWatchDogStatus(u8 Copy_u8ChannelMode, u8 Copy_u8WatchDogStatus)
{
    /* Use : Channel Mode, WatchDog Status */
    switch (Copy_u8ChannelMode)
    {
        case REGULAR_CHANNEL:
            SET_MASK((ADC1->CR1), MASK_1_BIT, CR1_AWDEN);
            SET_WORD(ADC1->CR1, Copy_u8WatchDogStatus, CR1_AWDEN);
        break;
        case INJECTED_CHANNEL:
            SET_MASK((ADC1->CR1), MASK_1_BIT, CR1_JAWDEN);
            SET_WORD(ADC1->CR1, Copy_u8WatchDogStatus, CR1_JAWDEN);
        break;
        default:
        break;
    }
}

void MADC_voidSetAnalogWatchDogSignal(u8 Copy_u8AnalogWatchDogSignalType)
{
    /* Use : Analog WatchDog Signal Type */
    SET_MASK((ADC1->CR1), MASK_1_BIT, CR1_AWDSGL);
    SET_WORD((ADC1->CR1), Copy_u8AnalogWatchDogSignalType, CR1_AWDSGL);
}

void MADC_voidSelectAnalogWatchDogChannel(u8 Copy_u8ChannelNumber)
{
    /* Use : Numbers in between of (0 ... 18) */
    if ((Copy_u8ChannelNumber >= 0) && (Copy_u8ChannelNumber <= 18))
    {
        SET_MASK((ADC1->CR1), MASK_5_BIT, CR1_AWDCH);
        SET_WORD((ADC1->CR1), Copy_u8ChannelNumber, CR1_AWDCH);
    }
}

void MADC_voidSetDiscontinuousModeStatus(u8 Copy_u8ChannelMode, u8 Copy_u8DiscontinuousModeStatus)
{
    /* Use : Channel Mode, Discontinuous Mode Status */
    switch (Copy_u8ChannelMode)
    {
        case REGULAR_CHANNEL:
            SET_MASK(ADC1->CR1, MASK_1_BIT, CR1_DISCEN);
            SET_WORD(ADC1->CR1, Copy_u8DiscontinuousModeStatus, CR1_DISCEN);
        break;
        case INJECTED_CHANNEL:
            SET_MASK(ADC1->CR1, MASK_1_BIT, CR1_JDISCEN);
            SET_WORD(ADC1->CR1, Copy_u8DiscontinuousModeStatus, CR1_JDISCEN);
        break;
        default:
        break;
    }
}

void MADC_voidSetDiscontinuousRegularChannelsNumber(u8 Copy_u8DiscontinuousRegularChannelsNumber)
{
    /* Use : Numbers in between of (1 ... 8) */
    if ((Copy_u8DiscontinuousRegularChannelsNumber >= 1) && (Copy_u8DiscontinuousRegularChannelsNumber <= 8))
    {
        SET_MASK((ADC1->CR1), MASK_3_BIT, CR1_DISCNUM);
        SET_WORD((ADC1->CR1), (Copy_u8DiscontinuousRegularChannelsNumber - 1), CR1_DISCNUM);
    }
}

void MADC_voidAutoInjectionStatus(u8 Copy_u8AutoInjectionStatus)
{
    /* Use : Auto Injection Status */
    SET_MASK(ADC1->CR1, MASK_1_BIT, CR1_JAUTO);
    SET_WORD(ADC1->CR1, Copy_u8AutoInjectionStatus, CR1_JAUTO);
}

void MADC_voidScanModeStatus(u8 Copy_u8ScanModeStatus)
{
    /* Use : Scan Mode Status */
    SET_MASK(ADC1->CR1, MASK_1_BIT, CR1_SCAN);
    SET_WORD(ADC1->CR1, Copy_u8ScanModeStatus, CR1_SCAN);
}

void MADC_voidStartConversion(u8 Copy_u8ChannelMode)
{
    /* Use : Channel Mode */
    switch (Copy_u8ChannelMode)
    {
        case REGULAR_CHANNEL:
            SET_WORD(ADC1->CR2, START_CONVERSION, CR2_SWSTART);
        break;
        case INJECTED_CHANNEL:
            SET_WORD(ADC1->CR2, START_CONVERSION, CR2_JSWSTART);
        break;
        default:
        break;
    }
}

void MADC_voidResetConversion(u8 Copy_u8ChannelMode)
{
    /* Use : Channel Mode */
    switch (Copy_u8ChannelMode)
    {
        case REGULAR_CHANNEL:
            SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_SWSTART);
        break;
        case INJECTED_CHANNEL:
            SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_JSWSTART);
        break;
        default:
        break;
    }
}

void MADC_voidExternalTriggerStatus(u8 Copy_u8ChannelMode, u8 Copy_u8ExternalTriggerStatus)
{
    /* Use : Channel Mode, External Trigger Status */
    switch (Copy_u8ChannelMode)
    {
        case REGULAR_CHANNEL:
            SET_MASK(ADC1->CR2, MASK_2_BIT, CR2_EXTEN);
            SET_WORD(ADC1->CR2, Copy_u8ExternalTriggerStatus, CR2_EXTEN);
        break;
        case INJECTED_CHANNEL:
            SET_MASK(ADC1->CR2, MASK_2_BIT, CR2_JEXTEN);
            SET_WORD(ADC1->CR2, Copy_u8ExternalTriggerStatus, CR2_JEXTEN);
        break;
        default:
        break;
    }
}

void MADC_voidSelectRegularExternalEvent(u8 Copy_u8RegularExternalEvent)
{
    /* Use : Regular External Event */
    SET_MASK(ADC1->CR2, MASK_4_BIT, CR2_EXTSEL);
    SET_WORD(ADC1->CR2, Copy_u8RegularExternalEvent, CR2_EXTSEL);
}

void MADC_voidSelectInjectedExternalEvent(u8 Copy_u8InjectedExternalEvent)
{
    /* Use : Injected External Event */
    SET_MASK(ADC1->CR2, MASK_4_BIT, CR2_JEXTSEL);
    SET_WORD(ADC1->CR2, Copy_u8InjectedExternalEvent, CR2_JEXTSEL);
}

void MADC_voidSetDataAlignment(u8 Copy_u8DataAlignment)
{
    /* Use : Data Alignment */
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_ALIGN);
    SET_WORD(ADC1->CR2, Copy_u8DataAlignment, CR2_ALIGN);
}

void MADC_voidSelectEndOfConversion(u8 Copy_u8EndOfConversion)
{
    /* Use : End Of Conversion */
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_EOCS);
    SET_WORD(ADC1->CR2, Copy_u8EndOfConversion, CR2_EOCS);
}

void MADC_voidSelectDMADisableRequest(u8 Copy_u8RequestStatus)
{
    /* Use : DMA Request Status */
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_DDS);
    SET_WORD(ADC1->CR2, Copy_u8RequestStatus, CR2_DDS);
}

void MADC_voidSelectDMAModeStatus(u8 Copy_u8DMAStatus)
{
    /* Use : DMA Mode Status */
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_DMA);
    SET_WORD(ADC1->CR2, Copy_u8DMAStatus, CR2_DMA);
}

void MADC_voidSetConversionMode(u8 Copy_u8ConversionMode)
{
    /* Use : Conversion Mode */
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_CONT);
    SET_WORD(ADC1->CR2, Copy_u8ConversionMode, CR2_CONT);
}

void MADC_voidEnableADC(void)
{
    SET_WORD(ADC1->CR2, ENABLE_ADC, CR2_ADON);
}

void MADC_voidDisableADC(void)
{
    SET_MASK(ADC1->CR2, MASK_1_BIT, CR2_ADON);
}

void MADC_voidSetChannelSamplingTime(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18) */
    if ((Copy_u8ChannelNumber >= 10) && (Copy_u8ChannelNumber <= 18))
    {
        SET_MASK((ADC1->SMPR1), MASK_3_BIT, ((Copy_u8ChannelNumber * 3) - 30));
        SET_WORD((ADC1->SMPR1), Copy_u8SamplingTime, ((Copy_u8ChannelNumber * 3) - 30));
    }
    else if ((Copy_u8ChannelNumber >= 0) && (Copy_u8ChannelNumber <= 9))
    {
        SET_MASK((ADC1->SMPR2), MASK_3_BIT, (Copy_u8ChannelNumber * 3));
        SET_WORD((ADC1->SMPR2), Copy_u8SamplingTime, (Copy_u8ChannelNumber * 3));
    }
}

void MADC_voidSetInjectedChannelDataOffset(u8 Copy_u8InjectedChannelNumber, u16 Copy_u16Offset)
{
    /* Use : Offset in between of (0 ... 2048), Injected Channel Number in between of (1 ... 4) */
    if ((Copy_u16Offset >= 0) && (Copy_u16Offset <= 2048))
    {
        switch (Copy_u8InjectedChannelNumber)
        {
            case 1:
                SET_MASK(ADC1->JOFR1, MASK_12_BIT, JOFR1_JOFFSET);
                SET_WORD(ADC1->JOFR1, Copy_u16Offset, JOFR1_JOFFSET);
            break;
            case 2:
                SET_MASK(ADC1->JOFR2, MASK_12_BIT, JOFR2_JOFFSET);
                SET_WORD(ADC1->JOFR2, Copy_u16Offset, JOFR2_JOFFSET);
            break;
            case 3:
                SET_MASK(ADC1->JOFR3, MASK_12_BIT, JOFR3_JOFFSET);
                SET_WORD(ADC1->JOFR3, Copy_u16Offset, JOFR3_JOFFSET);
            break;
            case 4:
                SET_MASK(ADC1->JOFR4, MASK_12_BIT, JOFR4_JOFFSET);
                SET_WORD(ADC1->JOFR4, Copy_u16Offset, JOFR4_JOFFSET);
            break;
            default:
            break;
        }
    }
}

void MADC_voidSetHigherWatchDogThreshold(u16 Copy_u16ThresholdNumber)
{
    /* Use : Offset in between of (0 ... 2048) */
    if ((Copy_u16ThresholdNumber >= 0) && (Copy_u16ThresholdNumber <= 2048))
    {
        SET_WORD(ADC1->HTR, MASK_12_BIT, HTR_HT);
        SET_WORD(ADC1->HTR, Copy_u16ThresholdNumber, HTR_HT);
    }
}

void MADC_voidSetLowerWatchDogThreshold(u16 Copy_u16ThresholdNumber)
{
    /* Use : Offset in between of (0 ... 2048) */
    if ((Copy_u16ThresholdNumber >= 0) && (Copy_u16ThresholdNumber <= 2048))
    {
        SET_MASK(ADC1->LTR, MASK_12_BIT, LTR_LT);
        SET_WORD(ADC1->LTR, Copy_u16ThresholdNumber, LTR_LT);
    }
}

void MADC_voidSetRegularSequenceLength(u8 Copy_u8RegularSequenceLength)
{
    /* Use : Regular Sequence Length in between of (1 ... 16) */
    if ((Copy_u8RegularSequenceLength >= 1) && (Copy_u8RegularSequenceLength <= 16))
    {
        SET_MASK(ADC1->SQR1, MASK_4_BIT, SQR1_L);
        SET_WORD(ADC1->SQR1, (Copy_u8RegularSequenceLength - 1), SQR1_L);
    }
}

void MADC_voidSetRegularSequenceChannel(u8 Copy_u8ChannelNumber, u8 Copy_u8SequenceNumber)
{
    /* Use : Sequence Number in between of (1 ... 16), Channel Number in between of (0 ... 18) */
    if ((Copy_u8SequenceNumber >= 13) && (Copy_u8SequenceNumber <= 16))
    {
        SET_MASK((ADC1->SQR1), MASK_5_BIT, (((Copy_u8SequenceNumber - 1) * 5) - 60));
        SET_WORD((ADC1->SQR1), Copy_u8ChannelNumber, (((Copy_u8SequenceNumber - 1) * 5) - 60));
    }
    else if ((Copy_u8SequenceNumber >= 7) && (Copy_u8SequenceNumber <= 12))
    {
        SET_MASK((ADC1->SQR2), MASK_5_BIT, (((Copy_u8SequenceNumber - 1) * 5) - 30));
        SET_WORD((ADC1->SQR2), Copy_u8ChannelNumber, (((Copy_u8SequenceNumber - 1) * 5) - 30));
    }
    else if ((Copy_u8SequenceNumber >= 1) && (Copy_u8SequenceNumber <= 6))
    {
        SET_MASK((ADC1->SQR3), MASK_5_BIT, ((Copy_u8SequenceNumber - 1) * 5));
        SET_WORD((ADC1->SQR3), Copy_u8ChannelNumber, ((Copy_u8SequenceNumber - 1) * 5));
    }
}

void MADC_voidSetInjectedSequenceLength(u8 Copy_u8InjectedSequenceLength)
{
    /* Use : Injected Sequence Length in between of (1 ... 4) */
    if ((Copy_u8InjectedSequenceLength >= 1) && (Copy_u8InjectedSequenceLength <= 4))
    {
        SET_MASK(ADC1->JSQR, MASK_2_BIT, JSQR_JL);
        SET_WORD(ADC1->JSQR, (Copy_u8InjectedSequenceLength - 1), JSQR_JL);
    }
}

void MADC_voidSetInjectedSequenceChannel(u8 Copy_u8ChannelNumber, u8 Copy_u8SequenceNumber)
{
    /* Use : Sequence Number in between of (1 ... 4), Channel Number in between of (0 ... 18) */
    if ((Copy_u8SequenceNumber >= 1) && (Copy_u8SequenceNumber <= 4))
    {
        SET_MASK((ADC1->JSQR), MASK_5_BIT, ((Copy_u8SequenceNumber - 1) * 5));
        SET_WORD((ADC1->JSQR), Copy_u8ChannelNumber, ((Copy_u8SequenceNumber - 1) * 5));
    }
}

s16 MADC_s16GetConvertedInjectedData(u8 Copy_u8InjectedChannelNumber)
{
    /* Use : Injected Channel Number in between of (1 ... 4) */
    s16 Local_s16Data = 0;
    switch (Copy_u8InjectedChannelNumber)
    {
        case 1:
            Local_s16Data = GET_REG(ADC1->JDR1);
        break;
        case 2:
            Local_s16Data = GET_REG(ADC1->JDR2);
        break;
        case 3:
            Local_s16Data = GET_REG(ADC1->JDR3);
        break;
        case 4:
            Local_s16Data = GET_REG(ADC1->JDR4);
        break;
        default:
        break;
    }
    return Local_s16Data;
}

u16 MADC_u16GetConvertedRegularData(void)
{
    return (GET_REG(ADC1->DR));
}

void MADC_voidSetADCPrescaler(u8 Copy_u8PrescalerValue)
{
    /* Use : Prescaler Value */
    SET_MASK(ADC_CCR, MASK_2_BIT, CCR_ADCPRE);
    SET_WORD(ADC_CCR, Copy_u8PrescalerValue, CCR_ADCPRE);
}

void MADC_voidSetVoltageBatteryStatus(u8 Copy_u8BatteryStatus)
{
    /* Use : Battery Status */
    SET_MASK(ADC_CCR, MASK_1_BIT, CCR_VBATE);
    SET_WORD(ADC_CCR, Copy_u8BatteryStatus, CCR_VBATE);
}

void MADC_voidSetTemperatureSensorStatus(u8 Copy_u8TemperatureSensorStatus)
{
    /* Use : Temperature Sensor Status */
    SET_MASK(ADC_CCR, MASK_1_BIT, CCR_TSVREFE);
    SET_WORD(ADC_CCR, Copy_u8TemperatureSensorStatus, CCR_TSVREFE);
}

u16 MADC_u16StartSingleRegularConversion(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18) */
    u16 Local_u16Reading = 0;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidSetChannelSamplingTime( Copy_u8ChannelNumber, Copy_u8SamplingTime);
    MADC_voidSetRegularSequenceLength(1);
    MADC_voidSetRegularSequenceChannel(Copy_u8ChannelNumber, 1);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(REGULAR_CHANNEL);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

s16 MADC_s16StartSingleInjectedConversion(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime, u16 Copy_u16Offset)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Offset in between of (0 ... 2048) */
    s16 Local_s16Reading = 0;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidSetChannelSamplingTime( Copy_u8ChannelNumber, Copy_u8SamplingTime);
    MADC_voidSetInjectedChannelDataOffset(1, Copy_u16Offset);
    MADC_voidSetInjectedSequenceLength(1);
    MADC_voidSetInjectedSequenceChannel(Copy_u8ChannelNumber, 4);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(INJECTED_CHANNEL);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

u16 MADC_u16StartSingleRegularConversionOnTrigger(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Regular External Event, External Trigger Status */
    u16 Local_u16Reading = 0;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidSetChannelSamplingTime( Copy_u8ChannelNumber, Copy_u8SamplingTime);
    MADC_voidSetRegularSequenceLength(1);
    MADC_voidSetRegularSequenceChannel(Copy_u8ChannelNumber, 1);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

s16 MADC_s16StartSingleInjectedConversionOnTrigger(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime, u16 Copy_u16Offset, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Offset in between of (0 ... 2048), Injected External Event, External Trigger Status */
    s16 Local_s16Reading = 0;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidSelectInjectedExternalEvent(Copy_u8InjectedExternalEvent);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidSetChannelSamplingTime( Copy_u8ChannelNumber, Copy_u8SamplingTime);
    MADC_voidSetInjectedChannelDataOffset(1, Copy_u16Offset);
    MADC_voidSetInjectedSequenceLength(1);
    MADC_voidSetInjectedSequenceChannel(Copy_u8ChannelNumber, 4);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

u16 MADC_u16StartSingleRegularGroupConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16) */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(REGULAR_CHANNEL);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

s16 MADC_s16StartSingleInjectedGroupConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Offset in between of (0 ... 2048), Data Size in between of (1 ... 4) */
    s16 Local_s16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetInjectedSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (4 - Local_u8Iterator));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator, Copy_pu16OffsetArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(INJECTED_CHANNEL);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

u16 MADC_u16StartSingleRegularGroupConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16), Regular External Event, External Trigger Status */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

s16 MADC_s16StartSingleInjectedGroupConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 4), Offset in between of (0 ... 2048), Injected External Event, External Trigger Status */
    s16 Local_s16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidSelectInjectedExternalEvent(Copy_u8InjectedExternalEvent);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetInjectedSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (4 - Local_u8Iterator));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator, Copy_pu16OffsetArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

u16 MADC_u16StartContinousRegularGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16) */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(REGULAR_CHANNEL);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

u16 MADC_u16StartContinousRegularGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16), Regular External Event, External Trigger Status */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

void MADC_voidStartContinousRegularGroupEachConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray)
{
    /* Set your read variables with flags activiation, this only for setting sequence */
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16) */
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_CONVERSION);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(REGULAR_CHANNEL);
}

void MADC_voidStartContinousRegularGroupEachConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Set your read variables with flags activiation, this only for setting sequence */
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16), Regular External Event, External Trigger Status */
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_CONVERSION);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
}

void MADC_voidStartContinousRegularDMAConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16) */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSelectDMAModeStatus(DMA_MODE_ENABLE);
    MADC_voidSelectDMADisableRequest(NO_NEW_REQUEST_AFTER_TRANSFER);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(OVER_RUN_FLAG);
}

void MADC_voidStartContinousRegularDMAConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16), Regular External Event, External Trigger Status */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSelectDMAModeStatus(DMA_MODE_ENABLE);
    MADC_voidSelectDMADisableRequest(NO_NEW_REQUEST_AFTER_TRANSFER);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(OVER_RUN_FLAG);
}

void MADC_voidStartContinousRegularDMACircularConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16) */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSelectDMAModeStatus(DMA_MODE_ENABLE);
    MADC_voidSelectDMADisableRequest(SET_NEW_REQUEST_AFTER_TRANSFER);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(OVER_RUN_FLAG);
}

void MADC_voidStartContinousRegularDMACircularConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    /* Use : Sampling Time, Channel Number in between of (0 ... 18), Data Size in between of (1 ... 16), Regular External Event, External Trigger Status */
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSetConversionMode(CONTINUOUS_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSelectDMAModeStatus(DMA_MODE_ENABLE);
    MADC_voidSelectDMADisableRequest(SET_NEW_REQUEST_AFTER_TRANSFER);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(OVER_RUN_FLAG);
}

void MADC_voidSetSingleAutoGroupConversion(u8* Copy_pu8RegularChannelsNumberArray, u8 Copy_u8RegularDataSize, u8* Copy_pu8RegularSamplingTimeArray, u8* Copy_pu8InjectedChannelsNumberArray, u8 Copy_u8InjectedDataSize, u8* Copy_pu8InjectedSamplingTimeArray, u16* Copy_pu16InjectedOffsetArray)
{
    u8 Local_u8Iterator1;
    u8 Local_u8Iterator2;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidAutoInjectionStatus(ENABLE_AUTO_INJECTION);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8RegularDataSize);
    MADC_voidSetInjectedSequenceLength(Copy_u8InjectedDataSize);
    for (Local_u8Iterator1 = 0; Local_u8Iterator1 < Copy_u8RegularDataSize; Local_u8Iterator1++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8RegularChannelsNumberArray[Local_u8Iterator1], (Local_u8Iterator1 + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8RegularChannelsNumberArray[Local_u8Iterator1], Copy_pu8RegularSamplingTimeArray[Local_u8Iterator1]);
    }
    for (Local_u8Iterator2 = 0; Local_u8Iterator2 < Copy_u8InjectedDataSize; Local_u8Iterator2++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8InjectedChannelsNumberArray[Local_u8Iterator2], (4 - Local_u8Iterator2));
        MADC_voidSetChannelSamplingTime( Copy_pu8InjectedChannelsNumberArray[Local_u8Iterator2], Copy_pu8InjectedSamplingTimeArray[Local_u8Iterator2]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator2, Copy_pu16InjectedOffsetArray[Local_u8Iterator2]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(INJECTED_CHANNEL);
    MADC_voidStartConversion(REGULAR_CHANNEL);
}

void MADC_voidSetSingleAutoGroupConversionOnTrigger(u8* Copy_pu8RegularChannelsNumberArray, u8 Copy_u8RegularDataSize, u8* Copy_pu8RegularSamplingTimeArray, u8* Copy_pu8InjectedChannelsNumberArray, u8 Copy_u8InjectedDataSize, u8* Copy_pu8InjectedSamplingTimeArray, u16* Copy_pu16InjectedOffsetArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity)
{
    u8 Local_u8Iterator1;
    u8 Local_u8Iterator2;
    MADC_voidSetConversionMode(SINGLE_CONVERSION_MODE);
    MADC_voidAutoInjectionStatus(ENABLE_AUTO_INJECTION);
    MADC_voidScanModeStatus(ENABLE_SCAN_MODE);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidSetRegularSequenceLength(Copy_u8RegularDataSize);
    MADC_voidSetInjectedSequenceLength(Copy_u8InjectedDataSize);
    for (Local_u8Iterator1 = 0; Local_u8Iterator1 < Copy_u8RegularDataSize; Local_u8Iterator1++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8RegularChannelsNumberArray[Local_u8Iterator1], (Local_u8Iterator1 + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8RegularChannelsNumberArray[Local_u8Iterator1], Copy_pu8RegularSamplingTimeArray[Local_u8Iterator1]);
    }
    for (Local_u8Iterator2 = 0; Local_u8Iterator2 < Copy_u8InjectedDataSize; Local_u8Iterator2++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8InjectedChannelsNumberArray[Local_u8Iterator2], (4 - Local_u8Iterator2));
        MADC_voidSetChannelSamplingTime( Copy_pu8InjectedChannelsNumberArray[Local_u8Iterator2], Copy_pu8InjectedSamplingTimeArray[Local_u8Iterator2]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator2, Copy_pu16InjectedOffsetArray[Local_u8Iterator2]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
}

u16 MADC_u16StartDiscontinousRegularGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8NumberDataPerConversion)
{
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidSetDiscontinuousModeStatus(REGULAR_CHANNEL, ENABLE_DISCONTINUOUS_MODE);
    MADC_voidSetDiscontinuousRegularChannelsNumber(Copy_u8NumberDataPerConversion);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(REGULAR_CHANNEL);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

u16 MADC_u16StartDiscontinousRegularGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity, u8 Copy_u8NumberDataPerConversion)
{
    u16 Local_u16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSelectRegularExternalEvent(Copy_u8RegularExternalEvent);
    MADC_voidSetDiscontinuousModeStatus(REGULAR_CHANNEL, ENABLE_DISCONTINUOUS_MODE);
    MADC_voidSetDiscontinuousRegularChannelsNumber(Copy_u8NumberDataPerConversion);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetRegularSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetRegularSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (Local_u8Iterator + 1));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(REGULAR_END_OF_CONVERSION_FLAG) == FALSE);
    Local_u16Reading = MADC_u16GetConvertedRegularData();
    MADC_voidExternalTriggerStatus(REGULAR_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(REGULAR_END_OF_CONVERSION_FLAG);
    return Local_u16Reading;
}

s16 MADC_s16StartDiscontinousInjectedGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8NumberDataPerConversion)
{
    s16 Local_s16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidSetDiscontinuousModeStatus(REGULAR_CHANNEL, ENABLE_DISCONTINUOUS_MODE);
    MADC_voidSetDiscontinuousRegularChannelsNumber(Copy_u8NumberDataPerConversion);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetInjectedSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (4 - Local_u8Iterator));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator, Copy_pu16OffsetArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidStartConversion(INJECTED_CHANNEL);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

s16 MADC_s16StartDiscontinousInjectedGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity, u8 Copy_u8NumberDataPerConversion)
{
    s16 Local_s16Reading = 0;
    u8 Local_u8Iterator;
    MADC_voidSelectInjectedExternalEvent(Copy_u8InjectedExternalEvent);
    MADC_voidAutoInjectionStatus(DISABLE_AUTO_INJECTION);
    MADC_voidSetDiscontinuousModeStatus(REGULAR_CHANNEL, ENABLE_DISCONTINUOUS_MODE);
    MADC_voidSetDiscontinuousRegularChannelsNumber(Copy_u8NumberDataPerConversion);
    MADC_voidSelectEndOfConversion(EOC_END_EACH_SEQUENCE);
    MADC_voidSetInjectedSequenceLength(Copy_u8DataSize);
    for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
    {
        MADC_voidSetInjectedSequenceChannel(Copy_pu8ChannelsNumberArray[Local_u8Iterator], (4 - Local_u8Iterator));
        MADC_voidSetChannelSamplingTime( Copy_pu8ChannelsNumberArray[Local_u8Iterator], Copy_pu8SamplingTimeArray[Local_u8Iterator]);
        MADC_voidSetInjectedChannelDataOffset(Local_u8Iterator, Copy_pu16OffsetArray[Local_u8Iterator]);
    }
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, Copy_u8TriggerPolarity);
    while (MADC_u8GetFlagStatus(INJECTED_END_OF_CONVERSION_FLAG) == FALSE);
    Local_s16Reading = MADC_s16GetConvertedInjectedData(1);
    MADC_voidExternalTriggerStatus(INJECTED_CHANNEL, TRIGGER_DETECTION_DISABLED);
    MADC_voidClearFlag(INJECTED_END_OF_CONVERSION_FLAG);
    return Local_s16Reading;
}

void MADC_voidSetRegularSingleAnalogWatchdog(u8 Copy_u8ChannelNumber, u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber)
{
    /* The analog voltage is compared to the lower and higher thresholds before alignment */
    MADC_voidSelectAnalogWatchDogChannel(Copy_u8ChannelNumber);
    MADC_voidSetAnalogWatchDogSignal(ON_SINGLE_CHANNELS);
    MADC_voidSetHigherWatchDogThreshold(Copy_u16HighThresholdNumber);
    MADC_voidSetLowerWatchDogThreshold(Copy_u16LowThresholdNumber);
    MADC_voidSetAnalogWatchDogStatus(REGULAR_CHANNEL, ENABLE_WATCHDOG);
}

void MADC_voidSetInjectedSingleAnalogWatchdog(u8 Copy_u8ChannelNumber, u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber)
{
    /* The analog voltage is compared to the lower and higher thresholds before alignment */
    MADC_voidSelectAnalogWatchDogChannel(Copy_u8ChannelNumber);
    MADC_voidSetAnalogWatchDogSignal(ON_SINGLE_CHANNELS);
    MADC_voidSetHigherWatchDogThreshold(Copy_u16HighThresholdNumber);
    MADC_voidSetLowerWatchDogThreshold(Copy_u16LowThresholdNumber);
    MADC_voidSetAnalogWatchDogStatus(INJECTED_CHANNEL, ENABLE_WATCHDOG);
}

void MADC_voidSetRegularAllAnalogWatchdog(u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber)
{
    /* The analog voltage is compared to the lower and higher thresholds before alignment */
    MADC_voidSetAnalogWatchDogSignal(ON_ALL_CHANNELS);
    MADC_voidSetHigherWatchDogThreshold(Copy_u16HighThresholdNumber);
    MADC_voidSetLowerWatchDogThreshold(Copy_u16LowThresholdNumber);
    MADC_voidSetAnalogWatchDogStatus(REGULAR_CHANNEL, ENABLE_WATCHDOG);
}

void MADC_voidSetInjectedAllAnalogWatchdog(u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber)
{
    /* The analog voltage is compared to the lower and higher thresholds before alignment */
    MADC_voidSetAnalogWatchDogSignal(ON_ALL_CHANNELS);
    MADC_voidSetHigherWatchDogThreshold(Copy_u16HighThresholdNumber);
    MADC_voidSetLowerWatchDogThreshold(Copy_u16LowThresholdNumber);
    MADC_voidSetAnalogWatchDogStatus(INJECTED_CHANNEL, ENABLE_WATCHDOG);
}

f64 MADC_f64GetAmbientTemperature(void)
{
    u16 Local_u16Reading = 0;
    f64 Local_f64SensorVolt;
    f64 Local_f64Temperature;
    MADC_voidSetVoltageBatteryStatus(VBAT_CHANNEL_DISABLE);
    MADC_voidSetChannelSamplingTime(16, SAMPLEING_TIME_112_CYCLES);
    MADC_voidSetTemperatureSensorStatus(TEMPERATURE_SENSOR_VREFINT_CHANNEL_ENABLE);
    Local_u16Reading = MADC_u16StartSingleRegularConversion(16, SAMPLEING_TIME_112_CYCLES);
    Local_f64SensorVolt = (Local_u16Reading * (3.3 / 4095.0));
    Local_f64Temperature = (((Local_f64SensorVolt - 0.76) * 1000.0) / 2.5 + 25.0);
    return Local_f64Temperature;
}

f64 MADC_f64MonitorBatteryCharge(void)
{
    /* Note : Battery might be cut by 'N' {externally using voltage divider} or {internally using bridges}, So multibly the func result by 'N' */
    u16 Local_u16Reading = 0;
    f64 Local_f64BatteryCharge;
    MADC_voidSetTemperatureSensorStatus(TEMPERATURE_SENSOR_VREFINT_CHANNEL_DISABLE);
    MADC_voidSetVoltageBatteryStatus(VBAT_CHANNEL_ENABLE);
    MADC_voidSetChannelSamplingTime(18, SAMPLEING_TIME_84_CYCLES);
    Local_u16Reading = MADC_u16StartSingleRegularConversion(18, SAMPLEING_TIME_84_CYCLES);
    Local_f64BatteryCharge = (Local_u16Reading * (3.3 / 4095.0));
    return Local_f64BatteryCharge;
}

void MADC_voidSetCallBack(void (*pvNotificationFunction)(void))
{
	pvCallBack = pvNotificationFunction;
}

/************* ADC ISR ******************/

void ADC_IRQHandler(void)
{
    if (pvCallBack != NULL)
    {
        pvCallBack();
    }
}