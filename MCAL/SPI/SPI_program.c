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


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


static void (*MSPI1_CallBack)(void) = NULL;
static void (*MSPI2_CallBack)(void) = NULL;
static void (*MSPI3_CallBack)(void) = NULL;
static void (*MSPI4_CallBack)(void) = NULL;


void MSPI_voidInit(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            #if     SPI_ENABLE_PERIPHERAL == SPI_ENABLE

                #if     SPI_FRAME_FORMAT == MOTOROLA_MODE

                    CLR_BIT((SPI1 -> CR2), CR2_FRF);
                    #if     SPI_CLOCK_POLARITY == FIRST_CLOCK_TRANSITION
                        CLR_BIT((SPI1 -> CR1), CR1_CPHA);
                    #elif   SPI_CLOCK_POLARITY == SECOND_CLOCK_TRANSITION
                        SET_BIT((SPI1 -> CR1), CR1_CPHA);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_CLOCK_PHASE == CLK_TO_0_AT_IDLE
                        CLR_BIT((SPI1 -> CR1), CR1_CPOL);
                    #elif   SPI_CLOCK_PHASE == CLK_TO_1_AT_IDLE
                        SET_BIT((SPI1 -> CR1), CR1_CPOL);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_FRAME_FORMAT == MSB_FIRST
                        CLR_BIT((SPI1 -> CR1), CR1_LSBFIRST);
                    #elif   SPI_FRAME_FORMAT == LSB_FIRST
                        SET_BIT((SPI1 -> CR1), CR1_LSBFIRST);
                    #else
                        #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                    #endif

                    #if     SPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
                        CLR_BIT((SPI1 -> CR1), CR1_SSM);
                    #elif   SPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
                        SET_BIT((SPI1 -> CR1), CR1_SSM);
                    #else
                        #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                    #endif

                #elif   SPI_FRAME_FORMAT == TI_MODE

                    SET_BIT((SPI1 -> CR2), CR2_FRF);
                    CLR_BIT((SPI1 -> CR1), CR1_SSI);
                    CLR_BIT((SPI1 -> CR2), CR2_SSOE);

                #else
                    #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                #endif

                #if     SPI_MASTER_SELECTION == SLAVE_CONFIGURATION
                    CLR_BIT((SPI1 -> CR1), CR1_MSTR);
                #elif   SPI_MASTER_SELECTION == MASTER_CONFIGURATION
                    SET_BIT((SPI1 -> CR1), CR1_MSTR);
                #else
                    #error "SPI SPI_MASTER_SELECTION, Configuration Error"
                #endif

                #if     SPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
                    CLR_BIT((SPI1 -> CR2), CR2_TXEIE);
                #elif   SPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
                    SET_BIT((SPI1 -> CR2), CR2_TXEIE);
                #else
                    #error "SPI SPI_TRANSMITTER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_RECEIVER_INTERRUPT == RXE_DISABLE
                    CLR_BIT((SPI1 -> CR2), CR2_RXNEIE);
                #elif   SPI_RECEIVER_INTERRUPT == RXE_ENABLE
                    SET_BIT((SPI1 -> CR2), CR2_RXNEIE);
                #else
                    #error "SPI SPI_RECEIVER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_ERROR_INTERRUPT == ERROR_DISABLE
                    CLR_BIT((SPI1 -> CR2), CR2_ERRIE);
                #elif   SPI_ERROR_INTERRUPT == ERROR_ENABLE
                    SET_BIT((SPI1 -> CR2), CR2_ERRIE);
                #else
                    #error "SPI SPI_ERROR_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_DATA_FRAME_FORMAT == FRAME_8_BIT
                    CLR_BIT((SPI1 -> CR1), CR1_DFF);
                #elif   SPI_DATA_FRAME_FORMAT == FRAME_16_BIT
                    SET_BIT((SPI1 -> CR1), CR1_DFF);
                #else
                    #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                #endif

                (SPI1 -> CR1) &= (SPI_FPCLK_MASK);
                (SPI1 -> CR1) |= (SPI_BAUD_RATE << CR1_BR);

                SET_BIT((SPI1 -> CR1), CR1_SPE);

            #elif   SPI_ENABLE_PERIPHERAL == SPI_DISABLE

                CLR_BIT((SPI1 -> CR1), CR1_SPE);

            #else
                #error "SPI SPI_ENABLE_PERIPHERAL, Configuration Error"
            #endif
        break;
        case MSPI2:
            #if     SPI_ENABLE_PERIPHERAL == SPI_ENABLE

                #if     SPI_FRAME_FORMAT == MOTOROLA_MODE

                    CLR_BIT((SPI2 -> CR2), CR2_FRF);
                    #if     SPI_CLOCK_POLARITY == FIRST_CLOCK_TRANSITION
                        CLR_BIT((SPI2 -> CR1), CR1_CPHA);
                    #elif   SPI_CLOCK_POLARITY == SECOND_CLOCK_TRANSITION
                        SET_BIT((SPI2 -> CR1), CR1_CPHA);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_CLOCK_PHASE == CLK_TO_0_AT_IDLE
                        CLR_BIT((SPI2 -> CR1), CR1_CPOL);
                    #elif   SPI_CLOCK_PHASE == CLK_TO_1_AT_IDLE
                        SET_BIT((SPI2 -> CR1), CR1_CPOL);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_FRAME_FORMAT == MSB_FIRST
                        CLR_BIT((SPI2 -> CR1), CR1_LSBFIRST);
                    #elif   SPI_FRAME_FORMAT == LSB_FIRST
                        SET_BIT((SPI2 -> CR1), CR1_LSBFIRST);
                    #else
                        #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                    #endif

                    #if     SPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
                        CLR_BIT((SPI2 -> CR1), CR1_SSM);
                    #elif   SPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
                        SET_BIT((SPI2 -> CR1), CR1_SSM);
                    #else
                        #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                    #endif

                #elif   SPI_FRAME_FORMAT == TI_MODE

                    SET_BIT((SPI2 -> CR2), CR2_FRF);
                    CLR_BIT((SPI2 -> CR1), CR1_SSI);
                    CLR_BIT((SPI2 -> CR2), CR2_SSOE);

                #else
                    #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                #endif

                #if     SPI_MASTER_SELECTION == SLAVE_CONFIGURATION
                    CLR_BIT((SPI2 -> CR1), CR1_MSTR);
                #elif   SPI_MASTER_SELECTION == MASTER_CONFIGURATION
                    SET_BIT((SPI2 -> CR1), CR1_MSTR);
                #else
                    #error "SPI SPI_MASTER_SELECTION, Configuration Error"
                #endif

                #if     SPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
                    CLR_BIT((SPI2 -> CR2), CR2_TXEIE);
                #elif   SPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
                    SET_BIT((SPI2 -> CR2), CR2_TXEIE);
                #else
                    #error "SPI SPI_TRANSMITTER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_RECEIVER_INTERRUPT == RXE_DISABLE
                    CLR_BIT((SPI2 -> CR2), CR2_RXNEIE);
                #elif   SPI_RECEIVER_INTERRUPT == RXE_ENABLE
                    SET_BIT((SPI2 -> CR2), CR2_RXNEIE);
                #else
                    #error "SPI SPI_RECEIVER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_ERROR_INTERRUPT == ERROR_DISABLE
                    CLR_BIT((SPI2 -> CR2), CR2_ERRIE);
                #elif   SPI_ERROR_INTERRUPT == ERROR_ENABLE
                    SET_BIT((SPI2 -> CR2), CR2_ERRIE);
                #else
                    #error "SPI SPI_ERROR_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_DATA_FRAME_FORMAT == FRAME_8_BIT
                    CLR_BIT((SPI2 -> CR1), CR1_DFF);
                #elif   SPI_DATA_FRAME_FORMAT == FRAME_16_BIT
                    SET_BIT((SPI2 -> CR1), CR1_DFF);
                #else
                    #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                #endif

                (SPI2 -> CR1) &= (SPI_FPCLK_MASK);
                (SPI2 -> CR1) |= (SPI_BAUD_RATE << CR1_BR);

                SET_BIT((SPI2 -> CR1), CR1_SPE);

            #elif   SPI_ENABLE_PERIPHERAL == SPI_DISABLE

                CLR_BIT((SPI2 -> CR1), CR1_SPE);

            #else
                #error "SPI SPI_ENABLE_PERIPHERAL, Configuration Error"
            #endif
        break;
        case MSPI3:
            #if     SPI_ENABLE_PERIPHERAL == SPI_ENABLE

                #if     SPI_FRAME_FORMAT == MOTOROLA_MODE

                    CLR_BIT((SPI3 -> CR2), CR2_FRF);
                    #if     SPI_CLOCK_POLARITY == FIRST_CLOCK_TRANSITION
                        CLR_BIT((SPI3 -> CR1), CR1_CPHA);
                    #elif   SPI_CLOCK_POLARITY == SECOND_CLOCK_TRANSITION
                        SET_BIT((SPI3 -> CR1), CR1_CPHA);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_CLOCK_PHASE == CLK_TO_0_AT_IDLE
                        CLR_BIT((SPI3 -> CR1), CR1_CPOL);
                    #elif   SPI_CLOCK_PHASE == CLK_TO_1_AT_IDLE
                        SET_BIT((SPI3 -> CR1), CR1_CPOL);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_FRAME_FORMAT == MSB_FIRST
                        CLR_BIT((SPI3 -> CR1), CR1_LSBFIRST);
                    #elif   SPI_FRAME_FORMAT == LSB_FIRST
                        SET_BIT((SPI3 -> CR1), CR1_LSBFIRST);
                    #else
                        #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                    #endif

                    #if     SPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
                        CLR_BIT((SPI3 -> CR1), CR1_SSM);
                    #elif   SPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
                        SET_BIT((SPI3 -> CR1), CR1_SSM);
                    #else
                        #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                    #endif

                #elif   SPI_FRAME_FORMAT == TI_MODE

                    SET_BIT((SPI3 -> CR2), CR2_FRF);
                    CLR_BIT((SPI3 -> CR1), CR1_SSI);
                    CLR_BIT((SPI3 -> CR2), CR2_SSOE);

                #else
                    #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                #endif

                #if     SPI_MASTER_SELECTION == SLAVE_CONFIGURATION
                    CLR_BIT((SPI3 -> CR1), CR1_MSTR);
                #elif   SPI_MASTER_SELECTION == MASTER_CONFIGURATION
                    SET_BIT((SPI3 -> CR1), CR1_MSTR);
                #else
                    #error "SPI SPI_MASTER_SELECTION, Configuration Error"
                #endif

                #if     SPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
                    CLR_BIT((SPI3 -> CR2), CR2_TXEIE);
                #elif   SPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
                    SET_BIT((SPI3 -> CR2), CR2_TXEIE);
                #else
                    #error "SPI SPI_TRANSMITTER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_RECEIVER_INTERRUPT == RXE_DISABLE
                    CLR_BIT((SPI3 -> CR2), CR2_RXNEIE);
                #elif   SPI_RECEIVER_INTERRUPT == RXE_ENABLE
                    SET_BIT((SPI3 -> CR2), CR2_RXNEIE);
                #else
                    #error "SPI SPI_RECEIVER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_ERROR_INTERRUPT == ERROR_DISABLE
                    CLR_BIT((SPI3 -> CR2), CR2_ERRIE);
                #elif   SPI_ERROR_INTERRUPT == ERROR_ENABLE
                    SET_BIT((SPI3 -> CR2), CR2_ERRIE);
                #else
                    #error "SPI SPI_ERROR_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_DATA_FRAME_FORMAT == FRAME_8_BIT
                    CLR_BIT((SPI3 -> CR1), CR1_DFF);
                #elif   SPI_DATA_FRAME_FORMAT == FRAME_16_BIT
                    SET_BIT((SPI3 -> CR1), CR1_DFF);
                #else
                    #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                #endif

                (SPI3 -> CR1) &= (SPI_FPCLK_MASK);
                (SPI3 -> CR1) |= (SPI_BAUD_RATE << CR1_BR);

                SET_BIT((SPI3 -> CR1), CR1_SPE);

            #elif   SPI_ENABLE_PERIPHERAL == SPI_DISABLE

                CLR_BIT((SPI3 -> CR1), CR1_SPE);

            #else
                #error "SPI SPI_ENABLE_PERIPHERAL, Configuration Error"
            #endif
        break;
        case MSPI4:
            #if     SPI_ENABLE_PERIPHERAL == SPI_ENABLE

                #if     SPI_FRAME_FORMAT == MOTOROLA_MODE

                    CLR_BIT((SPI4 -> CR2), CR2_FRF);
                    #if     SPI_CLOCK_POLARITY == FIRST_CLOCK_TRANSITION
                        CLR_BIT((SPI4 -> CR1), CR1_CPHA);
                    #elif   SPI_CLOCK_POLARITY == SECOND_CLOCK_TRANSITION
                        SET_BIT((SPI4 -> CR1), CR1_CPHA);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_CLOCK_PHASE == CLK_TO_0_AT_IDLE
                        CLR_BIT((SPI4 -> CR1), CR1_CPOL);
                    #elif   SPI_CLOCK_PHASE == CLK_TO_1_AT_IDLE
                        SET_BIT((SPI4 -> CR1), CR1_CPOL);
                    #else
                        #error "SPI SPI_CLOCK_POLARITY, Configuration Error"
                    #endif

                    #if     SPI_FRAME_FORMAT == MSB_FIRST
                        CLR_BIT((SPI4 -> CR1), CR1_LSBFIRST);
                    #elif   SPI_FRAME_FORMAT == LSB_FIRST
                        SET_BIT((SPI4 -> CR1), CR1_LSBFIRST);
                    #else
                        #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                    #endif

                    #if     SPI_SOFTWARE_SLAVE == SW_SLAVE_DISABLE
                        CLR_BIT((SPI4 -> CR1), CR1_SSM);
                    #elif   SPI_SOFTWARE_SLAVE == SW_SLAVE_ENABLE
                        SET_BIT((SPI4 -> CR1), CR1_SSM);
                    #else
                        #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                    #endif

                #elif   SPI_FRAME_FORMAT == TI_MODE

                    SET_BIT((SPI4 -> CR2), CR2_FRF);
                    CLR_BIT((SPI4 -> CR1), CR1_SSI);
                    CLR_BIT((SPI4 -> CR2), CR2_SSOE);

                #else
                    #error "SPI SPI_FRAME_FORMAT, Configuration Error"
                #endif

                #if     SPI_MASTER_SELECTION == SLAVE_CONFIGURATION
                    CLR_BIT((SPI4 -> CR1), CR1_MSTR);
                #elif   SPI_MASTER_SELECTION == MASTER_CONFIGURATION
                    SET_BIT((SPI4 -> CR1), CR1_MSTR);
                #else
                    #error "SPI SPI_MASTER_SELECTION, Configuration Error"
                #endif

                #if     SPI_TRANSMITTER_INTERRUPT == TXE_DISABLE
                    CLR_BIT((SPI4 -> CR2), CR2_TXEIE);
                #elif   SPI_TRANSMITTER_INTERRUPT == TXE_ENABLE
                    SET_BIT((SPI4 -> CR2), CR2_TXEIE);
                #else
                    #error "SPI SPI_TRANSMITTER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_RECEIVER_INTERRUPT == RXE_DISABLE
                    CLR_BIT((SPI4 -> CR2), CR2_RXNEIE);
                #elif   SPI_RECEIVER_INTERRUPT == RXE_ENABLE
                    SET_BIT((SPI4 -> CR2), CR2_RXNEIE);
                #else
                    #error "SPI SPI_RECEIVER_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_ERROR_INTERRUPT == ERROR_DISABLE
                    CLR_BIT((SPI4 -> CR2), CR2_ERRIE);
                #elif   SPI_ERROR_INTERRUPT == ERROR_ENABLE
                    SET_BIT((SPI4 -> CR2), CR2_ERRIE);
                #else
                    #error "SPI SPI_ERROR_INTERRUPT, Configuration Error"
                #endif

                #if     SPI_DATA_FRAME_FORMAT == FRAME_8_BIT
                    CLR_BIT((SPI4 -> CR1), CR1_DFF);
                #elif   SPI_DATA_FRAME_FORMAT == FRAME_16_BIT
                    SET_BIT((SPI4 -> CR1), CR1_DFF);
                #else
                    #error "SPI SPI_SOFTWARE_SLAVE, Configuration Error"
                #endif

                (SPI4 -> CR1) &= (SPI_FPCLK_MASK);
                (SPI4 -> CR1) |= (SPI_BAUD_RATE << CR1_BR);

                SET_BIT((SPI4 -> CR1), CR1_SPE);

            #elif   SPI_ENABLE_PERIPHERAL == SPI_DISABLE

                CLR_BIT((SPI4 -> CR1), CR1_SPE);

            #else
                #error "SPI SPI_ENABLE_PERIPHERAL, Configuration Error"
            #endif
        break;
        default:
        break;
    }
}

