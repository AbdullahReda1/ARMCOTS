/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        28 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         28 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#ifndef MCAL_ADC_ADC_PRIVATE_H
#define MCAL_ADC_ADC_PRIVATE_H


#define MASK_1_BIT             0b1
#define MASK_2_BIT             0b11
#define MASK_3_BIT             0b111
#define MASK_4_BIT             0b1111
#define MASK_5_BIT             0b11111
#define MASK_12_BIT            0xFFF

#define ENABLE_INTERRUPT       1
#define DISABLE_INTERRUPT      0

#define START_CONVERSION       1
#define RESET_CONVERSION       0

#define ENABLE_ADC             1
#define DISABLE_ADC            0

#define MADC_PCLK2_DIVIDED_BY_2      0b00
#define MADC_PCLK2_DIVIDED_BY_4      0b01
#define MADC_PCLK2_DIVIDED_BY_6      0b10
#define MADC_PCLK2_DIVIDED_BY_8      0b11

#define MADC_12_BIT_RESOLUTION       0b00
#define MADC_10_BIT_RESOLUTION       0b01
#define MADC_08_BIT_RESOLUTION       0b10
#define MADC_06_BIT_RESOLUTION       0b11

#define MADC_RIGHT_ALIGNMENT         0
#define MADC_LEFT_ALIGNMENT          1

#define MADC_ENABLE_INTERRUPT        1
#define MADC_DISABLE_INTERRUPT       0

#define MADC_ON                      1
#define MADC_OFF                     0


/**************************** Register Description ******************************/


typedef struct
{
    volatile u32 SR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SMPR1;
    volatile u32 SMPR2;
    volatile u32 JOFR1;
    volatile u32 JOFR2;
    volatile u32 JOFR3;
    volatile u32 JOFR4;
    volatile u32 HTR;
    volatile u32 LTR;
    volatile u32 SQR1;
    volatile u32 SQR2;
    volatile u32 SQR3;
    volatile u32 JSQR;
    volatile u32 JDR1;
    volatile u32 JDR2;
    volatile u32 JDR3;
    volatile u32 JDR4;
    volatile u32 DR;
}ADC_t;

#define ADC1_BASE_ADDRESS         0x40012000
#define COMMON_CONTROL_OFFSET     0x300
#define ADC_CCR_ADDRESS_OFFSET    0x04
#define CCR_BASE_ADDRESS          (ADC1_BASE_ADDRESS + COMMON_CONTROL_OFFSET + ADC_CCR_ADDRESS_OFFSET)

#define ADC1        ((volatile ADC_t *)ADC1_BASE_ADDRESS)

#define ADC_CCR     (*(volatile u32 *)CCR_BASE_ADDRESS)


#define SR_AWD          0
#define SR_EOC          1
#define SR_JEOC         2
#define SR_JSTRT        3
#define SR_STRT         4
#define SR_OVR          5

#define CR1_AWDCH       0
#define CR1_AWDCH0      0
#define CR1_AWDCH1      1
#define CR1_AWDCH2      2
#define CR1_AWDCH3      3
#define CR1_AWDCH4      4
#define CR1_EOCIE       5
#define CR1_AWDIE       6
#define CR1_JEOCIE      7
#define CR1_SCAN        8
#define CR1_AWDSGL      9
#define CR1_JAUTO       10
#define CR1_DISCEN      11
#define CR1_JDISCEN     12
#define CR1_DISCNUM     13
#define CR1_DISCNUM0    13
#define CR1_DISCNUM1    14
#define CR1_DISCNUM2    15
#define CR1_JAWDEN      22
#define CR1_AWDEN       23
#define CR1_RES         24
#define CR1_RES0        24
#define CR1_RES1        25
#define CR1_OVRIE       26

#define CR2_ADON        0
#define CR2_CONT        1
#define CR2_DMA         8
#define CR2_DDS         9
#define CR2_EOCS        10
#define CR2_ALIGN       11
#define CR2_JEXTSEL     16
#define CR2_JEXTSEL0    16
#define CR2_JEXTSEL1    17
#define CR2_JEXTSEL2    18
#define CR2_JEXTSEL3    19
#define CR2_JEXTEN      20
#define CR2_JEXTEN0     20
#define CR2_JEXTEN1     21
#define CR2_JSWSTART    22
#define CR2_EXTSEL      24
#define CR2_EXTSEL0     24
#define CR2_EXTSEL1     25
#define CR2_EXTSEL2     26
#define CR2_EXTSEL3     27
#define CR2_EXTEN       28
#define CR2_EXTEN0      28
#define CR2_EXTEN1      29
#define CR2_SWSTART     30

#define SMPR1_SMP10      0
#define SMPR1_SMP11      3
#define SMPR1_SMP12      6
#define SMPR1_SMP13      9
#define SMPR1_SMP14      12
#define SMPR1_SMP15      15
#define SMPR1_SMP16      18
#define SMPR1_SMP17      21
#define SMPR1_SMP18      24

#define SMPR2_SMP0       0
#define SMPR2_SMP1       3
#define SMPR2_SMP2       6
#define SMPR2_SMP3       9
#define SMPR2_SMP4       12
#define SMPR2_SMP5       15
#define SMPR2_SMP6       18
#define SMPR2_SMP7       21
#define SMPR2_SMP8       24
#define SMPR2_SMP9       27

#define JOFR1_JOFFSET    0
#define JOFR1_JOFFSET0   0
#define JOFR1_JOFFSET11  11

#define JOFR2_JOFFSET    0
#define JOFR2_JOFFSET0   0
#define JOFR2_JOFFSET11  11

#define JOFR3_JOFFSET    0
#define JOFR3_JOFFSET0   0
#define JOFR3_JOFFSET11  11

#define JOFR4_JOFFSET    0
#define JOFR4_JOFFSET0   0
#define JOFR4_JOFFSET11  11

#define HTR_HT           0
#define HTR_HT0          0
#define HTR_HT11         11

#define LTR_LT           0
#define LTR_LT0          0
#define LTR_LT11         11

#define SQR1_SQ13        0
#define SQR1_SQ14        5
#define SQR1_SQ15        10
#define SQR1_SQ16        15
#define SQR1_L           20

#define SQR2_SQ7         0
#define SQR2_SQ8         5
#define SQR2_SQ9         10
#define SQR2_SQ10        15 
#define SQR2_SQ11        20
#define SQR2_SQ12        25

#define SQR3_SQ1          0
#define SQR3_SQ2          5
#define SQR3_SQ3          10
#define SQR3_SQ4          15
#define SQR3_SQ5          20
#define SQR3_SQ6          25

#define JSQR_JSQ1         0
#define JSQR_JSQ2         5
#define JSQR_JSQ3         10
#define JSQR_JSQ4         15
#define JSQR_JL           20

#define JDR1_JDATA        0
#define JDR1_JDATA0       0
#define JDR1_JDATA15      15

#define JDR2_JDATA        0
#define JDR2_JDATA0       0
#define JDR2_JDATA15      15

#define JDR3_JDATA        0
#define JDR3_JDATA0       0
#define JDR3_JDATA15      15

#define JDR4_JDATA        0
#define JDR4_JDATA0       0
#define JDR4_JDATA15      15

#define DR_DATA           0
#define DR_DATA0          0
#define DR_DATA15         15

#define CCR_ADCPRE        16
#define CCR_ADCPRE0       16
#define CCR_ADCPRE1       17
#define CCR_VBATE         22
#define CCR_TSVREFE       23


#endif