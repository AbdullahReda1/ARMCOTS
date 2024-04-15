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


#ifndef MCAL_SYSCFG_SYSCFG_PRIVATE_H
#define MCAL_SYSCFG_SYSCFG_PRIVATE_H


#define     PORT_MAP_MASK       0b1111


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 RESERVED[2];
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG_BASE_ADDRESS     0x40013800

#define SYSCFG     ((volatile SYSCFG_t *)SYSCFG_BASE_ADDRESS)


#define MEMRMP_MEM_MODE     0
#define MEMRMP_MEM_MODE0    0
#define MEMRMP_MEM_MODE1    1

#define PMC_ADC1DC2         16

#define EXTICR1_EXTI0       0
#define EXTICR1_EXTI00      0
#define EXTICR1_EXTI01      1
#define EXTICR1_EXTI02      2
#define EXTICR1_EXTI03      3
#define EXTICR1_EXTI1       4
#define EXTICR1_EXTI10      4
#define EXTICR1_EXTI11      5
#define EXTICR1_EXTI12      6
#define EXTICR1_EXTI13      7
#define EXTICR1_EXTI2       8
#define EXTICR1_EXTI20      8
#define EXTICR1_EXTI21      9
#define EXTICR1_EXTI22      10
#define EXTICR1_EXTI23      11
#define EXTICR1_EXTI3       12
#define EXTICR1_EXTI30      12
#define EXTICR1_EXTI31      13
#define EXTICR1_EXTI32      14
#define EXTICR1_EXTI33      15

#define EXTICR2_EXTI4       0
#define EXTICR2_EXTI40      0
#define EXTICR2_EXTI41      1
#define EXTICR2_EXTI42      2
#define EXTICR2_EXTI43      3
#define EXTICR2_EXTI5       4
#define EXTICR2_EXTI50      4
#define EXTICR2_EXTI51      5
#define EXTICR2_EXTI52      6
#define EXTICR2_EXTI53      7
#define EXTICR2_EXTI6       8
#define EXTICR2_EXTI60      8
#define EXTICR2_EXTI61      9
#define EXTICR2_EXTI62      10
#define EXTICR2_EXTI63      11
#define EXTICR2_EXTI7       12
#define EXTICR2_EXTI70      12
#define EXTICR2_EXTI71      13
#define EXTICR2_EXTI72      14
#define EXTICR2_EXTI73      15

#define EXTICR3_EXTI8       0
#define EXTICR3_EXTI80      0
#define EXTICR3_EXTI81      1
#define EXTICR3_EXTI82      2
#define EXTICR3_EXTI83      3
#define EXTICR3_EXTI9       4
#define EXTICR3_EXTI90      4
#define EXTICR3_EXTI91      5
#define EXTICR3_EXTI92      6
#define EXTICR3_EXTI93      7
#define EXTICR3_EXTI10      8
#define EXTICR3_EXTI100     8
#define EXTICR3_EXTI101     9
#define EXTICR3_EXTI102     10
#define EXTICR3_EXTI103     11
#define EXTICR3_EXTI11      12
#define EXTICR3_EXTI110     12
#define EXTICR3_EXTI111     13
#define EXTICR3_EXTI112     14
#define EXTICR3_EXTI113     15

#define EXTICR4_EXTI12      0
#define EXTICR4_EXTI120     0
#define EXTICR4_EXTI121     1
#define EXTICR4_EXTI122     2
#define EXTICR4_EXTI123     3
#define EXTICR4_EXTI13      4
#define EXTICR4_EXTI130     4
#define EXTICR4_EXTI131     5
#define EXTICR4_EXTI132     6
#define EXTICR4_EXTI133     7
#define EXTICR4_EXTI14      8
#define EXTICR4_EXTI140     8
#define EXTICR4_EXTI141     9
#define EXTICR4_EXTI142     10
#define EXTICR4_EXTI143     11
#define EXTICR4_EXTI15      12
#define EXTICR4_EXTI150     12
#define EXTICR4_EXTI151     13
#define EXTICR4_EXTI152     14
#define EXTICR4_EXTI153     15

#define CMPCR_CMP_PD        0
#define CMPCR_READY         8


#endif