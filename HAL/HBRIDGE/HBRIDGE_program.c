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

#include "HBRIDGE_interface.h"
#include "HBRIDGE_private.h"
#include "HBRIDGE_config.h"


void HHBRIDGE_voidInit(HBRIDGE_t* HBRIDGEobj)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, HBRIDGEobj->HBRIDGE_IN1_PORT);
    MRCC_voidEnablePeripheralClock(RCC_AHB1, HBRIDGEobj->HBRIDGE_IN2_PORT);

    MGPIO_voidSetPinMode(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, LOW_SPEED_2MHZ);

    MGPIO_voidSetPinMode(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, OUTPUT_MODE);
	MGPIO_voidSetOutputType(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, PUSH_PULL);
	MGPIO_voidSetOutputSpeed(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, LOW_SPEED_2MHZ);
}

void HHBRIDGE_voidForward(HBRIDGE_t* HBRIDGEobj)
{
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, HIGH);
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, LOW);
}

void HHBRIDGE_voidBackward(HBRIDGE_t* HBRIDGEobj)
{
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, LOW);
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, HIGH);
}

void HHBRIDGE_voidStop(HBRIDGE_t* HBRIDGEobj)
{
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN1_PORT, HBRIDGEobj->HBRIDGE_IN1_PIN, LOW);
    MGPIO_voidSetPinValue(HBRIDGEobj->HBRIDGE_IN2_PORT, HBRIDGEobj->HBRIDGE_IN2_PIN, LOW);
}