/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        24 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         24 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/STK/STK_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/NVIC/NVIC_interface.h"
#include "../../MCAL/SYSCFG/SYSCFG_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"


static void (*pvCallBack[11])(void) = {{NULL}};

volatile u8 Global_u8StartEdgeFlag = 0;
volatile u32 Global_u32ReceivedFrame[100] = {0};
static u8 Global_u8ButtonData = 0;
static u8 Global_u8EdgeCounter = 0;
volatile u8 Global_u8Iterator = 0;


void HIR_voidInit(void)
{
    MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, HIR_PORT_NAME);
    MRCC_voidEnablePeripheralClock(RCC_APB2, RCC_SYSCFG);

    MGPIO_voidSetPinMode(HIR_PORT_NAME, HIR_PIN_NUMBER, INPUT_MODE);
	MGPIO_voidPullUpPullDownPin(HIR_PORT_NAME, HIR_PIN_NUMBER, PULL_UP);

    MNVIC_voidInit();
    #if ((HIR_PIN_NUMBER >= 0) && (HIR_PIN_NUMBER <= 4))
        u8 NVIC_LINE = HIR_PIN_NUMBER + 6;
        MNVIC_voidEnablePeripheralInterrupt(NVIC_LINE);
        MNVIC_voidSetPeripheralPriority(NVIC_LINE, 1);
    #elif ((HIR_PIN_NUMBER >= 5) && (HIR_PIN_NUMBER <= 9))
        MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI9_5);
        MNVIC_voidSetPeripheralPriority(MNVIC_EXTI9_5, 1);
    #elef ((HIR_PIN_NUMBER >= 10) && (HIR_PIN_NUMBER <= 15))
        MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI15_10);
        MNVIC_voidSetPeripheralPriority(MNVIC_EXTI15_10, 1);
    #else
        #error "IR HIR_PIN_NUMBER, Configuration Error"
    #endif

    MSYSCFG_voidSetEXTIConfiguration(HIR_PIN_NUMBER, HIR_PORT_NAME);

	MEXTI_voidChangeSenseMode(HIR_PIN_NUMBER , MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(HIR_PIN_NUMBER , &HIR_voidGetFrame);
	MEXTI_voidEnableInterrupt(HIR_PIN_NUMBER);

    MSTK_voidInit();
}

void HIR_voidGetFrame(void)
{
    if(Global_u8StartEdgeFlag == 0)
	{
        /* Stay here while start but */
		MSTK_voidSetSingleInterval(FRAME_TIME,&HIR_voidTakeAction);
        /* Change flag to get in else condition after start bit */
		Global_u8StartEdgeFlag = 1;
	}
	else
	{
        /* Stay here after start but */
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = MSTK_voidGetElapsedTime();
        /* Reset systick to avoid counting the 13.5 ms of the start bit and other pre-values of currernt reading */
		MSTK_voidResetSystick();
		MSTK_voidSetSingleInterval(FRAME_TIME,&HIR_voidTakeAction);
		Global_u8EdgeCounter++;
	}
}

void HIR_voidTakeAction(void)
{
	for (Global_u8Iterator = 0; Global_u8Iterator < 8; Global_u8Iterator++)
	{
        /* Check timeing */
		if ((Global_u32ReceivedFrame[(F1sT_DATA_BIT_OF_ARRAY + Global_u8Iterator)] >= LEFT_INTERVAL_TIME) && (Global_u32ReceivedFrame[(F1sT_DATA_BIT_OF_ARRAY + Global_u8Iterator)] <= RIGHT_INTERVAL_TIME))
		{
            /* Timing of logical zero */
			CLR_BIT(Global_u8ButtonData, Global_u8Iterator);
		}
		else
		{
            /* Timing of logical one */
			SET_BIT(Global_u8ButtonData, Global_u8Iterator);
		}
	}
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void HIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{
        case 22:    /*    0   */
            if (pvCallBack[ZER0_BUTTON] != NULL)
            {
                pvCallBack[ZER0_BUTTON]();
            }
        break;
        case 12:    /*    1   */
            if (pvCallBack[ONE_BUTTON] != NULL)
            {
                pvCallBack[ONE_BUTTON]();
            }
        break;
        case 24:    /*    2   */ 
            if (pvCallBack[TWO_BUTTON] != NULL)
            {
                pvCallBack[TWO_BUTTON]();
            }
        break;
        case 94:    /*    3   */
            if (pvCallBack[THREE_BUTTON] != NULL)
            {
                pvCallBack[THREE_BUTTON]();
            }
        break;
        case 8:     /*    4   */
            if (pvCallBack[FOUR_BUTTON] != NULL)
            {
                pvCallBack[FOUR_BUTTON]();
            }
        break;
        case 28:    /*    5   */
            if (pvCallBack[FIVE_BUTTON] != NULL)
            {
                pvCallBack[FIVE_BUTTON]();
            }
        break;
        case 90:    /*    6   */
            if (pvCallBack[SIX_BUTTON] != NULL)
            {
                pvCallBack[SIX_BUTTON]();
            }
        break;
        case 66:    /*    7   */
            if (pvCallBack[SEVEN_BUTTON] != NULL)
            {
                pvCallBack[SEVEN_BUTTON]();
            }
        break;
        case 82:    /*    8   */
            if (pvCallBack[EIGHT_BUTTON] != NULL)
            {
                pvCallBack[EIGHT_BUTTON]();
            }
        break;
        case 74:    /*    9   */
            if (pvCallBack[NINE_BUTTON] != NULL)
            {
                pvCallBack[NINE_BUTTON]();
            }
        break;
        case 69:    /* POWER  */
            if (pvCallBack[POWER_BUTTON] != NULL)
            {
                pvCallBack[POWER_BUTTON]();
            }
        break;
	}
}

void HIR_voidZeroButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[ZER0_BUTTON] = pvNotificationFunction;
}

void HIR_voidOneButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[ONE_BUTTON] = pvNotificationFunction;
}

void HIR_voidTwoButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[TWO_BUTTON] = pvNotificationFunction;
}

void HIR_voidThreeButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[THREE_BUTTON] = pvNotificationFunction;
}

void HIR_voidFourButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[FOUR_BUTTON] = pvNotificationFunction;
}

void HIR_voidFiveButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[FIVE_BUTTON] = pvNotificationFunction;
}

void HIR_voidSixButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[SIX_BUTTON] = pvNotificationFunction;
}

void HIR_voiSevendButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[SEVEN_BUTTON] = pvNotificationFunction;
}

void HIR_voidEightButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[EIGHT_BUTTON] = pvNotificationFunction;
}

void HIR_voidNineButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[NINE_BUTTON] = pvNotificationFunction;
}

void HIR_voidPowerButton(void (*pvNotificationFunction)(void))
{
    pvCallBack[POWER_BUTTON] = pvNotificationFunction;
}