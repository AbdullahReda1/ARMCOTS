/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         22 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*pvCallBack[23])(void) = {{NULL}};


void MEXTI_voidInit(void)
{
    /* Simple Funcion for single specific line, Don't use with mixed lines */
    #if     EXTI_SENSE_SIGNAL == RISING_EDGE
        CLR_BIT((EXTI -> FTSR), EXTI_LINE);
        SET_BIT((EXTI -> RTSR), EXTI_LINE);
    #elif   EXTI_SENSE_SIGNAL == FALLING_EDGE
        CLR_BIT((EXTI -> RTSR), EXTI_LINE);
        SET_BIT((EXTI -> FTSR), EXTI_LINE);
    #elif   EXTI_SENSE_SIGNAL == ON_CHANGE
        SET_BIT((EXTI -> FTSR), EXTI_LINE);
        SET_BIT((EXTI -> RTSR), EXTI_LINE);
    #else
        #error "EXTI EXTI_SENSE_SIGNAL, Configuration Error"
    #endif

    SET_BIT((EXTI -> IMR), EXTI_LINE);
}

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILINE)
{
    if (Copy_u8EXTILINE > 15)
    {
        return;
    }
    SET_BIT((EXTI -> IMR), Copy_u8EXTILINE);
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILINE)
{
    if (Copy_u8EXTILINE > 15)
    {
        return;
    }
    CLR_BIT((EXTI -> IMR), Copy_u8EXTILINE);
}

void MEXTI_voidEnableEvent(u8 Copy_u8EXTILINE)
{
    if (Copy_u8EXTILINE > 15)
    {
        return;
    }
    SET_BIT((EXTI -> EMR), Copy_u8EXTILINE);
}

void MEXTI_voidDisableEvent(u8 Copy_u8EXTILINE)
{
    if (Copy_u8EXTILINE > 15)
    {
        return;
    }
    CLR_BIT((EXTI -> EMR), Copy_u8EXTILINE);
}

void MEXTI_voidSoftWareTrigger(u8 Copy_u8EXTILINE)
{
    if (Copy_u8EXTILINE > 15)
    {
        return;
    }
	SET_BIT((EXTI -> SWIER), Copy_u8EXTILINE);
}

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILINE, u8 Copy_u8SenseSignal)
{
    switch (Copy_u8SenseSignal)
    {
        case MEXTI_RISING_EDGE:
            CLR_BIT((EXTI -> FTSR), Copy_u8EXTILINE);
            SET_BIT((EXTI -> RTSR), Copy_u8EXTILINE);
        break;
        case MEXTI_FALLING_EDGE:
            CLR_BIT((EXTI -> RTSR), Copy_u8EXTILINE);
            SET_BIT((EXTI -> FTSR), Copy_u8EXTILINE);
        break;
        case MEXTI_ON_CHANGE:
            SET_BIT((EXTI -> FTSR), Copy_u8EXTILINE);
            SET_BIT((EXTI -> RTSR), Copy_u8EXTILINE);
        break;
        default:
        break;
    }
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILINE, void (*pvNotificationFunction)(void))
{
    pvCallBack[Copy_u8EXTILINE] = pvNotificationFunction;
}


/************* EXTI0 ISR ******************/

void EXTI0_IRQHandler(void)
{
    if (pvCallBack[0] != NULL)
    {
        pvCallBack[0]();
    }
    SET_BIT((EXTI -> PR), PR_PR0);
}

/************* EXTI1 ISR ******************/

void EXTI1_IRQHandler(void)
{
    if (pvCallBack[1] != NULL)
    {
        pvCallBack[1]();
    }
    SET_BIT((EXTI -> PR), PR_PR1);
}

/************* EXTI2 ISR ******************/

void EXTI2_IRQHandler(void)
{
    if (pvCallBack[2] != NULL)
    {
        pvCallBack[2]();
    }
    SET_BIT((EXTI -> PR), PR_PR2);
}

/************* EXTI3 ISR ******************/

void EXTI3_IRQHandler(void)
{
    if (pvCallBack[3] != NULL)
    {
        pvCallBack[3]();
    }
    SET_BIT((EXTI -> PR), PR_PR3);
}

/************* EXTI4 ISR ******************/

void EXTI4_IRQHandler(void)
{
    if (pvCallBack[4] != NULL)
    {
        pvCallBack[4]();
    }
    SET_BIT((EXTI -> PR), PR_PR4);
}

/************* EXTI9_5 ISR ******************/

