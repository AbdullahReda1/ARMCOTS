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


#ifndef MCAL_SYSCFG_SYSCFG_INTERFACE_H
#define MCAL_SYSCFG_SYSCFG_INTERFACE_H


/* Memory mapping selection & BOOT mode */
#define MSYSCFG_MAIN_FLASH_MEMORY_MAPPED        0b00
#define MSYSCFG_SYSTEM_FLASH_MEMORY_MAPPED      0b01
#define MSYSCFG_EMBEDDED_SRAM_MAPPED            0b10

/* Port mapping */
#define MSYSCFG_EXTI_PORTA           0b0000
#define MSYSCFG_EXTI_PORTB           0b0001
#define MSYSCFG_EXTI_PORTC           0b0010

/* EXTI Line */
#define MSYSCFG_EXTI_LINE0			   0
#define MSYSCFG_EXTI_LINE1             1
#define MSYSCFG_EXTI_LINE2             2
#define MSYSCFG_EXTI_LINE3             3
#define MSYSCFG_EXTI_LINE4             4
#define MSYSCFG_EXTI_LINE5             5
#define MSYSCFG_EXTI_LINE6             6
#define MSYSCFG_EXTI_LINE7             7
#define MSYSCFG_EXTI_LINE8             8
#define MSYSCFG_EXTI_LINE9             9
#define MSYSCFG_EXTI_LINE10            10
#define MSYSCFG_EXTI_LINE11            11
#define MSYSCFG_EXTI_LINE12            12
#define MSYSCFG_EXTI_LINE13            13
#define MSYSCFG_EXTI_LINE14            14
#define MSYSCFG_EXTI_LINE15            15

/* Compensation Cell Status */
#define MSYSCFG_COMPENSATION_CELL_POWER_DOWN    0
#define MSYSCFG_COMPENSATION_CELL_ENABLE        1


void MSYSCFG_voidSetMemoryMapping(u8 Copy_u8MemoryMappingSelection);
u8 MSYSCFG_voidGetBOOTMode(void);
void MSYSCFG_voidImproveADC1Accuracy(void);
void MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8EXTILINE, u8 Copy_u8PortMap);
u8 MSYSCFG_voidIsCompensationCellReady(void);
void MSYSCFG_voidIsCompensationCellStatus(u8 Copy_u8CellStatus);


#endif