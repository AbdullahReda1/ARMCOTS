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


#ifndef MCAL_EXTI_EXTI_INTERFACE_H
#define MCAL_EXTI_EXTI_INTERFACE_H


#define MEXTI_RISING_EDGE       0
#define MEXTI_FALLING_EDGE      1
#define MEXTI_ON_CHANGE         2

#define MEXTI_LINE0				    0
#define MEXTI_LINE1                 1
#define MEXTI_LINE2                 2
#define MEXTI_LINE3                 3
#define MEXTI_LINE4                 4
#define MEXTI_LINE5                 5
#define MEXTI_LINE6                 6
#define MEXTI_LINE7                 7
#define MEXTI_LINE8                 8
#define MEXTI_LINE9                 9
#define MEXTI_LINE10                10
#define MEXTI_LINE11                11
#define MEXTI_LINE12                12
#define MEXTI_LINE13                13
#define MEXTI_LINE14                14
#define MEXTI_LINE15                15
#define MEXTI_PVD_LINE16            16
#define MEXTI_RTC_ALARM_LINE17      17
#define MEXTI_OTG_FS_WKUP_LINE18    18
#define MEXTI_TAMP_STAMP_LINE21     21
#define MEXTI_RTC_WKUP_LINE22       22


void MEXTI_voidInit(void);

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILINE);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILINE);

void MEXTI_voidEnableEvent(u8 Copy_u8EXTILINE);
void MEXTI_voidDisableEvent(u8 Copy_u8EXTILINE);

void MEXTI_voidSoftWareTrigger( u8 Copy_u8EXTILINE);

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILINE, u8 Copy_u8SenseSignal);

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILINE, void (*pvNotificationFunction)(void));


#endif