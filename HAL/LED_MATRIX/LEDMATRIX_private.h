/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        11 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         11 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_LEDMATRIX_LEDMATRIX_PRIVATE_H
#define MCAL_LEDMATRIX_LEDMATRIX_PRIVATE_H


#define LEDMATRIX_ROW0_PIN              ROW0
#define LEDMATRIX_ROW1_PIN              ROW1
#define LEDMATRIX_ROW2_PIN              ROW2
#define LEDMATRIX_ROW3_PIN              ROW3
#define LEDMATRIX_ROW4_PIN              ROW4
#define LEDMATRIX_ROW5_PIN              ROW5
#define LEDMATRIX_ROW6_PIN              ROW6
#define LEDMATRIX_ROW7_PIN              ROW7

#define LEDMATRIX_COL0_PIN              COL0
#define LEDMATRIX_COL1_PIN              COL1
#define LEDMATRIX_COL2_PIN              COL2
#define LEDMATRIX_COL3_PIN              COL3
#define LEDMATRIX_COL4_PIN              COL4
#define LEDMATRIX_COL5_PIN              COL5
#define LEDMATRIX_COL6_PIN              COL6    
#define LEDMATRIX_COL7_PIN              COL7

#define LEDMATRIX_ROW_PORT              ROW_PORT
#define LEDMATRIX_COL_PORT              COL_PORT

#define LEDMATRIX_STARTING_COL_PIN      STARTING_COL_PIN

#define Arr_Size                        8

#define NUM_ROWS                        8
#define NUM_COLS                        8
#define INIT_LOOP                       0


static void voidDisableColumns(void);


#endif