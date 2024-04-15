/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        30 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         30 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/

#ifndef HAL_TFT_TFT_INTERFACE_H_
#define HAL_TFT_TFT_INTERFACE_H_


void HTFT_voidInit(void);

void HTFT_voidDrawPixels(u8 Xaxis, u8 Yaxis, u16 Copy_u8Data);

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1);

void HTFT_voidDisplayImage(void);


#endif