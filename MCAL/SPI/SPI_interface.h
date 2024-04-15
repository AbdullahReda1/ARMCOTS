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


#ifndef MCAL_SPI_SPI_INTERFACE_H
#define MCAL_SPI_SPI_INTERFACE_H


/**** SPI Number ****/
#define MSPI1            0
#define MSPI2            1
#define MSPI3            2
#define MSPI4            3

#define DEFAULT_POLYNOMIAL      0x0007

/* Flag Name */
#define RECEIVE_BUFFER_NOT_EMPTY    0
#define TRANSMIT_BUFFER_EMPTY       1
#define CRC_ERROR                   4
#define MODE_FAULT                  5
#define OVERRUN_FLAG                6
#define BUSY_FLAG                   7
#define FRAME_FORMAT_ERROR          8


void MSPI_voidInit(u8 Copy_u8SPINumber);

void MSPI_voidAllowMultimasterMode(u8 Copy_u8SPINumber);

void MSPI_voidAllowSingleMasterMode(u8 Copy_u8SPINumber);

void MSPI_voidSetFullDuplexMode(u8 Copy_u8SPINumber);

void MSPI_voidSetUnidirectionalReceiveOnlyMode(u8 Copy_u8SPINumber);

void MSPI_voidSetBidirectionalTransmittingMode(u8 Copy_u8SPINumber);

void MSPI_voidSetBidirectionalReceivingMode(u8 Copy_u8SPINumber);

u8 MSPI_u8SendReceiveData(u8 Copy_u8SPINumber, u8 Copy_u8Data);

u16 MSPI_u16SendReceiveWord(u8 Copy_u8SPINumber, u16 Copy_u16Data);

void MSPI_voidSendData(u8 Copy_u8SPINumber, u8 Copy_u8Data);

void MSPI_voidSendWord(u8 Copy_u8SPINumber, u16 Copy_u16Data);

u8 MSPI_u8ReceiveData(u8 Copy_u8SPINumber);

u16 MSPI_u16ReceiveWord(u8 Copy_u8SPINumber);

void MSPI_voidSendDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8* Copy_pu8Data, u8 Copy_u8DataSize);

void MSPI_voidSendWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u16* Copy_pu16Word, u8 Copy_u8DataSize);

void MSPI_voidReceiveDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8 Copy_u8DataSize, u8* Copy_pu8ReceivedData);

void MSPI_voidReceiveWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8 Copy_u8DataSize, u16* Copy_pu16ReceivedData);

void MSPI_voidSendReceiveDataWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u8* Copy_pu8Data, u8 Copy_u8DataSize, u8* Copy_pu8ReceivedData);

void MSPI_voidSendReceiveWordWithCRC(u8 Copy_u8SPINumber, u16 Copy_u16Polynomial, u16* Copy_pu16Word, u8 Copy_u8DataSize, u16* Copy_pu16ReceivedData);

void MSPI_voidClearCRC(u8 Copy_u8SPINumber);

u8 MSPI_u8GetFlagStatus(u8 Copy_u8SPINumber,  u8 Copy_u8FlagName);

void MSPI_voidClearCRCErrorFlag(u8 Copy_u8SPINumber);

void MSPI_voidEnableDMAInterrupts(u8 Copy_u8SPINumber);

void MSPI1_voidSetCallBack(void(*pvNotificationFunction)(void));
void MSPI2_voidSetCallBack(void(*pvNotificationFunction)(void));
void MSPI3_voidSetCallBack(void(*pvNotificationFunction)(void));
void MSPI4_voidSetCallBack(void(*pvNotificationFunction)(void));


#endif