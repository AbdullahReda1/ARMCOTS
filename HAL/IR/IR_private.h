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


#ifndef MCAL_IR_IR_PRIVATE_H
#define MCAL_IR_IR_PRIVATE_H


#define HIR_GPIO_PORTA          0
#define HIR_GPIO_PORTB          1
#define HIR_GPIO_PORTC          2

#define HIR_PIN0                0
#define HIR_PIN1                1
#define HIR_PIN2                2
#define HIR_PIN3                3
#define HIR_PIN4                4
#define HIR_PIN5                5
#define HIR_PIN6                6
#define HIR_PIN7                7
#define HIR_PIN8                8
#define HIR_PIN9                9
#define HIR_PIN10               10
#define HIR_PIN11               11
#define HIR_PIN12               12
#define HIR_PIN13               13
#define HIR_PIN14               14
#define HIR_PIN15               15


#define ZER0_BUTTON              0
#define ONE_BUTTON               1
#define TWO_BUTTON               2
#define THREE_BUTTON             3
#define FOUR_BUTTON              4
#define FIVE_BUTTON              5
#define SIX_BUTTON               6
#define SEVEN_BUTTON             7
#define EIGHT_BUTTON             8
#define NINE_BUTTON              9
#define POWER_BUTTON             10


#define F1sT_DATA_BIT_OF_ARRAY      17
#define FRAME_TIME                  67500
#define LEFT_INTERVAL_TIME          1000
#define RIGHT_INTERVAL_TIME         1500


void HIR_voidGetFrame(void);

void HIR_voidTakeAction(void);


#endif