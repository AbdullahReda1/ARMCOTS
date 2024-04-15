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


#ifndef MCAL_IR_IR_INTERFACE_H
#define MCAL_IR_IR_INTERFACE_H


void HIR_voidInit(void);

void HIR_voidPlay(void);

void HIR_voidZeroButton (void (*pvNotificationFunction)(void));
void HIR_voidOneButton  (void (*pvNotificationFunction)(void));
void HIR_voidTwoButton  (void (*pvNotificationFunction)(void));
void HIR_voidThreeButton(void (*pvNotificationFunction)(void));
void HIR_voidFourButton (void (*pvNotificationFunction)(void));
void HIR_voidFiveButton (void (*pvNotificationFunction)(void));
void HIR_voidSixButton  (void (*pvNotificationFunction)(void));
void HIR_voiSevendButton(void (*pvNotificationFunction)(void));
void HIR_voidEightButton(void (*pvNotificationFunction)(void));
void HIR_voidNineButton (void (*pvNotificationFunction)(void));
void HIR_voidPowerButton(void (*pvNotificationFunction)(void));


#endif