void MSPI_voidAllowMultimasterMode(u8 Copy_u8SPINumber)
{
    /* Only with Hardware NSS management (SSM = 0) */
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SSM);
            CLR_BIT((SPI1 -> CR2), CR2_SSOE);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SSM);
            CLR_BIT((SPI2 -> CR2), CR2_SSOE);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SSM);
            CLR_BIT((SPI3 -> CR2), CR2_SSOE);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SSM);
            CLR_BIT((SPI4 -> CR2), CR2_SSOE);
        break;
        default:
        break;
    }
}

void MSPI_voidAllowSingleMasterMode(u8 Copy_u8SPINumber)
{
    /* Only with Hardware NSS management (SSM = 0) */
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SSM);
            SET_BIT((SPI1 -> CR2), CR2_SSOE);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SSM);
            SET_BIT((SPI2 -> CR2), CR2_SSOE);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SSM);
            SET_BIT((SPI3 -> CR2), CR2_SSOE);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SSM);
            SET_BIT((SPI4 -> CR2), CR2_SSOE);
        break;
        default:
        break;
    }
}

void MSPI_voidSetFullDuplexMode(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI1 -> CR1), CR1_RXONLY);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI2 -> CR1), CR1_RXONLY);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI3 -> CR1), CR1_RXONLY);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI4 -> CR1), CR1_RXONLY);
        break;
        default:
        break;
    }
}

