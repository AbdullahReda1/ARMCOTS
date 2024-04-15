/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        05 Jun, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         05 Jun, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_DMA_DMA_INTERFACE_H
#define MCAL_DMA_DMA_INTERFACE_H


/* DMA peripheral */
#define MDMA1   0
#define MDMA2   1

/* Stream Number */
#define MDMA_STREAM0    0
#define MDMA_STREAM1    1
#define MDMA_STREAM2    2
#define MDMA_STREAM3    3
#define MDMA_STREAM4    4
#define MDMA_STREAM5    5
#define MDMA_STREAM6    6
#define MDMA_STREAM7    7

/* Channel Number */
#define MDMA_CHANNEL0   0b000
#define MDMA_CHANNEL1   0b001
#define MDMA_CHANNEL2   0b010
#define MDMA_CHANNEL3   0b011
#define MDMA_CHANNEL4   0b100
#define MDMA_CHANNEL5   0b101
#define MDMA_CHANNEL6   0b110
#define MDMA_CHANNEL7   0b111

/* Peripheral Request = (DMA peripheral , Stream Number , Channel Number) */
#define SPI3_RX             MDMA1,MDMA_STREAM0,MDMA_CHANNEL0
#define SPI3_RX_S2          MDMA1,MDMA_STREAM2,MDMA_CHANNEL0
#define SPI2_RX             MDMA1,MDMA_STREAM3,MDMA_CHANNEL0
#define SPI2_TX             MDMA1,MDMA_STREAM4,MDMA_CHANNEL0
#define SPI3_TX             MDMA1,MDMA_STREAM5,MDMA_CHANNEL0
#define SPI3_TX_S7          MDMA1,MDMA_STREAM7,MDMA_CHANNEL0
#define I2C1_RX             MDMA1,MDMA_STREAM0,MDMA_CHANNEL1
#define I2C3_RX             MDMA1,MDMA_STREAM1,MDMA_CHANNEL1
#define I2C1_RX_S5          MDMA1,MDMA_STREAM5,MDMA_CHANNEL1
#define I2C1_TX             MDMA1,MDMA_STREAM6,MDMA_CHANNEL1
#define I2C1_TX_S7          MDMA1,MDMA_STREAM7,MDMA_CHANNEL1
#define TIM4_CH1            MDMA1,MDMA_STREAM0,MDMA_CHANNEL2
#define I2S3_EXT_RX         MDMA1,MDMA_STREAM2,MDMA_CHANNEL2
#define TIM4_CH2            MDMA1,MDMA_STREAM3,MDMA_CHANNEL2
#define I2S2_EXT_TX         MDMA1,MDMA_STREAM4,MDMA_CHANNEL2
#define I2S3_EXT_TX         MDMA1,MDMA_STREAM5,MDMA_CHANNEL2
#define TIM4_UP             MDMA1,MDMA_STREAM6,MDMA_CHANNEL2
#define TIM4_CH3            MDMA1,MDMA_STREAM7,MDMA_CHANNEL2
#define I2S3_EXT_RX_S0      MDMA1,MDMA_STREAM0,MDMA_CHANNEL3
#define TIM2_UP_CH3         MDMA1,MDMA_STREAM1,MDMA_CHANNEL3
#define I2C3_RX_S2          MDMA1,MDMA_STREAM2,MDMA_CHANNEL3
#define I2S2_EXT_RX_S3      MDMA1,MDMA_STREAM3,MDMA_CHANNEL3
#define I2C3_TX             MDMA1,MDMA_STREAM4,MDMA_CHANNEL3
#define TIM2_CH1            MDMA1,MDMA_STREAM5,MDMA_CHANNEL3
#define TIM2_CH2_CH4        MDMA1,MDMA_STREAM6,MDMA_CHANNEL3
#define TIM2_UP_CH4         MDMA1,MDMA_STREAM7,MDMA_CHANNEL3
#define USART2_RX           MDMA1,MDMA_STREAM5,MDMA_CHANNEL4
#define USART2_TX           MDMA1,MDMA_STREAM6,MDMA_CHANNEL4
#define TIM3_CH4_UP         MDMA1,MDMA_STREAM2,MDMA_CHANNEL5
#define TIM3_CH1_TRIG       MDMA1,MDMA_STREAM4,MDMA_CHANNEL5
#define TIM3_CH2            MDMA1,MDMA_STREAM5,MDMA_CHANNEL5
#define TIM3_CH3            MDMA1,MDMA_STREAM7,MDMA_CHANNEL5
#define TIM5_CH3_UP         MDMA1,MDMA_STREAM0,MDMA_CHANNEL6
#define TIM5_CH4_TRIG       MDMA1,MDMA_STREAM1,MDMA_CHANNEL6
#define TIM5_CH1            MDMA1,MDMA_STREAM2,MDMA_CHANNEL6
#define TIM5_CH4_TRIG_S3    MDMA1,MDMA_STREAM3,MDMA_CHANNEL6
#define TIM5_CH2            MDMA1,MDMA_STREAM4,MDMA_CHANNEL6
#define I2C3_TX_S5          MDMA1,MDMA_STREAM5,MDMA_CHANNEL6
#define TIM5_UP             MDMA1,MDMA_STREAM6,MDMA_CHANNEL6
#define I2C2_RX             MDMA1,MDMA_STREAM2,MDMA_CHANNEL7
#define I2C2_RX_S3          MDMA1,MDMA_STREAM3,MDMA_CHANNEL7
#define I2C2_TX             MDMA1,MDMA_STREAM7,MDMA_CHANNEL7
#define ADC1_S0             MDMA2,MDMA_STREAM0,MDMA_CHANNEL0
#define ADC1_S4             MDMA2,MDMA_STREAM4,MDMA_CHANNEL0
#define TIM1_CH1_CH2_CH3    MDMA2,MDMA_STREAM6,MDMA_CHANNEL0
#define SPI1_RX_S0          MDMA2,MDMA_STREAM0,MDMA_CHANNEL3
#define SPI1_RX_S2          MDMA2,MDMA_STREAM2,MDMA_CHANNEL3
#define SPI1_TX_S3          MDMA2,MDMA_STREAM3,MDMA_CHANNEL3
#define SPI1_TX_S5          MDMA2,MDMA_STREAM5,MDMA_CHANNEL3
#define SPI4_RX             MDMA2,MDMA_STREAM0,MDMA_CHANNEL4
#define SPI4_TX             MDMA2,MDMA_STREAM1,MDMA_CHANNEL4
#define USART1_RX_S1        MDMA2,MDMA_STREAM2,MDMA_CHANNEL4
#define SDIO_S3             MDMA2,MDMA_STREAM3,MDMA_CHANNEL4
#define USART1_RX_S5        MDMA2,MDMA_STREAM5,MDMA_CHANNEL4
#define SDIO_S6             MDMA2,MDMA_STREAM6,MDMA_CHANNEL4
#define USART1_TX_S6        MDMA2,MDMA_STREAM7,MDMA_CHANNEL4
#define USART6_RX_S1        MDMA2,MDMA_STREAM1,MDMA_CHANNEL5
#define USART6_RX_S2        MDMA2,MDMA_STREAM2,MDMA_CHANNEL5
#define SPI4_RX_S3          MDMA2,MDMA_STREAM3,MDMA_CHANNEL5
#define SPI4_TX_S4          MDMA2,MDMA_STREAM4,MDMA_CHANNEL5
#define USART6_TX_S6        MDMA2,MDMA_STREAM6,MDMA_CHANNEL5
#define USART6_TX_S7        MDMA2,MDMA_STREAM7,MDMA_CHANNEL5
#define TIM1_TRIG_S0        MDMA2,MDMA_STREAM0,MDMA_CHANNEL6
#define TIM1_CH1_S1         MDMA2,MDMA_STREAM1,MDMA_CHANNEL6
#define TIM1_CH2_S2         MDMA2,MDMA_STREAM2,MDMA_CHANNEL6
#define TIM1_CH1_S3         MDMA2,MDMA_STREAM3,MDMA_CHANNEL6
#define TIM1_CH4_TRIG_COM   MDMA2,MDMA_STREAM4,MDMA_CHANNEL6
#define TIM1_UP             MDMA2,MDMA_STREAM5,MDMA_CHANNEL6
#define TIM1_CH3_S6         MDMA2,MDMA_STREAM6,MDMA_CHANNEL6

