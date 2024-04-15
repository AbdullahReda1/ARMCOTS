/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        29 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         29 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include "../../Services/SongArray.h"


volatile u32 Global_u32SongCounter = 0;


void HDAC_voidInit(void)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, HDAC_PORT_NAME);

    MGPIO_voidSetHalfPortMode(HDAC_PORT_NAME, HDAC_HALF_PORT_NAME, OUTPUT_MODE);
    MGPIO_voidSetHalfPortOutputType(HDAC_PORT_NAME, HDAC_HALF_PORT_NAME, PUSH_PULL);
    MGPIO_voidSetHalfPortOutputSpeed(HDAC_PORT_NAME, HDAC_HALF_PORT_NAME, MEDIUM_SPEED_10MHZ);

	MSTK_voidInit();
}

void HDAC_voidPlay(void)
{
    for(Global_u32SongCounter = 0; Global_u32SongCounter < Song_Length; Global_u32SongCounter++)
    {
	    MGPIO_voidSetHalfPortValue(HDAC_PORT_NAME, HDAC_HALF_PORT_NAME ,Song_Array[Global_u32SongCounter]);
		MSTK_voidSetMicroBusyWait(125);
    }
}