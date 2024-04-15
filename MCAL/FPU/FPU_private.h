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


#ifndef MCAL_FPU_FPU_PRIVATE_H
#define MCAL_FPU_FPU_PRIVATE_H


static void FPU_ExceptionHandler(u32 lr, u32 sp);


/* do-while loop without a body */
/* In GCC and Clang, asm is typically used, while in ARM's Keil compiler, __asm is commonly used */

#define __DMB()                     do { __asm volatile ("dmb" : : : "memory"); } while (0)         // Data Memory Barrier.
#define __DSB()                     do { __asm volatile ("dsb" : : : "memory"); } while (0)         // Data Synchronization Barrier.
#define __ISB()                     do { __asm volatile ("isb" : : : "memory"); } while (0)         // Instruction Synchronization Barrier.

/* Macro for setting & getting the FPSCR - not maped - register or PSP or SP or LR with the given value */
#define __get_FPSCR()               ({ u32 __regfpscr; __asm volatile ("vmrs %0, fpscr\n" : "=r" (__regfpscr)); __regfpscr; })
#define __set_FPSCR(fpscr_val)      do { __asm volatile ("vmrs r0, fpscr\n" "orr r0, r0, %0\n" "vmsr fpscr, r0\n" : : "r" (fpscr_val) : "memory"); } while (0)
#define __get_PSP()                 ({ u32 __regpsp; __asm volatile ("MRS %0, psp\n" : "=r" (__regpsp)); __regpsp; })
#define __get_SP()                  ({ u32 __regsp; __asm volatile ("MRS %0, sp\n" : "=r" (__regsp)); __regsp; })
#define __set_SP(sp_val)            do { __asm volatile ("MSR sp, %0\n" : : "r" (sp_val) : "memory"); } while (0)
#define __get_LR()                  ({ u32 __reglr; __asm volatile ("MOV %0, lr\n" : "=r" (__reglr)); __reglr; })
#define __set_LR(lr_val)            do { __asm volatile ("MOV lr, %0\n" : : "r" (lr_val) : "memory"); } while (0)

#define __IO                        volatile

#define ACCESS_DENIED               0b0000
#define PRIVILEGED_ACCESS_ONLY      0b0101
#define FULL_ACCESS                 0b1111

#define USER_PRIVILEGED             0b0
#define USER_NOT_PRIVILEGED         0b1

#define THREAD_MODE_OFF             0b0
#define THREAD_MODE_ON              0b1

#define DISABLE_FAULTS_HANDLER      0b00000
#define ENABLE_FAULTS_HANDLER       0b10111

#define NO_FLOATING_POINT_REGISTER_SAVING                   0
#define LAZY_FLOATING_POINT_REGISTER_SAVE_RESTORE           1
#define AUTOMATIC_FLOATING_POINT_REGISTER_SAVE_RESTORE      2


/**************************** Register Description ******************************/


typedef struct 
{
    volatile u32 RESERVED;
    volatile u32 FPCCR;
    volatile u32 FPCAR;
    volatile u32 FPDSCR;
}FPU_t;

#define SCB_BASE_ADDRESS     0xE000ED00
#define FPU_BASE_ADDRESS     0xE000EF30

//      FPSCR           :  Not Mapped Register.
#define FPU_CPACR       *((volatile u32*)(SCB_BASE_ADDRESS + 0x88))
#define FPU             ((volatile FPU_t *)FPU_BASE_ADDRESS)


#define CPACR_CP10          20
#define CPACR_CP11          22

#define FPCCR_LSPACT        0
#define FPCCR_USER          1
#define FPCCR_THREAD        3
#define FPCCR_HFRDY         4
#define FPCCR_MMRDY         5
#define FPCCR_BFRDY         6
#define FPCCR_MONRDY        8
#define FPCCR_LSPEN         30
#define FPCCR_ASPEN         31

#define FPCAR_ADDRESS       3
#define FPCAR_ADDRESS3      3
#define FPCAR_ADDRESS31     31

#define FPSCR_IOC           0
#define FPSCR_DZC           1
#define FPSCR_OFC           2
#define FPSCR_UFC           3
#define FPSCR_IXC           4
#define FPSCR_IDC           7
#define FPSCR_RMODE         22
#define FPSCR_FZ            24
#define FPSCR_DN            25
#define FPSCR_AHP           26
#define FPSCR_V             28
#define FPSCR_C             29
#define FPSCR_Z             30
#define FPSCR_N             31

#define FPDSCR_RMODE        22
#define FPDSCR_FZ           24
#define FPDSCR_DN           25
#define FPDSCR_AHP          26


#endif