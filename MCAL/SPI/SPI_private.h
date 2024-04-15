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


#ifndef MCAL_SPI_SPI_PRIVATE_H
#define MCAL_SPI_SPI_PRIVATE_H


#define SPI_ENABLE                  1
#define SPI_DISABLE                 0

#define MOTOROLA_MODE               0
#define TI_MODE                     1

#define SPI_FPCLK_DIVIDED_BY_2      0b000
#define SPI_FPCLK_DIVIDED_BY_4      0b001
#define SPI_FPCLK_DIVIDED_BY_8      0b010
#define SPI_FPCLK_DIVIDED_BY_16     0b011
#define SPI_FPCLK_DIVIDED_BY_32     0b100
#define SPI_FPCLK_DIVIDED_BY_64     0b101
#define SPI_FPCLK_DIVIDED_BY_128    0b110
#define SPI_FPCLK_DIVIDED_BY_256    0b111
#define SPI_FPCLK_MASK              0xFFC7

#define CLK_TO_0_AT_IDLE            0
#define CLK_TO_1_AT_IDLE            1

#define FIRST_CLOCK_TRANSITION      0
#define SECOND_CLOCK_TRANSITION     1

#define SLAVE_CONFIGURATION         0
#define MASTER_CONFIGURATION        1

#define MSB_FIRST                   0
#define LSB_FIRST                   1

#define SW_SLAVE_DISABLE            0
#define SW_SLAVE_ENABLE             1

#define FRAME_8_BIT                 0
#define FRAME_16_BIT                1

#define TXE_DISABLE                 0
#define TXE_ENABLE                  1

#define RXE_DISABLE                 0
#define RXE_ENABLE                  1

#define ERROR_DISABLE               0
#define ERROR_ENABLE                1


/**************************** Register Description ******************************/


typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 RESERVED0;
    volatile u32 RESERVED1;
}SPI_t;

#define SPI1_BASE_ADDRESS       0x40013000
#define SPI2_BASE_ADDRESS       0x40003800
#define SPI3_BASE_ADDRESS       0x40003C00
#define SPI4_BASE_ADDRESS       0x40013400

#define SPI1    ((volatile SPI_t *)SPI1_BASE_ADDRESS)
#define SPI2    ((volatile SPI_t *)SPI2_BASE_ADDRESS)
#define SPI3    ((volatile SPI_t *)SPI3_BASE_ADDRESS)
#define SPI4    ((volatile SPI_t *)SPI4_BASE_ADDRESS)


#define CR1_CPHA        0
#define CR1_CPOL        1
#define CR1_MSTR        2
#define CR1_BR          3
#define CR1_SPE         6
#define CR1_LSBFIRST    7
#define CR1_SSI         8
#define CR1_SSM         9
#define CR1_RXONLY      10
#define CR1_DFF         11
#define CR1_CRCNEXT     12
#define CR1_CRCEN       13
#define CR1_BIDIOE      14
#define CR1_BIDIMODE    15

#define CR2_RXDMAEN     0
#define CR2_TXDMAEN     1
#define CR2_SSOE        2
#define CR2_FRF         4
#define CR2_ERRIE       5
#define CR2_RXNEIE      6
#define CR2_TXEIE       7

#define SR_RXNE         0
#define SR_TXE          1
#define SR_CHSIDE       2
#define SR_UDR          3
#define SR_CRCERR       4
#define SR_MODF         5
#define SR_OVR          6
#define SR_BSY          7
#define SR_FRE          8

#define DR_DR           0

#define CRCPR_CRCPOLY   0

#define RXCRCR_RXCRC    0

#define TXCRCR_TXCRC    0


#endif