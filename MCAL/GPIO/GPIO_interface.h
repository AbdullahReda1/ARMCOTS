/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         7 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_GPIO_GPIO_INTERFACE_H
#define MCAL_GPIO_GPIO_INTERFACE_H


#define MGPIO_PORTA         0
#define MGPIO_PORTB         1
#define MGPIO_PORTC         2

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

#define HIGH        1
#define LOW         0

#define ALL_HIGH    0xFFFF
#define ALL_LOW     0x0000

#define HALF_HIGH   0xFF
#define HALF_LOW    0x00

#define NIPPLE_HIGH 0xF
#define NIPPLE_LOW  0x0

/* GPIO Half Port Selection */
#define HIGH_HALF_PORT        1
#define LOW_HALF_PORT         0

/* GPIO Nipple Port Selection */
#define F1ST_NIPPLE_PORT      0
#define S2ND_NIPPLE_PORT      1
#define T3RD_NIPPLE_PORT      2
#define F4TH_NIPPLE_PORT      3

/* GPIO pin Output Modes */
#define INPUT_MODE                  0b00
#define OUTPUT_MODE                 0b01
#define ALTERNATE_FUNCTION_MODE     0b10
#define ANALOG_MODE                 0b11

/* GPIO port Output Modes */
#define ALL_INPUT_MODE              0x00000000
#define ALL_OUTPUT_MODE             0x55555555

/* GPIO pin Output Types */
#define PUSH_PULL                   0b0
#define OPEN_DRAIN                  0b1

/* GPIO port Output Types */
#define ALL_PUSH_PULL               0x0000
#define ALL_OPEN_DRAIN              0xFFFF

/* GPIO pin Output Speeds */
#define LOW_SPEED_2MHZ              0b00
#define MEDIUM_SPEED_10MHZ          0b01
#define HIGH_SPEED_50MHZ            0b10
#define VERY_HIGH_SPEED_200MHZ      0b11

/* GPIO port Output Speeds */
#define ALL_LOW_SPEED_2MHZ          0x00000000
#define ALL_MEDIUM_SPEED_10MHZ      0x55555555
#define ALL_HIGH_SPEED_50MHZ        0xAAAAAAAA
#define ALL_VERY_HIGH_SPEED_200MHZ  0xFFFFFFFF

/* GPIO Pin Pull up OR Pull down OR not */
#define FLOATING_NO_PP              0b00
#define PULL_UP                     0b01
#define PULL_DOWN                   0b10

/* GPIO Port Pull up OR Pull down OR not */
#define ALL_FLOATING_NO_PP          0x00000000
#define ALL_PULL_UP                 0x55555555
#define ALL_PULL_DOWN               0xAAAAAAAA

/* Alternative Numbers */
#define AF0_SYSTEM                  0b0000
#define AF1_TIM1_2                  0b0001
#define AF2_TIM3_5                  0b0010
#define AF3_TIM9_11                 0b0011
#define AF4_I2C1_3                  0b0100
#define AF5_SPI1_4                  0b0101
#define AF6_SPI3                    0b0110
#define AF7_USART1_2                0b0111
#define AF8_USART6                  0b1000
#define AF9_I2C2_3                  0b1001
#define AF10_OTG_FS                 0b1010
#define AF12_SDIO                   0b1100
#define AF15_EVENTOUT               0b1111

/* Lock Key Status */
#define ENABLE_LOCK_KEY             1
#define DISABLE_LOCK_KEY            0


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8Mode);
void MGPIO_voidSetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8OutputType);
void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8PinValue);
void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8AlternativeNumber);

void MGPIO_voidTogPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber);

void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32PortMode);
void MGPIO_voidSetPortOutputType(u8 Copy_u8PortName, u16 Copy_u16PortType);
void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32PortSpeed);
void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u16 Copy_u16PinValue);

void MGPIO_voidTogPortValue(u8 Copy_u8PortName);

void MGPIO_voidSetHalfPortMode(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8Mode);
void MGPIO_voidSetHalfPortOutputType(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8OutputType);
void MGPIO_voidSetHalfPortOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetHalfPortValue(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition,u8 Copy_u8HalfPortValue);

void MGPIO_voidSetNipplePortMode(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8Mode);
void MGPIO_voidSetNipplePortOutputType(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8OutputType);
void MGPIO_voidSetNipplePortOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetNipplePortValue(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition,u8 Copy_u8NipplePortValue);

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber);
u16 MGPIO_u16GetPortValue(u8 Copy_u8PortName);

void MGPIO_voidPullUpPullDownPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8PullUpDown);
void MGPIO_voidPullUpPullDownPort(u8 Copy_u8PortName, u32 Copy_u32PullUpDown);
void MGPIO_voidPullUpPullDownHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8PullUpDown);
void MGPIO_voidPullUpPullDownNipplePort(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8PullUpDown);

void MGPIO_voidAtomicSetPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber);
void MGPIO_voidAtomicResetPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber);

void MGPIO_voidAtomicSetPort(u8 Copy_u8PortName);
void MGPIO_voidAtomicResetPort(u8 Copy_u8PortName);

void MGPIO_voidAtomicSetSpecificPins(u8 Copy_u8PortName, u16 Copy_u16PortValue);
void MGPIO_voidAtomicResetSpecificPins(u8 Copy_u8PortName, u16 Copy_u16PortValue);

void MGPIO_voidAtomicSetHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition);
void MGPIO_voidAtomicResetHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition);

void MGPIO_voidSetLockKey(u8 Copy_u8PortName, u8 Copy_u8LockStatus);
void MGPIO_voidLockPinConfiguration(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
void MGPIO_voidUnlockPinConfiguration(u8 Copy_u8PortName, u8 Copy_u8PinNumber);

void MGPIO_voidSPI1MasterConfiguration(void);
void MGPIO_voidSPI1SlaveConfiguration(void);


#endif