/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        8 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         8 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"


static void (*pvCallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;


void MSTK_voidInit(void)
{
    /* Select systick clock source */
    #if     MSTK_CLOCK_SOURCE == AHB_DEVIDED_BY_8
        CLR_BIT((STK->CTRL), CTRL_CLKSOURCE);
    #elif   MSTK_CLOCK_SOURCE == AHB_DEVIDED_BY_1
        SET_BIT((STK->CTRL), CTRL_CLKSOURCE);
    #else
        #error "STK MSTK_CLOCK_SOURCE, Configuration Error"
    #endif

    /* Enable/Disable systick Interrupt */
    #if     MSTK_INTERRUPT == ENABLE_INTERRUPT
        SET_BIT((STK->CTRL), CTRL_TICKINT);
    #elif   MSTK_INTERRUPT == DISABLE_INTERRUPT
        CLR_BIT((STK->CTRL), CTRL_TICKINT);
    #else
        #error "STK MSTK_INTERRUPT, Configuration Error"
    #endif

    /* Enable/Disable systick */
    #if     MSTK_ENABLE == STK_ENABLE
        SET_BIT((STK->CTRL), CTRL_ENABLE);
    #elif   MSTK_ENABLE == STK_DISABLE
        CLR_BIT((STK->CTRL), CTRL_ENABLE);
    #else
        #error "STK MSTK_ENABLE, Configuration Error"
    #endif
}

void MSTK_voidInterruptEnable(void)
{
    SET_BIT((STK->CTRL), CTRL_TICKINT);
}

void MSTK_voidInterruptDisable(void)
{
    CLR_BIT((STK->CTRL), CTRL_TICKINT);
}

void MSTK_voidEnable(void)
{
    SET_BIT((STK->CTRL), CTRL_ENABLE);
}

void MSTK_voidDisable(void)
{
    CLR_BIT((STK->CTRL), CTRL_ENABLE);
}

void MSTK_voidClockSource(u8 Copy_u8SelectedClock)
{
    switch (Copy_u8SelectedClock)
    {
        case MSTK_AHB_DEVIDED_BY_8:
            CLR_BIT((STK->CTRL), CTRL_CLKSOURCE);
        break;
        case MSTK_AHB_DEVIDED_BY_1:
            SET_BIT((STK->CTRL), CTRL_CLKSOURCE);
        break;
        default:
        break;
    }
    SET_BIT((STK->CTRL), CTRL_ENABLE);
}

u32 MSTK_voidGetElapsedTime(void)
{
    u32 Local_u32ElapsedTime;
    Local_u32ElapsedTime = (STK->LOAD) - (STK->VAL);
    return Local_u32ElapsedTime;
}

u32 MSTK_voidGetRemainingTime(void)
{
    u32 Local_u32RemainingTime;
    Local_u32RemainingTime = (STK->VAL);
    return Local_u32RemainingTime;
}

void MSTK_voidSetMicroBusyWait(u32 Copy_u32uTicksWaiting)
{
    /* Max = 16,777,215 us */
    (STK->LOAD) =  Copy_u32uTicksWaiting;
    while(GET_BIT((STK->CTRL), CTRL_COUNTFLAG) == 0);
    (STK->VAL) = 0;
}

void MSTK_voidSetMilliBusyWait(u16 Copy_u16mTicksWaiting)
{
    /* Max = 16,777 ms */
    (STK->LOAD) =  (Copy_u16mTicksWaiting * 1000);
    while(GET_BIT((STK->CTRL), CTRL_COUNTFLAG) == 0);
    (STK->VAL) = 0;
}

void MSTK_voidSetSecondsBusyWait(u8 Copy_u8sTicksWaiting)
{
    /* Max = 16 s */
    (STK->LOAD) =  (Copy_u8sTicksWaiting * 1000000);
    while(GET_BIT((STK->CTRL), CTRL_COUNTFLAG) == 0);
    (STK->VAL) = 0;
}

void MSTK_voidResetSystick(void)
{
    (STK->VAL) = 0;
}

u8 MSTK_u8IsSeparateRefClkProvided(void)
{
    u32 Local_u32RegisterValue = GET_REG(STK->CALIB);
    u8 Local_u8IsNorefStatus = GET_BIT(Local_u32RegisterValue, CALIB_NOREF);
    return Local_u8IsNorefStatus;
}

u8 MSTK_u8IsScewRefClkHappen(void)
{
    u32 Local_u32RegisterValue = GET_REG(STK->CALIB);
    u8 Local_u8IsScewStatus = GET_BIT(Local_u32RegisterValue, CALIB_SKEW);
    return Local_u8IsScewStatus;
}

u32 MSTK_u8GetSeparateRefClkTENMSCalibreion(void)
{
    u32 Local_u32RegisterValue = GET_REG(STK->CALIB);
    u32 Local_u32Calibration = ((Local_u32RegisterValue << (MAX_REG_VAL - CALIB_TENMS23)) >> (MAX_REG_VAL - CALIB_TENMS23));
    return Local_u32Calibration;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
    (STK->LOAD) =  Copy_u32Ticks;
    u8IntervalFlag = SINGLE_INTERVAL;
	pvCallBackFunction = NotificationFunction;
    MSTK_voidInterruptEnable();
    MSTK_voidEnable();
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
    (STK->LOAD) =  (Copy_u32Ticks - 1);
    u8IntervalFlag = PERIODIC_INTERVAL;
	pvCallBackFunction = NotificationFunction;
    MSTK_voidInterruptEnable();
    MSTK_voidEnable();
}

/************* SysTick ISR ******************/

void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		(STK->LOAD) = 0;
		(STK->VAL)  = 0;
		CLR_BIT((STK->CTRL), CTRL_ENABLE);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT((STK->CTRL), CTRL_COUNTFLAG);
}