void MSPI_voidSetUnidirectionalReceiveOnlyMode(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI1 -> CR1), CR1_RXONLY);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI2 -> CR1), CR1_RXONLY);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI3 -> CR1), CR1_RXONLY);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI4 -> CR1), CR1_RXONLY);
        break;
        default:
        break;
    }
}

void MSPI_voidSetBidirectionalTransmittingMode(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            SET_BIT((SPI1 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI1 -> CR1), CR1_BIDIOE);
        break;
        case MSPI2:
            SET_BIT((SPI2 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI2 -> CR1), CR1_BIDIOE);
        break;
        case MSPI3:
            SET_BIT((SPI3 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI3 -> CR1), CR1_BIDIOE);
        break;
        case MSPI4:
            SET_BIT((SPI4 -> CR1), CR1_BIDIMODE);
            SET_BIT((SPI4 -> CR1), CR1_BIDIOE);
        break;
        default:
        break;
    }
}

void MSPI_voidSetBidirectionalReceivingMode(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            SET_BIT((SPI1 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI1 -> CR1), CR1_BIDIOE);
        break;
        case MSPI2:
            SET_BIT((SPI2 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI2 -> CR1), CR1_BIDIOE);
        break;
        case MSPI3:
            SET_BIT((SPI3 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI3 -> CR1), CR1_BIDIOE);
        break;
        case MSPI4:
            SET_BIT((SPI4 -> CR1), CR1_BIDIMODE);
            CLR_BIT((SPI4 -> CR1), CR1_BIDIOE);
        break;
        default:
        break;
    }
}