void EXTI9_5_IRQHandler(void)
{
    u8 Local_u8PendingResult5;
    Local_u8PendingResult5 = (GET_BIT((EXTI->PR), PR_PR5));

    if (Local_u8PendingResult5 == HIGH)
    {
        if (pvCallBack[5] != NULL)
        {
            pvCallBack[5]();
        }
        SET_BIT((EXTI -> PR), PR_PR5);
    }
    
    u8 Local_u8PendingResult6;
    Local_u8PendingResult6 = (GET_BIT((EXTI->PR), PR_PR6));
    
    if (Local_u8PendingResult6 == HIGH)
    {
        if (pvCallBack[6] != NULL)
        {
            pvCallBack[6]();
        }
        SET_BIT((EXTI -> PR), PR_PR6);
    }
    
    u8 Local_u8PendingResult7;
    Local_u8PendingResult7 = (GET_BIT((EXTI->PR), PR_PR7));
    
    if (Local_u8PendingResult7 == HIGH)
    {
        if (pvCallBack[7] != NULL)
        {
            pvCallBack[7]();
        }
        SET_BIT((EXTI -> PR), PR_PR7);
    }
    
    u8 Local_u8PendingResult8;
    Local_u8PendingResult8 = (GET_BIT((EXTI->PR), PR_PR8));
    
    if (Local_u8PendingResult8 == HIGH)
    {
        if (pvCallBack[8] != NULL)
        {
            pvCallBack[8]();
        }
        SET_BIT((EXTI -> PR), PR_PR8);
    }
    
    u8 Local_u8PendingResult9;
    Local_u8PendingResult9 = (GET_BIT((EXTI->PR), PR_PR9));
    
    if (Local_u8PendingResult9 == HIGH)
    {
        if (pvCallBack[9] != NULL)
        {
            pvCallBack[9]();
        }
        SET_BIT((EXTI -> PR), PR_PR9);
    }
    
}

/************* EXTI15_10 ISR ******************/

void EXTI15_10_IRQHandler(void)
{
    u8 Local_u8PendingResult10;
    Local_u8PendingResult10 = (GET_BIT((EXTI->PR), PR_PR10));

    if (Local_u8PendingResult10 == HIGH)
    {
        if (pvCallBack[10] != NULL)
        {
            pvCallBack[10]();
        }
        SET_BIT((EXTI -> PR), PR_PR10);
    }
    
    u8 Local_u8PendingResult11;
    Local_u8PendingResult11 = (GET_BIT((EXTI->PR), PR_PR11));
    
    if (Local_u8PendingResult11 == HIGH)
    {
        if (pvCallBack[11] != NULL)
        {
            pvCallBack[11]();
        }
        SET_BIT((EXTI -> PR), PR_PR11);
    }
    
    u8 Local_u8PendingResult12;
    Local_u8PendingResult12 = (GET_BIT((EXTI->PR), PR_PR12));
    
    if (Local_u8PendingResult12 == HIGH)
    {
        if (pvCallBack[12] != NULL)
        {
            pvCallBack[12]();
        }
        SET_BIT((EXTI -> PR), PR_PR12);
    }
    
    u8 Local_u8PendingResult13;
    Local_u8PendingResult13 = (GET_BIT((EXTI->PR), PR_PR13));
    
    if (Local_u8PendingResult13 == HIGH)
    {
        if (pvCallBack[13] != NULL)
        {
            pvCallBack[13]();
        }
        SET_BIT((EXTI -> PR), PR_PR13);
    }
    
    u8 Local_u8PendingResult14;
    Local_u8PendingResult14 = (GET_BIT((EXTI->PR), PR_PR14));
    
    if (Local_u8PendingResult14 == HIGH)
    {
        if (pvCallBack[14] != NULL)
        {
            pvCallBack[14]();
        }
        SET_BIT((EXTI -> PR), PR_PR14);
    }
    
    u8 Local_u8PendingResult15;
    Local_u8PendingResult15 = (GET_BIT((EXTI->PR), PR_PR15));
    
    if (Local_u8PendingResult15 == HIGH)
    {
        if (pvCallBack[15] != NULL)
        {
            pvCallBack[15]();
        }
        SET_BIT((EXTI -> PR), PR_PR15);
    }

}

/************* EXTI16 ISR ******************/

void PVD_IRQHandler(void)
{
    if (pvCallBack[16] != NULL)
    {
        pvCallBack[16]();
    }
    SET_BIT((EXTI -> PR), PR_PR16);
}

/************* EXTI17 ISR ******************/

void RTC_Alarm_IRQHandler(void)
{
    if (pvCallBack[17] != NULL)
    {
        pvCallBack[17]();
    }
    SET_BIT((EXTI -> PR), PR_PR17);
}

/************* EXTI18 ISR ******************/

void OTG_FS_WKUP_IRQHandler(void)
{
    if (pvCallBack[18] != NULL)
    {
        pvCallBack[18]();
    }
    SET_BIT((EXTI -> PR), PR_PR18);
}

/************* EXTI21 ISR ******************/

void TAMP_STAMP_IRQHandler(void)
{
    if (pvCallBack[21] != NULL)
    {
        pvCallBack[21]();
    }
    SET_BIT((EXTI -> PR), PR_PR21);
}

/************* EXTI22 ISR ******************/

void RTC_WKUP_IRQHandler(void)
{
    if (pvCallBack[22] != NULL)
    {
        pvCallBack[22]();
    }
    SET_BIT((EXTI -> PR), PR_PR22);
}