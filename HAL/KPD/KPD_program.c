/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAR, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAR, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


void HKPD_voidInit(void)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, KPD_ROWS_PORT);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, KPD_COLS_PORT);

    MGPIO_voidSetNipplePortMode(KPD_ROWS_PORT, KPD_ROWS_NIPPLE, INPUT_MODE);
	MGPIO_voidPullUpPullDownNipplePort(KPD_ROWS_PORT, KPD_ROWS_NIPPLE, PULL_UP);

    MGPIO_voidSetNipplePortMode(KPD_COLS_PORT, KPD_COLS_NIPPLE, OUTPUT_MODE);
    MGPIO_voidSetNipplePortOutputType(KPD_COLS_PORT, KPD_COLS_NIPPLE, PUSH_PULL);
    MGPIO_voidSetNipplePortOutputSpeed(KPD_COLS_PORT, KPD_COLS_NIPPLE, LOW_SPEED_2MHZ);

    MGPIO_voidSetNipplePortValue(KPD_COLS_PORT, KPD_COLS_NIPPLE, NIPPLE_HIGH);
}

u8 HKPD_u8GetPressedKey(void)
{
    static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COULMNS_NUM] = KPD_ARR_VAL;
    u8 Local_u8RowValue;
    u8 Local_u8ColumnsIterator;
    u8 Local_u8RowsIterator;
    u8 Local_u8PressedKey = KPD_NOT_PRESSED_VAL;
    for(Local_u8ColumnsIterator = 0; Local_u8ColumnsIterator < KPD_COULMNS_NUM; Local_u8ColumnsIterator++)
    {
        MGPIO_voidSetPinValue(KPD_COLS_PORT, (KPD_START_COL_PIN + Local_u8ColumnsIterator), LOW);
        for(Local_u8RowsIterator = 0; Local_u8RowsIterator < KPD_ROWS_NUM; Local_u8RowsIterator++)
        {
            Local_u8RowValue = MGPIO_u8GetPinValue(KPD_ROWS_PORT, (KPD_START_ROW_PIN + Local_u8RowsIterator));
            if(Local_u8RowValue == LOW)
            {
                Local_u8PressedKey = Local_u8KPDArray[Local_u8RowsIterator][Local_u8ColumnsIterator];
                while(Local_u8RowValue == LOW)
                {
                    Local_u8RowValue = MGPIO_u8GetPinValue(KPD_ROWS_PORT, (KPD_START_ROW_PIN + Local_u8RowsIterator));
                }
                return Local_u8PressedKey;
            }
        }
        MGPIO_voidSetPinValue(KPD_COLS_PORT, (KPD_START_COL_PIN + Local_u8ColumnsIterator), HIGH);
    }
    return Local_u8PressedKey;
}