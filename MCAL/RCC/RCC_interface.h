/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        1 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         1 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_RCC_RCC_INTERFACE_H
#define MCAL_RCC_RCC_INTERFACE_H


#define ENABLE      1
#define DISABLE     0

/* Interrupt Flags */
#define LOW_POWER_RESET                 0
#define WINDOW_WATCHDOG_RESET           1
#define INDEPENDENT_WATCHDOG_RESET      2
#define SOFTWARE_RESET                  3
#define POR_PDR_RESET                   4
#define PIN_RESET                       5
#define BOR_RESET                       6

/* Interrupt Flags */
#define HSI         0
#define HSE         1
#define PLL         2
#define LSI         3
#define LSE         4
#define PLLI2S      5
#define CSS         6

/* Clock Source */

#define AHB             0
#define APB1            1
#define APB2            2


/**************** RCC PeripheralBus *****************/

#define RCC_AHB1        0
#define RCC_AHB2        1
#define RCC_APB1        2
#define RCC_APB2        3


/***************** RCC PeripheralID Clock Enable ******************/

/* RCC_AHB1 BUS, AHB1ENR REGISTER */
#define RCC_GPIOA       0
#define RCC_GPIOB       1
#define RCC_GPIOC       2
#define RCC_GPIOD       3
#define RCC_GPIOE       4
#define RCC_GPIOH       7
#define RCC_CRC         12
#define RCC_DMA1        21
#define RCC_DMA2        22

/* RCC_AHB2 BUS, AHB2ENR REGISTER */
#define RCC_OTGFS       7

/* RCC_APB1 BUS, APB1ENR REGISTER */
#define RCC_TIM2        0
#define RCC_TIM3        1
#define RCC_TIM4        2
#define RCC_TIM5        3
#define RCC_WWDG        11
#define RCC_SPI2        14
#define RCC_SPI3        15
#define RCC_USART2      17
#define RCC_I2C1        21
#define RCC_I2C2        22
#define RCC_I2C3        23
#define RCC_PWR         28

/* RCC_APB2 BUS, APB2ENR REGISTER */
#define RCC_TIM1        0
#define RCC_USART1      4
#define RCC_USART6      5
#define RCC_ADC1        8
#define RCC_SDIO        11
#define RCC_SPI1        12
#define RCC_SPI4        13
#define RCC_SYSCFG      14
#define RCC_TIM9        16
#define RCC_TIM10       17
#define RCC_TIM11       18

/************* RCC PeripheralID Enable Low Power (Sleep mode) **************/

/* RCC_AHB1 LPENR */
#define RCC_GPIOA_LPEN  0
#define RCC_GPIOB_LPEN  1
#define RCC_GPIOC_LPEN  2
#define RCC_GPIOD_LPEN  3
#define RCC_GPIOE_LPEN  4
#define RCC_GPIOH_LPEN  7
#define RCC_CRC_LPEN    12
#define RCC_FLITF_LPEN  15
#define RCC_SRAM1_LPEN  16
#define RCC_DMA1_LPEN   21
#define RCC_DMA2_LPEN   22

/* RCC_AHB2 LPENR */
#define RCC_OTGFS_LPEN  7

/* RCC_APB1 LPENR */
#define RCC_TIM2_LPEN   0
#define RCC_TIM3_LPEN   1
#define RCC_TIM4_LPEN   2
#define RCC_TIM5_LPEN   3
#define RCC_WWDG_LPEN   11
#define RCC_SPI2_LPEN   14
#define RCC_SPI3_LPEN   15
#define RCC_USART2_LPEN 17
#define RCC_I2C1_LPEN   21
#define RCC_I2C2_LPEN   22
#define RCC_I2C3_LPEN   23
#define RCC_PWR_LPEN    28

/* RCC_APB2 LPENR */
#define RCC_TIM1_LPEN   0
#define RCC_USART1_LPEN 4
#define RCC_USART6_LPEN 5
#define RCC_ADC1_LPEN   8
#define RCC_SDIO_LPEN   11
#define RCC_SPI1_LPEN   12
#define RCC_SPI4_LPEN   13
#define RCC_SYSCFG_LPEN 14
#define RCC_TIM9_LPEN   16
#define RCC_TIM10_LPEN  17
#define RCC_TIM11_LPEN  18

/***************** RCC PeripheralID Reset ******************/

/* RCC_AHB1 RSTR */
#define RCC_GPIOA_RST   0
#define RCC_GPIOB_RST   1
#define RCC_GPIOC_RST   2
#define RCC_GPIOD_RST   3
#define RCC_GPIOE_RST   4
#define RCC_GPIOH_RST   7
#define RCC_CRC_RST     12
#define RCC_DMA1_RST    21
#define RCC_DMA2_RST    22

/* RCC_AHB2 RSTR */
#define RCC_OTGFS_RST   7

/* RCC_APB1 RSTR */
#define RCC_TIM2_RST    0
#define RCC_TIM3_RST    1
#define RCC_TIM4_RST    2
#define RCC_TIM5_RST    3
#define RCC_WWDG_RST    11
#define RCC_SPI2_RST    14
#define RCC_SPI3_RST    15
#define RCC_USART2_RST  17
#define RCC_I2C1_RST    21
#define RCC_I2C2_RST    22
#define RCC_I2C3_RST    23
#define RCC_PWR_RST     28

/* RCC_APB2 RSTR */
#define RCC_TIM1_RST    0
#define RCC_USART1_RST  4
#define RCC_USART6_RST  5
#define RCC_ADC1_RST    8
#define RCC_SDIO_RST    11
#define RCC_SPI1_RST    12
#define RCC_SPI4_RST    13
#define RCC_SYSCFG_RST  14
#define RCC_TIM9_RST    16
#define RCC_TIM10_RST   17
#define RCC_TIM11_RST   18


void MRCC_voidInit(void);

u8 MRCC_u8GetHSIHardwareCalebration(void);

void MRCC_voidEnableHSEByPass(void);

void MRCC_voidClockSecuritySystem(u8 Copy_u8Status);

void MRCC_voidI2SClock(void);

void MRCC_voidRTCClock(void);

void MRCC_voidEnableLSEByPass(void);

void MRCC_voidSetLowSpeedClockSource(void);

void MRCC_voidSetMCO1Source(void);

u8 MRCC_u8GetMCO1Prescaler(void);

void MRCC_voidSetMCO2Source(void);

u8 MRCC_u8GetMCO2Prescaler(void);

u8 MRCC_u8GetFlagStatus(u8 Copy_u8Flag);

u8 MRCC_u8CheckClockSecutitySystem(void);

void MRCC_u8ClearFlag(u8 Copy_u8Flag);

void MRCC_voidResetPeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

void MRCC_voidEnablePeripheralClockDuringSleepMode(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

void MRCC_voidDisablePeripheralClockDuringSleepMode(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID);

void MRCC_voidBackupDomainReset(void);

u8 MRCC_u8GetResetFlagStatus(u8 Copy_u8ResetFlag);

void MRCC_voidClearResetFlags(void);

void MRCC_voidSpreadSpectrumClockGeneration(void);

void MRCC_voidTimersclocksprescalers(void);

void MRCC_u8ClockSourceInterrupt(u8 Copy_u8ClockSource, u8 Copy_u8InterruptStatus);
void MRCC_voidSetCallBack(void (*pvNotificationFunction)(void));


#endif