u8 MSPI_u8SendReceiveData(u8 Copy_u8SPINumber, u8 Copy_u8Data)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            (SPI1 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
            return ((u8) (SPI1 -> DR));
        break;
        case MSPI2:
            (SPI2 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
            return ((u8) (SPI2 -> DR));
        break;
        case MSPI3:
            (SPI3 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
            return ((u8) (SPI3 -> DR));
        break;
        case MSPI4:
            (SPI4 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
            return ((u8) (SPI4 -> DR));
        break;
        default:
        break;
    }
}

u16 MSPI_u16SendReceiveWord(u8 Copy_u8SPINumber, u16 Copy_u16Data)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            (SPI1 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
            return (SPI1 -> DR);
        break;
        case MSPI2:
            (SPI2 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
            return (SPI2 -> DR);
        break;
        case MSPI3:
            (SPI3 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
            return (SPI3 -> DR);
        break;
        case MSPI4:
            (SPI4 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
            return (SPI4 -> DR);
        break;
        default:
        break;
    }
}

void MSPI_voidSendData(u8 Copy_u8SPINumber, u8 Copy_u8Data)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            (SPI1 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
        break;
        case MSPI2:
            (SPI2 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
        break;
        case MSPI3:
            (SPI3 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
        break;
        case MSPI4:
            (SPI4 -> DR) = Copy_u8Data;
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
        break;
        default:
        break;
    }
}

void MSPI_voidSendWord(u8 Copy_u8SPINumber, u16 Copy_u16Data)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            (SPI1 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
        break;
        case MSPI2:
            (SPI2 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
        break;
        case MSPI3:
            (SPI3 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
        break;
        case MSPI4:
            (SPI4 -> DR) = Copy_u16Data;
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
        break;
        default:
        break;
    }
}

u8 MSPI_u8ReceiveData(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
            return ((u8) (SPI1 -> DR));
        break;
        case MSPI2:
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
            return ((u8) (SPI2 -> DR));
        break;
        case MSPI3:
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
            return ((u8) (SPI3 -> DR));
        break;
        case MSPI4:
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
            return ((u8) (SPI4 -> DR));
        break;
        default:
        break;
    }
}

u16 MSPI_u16ReceiveWord(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            while(GET_BIT((SPI1 -> SR), SR_BSY) == 1);
            return (SPI1 -> DR);
        break;
        case MSPI2:
            while(GET_BIT((SPI2 -> SR), SR_BSY) == 1);
            return (SPI2 -> DR);
        break;
        case MSPI3:
            while(GET_BIT((SPI3 -> SR), SR_BSY) == 1);
            return (SPI3 -> DR);
        break;
        case MSPI4:
            while(GET_BIT((SPI4 -> SR), SR_BSY) == 1);
            return (SPI4 -> DR);
        break;
        default:
        break;
    }
}

void MSPI_voidSendDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8* Copy_pu8Data, u8 Copy_u8DataSize)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_TXE) == 1);
                (SPI1 -> DR) = Copy_pu8Data[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_TXE) == 1);
                (SPI2 -> DR) = Copy_pu8Data[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_TXE) == 1);
                (SPI3 -> DR) = Copy_pu8Data[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_TXE) == 1);
                (SPI4 -> DR) = Copy_pu8Data[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidSendWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u16* Copy_pu16Word, u8 Copy_u8DataSize)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_TXE) == 1);
                (SPI1 -> DR) = Copy_pu16Word[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_TXE) == 1);
                (SPI2 -> DR) = Copy_pu16Word[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_TXE) == 1);
                (SPI3 -> DR) = Copy_pu16Word[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_TXE) == 1);
                (SPI4 -> DR) = Copy_pu16Word[Local_u8Iterator];
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidReceiveDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8 Copy_u8DataSize, u8* Copy_pu8ReceivedData)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI1 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI2 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI3 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI4 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidReceiveWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8 Copy_u8DataSize, u16* Copy_pu16ReceivedData)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI1 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI2 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI3 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI4 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidSendReceiveDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8* Copy_pu8Data, u8 Copy_u8DataSize, u8* Copy_pu8ReceivedData)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_TXE) == 1);
                (SPI1 -> DR) = Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT((SPI1 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI1 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_TXE) == 1);
                (SPI2 -> DR) = Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT((SPI2 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI2 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_TXE) == 1);
                (SPI3 -> DR) = Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT((SPI3 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI3 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_TXE) == 1);
                (SPI4 -> DR) = Copy_pu8Data[Local_u8Iterator];
                while(GET_BIT((SPI4 -> SR), SR_RXNE) == 1);
                Copy_pu8ReceivedData[Local_u8Iterator] = (SPI4 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidSendReceiveWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u16* Copy_pu16Word, u8 Copy_u8DataSize, u16* Copy_pu16ReceivedData)
{
    u8 Local_u8Iterator;
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            SET_REG((SPI1 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI1 -> SR), SR_TXE) == 1);
                (SPI1 -> DR) = Copy_pu16Word[Local_u8Iterator];
                while(GET_BIT((SPI1 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI1 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI1 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            SET_REG((SPI2 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI2 -> SR), SR_TXE) == 1);
                (SPI2 -> DR) = Copy_pu16Word[Local_u8Iterator];
                while(GET_BIT((SPI2 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI2 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI2 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            SET_REG((SPI3 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI3 -> SR), SR_TXE) == 1);
                (SPI3 -> DR) = Copy_pu16Word[Local_u8Iterator];
                while(GET_BIT((SPI3 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI3 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI3 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            SET_REG((SPI4 -> CRCPR), Copy_u16Polynomial);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
            for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8DataSize; Local_u8Iterator++)
            {
                while(GET_BIT((SPI4 -> SR), SR_TXE) == 1);
                (SPI4 -> DR) = Copy_pu16Word[Local_u8Iterator];
                while(GET_BIT((SPI4 -> SR), SR_RXNE) == 1);
                Copy_pu16ReceivedData[Local_u8Iterator] = (SPI4 -> DR);
                if (Local_u8Iterator == (Copy_u8DataSize - 2))
                {
                    SET_BIT((SPI4 -> CR1), CR1_CRCNEXT);
                }
            }
        break;
        default:
        break;
    }
}

void MSPI_voidClearCRC(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> CR1), CR1_SPE);
            CLR_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_CRCEN);
            SET_BIT((SPI1 -> CR1), CR1_SPE);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> CR1), CR1_SPE);
            CLR_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_CRCEN);
            SET_BIT((SPI2 -> CR1), CR1_SPE);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> CR1), CR1_SPE);
            CLR_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_CRCEN);
            SET_BIT((SPI3 -> CR1), CR1_SPE);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> CR1), CR1_SPE);
            CLR_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_CRCEN);
            SET_BIT((SPI4 -> CR1), CR1_SPE);
        break;
        default:
        break;
    }
}

