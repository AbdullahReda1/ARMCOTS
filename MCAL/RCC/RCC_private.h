/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        1 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         1 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_RCC_RCC_PRIVATE_H
#define MCAL_RCC_RCC_PRIVATE_H


#define HSI     0
#define HSE     1
#define PLL     2
#define LSI     3
#define LSE     4

#define RTC_ENABLE          1
#define RTC_DISABLE         0

#define NO_CLK              0

#define INTERNAL_PLLI2S         0
#define EXTERNAL_I2S_CKIN       1

#define CLOCK_SECURITY_SYSTEM_ENABLE     1
#define CLOCK_SECURITY_SYSTEM_DISABLE    0

#define MCO1_HSI        0b00
#define MCO1_LSE        0b01
#define MCO1_HSE        0b10
#define MCO1_PLL        0b11

#define MCO2_SYSCLK     0b00
#define MCO2_PLLI2S     0b01
#define MCO2_HSE        0b10
#define MCO2_PLL        0b11

#define NO_DIVISION         0b000
#define DIVISION_BY_2       0b100
#define DIVISION_BY_3       0b101
#define DIVISION_BY_4       0b110
#define DIVISION_BY_5       0b111

#define TRIM_MINUS_600      0b01111
#define TRIM_MINUS_560      0b01110
#define TRIM_MINUS_520      0b01101
#define TRIM_MINUS_480      0b01100
#define TRIM_MINUS_440      0b01011
#define TRIM_MINUS_400      0b01010
#define TRIM_MINUS_360      0b01001
#define TRIM_MINUS_320      0b01000
#define TRIM_MINUS_280      0b00111
#define TRIM_MINUS_240      0b00110
#define TRIM_MINUS_200      0b00101
#define TRIM_MINUS_160      0b00100
#define TRIM_MINUS_120      0b00011
#define TRIM_MINUS_80       0b00010
#define TRIM_MINUS_40       0b00001
#define TRIM_0              0b10000
#define TRIM_PLUS_40        0b10001
#define TRIM_PLUS_80        0b10010
#define TRIM_PLUS_120       0b10011
#define TRIM_PLUS_160       0b10100
#define TRIM_PLUS_200       0b10101
#define TRIM_PLUS_240       0b10110
#define TRIM_PLUS_280       0b10111
#define TRIM_PLUS_320       0b11000
#define TRIM_PLUS_360       0b11001
#define TRIM_PLUS_400       0b11010
#define TRIM_PLUS_440       0b11011
#define TRIM_PLUS_480       0b11100
#define TRIM_PLUS_520       0b11101
#define TRIM_PLUS_560       0b11110
#define TRIM_PLUS_600       0b11111

#define AHB_DEVIDED_BY_1     0
#define AHB_DEVIDED_BY_2     4
#define AHB_DEVIDED_BY_4     5
#define AHB_DEVIDED_BY_8     6
#define AHB_DEVIDED_BY_16    7

#define SYSCLOCK_DEVIDED_BY_1      0
#define SYSCLOCK_DEVIDED_BY_2      8
#define SYSCLOCK_DEVIDED_BY_4      9
#define SYSCLOCK_DEVIDED_BY_8      10
#define SYSCLOCK_DEVIDED_BY_16     11
#define SYSCLOCK_DEVIDED_BY_64     12
#define SYSCLOCK_DEVIDED_BY_128    13
#define SYSCLOCK_DEVIDED_BY_256    14
#define SYSCLOCK_DEVIDED_BY_512    15

#define PLLP_2     0
#define PLLP_4     1
#define PLLP_6     2
#define PLLP_8     3

#define SPREAD_SPECTRUM_MUDULATION_ENABLE   1
#define SPREAD_SPECTRUM_MUDULATION_DISABLE  0

#define CENTER_SPREAD_SPECTRUM_MUDULATION   0
#define DOWN_SPREAD_SPECTRUM_MUDULATION     1

#define TWICE           0
#define FOUR_TIMES      1


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
}RCC_t;

#define RCC_BASE_ADDRESS  0x40023800

#define RCC     ((volatile RCC_t *)RCC_BASE_ADDRESS)


