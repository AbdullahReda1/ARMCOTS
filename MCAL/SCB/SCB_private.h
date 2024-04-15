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


#ifndef MCAL_SCB_SCB_PRIVATE_H
#define MCAL_SCB_SCB_PRIVATE_H


#define MAX_REG_VALUE       32
#define MAX_NIP_VALUE       16
#define SHIFT_28_VALUE      28

#define THREAD_MODE_VAL     0b000000000
#define MAX_OFFSET          1048576

#define VECTOR_KEY          0x05FA


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR1;
    volatile u32 SHPR2;
    volatile u32 SHPR3;
    volatile u32 SHCSR;
    volatile u8  MMFSR;
    volatile u8  BFSR;
    volatile u16 UFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;
    volatile u32 AFSR;
}SCB_t;

#define SCB_ACTLR_ADDRESS    0xE000E008
#define SCB_BASE_ADDRESS     0xE000ED00

#define SCB_ACTLR       *((volatile u32*)SCB_ACTLR_ADDRESS)
#define SCB             ((volatile SCB_t *)SCB_BASE_ADDRESS)


#define ACTLR_DISMCYCINT        0
#define ACTLR_DISDEFWBUF        1
#define ACTLR_DISFOLD           2
#define ACTLR_DISFPCA           8
#define ACTLR_DISOOFP           9

#define CPUID_REVISION          0
#define CPUID_PARTNO            4
#define CPUID_CONSTANT          16
#define CPUID_VARIANT           20
#define CPUID_IMPLEMENTER       24

#define ICSR_VECTACTIVE         0
#define ICSR_VECTACTIVE0        0
#define ICSR_VECTACTIVE1        1
#define ICSR_VECTACTIVE2        2
#define ICSR_VECTACTIVE3        3
#define ICSR_VECTACTIVE4        4
#define ICSR_VECTACTIVE5        5
#define ICSR_VECTACTIVE6        6
#define ICSR_VECTACTIVE7        7
#define ICSR_VECTACTIVE8        8
#define ICSR_RETTOBASE          11
#define ICSR_VECTPENDING        12
#define ICSR_VECTPENDING0       12
#define ICSR_VECTPENDING1       13
#define ICSR_VECTPENDING2       14
#define ICSR_VECTPENDING3       15
#define ICSR_VECTPENDING4       16
#define ICSR_VECTPENDING5       17
#define ICSR_VECTPENDING6       18
#define ICSR_ISRPENDING         22
#define ICSR_PENDSTCLR          25
#define ICSR_PENDSTSET          26
#define ICSR_PENDSVCLR          27
#define ICSR_PENDSVSET          28
#define ICSR_NMIPENDSET         31

#define VTOR_TBLOFF             9
#define VTOR_TBLBASE            29

#define AIRCR_VECTRESET         0
#define AIRCR_VECTCLRACTIVE     1
#define AIRCR_SYSRESETREQ       2
#define AIRCR_PRIGROUP          8
#define AIRCR_PRIGROUP0         8
#define AIRCR_PRIGROUP1         9
#define AIRCR_PRIGROUP2         10
#define AIRCR_ENDIANESS         15
#define AIRCR_VECTKEYSTAT       16
#define AIRCR_VECTKEY           16

#define SCR_SLEEPONEXIT         1
#define SCR_SLEEPDEEP           2
#define SCR_SEVONPEND           4

#define CCR_NONBASETHRDENA      0
#define CCR_USERSETMPEND        1
#define CCR_UNALIGN_TRP         3
#define CCR_DIV_0_TRP           4
#define CCR_BFHFNMIGN           8
#define CCR_STKALIGN            9

#define SHPR1_PRI_4             0
#define SHPR1_PRI_40            0
#define SHPR1_PRI_41            1
#define SHPR1_PRI_42            2
#define SHPR1_PRI_43            3
#define SHPR1_PRI_44            4
#define SHPR1_PRI_45            5
#define SHPR1_PRI_46            6
#define SHPR1_PRI_47            7
#define SHPR1_PRI_5             8
#define SHPR1_PRI_50            8
#define SHPR1_PRI_51            9
#define SHPR1_PRI_52            10
#define SHPR1_PRI_53            11
#define SHPR1_PRI_54            12
#define SHPR1_PRI_55            13
#define SHPR1_PRI_56            14
#define SHPR1_PRI_57            15
#define SHPR1_PRI_6             16
#define SHPR1_PRI_60            16
#define SHPR1_PRI_61            17
#define SHPR1_PRI_62            18
#define SHPR1_PRI_63            19
#define SHPR1_PRI_64            20
#define SHPR1_PRI_65            21
#define SHPR1_PRI_66            22
#define SHPR1_PRI_67            23

#define SHPR2_PRI_11            24
#define SHPR2_PRI_110           24
#define SHPR2_PRI_111           25
#define SHPR2_PRI_112           26
#define SHPR2_PRI_113           27
#define SHPR2_PRI_114           28
#define SHPR2_PRI_115           29
#define SHPR2_PRI_116           30
#define SHPR2_PRI_117           31

#define SHPR3_PRI_14            16
#define SHPR3_PRI_140           16
#define SHPR3_PRI_141           17
#define SHPR3_PRI_142           18
#define SHPR3_PRI_143           19
#define SHPR3_PRI_144           20
#define SHPR3_PRI_145           21
#define SHPR3_PRI_146           22
#define SHPR3_PRI_147           23
#define SHPR3_PRI_15            24
#define SHPR3_PRI_150           24
#define SHPR3_PRI_151           25
#define SHPR3_PRI_152           26
#define SHPR3_PRI_153           27
#define SHPR3_PRI_154           28
#define SHPR3_PRI_155           29
#define SHPR3_PRI_156           30
#define SHPR3_PRI_157           31

