/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        8 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 APP
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         8 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef APP_CLK_CASCADING_SIMULATE_CLK_CASCADING_SIMULATE_H
#define APP_CLK_CASCADING_SIMULATE_CLK_CASCADING_SIMULATE_H


/* Clock cascading MCO Pin */
#define MCO1        PIN8
#define MCO2        PIN9


void SetClockCascadingOut(u8 Copy_u8MCOType);
void StartClockCascading(u8 Copy_u8MCOType);


#endif