#define CR_HSION                0
#define CR_HSIRDY               1
#define CR_HSITRIM              3
#define CR_HSITRIM0             3
#define CR_HSITRIM1             4
#define CR_HSITRIM2             5
#define CR_HSITRIM3             6
#define CR_HSITRIM4             7
#define CR_HSICAL               8
#define CR_HSICAL0              8
#define CR_HSICAL1              9
#define CR_HSICAL2              10
#define CR_HSICAL3              11
#define CR_HSICAL4              12
#define CR_HSICAL5              13
#define CR_HSICAL6              14
#define CR_HSICAL7              15
#define CR_HSEON                16
#define CR_HSERDY               17
#define CR_HSEBYP               18
#define CR_CSSON                19
#define CR_PLLON                24
#define CR_PLLRDY               25
#define CR_PLLI2SON             26
#define CR_PLLI2SRDY            27

#define PLLCFGR_PLLM            0
#define PLLCFGR_PLLM0           0
#define PLLCFGR_PLLM1           1
#define PLLCFGR_PLLM2           2
#define PLLCFGR_PLLM3           3
#define PLLCFGR_PLLM4           4
#define PLLCFGR_PLLM5           5
#define PLLCFGR_PLLN            6
#define PLLCFGR_PLLN0           6
#define PLLCFGR_PLLN1           7
#define PLLCFGR_PLLN2           8
#define PLLCFGR_PLLN3           9
#define PLLCFGR_PLLN4           10
#define PLLCFGR_PLLN5           11
#define PLLCFGR_PLLN6           12
#define PLLCFGR_PLLN7           13
#define PLLCFGR_PLLN8           14
#define PLLCFGR_PLLP            16
#define PLLCFGR_PLLP0           16
#define PLLCFGR_PLLP1           17
#define PLLCFGR_PLLSRC          22
#define PLLCFGR_PLLQ            24
#define PLLCFGR_PLLQ0           24
#define PLLCFGR_PLLQ1           25
#define PLLCFGR_PLLQ2           26
#define PLLCFGR_PLLQ3           27

#define CFGR_SW0                0
#define CFGR_SW1                1
#define CFGR_SWS0               2
#define CFGR_SWS1               3
#define CFGR_HPRE               4
#define CFGR_HPRE0              4
#define CFGR_HPRE1              5   
#define CFGR_HPRE2              6
#define CFGR_HPRE3              7
#define CFGR_HPPRE1             10
#define CFGR_HPPRE10            10
#define CFGR_HPPRE11            11
#define CFGR_HPPRE12            12
#define CFGR_HPPRE2             13
#define CFGR_HPPRE20            13
#define CFGR_HPPRE21            14
#define CFGR_HPPRE22            15
#define CFGR_RTCPRE             16
#define CFGR_RTCPRE0            16
#define CFGR_RTCPRE1            17
#define CFGR_RTCPRE2            18
#define CFGR_RTCPRE3            19
#define CFGR_RTCPRE4            20
#define CFGR_MCO1               21
#define CFGR_MCO10              21
#define CFGR_MCO11              22
#define CFGR_I2SSCR             23
#define CFGR_MCO1PRE            24
#define CFGR_MCO1PRE0           24
#define CFGR_MCO1PRE1           25
#define CFGR_MCO1PRE2           26
#define CFGR_MCO2PRE            27
#define CFGR_MCO2PRE0           27
#define CFGR_MCO2PRE1           28
#define CFGR_MCO2PRE2           29
#define CFGR_MCO2               30
#define CFGR_MCO20              30
#define CFGR_MCO21              31

#define CIR_LSIRDYF             0
#define CIR_LSERDYF             1
#define CIR_HSIRDYF             2
#define CIR_HSERDYF             3   
#define CIR_PLLRDYF             4
#define CIR_PLLI2SRDYF          5
#define CIR_CSSF                7
#define CIR_LSIRDYIE            8
#define CIR_LSERDYIE            9
#define CIR_HSIRDYIE            10
#define CIR_HSERDYIE            11
#define CIR_PLLRDYIE            12
#define CIR_PLLI2SRDYIE         13
#define CIR_LSIRDYC             16
#define CIR_LSERDYC             17
#define CIR_HSIRDYC             18
#define CIR_HSERDYC             19
#define CIR_PLLRDYC             20
#define CIR_PLLI2SRDYC          21
#define CIR_CSSC                23