/* Burst Beats */
#define MDMA_SINGLE_TRANSFER             0b00
#define MDMA_BURST_4_BEATS               0b01
#define MDMA_BURST_8_BEATS               0b10
#define MDMA_BURST_16_BEATS              0b11

/* Double Buffer Current Target */
#define MDMA_MEMORY_0                    0b0
#define MDMA_MEMORY_1                    0b1

/* Double Buffer Mode Status */
#define DISABLE_DOUBLE_BUFFER            0b0
#define ENABLE_DOUBLE_BUFFER             0b1

/* Priority Level */
#define MDMA_PRIORITY_LOW                0b00
#define MDMA_PRIORITY_MEDIUM             0b01
#define MDMA_PRIORITY_HIGH               0b10
#define MDMA_PRIORITY_VERY_HIGH          0b11

/* Peripheral Increment Offset Status */
#define LINKED_TO_PSIZE                  0b0
#define FIXED_TO_32_BIT                  0b1

/* Peripheral & Memory Data Size */
#define MDMA_BYTE_SIZE                   0b00
#define MDMA_HALF_WORD_SIZE              0b01
#define MDMA_WORD_SIZE                   0b10

/* Peripheral & Memory Increment Mode */
#define ADDRESS_POINTER_FIXED            0b0
#define ADDRESS_POINTER_INCREMENTED      0b1

