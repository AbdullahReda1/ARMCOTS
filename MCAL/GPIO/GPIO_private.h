/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         7 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_GPIO_GPIO_PRIVATE_H
#define MCAL_GPIO_GPIO_PRIVATE_H


#define MGPIO_OUTPUT_MODE_MASK    0b11

#define MGPIO_OUTPUT_TYPE_MASK    0b1

#define MGPIO_OUTPUT_SPEED_MASK   0b11

#define MGPIO_OUTPUT_PULL_MASK    0b11

#define MGPIO_ALTERNATIVE_MASK    0b1111


/**************************** Register Description ******************************/


typedef struct
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
}GPIO_t;

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800

#define GPIOA   ((volatile GPIO_t *)GPIOA_BASE_ADDRESS)
#define GPIOB   ((volatile GPIO_t *)GPIOB_BASE_ADDRESS)
#define GPIOC   ((volatile GPIO_t *)GPIOC_BASE_ADDRESS)


#define MODER_MODER0             0
#define MODER_MODER00            0
#define MODER_MODER01            1
#define MODER_MODER1             2
#define MODER_MODER10            2
#define MODER_MODER11            3
#define MODER_MODER2             4
#define MODER_MODER20            4
#define MODER_MODER21            5
#define MODER_MODER3             6
#define MODER_MODER30            6
#define MODER_MODER31            7
#define MODER_MODER4             8
#define MODER_MODER40            8
#define MODER_MODER41            9
#define MODER_MODER5             10
#define MODER_MODER50            10
#define MODER_MODER51            11
#define MODER_MODER6             12
#define MODER_MODER60            12
#define MODER_MODER61            13
#define MODER_MODER7             14
#define MODER_MODER70            14
#define MODER_MODER71            15
#define MODER_MODER8             16
#define MODER_MODER80            16
#define MODER_MODER81            17
#define MODER_MODER9             18
#define MODER_MODER90            18
#define MODER_MODER91            19
#define MODER_MODER10            20
#define MODER_MODER100           20
#define MODER_MODER101           21
#define MODER_MODER11            22
#define MODER_MODER110           22
#define MODER_MODER111           23
#define MODER_MODER12            24
#define MODER_MODER120           24
#define MODER_MODER121           25
#define MODER_MODER13            26
#define MODER_MODER130           26
#define MODER_MODER131           27
#define MODER_MODER14            28
#define MODER_MODER140           28
#define MODER_MODER141           29
#define MODER_MODER15            30
#define MODER_MODER150           30
#define MODER_MODER151           31

#define OTYPER_OT0               0
#define OTYPER_OT1               1
#define OTYPER_OT2               2
#define OTYPER_OT3               3
#define OTYPER_OT4               4
#define OTYPER_OT5               5
#define OTYPER_OT6               6
#define OTYPER_OT7               7
#define OTYPER_OT8               8
#define OTYPER_OT9               9
#define OTYPER_OT10              10
#define OTYPER_OT11              11
#define OTYPER_OT12              12
#define OTYPER_OT13              13
#define OTYPER_OT14              14
#define OTYPER_OT15              15

#define OSPEEDR_OSPEEDR0         0
#define OSPEEDR_OSPEEDR00        0
#define OSPEEDR_OSPEEDR01        1
#define OSPEEDR_OSPEEDR1         2
#define OSPEEDR_OSPEEDR10        2
#define OSPEEDR_OSPEEDR11        3
#define OSPEEDR_OSPEEDR2         4
#define OSPEEDR_OSPEEDR20        4
#define OSPEEDR_OSPEEDR21        5
#define OSPEEDR_OSPEEDR3         6
#define OSPEEDR_OSPEEDR30        6
#define OSPEEDR_OSPEEDR31        7
#define OSPEEDR_OSPEEDR4         8
#define OSPEEDR_OSPEEDR40        8
#define OSPEEDR_OSPEEDR41        9
#define OSPEEDR_OSPEEDR5         10
#define OSPEEDR_OSPEEDR50        10
#define OSPEEDR_OSPEEDR51        11
#define OSPEEDR_OSPEEDR6         12
#define OSPEEDR_OSPEEDR60        12
#define OSPEEDR_OSPEEDR61        13
#define OSPEEDR_OSPEEDR7         14
#define OSPEEDR_OSPEEDR70        14
#define OSPEEDR_OSPEEDR71        15
#define OSPEEDR_OSPEEDR8         16
#define OSPEEDR_OSPEEDR80        16
#define OSPEEDR_OSPEEDR81        17
#define OSPEEDR_OSPEEDR9         18
#define OSPEEDR_OSPEEDR90        18
#define OSPEEDR_OSPEEDR91        19
#define OSPEEDR_OSPEEDR10        20
#define OSPEEDR_OSPEEDR100       20
#define OSPEEDR_OSPEEDR101       21
#define OSPEEDR_OSPEEDR11        22
#define OSPEEDR_OSPEEDR110       22
#define OSPEEDR_OSPEEDR111       23
#define OSPEEDR_OSPEEDR12        24
#define OSPEEDR_OSPEEDR120       24
#define OSPEEDR_OSPEEDR121       25
#define OSPEEDR_OSPEEDR13        26
#define OSPEEDR_OSPEEDR130       26
#define OSPEEDR_OSPEEDR131       27
#define OSPEEDR_OSPEEDR14        28
#define OSPEEDR_OSPEEDR140       28
#define OSPEEDR_OSPEEDR141       29
#define OSPEEDR_OSPEEDR15        30
#define OSPEEDR_OSPEEDR150       30
#define OSPEEDR_OSPEEDR151       31

