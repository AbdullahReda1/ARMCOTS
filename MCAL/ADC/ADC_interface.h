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


#ifndef MCAL_ADC_ADC_INTERFACE_H
#define MCAL_ADC_ADC_INTERFACE_H


/* Channel Mode */
#define REGULAR_CHANNEL     0
#define INJECTED_CHANNEL    1

/* Flags Name */
#define ANALOG_WATCHDOG_FLAG               0
#define REGULAR_END_OF_CONVERSION_FLAG     1
#define INJECTED_END_OF_CONVERSION_FLAG    2
#define INJECTED_START_FLAG                3
#define REGULAR_START_FLAG                 4
#define OVER_RUN_FLAG                      5

/* Interrupt Name */
#define REGULAR_END_OF_CONVERSION_INTERRUPT     5
#define ANALOG_WATCHDOG_INTERRUPT               6
#define INJECTED_END_OF_CONVERSION_INTERRUPT    7
#define OVER_RUN_INTERRUPT                      26

/* Resolution Value */
#define RESOLUTION_12_BIT          0b00
#define RESOLUTION_10_BIT          0b01
#define RESOLUTION_08_BIT          0b10
#define RESOLUTION_06_BIT          0b11

/* WatchDog Status */
#define ENABLE_WATCHDOG       1
#define DISABLE_WATCHDOG      0

/* Discontinuous Mode Status */
#define ENABLE_DISCONTINUOUS_MODE       1
#define DISABLE_DISCONTINUOUS_MODE      0

/* Auto Injecion Status */
#define ENABLE_AUTO_INJECTION       1
#define DISABLE_AUTO_INJECTION      0

/* Scan Mode Status */
#define ENABLE_SCAN_MODE       1
#define DISABLE_SCAN_MODE      0

/* Analog WatchDog Signal Type */
#define ON_ALL_CHANNELS         0
#define ON_SINGLE_CHANNELS      1

/* External Trigger Status */
#define TRIGGER_DETECTION_DISABLED      0b00
#define TRIGGER_DETECTION_ON_RISING     0b01
#define TRIGGER_DETECTION_ON_FALLING    0b10
#define TRIGGER_DETECTION_ON_CHANGE     0b11

/* Regular External Event */
#define TIM1_CH1_REGULAR_EVENT        0b0000
#define TIM1_CH2_REGULAR_EVENT        0b0001
#define TIM1_CH3_REGULAR_EVENT        0b0010
#define TIM2_CH2_REGULAR_EVENT        0b0011
#define TIM2_CH3_REGULAR_EVENT        0b0100
#define TIM2_CH4_REGULAR_EVENT        0b0101
#define TIM2_TRGO_REGULAR_EVENT       0b0110
#define TIM3_CH1_REGULAR_EVENT        0b0111
#define TIM3_TRGO_REGULAR_EVENT       0b1000
#define TIM4_CH4_REGULAR_EVENT        0b1001
#define TIM5_CH1_REGULAR_EVENT        0b1010
#define TIM5_CH2_REGULAR_EVENT        0b1011
#define TIM5_CH3_REGULAR_EVENT        0b1100
#define EXTI_11_REGULAR_EVENT         0b1111

/* Injected External Event */
#define TIM1_CH4_INJECTED_EVENT       0b0000
#define TIM1_TRGO_INJECTED_EVENT      0b0001
#define TIM2_CH1_INJECTED_EVENT       0b0010
#define TIM2_TRGO_INJECTED_EVENT      0b0011
#define TIM3_CH2_INJECTED_EVENT       0b0100
#define TIM3_CH4_INJECTED_EVENT       0b0101
#define TIM4_CH1_INJECTED_EVENT       0b0110
#define TIM4_CH2_INJECTED_EVENT       0b0111
#define TIM4_CH3_INJECTED_EVENT       0b1000
#define TIM4_TRGO_INJECTED_EVENT      0b1001
#define TIM5_CH4_INJECTED_EVENT       0b1010
#define TIM5_TRGO_INJECTED_EVENT      0b1011
#define EXTI_15_INJECTED_EVENT        0b1111

/* Data Alignment */
#define RIGHT_ALIGNMENT         0
#define LEFT_ALIGNMENT          1

/* End Of Conversion */
#define EOC_END_EACH_SEQUENCE            0
#define EOC_END_EACH_CONVERSION          1

/* DMA Request Status */
#define NO_NEW_REQUEST_AFTER_TRANSFER    0
#define SET_NEW_REQUEST_AFTER_TRANSFER   1

/* DMA Mode Status */
#define DMA_MODE_DISABLE       0
#define DMA_MODE_ENABLE        1

