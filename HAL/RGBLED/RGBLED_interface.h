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
 * v1.0         19 SEP, 2023      Abdullah R.Hebashi           Initial Creation 
*********************************************************************************/


#ifndef HAL_RGBLED_RGBLED_INTERFACE_H
#define HAL_RGBLED_RGBLED_INTERFACE_H


typedef struct {
	u8 COMMON_TYPE;		//ANODE: CA , CATHODE: CC
	u8 PORT;			//GPIO_PORTA , B , C
	u8 RPIN;			//PIN0 , 15
	u8 GPIN;
	u8 BPIN;
	u8 COMPIN;
}RGBLED_t;


#define CA      0
#define CC      1

#define	BLACK		0b000
#define	WHITE		0b111
#define	RED			0b100
#define	GREEN		0b010
#define	BLUE		0b001
#define	YELLOW		0b110
#define	AQUA		0b011
#define	FUCHSIA		0b101


void HRGBLED_voidInit(RGBLED_t* RGBLedobj);

void HRGBLED_voidSetColor(RGBLED_t* RGBLedobj, u8 Copy_u8Color);


#endif