#define PUPDR_PUPDR0             0
#define PUPDR_PUPDR00            0
#define PUPDR_PUPDR01            1
#define PUPDR_PUPDR1             2
#define PUPDR_PUPDR10            2
#define PUPDR_PUPDR11            3
#define PUPDR_PUPDR2             4
#define PUPDR_PUPDR20            4
#define PUPDR_PUPDR21            5
#define PUPDR_PUPDR3             6
#define PUPDR_PUPDR30            6
#define PUPDR_PUPDR31            7
#define PUPDR_PUPDR4             8
#define PUPDR_PUPDR40            8
#define PUPDR_PUPDR41            9
#define PUPDR_PUPDR5             10
#define PUPDR_PUPDR50            10
#define PUPDR_PUPDR51            11
#define PUPDR_PUPDR6             12
#define PUPDR_PUPDR60            12
#define PUPDR_PUPDR61            13
#define PUPDR_PUPDR7             14
#define PUPDR_PUPDR70            14
#define PUPDR_PUPDR71            15
#define PUPDR_PUPDR8             16
#define PUPDR_PUPDR80            16
#define PUPDR_PUPDR81            17
#define PUPDR_PUPDR9             18
#define PUPDR_PUPDR90            18
#define PUPDR_PUPDR91            19
#define PUPDR_PUPDR10            20
#define PUPDR_PUPDR100           20
#define PUPDR_PUPDR101           21
#define PUPDR_PUPDR11            22
#define PUPDR_PUPDR110           22
#define PUPDR_PUPDR111           23
#define PUPDR_PUPDR12            24
#define PUPDR_PUPDR120           24
#define PUPDR_PUPDR121           25
#define PUPDR_PUPDR13            26
#define PUPDR_PUPDR130           26
#define PUPDR_PUPDR131           27
#define PUPDR_PUPDR14            28
#define PUPDR_PUPDR140           28
#define PUPDR_PUPDR141           29
#define PUPDR_PUPDR15            30
#define PUPDR_PUPDR150           30
#define PUPDR_PUPDR151           31

#define IDR_IDR0                 0
#define IDR_IDR1                 1
#define IDR_IDR2                 2
#define IDR_IDR3                 3
#define IDR_IDR4                 4
#define IDR_IDR5                 5
#define IDR_IDR6                 6
#define IDR_IDR7                 7
#define IDR_IDR8                 8
#define IDR_IDR9                 9
#define IDR_IDR10                10
#define IDR_IDR11                11
#define IDR_IDR12                12
#define IDR_IDR13                13
#define IDR_IDR14                14
#define IDR_IDR15                15

#define ODR_ODR0                 0
#define ODR_ODR1                 1
#define ODR_ODR2                 2
#define ODR_ODR3                 3
#define ODR_ODR4                 4
#define ODR_ODR5                 5
#define ODR_ODR6                 6
#define ODR_ODR7                 7
#define ODR_ODR8                 8
#define ODR_ODR9                 9
#define ODR_ODR10                10
#define ODR_ODR11                11
#define ODR_ODR12                12
#define ODR_ODR13                13
#define ODR_ODR14                14
#define ODR_ODR15                15

