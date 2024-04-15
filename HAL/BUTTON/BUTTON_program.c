/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        20 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         20 SEP, 2023      Abdullah R.Hebashi           Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "BUTTON_interface.h"
#include "BUTTON_config.h"
#include "BUTTON_private.h"


void HBUTTON_voidInit(BUTTON_t* Buttonobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, Buttonobj->BUTTON_PORT);
    MGPIO_voidSetPinMode(Buttonobj->BUTTON_PORT, Buttonobj->BUTTON_PIN, INPUT_MODE);
	MGPIO_voidSetOutputType(Buttonobj->BUTTON_PORT, Buttonobj->BUTTON_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(Buttonobj->BUTTON_PORT, Buttonobj->BUTTON_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidPullUpPullDownPin(Buttonobj->BUTTON_PORT, Buttonobj->BUTTON_PIN, Buttonobj->BUTTON_PP_TYPE);
}

u8 HBUTTON_u8GetButtonStatus(BUTTON_t* Buttonobj)
{
	return (MGPIO_u8GetPinValue(Buttonobj->BUTTON_PORT, Buttonobj->BUTTON_PIN));
}