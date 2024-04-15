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


#ifndef MCAL_EXTI_EXTI_PRIVATE_H
#define MCAL_EXTI_EXTI_PRIVATE_H


#define RISING_EDGE       0
#define FALLING_EDGE      1
#define ON_CHANGE         2

#define LINE0			  0
#define LINE1             1
#define LINE2             2
#define LINE3             3
#define LINE4             4
#define LINE5             5
#define LINE6             6
#define LINE7             7
#define LINE8             8
#define LINE9             9
#define LINE10            10
#define LINE11            11
#define LINE12            12
#define LINE13            13
#define LINE14            14
#define LINE15            15

#define HIGH              1
#define LOW               0


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI_BASE_ADDRESS   0x40013C00

#define EXTI     ((volatile EXTI_t *)EXTI_BASE_ADDRESS)


#define IMR_MR0         0
#define IMR_MR1         1
#define IMR_MR2         2
#define IMR_MR3         3
#define IMR_MR4         4
#define IMR_MR5         5
#define IMR_MR6         6
#define IMR_MR7         7
#define IMR_MR8         8
#define IMR_MR9         9
#define IMR_MR10        10
#define IMR_MR11        11
#define IMR_MR12        12
#define IMR_MR13        13
#define IMR_MR14        14
#define IMR_MR15        15
#define IMR_MR16        16
#define IMR_MR17        17
#define IMR_MR18        18
#define IMR_MR21        21
#define IMR_MR22        22

#define EMR_MR0         0
#define EMR_MR1         1
#define EMR_MR2         2
#define EMR_MR3         3
#define EMR_MR4         4
#define EMR_MR5         5
#define EMR_MR6         6
#define EMR_MR7         7
#define EMR_MR8         8
#define EMR_MR9         9
#define EMR_MR10        10
#define EMR_MR11        11
#define EMR_MR12        12
#define EMR_MR13        13
#define EMR_MR14        14
#define EMR_MR15        15
#define EMR_MR16        16
#define EMR_MR17        17
#define EMR_MR18        18
#define EMR_MR21        21
#define EMR_MR22        22

#define RTSR_TR0        0
#define RTSR_TR1        1
#define RTSR_TR2        2
#define RTSR_TR3        3
#define RTSR_TR4        4
#define RTSR_TR5        5
#define RTSR_TR6        6
#define RTSR_TR7        7
#define RTSR_TR8        8
#define RTSR_TR9        9
#define RTSR_TR10       10
#define RTSR_TR11       11
#define RTSR_TR12       12
#define RTSR_TR13       13
#define RTSR_TR14       14
#define RTSR_TR15       15
#define RTSR_TR16       16
#define RTSR_TR17       17
#define RTSR_TR18       18
#define RTSR_TR21       21
#define RTSR_TR22       22

#define FTSR_TR0        0
#define FTSR_TR1        1
#define FTSR_TR2        2
#define FTSR_TR3        3
#define FTSR_TR4        4
#define FTSR_TR5        5
#define FTSR_TR6        6
#define FTSR_TR7        7
#define FTSR_TR8        8
#define FTSR_TR9        9
#define FTSR_TR10       10
#define FTSR_TR11       11
#define FTSR_TR12       12
#define FTSR_TR13       13
#define FTSR_TR14       14
#define FTSR_TR15       15
#define FTSR_TR16       16
#define FTSR_TR17       17
#define FTSR_TR18       18
#define FTSR_TR21       21
#define FTSR_TR22       22

#define SWIER_SWIER0    0
#define SWIER_SWIER1    1
#define SWIER_SWIER2    2
#define SWIER_SWIER3    3
#define SWIER_SWIER4    4
#define SWIER_SWIER5    5
#define SWIER_SWIER6    6
#define SWIER_SWIER7    7
#define SWIER_SWIER8    8
#define SWIER_SWIER9    9
#define SWIER_SWIER10   10
#define SWIER_SWIER11   11
#define SWIER_SWIER12   12
#define SWIER_SWIER13   13
#define SWIER_SWIER14   14
#define SWIER_SWIER15   15
#define SWIER_SWIER16   16
#define SWIER_SWIER17   17
#define SWIER_SWIER18   18
#define SWIER_SWIER21   21
#define SWIER_SWIER22   22

#define PR_PR0          0
#define PR_PR1          1
#define PR_PR2          2
#define PR_PR3          3
#define PR_PR4          4
#define PR_PR5          5
#define PR_PR6          6
#define PR_PR7          7
#define PR_PR8          8
#define PR_PR9          9
#define PR_PR10         10
#define PR_PR11         11
#define PR_PR12         12
#define PR_PR13         13
#define PR_PR14         14
#define PR_PR15         15
#define PR_PR16         16
#define PR_PR17         17
#define PR_PR18         18
#define PR_PR21         21
#define PR_PR22         22


#endif