#define BSRR_BS0                 0
#define BSRR_BS1                 1
#define BSRR_BS2                 2
#define BSRR_BS3                 3
#define BSRR_BS4                 4
#define BSRR_BS5                 5
#define BSRR_BS6                 6
#define BSRR_BS7                 7
#define BSRR_BS8                 8
#define BSRR_BS9                 9
#define BSRR_BS10                10
#define BSRR_BS11                11
#define BSRR_BS12                12
#define BSRR_BS13                13
#define BSRR_BS14                14
#define BSRR_BS15                15
#define BSRR_BR0                 16
#define BSRR_BR1                 17
#define BSRR_BR2                 18
#define BSRR_BR3                 19
#define BSRR_BR4                 20
#define BSRR_BR5                 21
#define BSRR_BR6                 22
#define BSRR_BR7                 23
#define BSRR_BR8                 24
#define BSRR_BR9                 25
#define BSRR_BR10                26
#define BSRR_BR11                27
#define BSRR_BR12                28
#define BSRR_BR13                29
#define BSRR_BR14                30
#define BSRR_BR15                31

#define LCKR_LCK0                0
#define LCKR_LCK1                1
#define LCKR_LCK2                2
#define LCKR_LCK3                3
#define LCKR_LCK4                4
#define LCKR_LCK5                5
#define LCKR_LCK6                6
#define LCKR_LCK7                7
#define LCKR_LCK8                8
#define LCKR_LCK9                9
#define LCKR_LCK10               10
#define LCKR_LCK11               11
#define LCKR_LCK12               12
#define LCKR_LCK13               13
#define LCKR_LCK14               14
#define LCKR_LCK15               15
#define LCKR_LCKk                16

#define AFRL_AFRL0               0
#define AFRL_AFRL00              0
#define AFRL_AFRL01              1
#define AFRL_AFRL02              2
#define AFRL_AFRL03              3
#define AFRL_AFRL1               4
#define AFRL_AFRL10              4
#define AFRL_AFRL11              5
#define AFRL_AFRL12              6
#define AFRL_AFRL13              7
#define AFRL_AFRL2               8
#define AFRL_AFRL20              8
#define AFRL_AFRL21              9
#define AFRL_AFRL22              10
#define AFRL_AFRL23              11
#define AFRL_AFRL3               12
#define AFRL_AFRL30              12
#define AFRL_AFRL31              13
#define AFRL_AFRL32              14
#define AFRL_AFRL33              15
#define AFRL_AFRL4               16
#define AFRL_AFRL40              16
#define AFRL_AFRL41              17
#define AFRL_AFRL42              18
#define AFRL_AFRL43              19
#define AFRL_AFRL5               20
#define AFRL_AFRL50              20
#define AFRL_AFRL51              21
#define AFRL_AFRL52              22
#define AFRL_AFRL53              23
#define AFRL_AFRL6               24
#define AFRL_AFRL60              24
#define AFRL_AFRL61              25
#define AFRL_AFRL62              26
#define AFRL_AFRL63              27
#define AFRL_AFRL7               28
#define AFRL_AFRL70              28
#define AFRL_AFRL71              29
#define AFRL_AFRL72              30
#define AFRL_AFRL73              31

#define AFRH_AFRH0               0
#define AFRH_AFRH00              0
#define AFRH_AFRH01              1
#define AFRH_AFRH02              2
#define AFRH_AFRH03              3
#define AFRH_AFRH1               4
#define AFRH_AFRH10              4
#define AFRH_AFRH11              5
#define AFRH_AFRH12              6
#define AFRH_AFRH13              7
#define AFRH_AFRH2               8
#define AFRH_AFRH20              8
#define AFRH_AFRH21              9
#define AFRH_AFRH22              10
#define AFRH_AFRH23              11
#define AFRH_AFRH3               12
#define AFRH_AFRH30              12
#define AFRH_AFRH31              13
#define AFRH_AFRH32              14
#define AFRH_AFRH33              15
#define AFRH_AFRH4               16
#define AFRH_AFRH40              16
#define AFRH_AFRH41              17
#define AFRH_AFRH42              18
#define AFRH_AFRH43              19
#define AFRH_AFRH5               20
#define AFRH_AFRH50              20
#define AFRH_AFRH51              21
#define AFRH_AFRH52              22
#define AFRH_AFRH53              23
#define AFRH_AFRH6               24
#define AFRH_AFRH60              24
#define AFRH_AFRH61              25
#define AFRH_AFRH62              26
#define AFRH_AFRH63              27
#define AFRH_AFRH7               28
#define AFRH_AFRH70              28
#define AFRH_AFRH71              29
#define AFRH_AFRH72              30
#define AFRH_AFRH73              31


#endif