/* Circular Mode Status */
#define DISABLE_CIRCULAR_MODE            0b0
#define ENABLE_CIRCULAR_MODE             0b1

/* Data Transfer Direction */
#define PERIPHERAL_TO_MEMORY             0b00
#define MEMORY_TO_PERIPHERAL             0b01
#define MEMORY_TO_MEMORY                 0b10

/* Peripheral Flow Controller */
#define DMA_IS_FLOW_CONTROLLER           0b0
#define PERIPHERAL_IS_FLOW_CONTROLLER    0b1

/* Stream Status */
#define MDMA_STREAM_DISABLE              0b0
#define MDMA_STREAM_ENABLE               0b1

/* Interrupt Type */
#define FIFO_ERROR_INTERRUPT             7
#define TRANSFER_COMPLETE_INTERRUPT      4
#define HALF_TRANSFER_INTERRUPT          3
#define TRANSFER_ERROR_INTERRUPT         2
#define DIRECT_MODE_ERROR_INTERRUPT      1

/* Interrupt Status */
#define MDMA_INTERRUPT_DISABLE           0b0
#define MDMA_INTERRUPT_ENABLE            0b1

/* Interrupt Flags */
#define TRANSFER_COMPLETE_FLAG           5
#define HALF_TRANSFER_FLAG               4
#define TRANSFER_ERROR_FLAG              3
#define DIRECT_MODE_ERROR_FLAG           2
#define FIFO_ERROR_FLAG                  0

/* Direct Mode Status */
#define DIRECT_MODE_ENABLE               0b0
#define DIRECT_MODE_DISABLE              0b1

/* FIFO threshold selection */
#define FIFO_FULL_1_OVER_4               0b00
#define FIFO_FULL_1_OVER_2               0b01
#define FIFO_FULL_3_OVER_4               0b10
#define FIFO_FULL_TOTALLY                0b11


void MDMA1_voidInit(void);
void MDMA2_voidInit(void);

