/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        30 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         30 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_SPI_SPI_CONFIG_H
#define MCAL_SPI_SPI_CONFIG_H


/*
    OPTIONS:
    SPI_ENABLE
    SPI_DISABLE
*/
#define     SPI_ENABLE_PERIPHERAL         SPI_ENABLE

/*
    OPTIONS:
    SPI_FPCLK_DIVIDED_BY_2
    SPI_FPCLK_DIVIDED_BY_4
    SPI_FPCLK_DIVIDED_BY_8
    SPI_FPCLK_DIVIDED_BY_16
    SPI_FPCLK_DIVIDED_BY_32
    SPI_FPCLK_DIVIDED_BY_64
    SPI_FPCLK_DIVIDED_BY_128
    SPI_FPCLK_DIVIDED_BY_256
*/
#define     SPI_BAUD_RATE                 SPI_FPCLK_DIVIDED_BY_4

/*
    OPTIONS:
    FIRST_CLOCK_TRANSITION
    SECOND_CLOCK_TRANSITION
*/
#define     SPI_CLOCK_POLARITY            FIRST_CLOCK_TRANSITION

/*
    OPTIONS:
    CLK_TO_0_AT_IDLE
    CLK_TO_1_AT_IDLE
*/
#define     SPI_CLOCK_PHASE               CLK_TO_0_AT_IDLE

/*
    OPTIONS:
    SLAVE_CONFIGURATION
    MASTER_CONFIGURATION
*/
#define     SPI_MASTER_SELECTION          MASTER_CONFIGURATION

/*
    OPTIONS:
    MSB_FIRST
    LSB_FIRST
*/
#define     SPI_FRAME_FORMAT              MSB_FIRST

/*
    OPTIONS:
    SW_SLAVE_DISABLE
    SW_SLAVE_ENABLE
*/
#define     SPI_SOFTWARE_SLAVE            SW_SLAVE_DISABLE

/*
    OPTIONS:
    FRAME_8_BIT
    FRAME_16_BIT
*/
#define     SPI_DATA_FRAME_FORMAT         FRAME_8_BIT

/*
    OPTIONS:
    MOTOROLA_MODE
    TI_MODE
*/
#define     SPI_FRAME_FORMAT              MOTOROLA_MODE

/*
    OPTIONS:
    TXE_DISABLE
    TXE_ENABLE
*/
#define     SPI_TRANSMITTER_INTERRUPT     TXE_ENABLE

/*
    OPTIONS:
    RXE_DISABLE
    RXE_ENABLE
*/
#define     SPI_RECEIVER_INTERRUPT        RXE_DISABLE

/*
    OPTIONS:
    ERROR_DISABLE
    ERROR_ENABLE
*/
#define     SPI_ERROR_INTERRUPT           ERROR_ENABLE


#endif