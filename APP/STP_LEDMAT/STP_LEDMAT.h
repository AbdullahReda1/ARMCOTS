/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        29 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         29 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef APP_STP_LEDMAT_STP_LEDMAT_H
#define APP_STP_LEDMAT_STP_LEDMAT_H


typedef struct 
{
    u8 PORT;
    u8 DATA_PIN;
    u8 SHIFT_BIT_PIN;
    u8 SHIFT_BYTE_PIN;
}STP_LEDMAT_t;


void HSTPLEDMAT_voidInit(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, STP_LEDMAT_t * STP_LEDMAT_COL_obj);

void HSTPLEDMAT_voidDisplay(STP_LEDMAT_t * STP_LEDMAT_ROW_obj, STP_LEDMAT_t * STP_LEDMAT_COL_obj, const u8 * Copy_pu8DataArray);


#endif