/* Conversion Mode */
#define SINGLE_CONVERSION_MODE       0
#define CONTINUOUS_CONVERSION_MODE   1

/* Sampling Time */
#define SAMPLEING_TIME_3_CYCLES       0b000
#define SAMPLEING_TIME_15_CYCLES      0b001
#define SAMPLEING_TIME_28_CYCLES      0b010
#define SAMPLEING_TIME_56_CYCLES      0b011
#define SAMPLEING_TIME_84_CYCLES      0b100
#define SAMPLEING_TIME_112_CYCLES     0b101
#define SAMPLEING_TIME_144_CYCLES     0b110
#define SAMPLEING_TIME_480_CYCLES     0b111

/* Prescaler Value */
#define PCLK2_DIVIDED_BY_2      0b00
#define PCLK2_DIVIDED_BY_4      0b01
#define PCLK2_DIVIDED_BY_6      0b10
#define PCLK2_DIVIDED_BY_8      0b11

/* Battery Status */
#define VBAT_CHANNEL_DISABLE    0b0
#define VBAT_CHANNEL_ENABLE     0b1

/* Temperature Sensor Status */
#define TEMPERATURE_SENSOR_VREFINT_CHANNEL_DISABLE    0b0
#define TEMPERATURE_SENSOR_VREFINT_CHANNEL_ENABLE     0b1


/*  _________________________INIT_________________________  */
void MADC_voidInit(void);

/* _________________________SR_________________________ */
u8 MADC_u8GetFlagStatus(u8 Copy_u8FlagName);
void MADC_voidClearFlag(u8 Copy_u8FlagName);
void MADC_voidClearAllFlags(void);


/* _________________________CR1_________________________ */
void MADC_voidEnableInterrupt(u8 Copy_u8InterruptName);
void MADC_voidDisableInterrupt(u8 Copy_u8InterruptName);
void MADC_voidEnableAllInterrupts(void);
void MADC_voidDisableAllInterrupts(void);

void MADC_voidSetResolution(u8 Copy_u8ResolutionValue);

void MADC_voidSetAnalogWatchDogStatus(u8 Copy_u8ChannelMode, u8 Copy_u8WatchDogStatus);
void MADC_voidSetAnalogWatchDogSignal(u8 Copy_u8AnalogWatchDogSignalType);
void MADC_voidSelectAnalogWatchDogChannel(u8 Copy_u8ChannelNumber);

void MADC_voidSetDiscontinuousModeStatus(u8 Copy_u8ChannelMode, u8 Copy_u8DiscontinuousModeStatus);
void MADC_voidSetDiscontinuousRegularChannelsNumber(u8 Copy_u8DiscontinuousRegularChannelsNumber);

void MADC_voidAutoInjectionStatus(u8 Copy_u8AutoInjectionStatus);

void MADC_voidScanModeStatus(u8 Copy_u8ScanModeStatus);


/* _________________________CR2_________________________ */
void MADC_voidStartConversion(u8 Copy_u8ChannelMode);
void MADC_voidResetConversion(u8 Copy_u8ChannelMode);

void MADC_voidExternalTriggerStatus(u8 Copy_u8ChannelMode, u8 Copy_u8ExternalTriggerStatus);
void MADC_voidSelectRegularExternalEvent(u8 Copy_u8RegularExternalEvent);
void MADC_voidSelectInjectedExternalEvent(u8 Copy_u8InjectedExternalEvent);

void MADC_voidSetDataAlignment(u8 Copy_u8DataAlignment);

void MADC_voidSelectEndOfConversion(u8 Copy_u8EndOfConversion);

void MADC_voidSelectDMADisableRequest(u8 Copy_u8RequestStatus);
void MADC_voidSelectDMAModeStatus(u8 Copy_u8DMAStatus);

void MADC_voidSetConversionMode(u8 Copy_u8ConversionMode);

void MADC_voidEnableADC(void);
void MADC_voidDisableADC(void);


/* _________________________SMPR_________________________ */
void MADC_voidSetChannelSamplingTime(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime);

/* _________________________JOFR_________________________ */
void MADC_voidSetInjectedChannelDataOffset(u8 Copy_u8InjectedChannelNumber, u16 Copy_u16Offset);

/* _________________________HTR/LTR_________________________ */
void MADC_voidSetHigherWatchDogThreshold(u16 Copy_u16ThresholdNumber);
void MADC_voidSetLowerWatchDogThreshold(u16 Copy_u16ThresholdNumber);


/* _________________________SQR_________________________ */
void MADC_voidSetRegularSequenceLength(u8 Copy_u8RegularSequenceLength);
void MADC_voidSetRegularSequenceChannel(u8 Copy_u8ChannelNumber, u8 Copy_u8SequenceNumber);