#define AHB1RSTR_GPIOARST       0
#define AHB1RSTR_GPIOBRST       1
#define AHB1RSTR_GPIOCRST       2
#define AHB1RSTR_GPIODRST       3
#define AHB1RSTR_GPIOERST       4
#define AHB1RSTR_GPIOHRST       7
#define AHB1RSTR_CRCRST         12
#define AHB1RSTR_DMA1RST        21
#define AHB1RSTR_DMA2RST        22

#define AHB2RSTR_OTGFSRST       7

#define APB1RSTR_TIM2RST        0
#define APB1RSTR_TIM3RST        1
#define APB1RSTR_TIM4RST        2
#define APB1RSTR_TIM5RST        3
#define APB1RSTR_WWDGRST        11
#define APB1RSTR_SPI2RST        14
#define APB1RSTR_SPI3RST        15
#define APB1RSTR_USART2RST      17
#define APB1RSTR_I2C1RST        21
#define APB1RSTR_I2C2RST        22
#define APB1RSTR_I2C3RST        23
#define APB1RSTR_PWRRST         28

#define APB2RSTR_TIM1RST        0
#define APB2RSTR_USART1RST      4
#define APB2RSTR_USART6RST      5
#define APB2RSTR_ADC1RST        8
#define APB2RSTR_SDIORST        11
#define APB2RSTR_SPI1RST        12
#define APB2RSTR_SPI4RST        13
#define APB2RSTR_SYSCFGRST      14
#define APB2RSTR_TIM9RST        16
#define APB2RSTR_TIM10RST       17
#define APB2RSTR_TIM11RST       18

#define AHB1ENR_GPIOAEN         0
#define AHB1ENR_GPIOBEN         1
#define AHB1ENR_GPIOCEN         2
#define AHB1ENR_GPIODEN         3
#define AHB1ENR_GPIOEEN         4
#define AHB1ENR_GPIOHEN         7
#define AHB1ENR_CRCEN           12
#define AHB1ENR_DMA1EN          21
#define AHB1ENR_DMA2EN          22

#define AHB2ENR_OTGFSEN         7

#define APB1ENR_TIM2EN          0
#define APB1ENR_TIM3EN          1
#define APB1ENR_TIM4EN          2
#define APB1ENR_TIM5EN          3
#define APB1ENR_WWDGEN          11
#define APB1ENR_SPI2EN          14
#define APB1ENR_SPI3EN          15
#define APB1ENR_USART2EN        17
#define APB1ENR_I2C1EN          21
#define APB1ENR_I2C2EN          22
#define APB1ENR_I2C3EN          23
#define APB1ENR_PWREN           28

#define APB2ENR_TIM1EN          0
#define APB2ENR_USART1EN        4
#define APB2ENR_USART6EN        5
#define APB2ENR_ADC1EN          8
#define APB2ENR_SDIOEN          11
#define APB2ENR_SPI1EN          12
#define APB2ENR_SPI4EN          13
#define APB2ENR_SYSCFGEN        14
#define APB2ENR_TIM9EN          16
#define APB2ENR_TIM10EN         17
#define APB2ENR_TIM11EN         18

#define AHB1LPENR_GPIOALPEN     0
#define AHB1LPENR_GPIOBLPEN     1
#define AHB1LPENR_GPIOCLPEN     2
#define AHB1LPENR_GPIODLPEN     3
#define AHB1LPENR_GPIOELPEN     4
#define AHB1LPENR_GPIOHLPEN     7
#define AHB1LPENR_CRCLPEN       12
#define AHB1LPENR_FLITFLPEN     15
#define AHB1LPENR_SRAM1LPEN     16
#define AHB1LPENR_DMA1LPEN      21
#define AHB1LPENR_DMA2LPEN      22

#define AHB2LPENR_OTGFSLPEN     7

