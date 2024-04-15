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


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "FPU_interface.h"
#include "FPU_private.h"
#include "FPU_config.h"


void MFPU_voidInit(void)
{
    SET_WORD(FPU_CPACR, FPU_COPROCESSOR_ACCESS, CPACR_CP10);
    SET_REG((FPU->FPCCR), ((FPU_FAULTS_HANDLER << FPCCR_HFRDY) | (FPU_THREAD_MODE << FPCCR_THREAD) | (FPU_THREAD_MODE << FPCCR_THREAD) | (FPU_USER_MODE << FPCCR_USER)));
    MFPU_voidClearAllExceptionFlags();
    __DSB();
    __ISB();
}

void MFPU_voidSetContextAddress(u32 Copy_u32Address)
{
    SET_REG(FPU->FPCAR, (Copy_u32Address << FPCAR_ADDRESS));
}

u32 MFPU_u32GetContextAddress(void)
{
    return ((FPU->FPCAR) >> FPCAR_ADDRESS);
}

void MFPU_voidClearAllExceptionFlags(void)
{
    __set_FPSCR((u8) 0x00);
}

u8 MFPU_voidGetExceptionFlagStatus(u8 Copy_u8ExceptionName)
{
    u32 Local_u32RegisterValue;
    Local_u32RegisterValue = __get_FPSCR();
    return (GET_BIT(Local_u32RegisterValue, Copy_u8ExceptionName));
}

u8 MFPU_voidGetFPUSystemFlagStatus(u8 Copy_u8FlagName)
{
    u32 Local_u32RegisterValue;
    Local_u32RegisterValue = __get_FPSCR();
    return (GET_BIT(Local_u32RegisterValue, Copy_u8FlagName));
}

void MFPU_voidSetDefaultData(u8 Copy_u8RoundingMode, u8 Copy_u8FlushToZeroMode, u8 Copy_u8DefaultNaNMode, u8 Copy_u8AlternativeHalfPrecisionControl)
{
    SET_REG((FPU->FPDSCR), ((Copy_u8RoundingMode << FPDSCR_RMODE) | (Copy_u8FlushToZeroMode << FPDSCR_FZ) | (Copy_u8DefaultNaNMode << FPDSCR_DN) | (Copy_u8AlternativeHalfPrecisionControl << FPDSCR_AHP)));
}

u8 MFPU_voidGetFPUDefaultDataStatus(u8 Copy_u8DefaultDataName)
{
    u32 Local_u32RegisterValue;
    u8 Local_u8FlagValue;
    Local_u32RegisterValue = GET_REG(FPU->FPDSCR);
    if (Copy_u8DefaultDataName != ROUNDING_MODE_CONTROL_FIELD)
    {
        Local_u8FlagValue = GET_BIT(Local_u32RegisterValue, Copy_u8DefaultDataName);
    }
    else
    {
        Local_u8FlagValue = GET_WORD(Local_u32RegisterValue, FPDSCR_RMODE, (FPDSCR_RMODE + 1));
    }
    return Local_u8FlagValue;
}

void MFPU_voidSetContextMechanism(void)
{
    #if     (FPU_CONTEXT_SAVE_RESTORE == NO_FLOATING_POINT_REGISTER_SAVING)
        
        SET_REG((FPU->FPCCR), ((0b00 << FPCCR_LSPEN) | (0b0 << FPCCR_LSPACT)));
        register u32 fpscr_val = 0;
        register u32 reg_val = 0; 
        reg_val = __get_FPSCR();                        //dummy access
        fpscr_val = *(__IO u32*)(FPU->FPCAR + 0x40);
        while (((fpscr_val) & 0x000000FF) == 0);        //check exception flags
        fpscr_val &= (u32) ~ 0x8F;                      //Clear all exception flags
        *(__IO u32*)(FPU->FPCAR + 0x40) = fpscr_val;
        __DMB();

    #elif   (FPU_CONTEXT_SAVE_RESTORE == LAZY_FLOATING_POINT_REGISTER_SAVE_RESTORE)

        SET_REG((FPU->FPCCR), ((0b01 << FPCCR_LSPEN) | (0b1 << FPCCR_LSPACT)));
        register u32 fpscr_val = 0;
        register u32 reg_val = 0; 
        reg_val = __get_FPSCR();                        //dummy access
        fpscr_val = *(__IO u32*)(FPU->FPCAR + 0x40);
        while (((fpscr_val) & 0x000000FF) == 0);        //check exception flags
        fpscr_val &= (u32) ~ 0x8F;                      // Clear all exception flags
        *(__IO u32*)(FPU->FPCAR + 0x40) = fpscr_val;
        __DMB();

    #elif   (FPU_CONTEXT_SAVE_RESTORE == AUTOMATIC_FLOATING_POINT_REGISTER_SAVE_RESTORE)

        SET_REG((FPU->FPCCR), ((0b10 << FPCCR_LSPEN) | (0b0 << FPCCR_LSPACT)));

    #else
            #error "FPU FPU_CONTEXT_SAVE_RESTORE, Configuration Error"
    #endif 
}

static void FPU_ExceptionHandler(u32 lr, u32 sp)
{
    u32 fpscr_val;
    if (lr == 0xFFFFFFE9)
    {
        sp = sp + 0x60;
    } 
    else if (lr == 0xFFFFFFED)
    {
        sp = __get_PSP() + 0x60;
    }
    fpscr_val = *(u32*)sp;
    while (((fpscr_val) & 0x000000FF) == 0);        //check exception flags
    fpscr_val &= ~(u32)0x8F;                        // Clear all exception flags
    *(u32*)sp = fpscr_val;
    __DMB();
}


/************* FPU ISR ******************/

void FPU_IRQHandler(void)
{
    /* Test handling FPU exceptions by Simulating 
    FPU interrupt to trigger the FPU exception handler, 
    For example, by calling FPU_IRQHandler directly. */
    u32 lr, sp;
    u32 fpscr_val;
    asm volatile (
        "MOV %[lr_val], lr\n"                       // Move LR to lr_val
        "MOV %[sp_val], sp\n"                       // Save SP to sp_val
        "VMRS %[fpscr_val], fpscr\n"                // Dummy read access to force clear
        : [lr_val] "=r" (lr), [sp_val] "=r" (sp), [fpscr_val] "=r" (fpscr_val) /* Outputs */
        : /* Inputs */
        : "memory"                                  // Clobbered list
    );
    FPU_ExceptionHandler(lr, sp);
    asm volatile ("BX LR");                         // Return from IRQ
}