/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        19 SEP, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "TRANSISTOR_interface.h"
#include "TRANSISTOR_private.h"
#include "TRANSISTOR_config.h"


void HTRANSISTOR_voidInit(TRANSISTOR_t* TRANSISTORobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, TRANSISTORobj->TRANSISTOR_PORT);

    MGPIO_voidSetPinMode(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, LOW_SPEED_2MHZ);
}

void HTRANSISTOR_voidSaturationMode(TRANSISTOR_t* TRANSISTORobj)
{
    switch (TRANSISTORobj->TRANSISTOR_TYPE)
    {
        case NPN:
            MGPIO_voidSetPinValue(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, HIGH);
        break;
        case PNP:
            MGPIO_voidSetPinValue(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, LOW);
        break;
        default:
        break;
    }
}

void HTRANSISTOR_voidCutoffMode(TRANSISTOR_t* TRANSISTORobj)
{
    switch (TRANSISTORobj->TRANSISTOR_TYPE)
    {
        case NPN:
            MGPIO_voidSetPinValue(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, LOW);
        break;
        case PNP:
            MGPIO_voidSetPinValue(TRANSISTORobj->TRANSISTOR_PORT, TRANSISTORobj->TRANSISTOR_PIN, HIGH);
        break;
        default:
        break;
    }
}