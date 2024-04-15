/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        11 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         11 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SEVENSEGMENT_interface.h"
#include "SEVENSEGMENT_config.h"
#include "SEVENSEGMENT_private.h"


void HSEVENSEGMENT_voidInit(SEVENSEGMENT_t* SEVENSEGMENTobj)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, (SEVENSEGMENTobj->SEVENSEGMENT_PORT));

	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINA), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINB), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINC), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PIND), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINE), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINF), OUTPUT_MODE);
	MGPIO_voidSetPinMode((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PING), OUTPUT_MODE);

	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINA), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINB), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINC), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PIND), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINE), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINF), PUSH_PULL);
	MGPIO_voidSetOutputType((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PING), PUSH_PULL);

	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINA), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINB), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINC), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PIND), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINE), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINF), LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PING), LOW_SPEED_2MHZ);
}

void HSEVENSEGMENT_voidSendNumber(SEVENSEGMENT_t* SEVENSEGMENTobj, u8 Copy_u8Number)
{
	u8 Local_u8NumValue;
	#if		SEVENSEGMENT_TYPE == COMMON_CATHODE
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINA), (GET_BIT(Local_u8NumValue, 0)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINB), (GET_BIT(Local_u8NumValue, 1)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINC), (GET_BIT(Local_u8NumValue, 2)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PIND), (GET_BIT(Local_u8NumValue, 3)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINE), (GET_BIT(Local_u8NumValue, 4)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINF), (GET_BIT(Local_u8NumValue, 5)));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PING), (GET_BIT(Local_u8NumValue, 6)));
	#elif	SEVENSEGMENT_TYPE == COMMON_ANODE
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINA), (~(GET_BIT(Local_u8NumValue, 0))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINB), (~(GET_BIT(Local_u8NumValue, 1))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINC), (~(GET_BIT(Local_u8NumValue, 2))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PIND), (~(GET_BIT(Local_u8NumValue, 3))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINE), (~(GET_BIT(Local_u8NumValue, 4))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PINF), (~(GET_BIT(Local_u8NumValue, 5))));
		Local_u8NumValue = u8ArrayNumbers[Copy_u8Number];
		MGPIO_voidSetPinValue((SEVENSEGMENTobj->SEVENSEGMENT_PORT), (SEVENSEGMENTobj->SEVENSEGMENT_PING), (~(GET_BIT(Local_u8NumValue, 6))));
	#else
		#error "SEVENSEGMENT SEVENSEGMENT_TYPE, Configuration Error"
	#endif
}