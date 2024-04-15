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


#ifndef MCAL_MPU_MPU_PRIVATE_H
#define MCAL_MPU_MPU_PRIVATE_H


/* do-while loop without a body */
/* In GCC and Clang, asm is typically used, while in ARM's Keil compiler, __asm is commonly used */
#define __DMB()   do { __asm volatile ("dmb" : : : "memory"); } while (0)           // Data Memory Barrier.
#define __DSB()   do { __asm volatile ("dsb" : : : "memory"); } while (0)           // Data Synchronization Barrier.
#define __ISB()   do { __asm volatile ("isb" : : : "memory"); } while (0)           // Instruction Synchronization Barrier.


#define MASK_1_BIT      0b1

#define CLEAR_SDR       0x00

#define ENABLE          1
#define DISABLE         0


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 TYPER;
    volatile u32 CTRL;
    volatile u32 RNR;
    volatile u32 RBAR;
    volatile u32 RASR;
    volatile u32 RBAR_A1;
    volatile u32 RASR_A1;
    volatile u32 RBAR_A2;
    volatile u32 RASR_A2;
    volatile u32 RBAR_A3;
    volatile u32 RASR_A3;
}MPU_t;

#define MPU_BASE_ADDRESS     0xE000ED90

#define MPU     ((volatile MPU_t *)MPU_BASE_ADDRESS)


#define TYPER_SEPARATE      0
#define TYPER_DREGION       8
#define TYPER_DREGION0      8
#define TYPER_DREGION1      9
#define TYPER_DREGION2      10
#define TYPER_DREGION3      11
#define TYPER_DREGION4      12
#define TYPER_DREGION5      13
#define TYPER_DREGION6      14
#define TYPER_DREGION7      15
#define TYPER_IREGION       16
#define TYPER_IREGION0      16
#define TYPER_IREGION1      17
#define TYPER_IREGION2      18
#define TYPER_IREGION3      19
#define TYPER_IREGION4      20
#define TYPER_IREGION5      21
#define TYPER_IREGION6      22
#define TYPER_IREGION7      23

#define CTRL_ENABLE         0
#define CTRL_HFNMIENA       1
#define CTRL_PRIVDEFENA     2

#define RNR_REGION          0
#define RNR_REGION0         0
#define RNR_REGION1         1
#define RNR_REGION2         2
#define RNR_REGION3         3
#define RNR_REGION4         4
#define RNR_REGION5         5
#define RNR_REGION6         6
#define RNR_REGION7         7

#define RBAR_REGION         0
#define RBAR_REGION0        0
#define RBAR_REGION1        1
#define RBAR_REGION2        2
#define RBAR_REGION3        3
#define RBAR_VALID          4
#define RBAR_ADDR           5

#define RASR_ENABLE         0
#define RASR_SIZE           1
#define RASR_SIZE0          1
#define RASR_SIZE1          2
#define RASR_SIZE2          3
#define RASR_SIZE3          4
#define RASR_SIZE4          5
#define RASR_SDR            8
#define RASR_SDR0           8
#define RASR_SDR1           9
#define RASR_SDR2           10
#define RASR_SDR3           11
#define RASR_SDR4           12
#define RASR_SDR5           13
#define RASR_SDR6           14
#define RASR_SDR7           15
#define RASR_B              16
#define RASR_C              17
#define RASR_S              18
#define RASR_TEX            19
#define RASR_TEX0           19
#define RASR_TEX1           20
#define RASR_TEX2           21
#define RASR_AP             24
#define RASR_AP0            24
#define RASR_AP1            25
#define RASR_AP2            26
#define RASR_XN             28


#endif