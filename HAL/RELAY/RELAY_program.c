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

#include "RELAY_interface.h"
#include "RELAY_private.h"
#include "RELAY_config.h"


void HRELAY_voidInit(RELAY_t* RELAYobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, RELAYobj->RELAY_PORT);

    MGPIO_voidSetPinMode(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, LOW_SPEED_2MHZ);
}

void HRELAY_voidOpen(RELAY_t* RELAYobj)
{
    switch (RELAYobj->RELAY_TYPE)
    {
        case NORMAL_OPEN:
            MGPIO_voidSetPinValue(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, LOW);
        break;
        case NORMAL_CLOSE:
            MGPIO_voidSetPinValue(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, HIGH);
        break;
        default:
        break;
    }
}

void HRELAY_voidClose(RELAY_t* RELAYobj)
{
    switch (RELAYobj->RELAY_TYPE)
    {
        case NORMAL_OPEN:
            MGPIO_voidSetPinValue(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, HIGH);
        break;
        case NORMAL_CLOSE:
            MGPIO_voidSetPinValue(RELAYobj->RELAY_PORT, RELAYobj->RELAY_PIN, LOW);
        break;
        default:
        break;
    }
}