void MDMA_voidSelectChannel(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber);
void MDMA_voidSetMemoryBurst(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8BurstBeat);
void MDMA_voidSetPeripheralBurst(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8BurstBeat);
void MDMA_voidSetCurrentTarget(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8CurrentTarget);
void MDMA_voidDoubleBufferStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8DoubleBufferStatus);
void MDMA_voidSetPriorityLevel(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PriorityLevel);
void MDMA_voidPeripheralIncrementOffsetStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralIncrementOffsetStatus);
void MDMA_voidSetMemoryDataSize(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8MemoryDataSize);
void MDMA_voidSetPeripheralDataSize(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralDataSize);
void MDMA_voidSetMemoryIncrementMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8MemoryIncrementMode);
void MDMA_voidSetPeripheralIncrementMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralIncrementMode);
void MDMA_voidCircularModeStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8CircularModeStatus);
void MDMA_voidSetDataTransferDirection(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8TransferDirection);
void MDMA_voidSetPeripheralFlowController(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8PeripheralFlowController);
void MDMA_voidStreamStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8StreamStatus);

u8 MDMA_u8GetFIFOStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber);
void MDMA_voidSetDirectModeStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8DirectModeStatus);
void MDMA_voidSelectFIFOThreshold(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8FIFOThreshold);

void MDMA_voidSetNumberOfData(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u16 Copy_u16NumberOfData);
void MDMA_voidSetPeripheralAddress(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32PeripheralAddress);
void MDMA_voidSetMemory0Address(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32Memory0Address);
void MDMA_voidSetMemory1Address(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u32 Copy_u32Memory1Address);

void MDMA_voidSetInterruptStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptType, u8 Copy_u8InterruptStatus);
u8 MDMA_u8GetInterruptFlagStatus(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptFlag);
void MDMA_voidClearInterruptFlag(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8InterruptFlag);

void MDMA_voidEnableAllInterrupts(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber);
void MDMA_voidDisableAllInterrupts(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber);
void MDMA_voidClearAllInterruptFlags(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber);

void MDMA_voidSetCallBack(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, void (*pvNotificationFunction)(void));

void MDMA_voidDirectModeP2M(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                            u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                            u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController);
void MDMA_voidFIFOModeP2M(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                          u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                          u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                          u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController, u8 Copy_u8FIFOThreshold);
void MDMA_voidDirectModeM2P(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                            u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                            u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController);
void MDMA_voidFIFOModeM2P(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                          u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                          u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                          u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8PeripheralFlowController, u8 Copy_u8FIFOThreshold);
void MDMA_voidM2M(u8 Copy_u8StreamNumber, u16 Copy_u16NumberOfData, u32 Copy_u32PeripheralAddress,
                  u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize, u8 Copy_u8MemoryDataSize,
                  u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                  u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8FIFOThreshold);
void MDMA_voidCircularDirectMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                 u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, 
                                 u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection);
void MDMA_voidCircularFIFOMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                               u32 Copy_u32PeripheralAddress, u32 Copy_u32MemoryAddress, u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize,
                               u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus,
                               u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection, u8 Copy_u8FIFOThreshold);
void MDMA_voidDoubleBufferDirectMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                     u32 Copy_u32PeripheralAddress, u32 Copy_u32Memory0Address, u32 Copy_u32Memory1Address, u8 Copy_u8CurrentTarget,
                                     u8 Copy_u8PriorityLevel, u8 Copy_u8DataSize, u8 Copy_u8PeripheralIncrementMode, u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection);
void MDMA_voidDoubleBufferFIFOMode(u8 Copy_u8DMANumber, u8 Copy_u8StreamNumber, u8 Copy_u8ChannelNumber, u16 Copy_u16NumberOfData,
                                   u32 Copy_u32PeripheralAddress, u32 Copy_u32Memory0Address, u32 Copy_u32Memory1Address, u8 Copy_u8CurrentTarget,
                                   u8 Copy_u8PriorityLevel, u8 Copy_u8PeripheralDataSize, u8 Copy_u8MemoryDataSize, u8 Copy_u8PeripheralBurstBeat, 
                                   u8 Copy_u8MemoryBurstBeat, u8 Copy_u8PeripheralIncrementOffsetStatus, u8 Copy_u8PeripheralIncrementMode, 
                                   u8 Copy_u8MemoryIncrementMode, u8 Copy_u8TransferDirection, u8 Copy_u8FIFOThreshold);


#endif