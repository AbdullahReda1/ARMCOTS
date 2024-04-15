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


#ifndef MCAL_STK_STK_INTERFACE_H
#define MCAL_STK_STK_INTERFACE_H


#define MSTK_AHB_DEVIDED_BY_8    0
#define MSTK_AHB_DEVIDED_BY_1    1


void MSTK_voidInit(void);

void MSTK_voidInterruptEnable(void);
void MSTK_voidInterruptDisable(void);

void MSTK_voidEnable(void);
void MSTK_voidDisable(void);

void MSTK_voidClockSource(u8 Copy_u8SelectedClock);

u32 MSTK_voidGetElapsedTime(void);
u32 MSTK_voidGetRemainingTime(void);

void MSTK_voidSetMicroBusyWait(u32 Copy_u32uTicksWaiting);
void MSTK_voidSetMilliBusyWait(u16 Copy_u16mTicksWaiting);
void MSTK_voidSetSecondsBusyWait(u8 Copy_u8sTicksWaiting);
void MSTK_voidResetSystick(void);

u8 MSTK_u8IsSeparateRefClkProvided(void);
u8 MSTK_u8IsScewRefClkHappen(void);
u32 MSTK_u8GetSeparateRefClkTENMSCalibreion(void);

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));


#endif