#define APB1LPENR_TIM2LPEN      0
#define APB1LPENR_TIM3LPEN      1
#define APB1LPENR_TIM4LPEN      2
#define APB1LPENR_TIM5LPEN      3
#define APB1LPENR_WWDGLPEN      11
#define APB1LPENR_SPI2LPEN      14
#define APB1LPENR_SPI3LPEN      15
#define APB1LPENR_USART2LPEN    17
#define APB1LPENR_I2C1LPEN      21
#define APB1LPENR_I2C2LPEN      22
#define APB1LPENR_I2C3LPEN      23
#define APB1LPENR_PWRLPEN       28

#define APB2LPENR_TIM1LPEN      0
#define APB2LPENR_USART1LPEN    4
#define APB2LPENR_USART6LPEN    5
#define APB2LPENR_ADC1LPEN      8
#define APB2LPENR_SDIOLPEN      11
#define APB2LPENR_SPI1LPEN      12
#define APB2LPENR_SPI4LPEN      13
#define APB2LPENR_SYSCFGLPEN    14
#define APB2LPENR_TIM9LPEN      16
#define APB2LPENR_TIM10LPEN     17
#define APB2LPENR_TIM11LPEN     18

#define BDCR_LSEON              0
#define BDCR_LSERDY             1
#define BDCR_LSEBYP             2
#define BDCR_RTCSEL             8
#define BDCR_RTCSEL0            8
#define BDCR_RTCSEL1            9
#define BDCR_RTCEN              15
#define BDCR_BDRST              16

#define CSR_LSION               0
#define CSR_LSIRDY              1
#define CSR_RMVF                24
#define CSR_BORRSTF             25
#define CSR_PINRSTF             26
#define CSR_PORRSTF             27
#define CSR_SFTRSTF             28
#define CSR_IWDGRSTF            29
#define CSR_WWDGRSTF            30
#define CSR_LPWRRSTF            31

#define SSCGR_MODPER            0
#define SSCGR_MODPER0           0
#define SSCGR_MODPER1           1
#define SSCGR_MODPER2           2
#define SSCGR_MODPER3           3
#define SSCGR_MODPER4           4   
#define SSCGR_MODPER5           5
#define SSCGR_MODPER6           6
#define SSCGR_MODPER7           7
#define SSCGR_MODPER8           8
#define SSCGR_MODPER9           9
#define SSCGR_MODPER10          10
#define SSCGR_MODPER11          11
#define SSCGR_MODPER12          12
#define SSCGR_INCSTEP           13
#define SSCGR_INCSTEP0          13
#define SSCGR_INCSTEP1          14
#define SSCGR_INCSTEP2          15
#define SSCGR_INCSTEP3          16
#define SSCGR_INCSTEP4          17
#define SSCGR_INCSTEP5          18
#define SSCGR_INCSTEP6          19
#define SSCGR_INCSTEP7          20
#define SSCGR_INCSTEP8          21
#define SSCGR_INCSTEP9          22
#define SSCGR_INCSTEP10         23
#define SSCGR_INCSTEP11         24
#define SSCGR_INCSTEP12         25
#define SSCGR_INCSTEP13         26
#define SSCGR_INCSTEP14         27
#define SSCGR_SPREADSEL         30
#define SSCGR_SSCGEN            31

#define PLLI2SCFGR_PLLI2SN      6
#define PLLI2SCFGR_PLLI2SN0     6
#define PLLI2SCFGR_PLLI2SN1     7
#define PLLI2SCFGR_PLLI2SN2     8
#define PLLI2SCFGR_PLLI2SN3     9
#define PLLI2SCFGR_PLLI2SN4     10
#define PLLI2SCFGR_PLLI2SN5     11
#define PLLI2SCFGR_PLLI2SN6     12
#define PLLI2SCFGR_PLLI2SN7     13
#define PLLI2SCFGR_PLLI2SN8     14
#define PLLI2SCFGR_PLLI2SR      28
#define PLLI2SCFGR_PLLI2SR0     28
#define PLLI2SCFGR_PLLI2SR1     29
#define PLLI2SCFGR_PLLI2SR2     30

#define DCKCFGR_TIMPRE          24


#endif