u8 MSPI_u8GetFlagStatus(u8 Copy_u8SPINumber,  u8 Copy_u8FlagName)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            return (GET_BIT((SPI1 -> SR), Copy_u8FlagName));
        break;
        case MSPI2:
            return (GET_BIT((SPI2 -> SR), Copy_u8FlagName));
        break;
        case MSPI3:
            return (GET_BIT((SPI3 -> SR), Copy_u8FlagName));
        break;
        case MSPI4:
            return (GET_BIT((SPI4 -> SR), Copy_u8FlagName));
        break;
        default:
        break;
    }
}

void MSPI_voidClearCRCErrorFlag(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            CLR_BIT((SPI1 -> SR), SR_CRCERR);
        break;
        case MSPI2:
            CLR_BIT((SPI2 -> SR), SR_CRCERR);
        break;
        case MSPI3:
            CLR_BIT((SPI3 -> SR), SR_CRCERR);
        break;
        case MSPI4:
            CLR_BIT((SPI4 -> SR), SR_CRCERR);
        break;
        default:
        break;
    }
}

void MSPI_voidEnableDMAInterrupts(u8 Copy_u8SPINumber)
{
    switch (Copy_u8SPINumber)
    {
        case MSPI1:
            SET_BIT((SPI1 -> CR2), CR2_RXDMAEN);
            SET_BIT((SPI1 -> CR2), CR2_TXDMAEN);
        break;
        case MSPI2:
            SET_BIT((SPI2 -> CR2), CR2_RXDMAEN);
            SET_BIT((SPI2 -> CR2), CR2_TXDMAEN);
        break;
        case MSPI3:
            SET_BIT((SPI3 -> CR2), CR2_RXDMAEN);
            SET_BIT((SPI3 -> CR2), CR2_TXDMAEN);
        break;
        case MSPI4:
            SET_BIT((SPI4 -> CR2), CR2_RXDMAEN);
            SET_BIT((SPI4 -> CR2), CR2_TXDMAEN);
        break;
        default:
        break;
    }
}

void MSPI1_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI1_CallBack = pvNotificationFunction;
}

void MSPI2_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI2_CallBack = pvNotificationFunction;
}

void MSPI3_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI3_CallBack = pvNotificationFunction;
}

void MSPI4_voidSetCallBack(void(*pvNotificationFunction)(void))
{
	MSPI4_CallBack = pvNotificationFunction;
}

/************* SPI ISR ******************/

void SPI1_IRQHandler(void)
{
    if (MSPI1_CallBack != NULL)
    {
        MSPI1_CallBack();
    }
}

void SPI2_IRQHandler(void)
{
    if (MSPI2_CallBack != NULL)
    {
        MSPI2_CallBack();
    }
}

void SPI3_IRQHandler(void)
{
    if (MSPI3_CallBack != NULL)
    {
        MSPI3_CallBack();
    }
}

void SPI4_IRQHandler(void)
{
    if (MSPI4_CallBack != NULL)
    {
        MSPI4_CallBack();
    }
}