/* _________________________JSQR_________________________ */
void MADC_voidSetInjectedSequenceLength(u8 Copy_u8InjectedSequenceLength);
void MADC_voidSetInjectedSequenceChannel(u8 Copy_u8ChannelNumber, u8 Copy_u8SequenceNumber);


/* _________________________DR/JDR_________________________ */
s16 MADC_s16GetConvertedInjectedData(u8 Copy_u8InjectedChannelNumber);
u16 MADC_u16GetConvertedRegularData(void);


/* _________________________CCR_________________________ */
void MADC_voidSetADCPrescaler(u8 Copy_u8PrescalerValue);
void MADC_voidSetVoltageBatteryStatus(u8 Copy_u8BatteryStatus);
void MADC_voidSetTemperatureSensorStatus(u8 Copy_u8TemperatureSensorStatus);


/* _________________________GENERAL_________________________ */
u16 MADC_u16StartSingleRegularConversion(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime);
s16 MADC_s16StartSingleInjectedConversion(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime, u16 Copy_u16Offset);
u16 MADC_u16StartSingleRegularConversionOnTrigger(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime,u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);
s16 MADC_s16StartSingleInjectedConversionOnTrigger(u8 Copy_u8ChannelNumber, u8 Copy_u8SamplingTime, u16 Copy_u16Offset, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity);

u16 MADC_u16StartSingleRegularGroupConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray);
s16 MADC_s16StartSingleInjectedGroupConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray);
u16 MADC_u16StartSingleRegularGroupConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);
s16 MADC_s16StartSingleInjectedGroupConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity);

u16 MADC_u16StartContinousRegularGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray);
u16 MADC_u16StartContinousRegularGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);

void MADC_voidStartContinousRegularGroupEachConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray);
void MADC_voidStartContinousRegularGroupEachConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);

void MADC_voidStartContinousRegularDMAConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray);
void MADC_voidStartContinousRegularDMAConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);

void MADC_voidStartContinousRegularDMACircularConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray);
void MADC_voidStartContinousRegularDMACircularConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);

void MADC_voidSetSingleAutoGroupConversion(u8* Copy_pu8RegularChannelsNumberArray, u8 Copy_u8RegularDataSize, u8* Copy_pu8RegularSamplingTimeArray, u8* Copy_pu8InjectedChannelsNumberArray, u8 Copy_u8InjectedDataSize, u8* Copy_pu8InjectedSamplingTimeArray, u16* Copy_pu16InjectedOffsetArray);
void MADC_voidSetSingleAutoGroupConversionOnTrigger(u8* Copy_pu8RegularChannelsNumberArray, u8 Copy_u8RegularDataSize, u8* Copy_pu8RegularSamplingTimeArray, u8* Copy_pu8InjectedChannelsNumberArray, u8 Copy_u8InjectedDataSize, u8* Copy_pu8InjectedSamplingTimeArray, u16* Copy_pu16InjectedOffsetArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity);

u16 MADC_u16StartDiscontinousRegularGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8NumberDataPerConversion);
u16 MADC_u16StartDiscontinousRegularGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u8 Copy_u8RegularExternalEvent, u8 Copy_u8TriggerPolarity, u8 Copy_u8NumberDataPerConversion);
s16 MADC_s16StartDiscontinousInjectedGroupSequenceConversion(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8NumberDataPerConversion);
s16 MADC_s16StartDiscontinousInjectedGroupSequenceConversionOnTrigger(u8* Copy_pu8ChannelsNumberArray, u8 Copy_u8DataSize, u8* Copy_pu8SamplingTimeArray, u16* Copy_pu16OffsetArray, u8 Copy_u8InjectedExternalEvent, u8 Copy_u8TriggerPolarity, u8 Copy_u8NumberDataPerConversion);

void MADC_voidSetRegularSingleAnalogWatchdog(u8 Copy_u8ChannelNumber, u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber);
void MADC_voidSetInjectedSingleAnalogWatchdog(u8 Copy_u8ChannelNumber, u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber);
void MADC_voidSetRegularAllAnalogWatchdog(u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber);
void MADC_voidSetInjectedAllAnalogWatchdog(u16 Copy_u16HighThresholdNumber, u16 Copy_u16LowThresholdNumber);

f64 MADC_f64GetAmbientTemperature(void);
f64 MADC_f64MonitorBatteryCharge(void);

void MADC_voidSetCallBack(void (*pvNotificationFunction)(void));


#endif