#define SHCSR_MEMFAULTACT       0
#define SHCSR_BUSFAULTACT       1
#define SHCSR_USGFAULTACT       3
#define SHCSR_SVCALLACT         7
#define SHCSR_MONITORACT        8
#define SHCSR_PENDSVACT         10
#define SHCSR_SYSTICKACT        11
#define SHCSR_USGFAULTPENDED    12
#define SHCSR_MEMFAULTPENDED    13
#define SHCSR_BUSFAULTPENDED    14
#define SHCSR_SVCALLPENDED      15
#define SHCSR_MEMFAULTENA       16
#define SHCSR_BUSFAULTENA       17
#define SHCSR_USGFAULTENA       18

#define MMFSR_IACCVIOL          0
#define MMFSR_DACCVIOL          1
#define MMFSR_MUNSTKERR         3
#define MMFSR_MSTKERR           4
#define MMFSR_MLSPERR           5
#define MMFSR_MMARVALID         7

#define BFSR_IBUSERR            0
#define BFSR_PRECISERR          1
#define BFSR_IMPRECISERR        2
#define BFSR_UNSTKERR           3
#define BFSR_STKERR             4
#define BFSR_LSPERR             5
#define BFSR_BFARVALID          7

#define UFSR_UNDEFINSTR         0
#define UFSR_INVSTATE           1
#define UFSR_INVPC              2
#define UFSR_NOCP               3
#define UFSR_UNALIGNED          8
#define UFSR_DIVBYZERO          9

#define HFSR_VECTTBL            1
#define HFSR_FORCED             30
#define HFSR_DEBUGE_VT          31

#define MMFAR_MMFAR             0
#define MMFAR_MMFAR0            0
#define MMFAR_MMFAR1            1
#define MMFAR_MMFAR2            2
#define MMFAR_MMFAR3            3
#define MMFAR_MMFAR4            4
#define MMFAR_MMFAR5            5
#define MMFAR_MMFAR6            6
#define MMFAR_MMFAR7            7
#define MMFAR_MMFAR8            8
#define MMFAR_MMFAR9            9
#define MMFAR_MMFAR10           10
#define MMFAR_MMFAR11           11
#define MMFAR_MMFAR12           12
#define MMFAR_MMFAR13           13
#define MMFAR_MMFAR14           14
#define MMFAR_MMFAR15           15
#define MMFAR_MMFAR16           16
#define MMFAR_MMFAR17           17
#define MMFAR_MMFAR18           18
#define MMFAR_MMFAR19           19
#define MMFAR_MMFAR20           20
#define MMFAR_MMFAR21           21
#define MMFAR_MMFAR22           22
#define MMFAR_MMFAR23           23
#define MMFAR_MMFAR24           24
#define MMFAR_MMFAR25           25
#define MMFAR_MMFAR26           26
#define MMFAR_MMFAR27           27
#define MMFAR_MMFAR28           28
#define MMFAR_MMFAR29           29
#define MMFAR_MMFAR30           30
#define MMFAR_MMFAR31           31

#define BFAR_BFAR               0
#define BFAR_BFAR0              0
#define BFAR_BFAR1              1
#define BFAR_BFAR2              2
#define BFAR_BFAR3              3
#define BFAR_BFAR4              4
#define BFAR_BFAR5              5
#define BFAR_BFAR6              6
#define BFAR_BFAR7              7
#define BFAR_BFAR8              8
#define BFAR_BFAR9              9
#define BFAR_BFAR10             10
#define BFAR_BFAR11             11
#define BFAR_BFAR12             12
#define BFAR_BFAR13             13
#define BFAR_BFAR14             14
#define BFAR_BFAR15             15
#define BFAR_BFAR16             16
#define BFAR_BFAR17             17
#define BFAR_BFAR18             18
#define BFAR_BFAR19             19
#define BFAR_BFAR20             20
#define BFAR_BFAR21             21
#define BFAR_BFAR22             22
#define BFAR_BFAR23             23
#define BFAR_BFAR24             24
#define BFAR_BFAR25             25
#define BFAR_BFAR26             26
#define BFAR_BFAR27             27
#define BFAR_BFAR28             28
#define BFAR_BFAR29             29
#define BFAR_BFAR30             30
#define BFAR_BFAR31             31

#define AFSR_IMPDEF             0
#define AFSR_IMPDEF0            0
#define AFSR_IMPDEF1            1
#define AFSR_IMPDEF2            2
#define AFSR_IMPDEF3            3
#define AFSR_IMPDEF4            4
#define AFSR_IMPDEF5            5
#define AFSR_IMPDEF6            6
#define AFSR_IMPDEF7            7
#define AFSR_IMPDEF8            8
#define AFSR_IMPDEF9            9
#define AFSR_IMPDEF10           10
#define AFSR_IMPDEF11           11
#define AFSR_IMPDEF12           12
#define AFSR_IMPDEF13           13
#define AFSR_IMPDEF14           14
#define AFSR_IMPDEF15           15
#define AFSR_IMPDEF16           16
#define AFSR_IMPDEF17           17
#define AFSR_IMPDEF18           18
#define AFSR_IMPDEF19           19
#define AFSR_IMPDEF20           20
#define AFSR_IMPDEF21           21
#define AFSR_IMPDEF22           22
#define AFSR_IMPDEF23           23
#define AFSR_IMPDEF24           24
#define AFSR_IMPDEF25           25
#define AFSR_IMPDEF26           26
#define AFSR_IMPDEF27           27
#define AFSR_IMPDEF28           28
#define AFSR_IMPDEF29           29
#define AFSR_IMPDEF30           30
#define AFSR_IMPDEF31           31


#endif