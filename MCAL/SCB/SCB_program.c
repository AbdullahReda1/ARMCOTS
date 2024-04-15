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

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"


void MSCB_voidFPUInstructionsWithIntStatus(u8 Copy_u8FunctionStatus)
{
    switch (Copy_u8FunctionStatus)
    {
        case ENABLE:
            CLR_BIT(SCB_ACTLR, ACTLR_DISOOFP);
        break;
        case DISABLE:
            SET_BIT(SCB_ACTLR, ACTLR_DISOOFP);
        break;
        default:
        break;
    }
}

void MSCB_voidAutomaticUpdateOfCONTROLFPCAStatus(u8 Copy_u8FunctionStatus)
{
    switch (Copy_u8FunctionStatus)
    {
        case ENABLE:
            CLR_BIT(SCB_ACTLR, ACTLR_DISFPCA);
        break;
        case DISABLE:
            SET_BIT(SCB_ACTLR, ACTLR_DISFPCA);
        break;
        default:
        break;
    }
}

void MSCB_voidITFoldingStatus(u8 Copy_u8FunctionStatus)
{
    switch (Copy_u8FunctionStatus)
    {
        case ENABLE:
            CLR_BIT(SCB_ACTLR, ACTLR_DISFOLD);
        break;
        case DISABLE:
            SET_BIT(SCB_ACTLR, ACTLR_DISFOLD);
        break;
        default:
        break;
    }
}

void MSCB_voidWriteBufferStatus(u8 Copy_u8FunctionStatus)
{
    switch (Copy_u8FunctionStatus)
    {
        case ENABLE:
            CLR_BIT(SCB_ACTLR, ACTLR_DISDEFWBUF);
        break;
        case DISABLE:
            SET_BIT(SCB_ACTLR, ACTLR_DISDEFWBUF);
        break;
        default:
        break;
    }
}

void MSCB_voidInterruptMultCycleInstructionsStatus(u8 Copy_u8FunctionStatus)
{
    switch (Copy_u8FunctionStatus)
    {
        case ENABLE:
            CLR_BIT(SCB_ACTLR, ACTLR_DISMCYCINT);
        break;
        case DISABLE:
            SET_BIT(SCB_ACTLR, ACTLR_DISMCYCINT);
        break;
        default:
        break;
    }
}

u32 MSCB_u32GetCPUID(void)
{
    u32 Local_u8IDValue = GET_REG(SCB->CPUID);
    return (Local_u8IDValue);
}

u8 MSCB_u8GetCPURevisionID(void)
{
    u8 Local_u8IDValue = GET_REG(SCB->CPUID);
    Local_u8IDValue = ((Local_u8IDValue << CPUID_PARTNO) >> CPUID_PARTNO);
    return (Local_u8IDValue);
}

u16 MSCB_u16GetCPUPartNoID(void)
{
    u16 Local_u8IDValue = GET_REG(SCB->CPUID);
    Local_u8IDValue = (Local_u8IDValue  >> CPUID_PARTNO);
    return (Local_u8IDValue);
}

u8 MSCB_u8GetCPUConstantID(void)
{
    u32 Local_u8IDValue = GET_REG(SCB->CPUID);
    Local_u8IDValue = ((Local_u8IDValue << (MAX_REG_VALUE - CPUID_VARIANT)) >> SHIFT_28_VALUE);
    return (Local_u8IDValue);
}

u8 MSCB_u8GetCPUVariantID(void)
{
    u32 Local_u8IDValue = GET_REG(SCB->CPUID);
    Local_u8IDValue = ((Local_u8IDValue << (MAX_REG_VALUE - CPUID_IMPLEMENTER)) >> SHIFT_28_VALUE);
    return (Local_u8IDValue);
}

u8 MSCB_u8GetCPUImplementerID(void)
{
    u32 Local_u8IDValue = GET_REG(SCB->CPUID);
    Local_u8IDValue = (Local_u8IDValue >> CPUID_IMPLEMENTER);
    return (Local_u8IDValue);
}

void MSCB_voidSetNMIExceptionPending(void)
{
    SET_BIT((SCB->ICSR), ICSR_NMIPENDSET);
}

void MSCB_voidSVExceptionPendingStatus(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case SET:
            SET_BIT((SCB->ICSR), ICSR_PENDSVSET);
        break;
        case CLR:
            SET_BIT((SCB->ICSR), ICSR_PENDSVCLR);
        break;
        default:
        break;
    }
}

void MSCB_voidSYSTICKExceptionPendingStatus(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case SET:
            SET_BIT((SCB->ICSR), ICSR_PENDSTSET);
        break;
        case CLR:
            SET_BIT((SCB->ICSR), ICSR_PENDSTCLR);
        break;
        default:
        break;
    }
}

u8 MSCB_u8GetExceptionPendingStatus(u8 Copy_u8PendingName)
{
    u8 Local_u8FlagValue;
    switch (Copy_u8PendingName)
    {
        case NMI:
            Local_u8FlagValue = GET_BIT((SCB->ICSR), ICSR_NMIPENDSET);
        break;
        case SV:
            Local_u8FlagValue = GET_BIT((SCB->ICSR), ICSR_PENDSVSET);
        break;
        case SYSTICK:
            Local_u8FlagValue = GET_BIT((SCB->ICSR), ICSR_PENDSTSET);
        break;
        default:
        break;
    }
    return Local_u8FlagValue;
}

u8 MSCB_u8GetISRPendingStatus(void)
{
    u8 Local_u8FlagValue;
    Local_u8FlagValue = GET_BIT((SCB->ICSR), ICSR_ISRPENDING);
    return Local_u8FlagValue;
}

u8 MSCB_u8GetCurrentVectorPending(void)
{
    u32 Local_u32VectorValue = GET_REG(SCB->ICSR);
    Local_u32VectorValue = ((Local_u32VectorValue << (MAX_REG_VALUE - (ICSR_VECTPENDING6 + 1))) >> ICSR_PENDSTCLR);
    return Local_u32VectorValue;
}

u8 MSCB_u8checkPreemptionActiveException(void)
{
    u32 Local_u32RegValue = GET_REG((SCB->ICSR));
    return (GET_BIT(Local_u32RegValue, ICSR_RETTOBASE));
}

u16 MSCB_u16GetCurrentVectorActive(void)
{
    u16 Local_u16VectorValue = GET_REG(SCB->ICSR);
    Local_u16VectorValue = ((Local_u16VectorValue << (MAX_NIP_VALUE - (ICSR_VECTACTIVE8 + 1))) >> ICSR_VECTACTIVE7);
    return Local_u16VectorValue;
}

void MSCB_voidSetThreadMode(void)
{
    (SCB->ICSR) |= (THREAD_MODE_VAL << ICSR_VECTACTIVE);
}

void MSCB_viodActiveExceptionID(u16 Copy_u16ExceptionID)
{
    /* IRQn0:IRQn240 & Exceptions are IRQe-16 */
    (SCB->ICSR) |= (Copy_u16ExceptionID << ICSR_VECTACTIVE);
}

void MSCB_viodSetVectorTableRegion(u8 Copy_u8MemoryRegion)
{
    switch (Copy_u8MemoryRegion)
    {
        case CODE:
            CLR_BIT((SCB->VTOR), VTOR_TBLBASE);
        break;
        case SRAM:
            SET_BIT((SCB->VTOR), VTOR_TBLBASE);
        break;
        default:
        break;
    }
}

u8 MSCB_u8GetVectorTableRegion(void)
{
    u32 Local_u32RegValue = GET_REG((SCB->VTOR));
    return (GET_BIT((Local_u32RegValue), VTOR_TBLBASE));
}

void MSCB_viodSetVectorOffset(u32 Copy_u32Offset)
{
    if (Copy_u32Offset <= MAX_OFFSET)
    {
        (SCB->VTOR) |= (Copy_u32Offset << VTOR_TBLOFF);
    }
}

u32 MSCB_u32GetVectorOffset(void)
{
    u32 Local_u32offset = GET_REG(SCB->VTOR);
    Local_u32offset = ((Local_u32offset << (MAX_REG_VALUE - VTOR_TBLBASE)) >> VTOR_TBLOFF);
    return Local_u32offset;
}

u16 MSCB_u16GetVectorKeyStatus(void)
{
    u32 Local_u32KeyStatus = GET_REG(SCB->AIRCR);
    Local_u32KeyStatus = (Local_u32KeyStatus >> AIRCR_VECTKEYSTAT);
    return Local_u32KeyStatus;
}

void MSCB_voidSetVectorKey(void)
{
    (SCB->AIRCR) |= (VECTOR_KEY << AIRCR_VECTKEY);
}

u8 MSCB_u8GetEndianness(void)
{
    u32 Local_u32RegValue = GET_REG((SCB->AIRCR));
    return (GET_BIT((Local_u32RegValue), AIRCR_ENDIANESS));
}

void MSCB_viodSetInterruptPriorityGrouping(u8 Copy_u8GroupingValue)
{
    (SCB->AIRCR) |= ((VECTOR_KEY << AIRCR_VECTKEY) | (Copy_u8GroupingValue << AIRCR_PRIGROUP));
}

void MSCB_viodSystemResetRequest(u8 Copy_u8Status)
{
    /* Note that is the software reset type */
    switch (Copy_u8Status)
    {
        case SET:
            (SCB->AIRCR) |= ((VECTOR_KEY << AIRCR_VECTKEY) | (AIRCR_SYSRESETREQ << SET));
        break;
        case CLR:
            (SCB->AIRCR) |= ((VECTOR_KEY << AIRCR_VECTKEY) | (AIRCR_SYSRESETREQ << CLR));
        break;
        default:
        break;
    }
}

void MSCB_voidWakeupCPUCondition(u8 Copy_u8InterruptCondition)
{
    switch (Copy_u8InterruptCondition)
    {
        case ENABLE_DISABLE:
            SET_BIT((SCB->SCR), SCR_SEVONPEND);
        break;
        case ENABLE_ONLY:
            CLR_BIT((SCB->SCR), SCR_SEVONPEND);
        break;
        default:
        break;
    }
}

u8 MSCB_u8GetWakeupCPUCondition(void)
{
    u16 Local_u16RegValue = GET_REG((SCB->SCR));
    return (GET_BIT((Local_u16RegValue), SCR_SEVONPEND));
}

void MSCB_voidSelectSleepType(u8 Copy_u8SleepType)
{
    switch (Copy_u8SleepType)
    {
        case DEEP_SLEEP:
            SET_BIT((SCB->SCR), SCR_SLEEPDEEP);
        break;
        case SLEEP:
            CLR_BIT((SCB->SCR), SCR_SLEEPDEEP);
        break;
        default:
        break;
    }
}

void MSCB_voidSleepAtThreadModeStatus(u8 Copy_u8SleepStatus)
{
    switch (Copy_u8SleepStatus)
    {
        case ENTER_SLEEP:
            SET_BIT((SCB->SCR), SCR_SLEEPONEXIT);
        break;
        case DO_NOT_SLEEP:
            CLR_BIT((SCB->SCR), SCR_SLEEPONEXIT);
        break;
        default:
        break;
    }
}

void MSCB_voidConfigureStackAlignmentOnExceptionEntry(u8 Copy_u8StackAlignmentType)
{
    switch (Copy_u8StackAlignmentType)
    {
        case ALIGNE_8_BYTE:
            SET_BIT((SCB->CCR), CCR_STKALIGN);
        break;
        case ALIGNE_4_BYTE:
            CLR_BIT((SCB->CCR), CCR_STKALIGN);
        break;
        default:
        break;
    }
}

void MSCB_viodIgnoreDataBusFaults(void)
{
    /* Enables handlers with priority -1 or -2 to ignore data bus faults caused by load and store instructions */
    SET_BIT((SCB->CCR), CCR_BFHFNMIGN);
}

void MSCB_viodAllowDataBusFaults(void)
{
    /* Block handlers with priority -1 or -2 to ignore data bus faults caused by load and store instructions */
    CLR_BIT((SCB->CCR), CCR_BFHFNMIGN);
}

void MSCB_viodEnableTrap(u8 Copy_u8TrapType)
{
    switch (Copy_u8TrapType)
    {
        case DIV_0_TRAP:
            SET_BIT((SCB->CCR), CCR_DIV_0_TRP);
        break;
        case UNALIGN_TRAP:
            SET_BIT((SCB->CCR), CCR_UNALIGN_TRP);
        break;
        default:
        break;
    }
}

void MSCB_viodDisableTrap(u8 Copy_u8TrapType)
{
    switch (Copy_u8TrapType)
    {
        case DIV_0_TRAP:
            CLR_BIT((SCB->CCR), CCR_DIV_0_TRP);
        break;
        case UNALIGN_TRAP:
            CLR_BIT((SCB->CCR), CCR_UNALIGN_TRP);
        break;
        default:
        break;
    }
}

void MSCB_viodSTIRPrivileging(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case ENABLE:
            SET_BIT((SCB->CCR), CCR_USERSETMPEND);
        break;
        case DISABLE:
            CLR_BIT((SCB->CCR), CCR_USERSETMPEND);
        break;
        default:
        break;
    }
}

void MSCB_viodChooseHowEnterThreadMode(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case ENTER_FROM_EXC_RETURN:
            SET_BIT((SCB->CCR), CCR_NONBASETHRDENA);
        break;
        case NO_EXCEPTION_IS_ACTIVE:
            CLR_BIT((SCB->CCR), CCR_NONBASETHRDENA);
        break;
        default:
        break;
    }
}

void MSCB_voidSetExceptionPriority(u8 Copy_u8HandlerType, u8 Copy_u8Priority)
{
    /* Maximum priority is 0b1111 which is only 4-bit */
	if (Copy_u8HandlerType == MEMORY_FAULT_HANDLER)
    {
	    (SCB->SHPR1) |= ((Copy_u8Priority) << (SHPR1_PRI_44));
	}
    else if (Copy_u8HandlerType == BUS_FAULT_HANDLER)
    {
	    (SCB->SHPR1) |= ((Copy_u8Priority) << (SHPR1_PRI_54));
	}
    else if (Copy_u8HandlerType == USAGE_FAULT_HANDLER)
    {
	    (SCB->SHPR1) |= ((Copy_u8Priority) << (SHPR1_PRI_64));
	}
	else if (Copy_u8HandlerType == SV_CALL_HANDLER)
    {
	    (SCB->SHPR2) |= ((Copy_u8Priority) << (SHPR2_PRI_114));
	}
	else if (Copy_u8HandlerType == PEND_SV_HANDLER)
    {
	    (SCB->SHPR3) |= ((Copy_u8Priority) << (SHPR3_PRI_144));
	}
    else if (Copy_u8HandlerType == SYSTICK_HANDLER)
    {
	    (SCB->SHPR3) |= ((Copy_u8Priority) << (SHPR3_PRI_154));
	}
}

u8 MSCB_voidGetExceptionPriority(u8 Copy_u8HandlerType)
{
    u32 Local_u32RegValue;
	if (Copy_u8HandlerType == MEMORY_FAULT_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR1));
	    Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR1_PRI_44)) >> (SHIFT_28_VALUE));
	}
    else if (Copy_u8HandlerType == BUS_FAULT_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR1));
        Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR1_PRI_54)) >> (SHIFT_28_VALUE));
	}
    else if (Copy_u8HandlerType == USAGE_FAULT_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR1));
        Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR1_PRI_64)) >> (SHIFT_28_VALUE));
	}
	else if (Copy_u8HandlerType == SV_CALL_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR2));
        Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR2_PRI_114)) >> (SHIFT_28_VALUE));
	}
	else if (Copy_u8HandlerType == PEND_SV_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR3));
        Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR3_PRI_144)) >> (SHIFT_28_VALUE));
	}
    else if (Copy_u8HandlerType == SYSTICK_HANDLER)
    {
        Local_u32RegValue = GET_REG((SCB->SHPR3));
        Local_u32RegValue = (((Local_u32RegValue) << (MAX_REG_VALUE - SHPR3_PRI_154)) >> (SHIFT_28_VALUE));
	}
    return Local_u32RegValue;
}

void MSCB_viodEnableFault(u8 Copy_u8FaultType)
{
    switch (Copy_u8FaultType)
    {
        case USAGE_FAULT:
            SET_BIT((SCB->SHCSR), SHCSR_USGFAULTENA);
        break;
        case BUS_FAULT:
            SET_BIT((SCB->SHCSR), SHCSR_BUSFAULTENA);
        break;
        case MEMORY_FAULT:
            SET_BIT((SCB->SHCSR), SHCSR_MEMFAULTENA);
        break;
        default:
        break;
    }
}

void MSCB_viodDisableFault(u8 Copy_u8FaultType)
{
    switch (Copy_u8FaultType)
    {
        case USAGE_FAULT:
            CLR_BIT((SCB->SHCSR), SHCSR_USGFAULTENA);
        break;
        case BUS_FAULT:
            CLR_BIT((SCB->SHCSR), SHCSR_BUSFAULTENA);
        break;
        case MEMORY_FAULT:
            CLR_BIT((SCB->SHCSR), SHCSR_MEMFAULTENA);
        break;
        default:
        break;
    }
}

void MSCB_viodSetPending(u8 Copy_u8PendingType)
{
    switch (Copy_u8PendingType)
    {
        case SV_CALL_PEND:
            SET_BIT((SCB->SHCSR), SHCSR_SVCALLPENDED);
        break;
        case BUS_FAULT_PEND:
            SET_BIT((SCB->SHCSR), SHCSR_BUSFAULTPENDED);
        break;
        case MEMORY_FAULT_PEND:
            SET_BIT((SCB->SHCSR), SHCSR_MEMFAULTPENDED);
        break;
        case USAGE_FAULT_PEND:
            SET_BIT((SCB->SHCSR), SHCSR_USGFAULTPENDED);
        break;
        default:
        break;
    }
}

void MSCB_viodClearPending(u8 Copy_u8PendingType)
{
    switch (Copy_u8PendingType)
    {
        case SV_CALL_PEND:
            CLR_BIT((SCB->SHCSR), SHCSR_SVCALLPENDED);
        break;
        case BUS_FAULT_PEND:
            CLR_BIT((SCB->SHCSR), SHCSR_BUSFAULTPENDED);
        break;
        case MEMORY_FAULT_PEND:
            CLR_BIT((SCB->SHCSR), SHCSR_MEMFAULTPENDED);
        break;
        case USAGE_FAULT_PEND:
            CLR_BIT((SCB->SHCSR), SHCSR_USGFAULTPENDED);
        break;
        default:
        break;
    }
}

void MSCB_viodSetActive(u8 Copy_u8ActiveType)
{
    switch (Copy_u8ActiveType)
    {
        case SYSTICK_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_SYSTICKACT);
        break;
        case PEND_SV_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_PENDSVACT);
        break;
        case MONITOR_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_MONITORACT);
        break;
        case SV_CALL_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_SVCALLACT);
        break;
        case BUS_FAULT_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_BUSFAULTACT);
        break;
        case MEMORY_FAULT_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_MEMFAULTACT);
        break;
        case USAGE_FAULT_ACTIVE:
            SET_BIT((SCB->SHCSR), SHCSR_USGFAULTACT);
        break;
        default:
        break;
    }
}

void MSCB_viodClearActive(u8 Copy_u8ActiveType)
{
    switch (Copy_u8ActiveType)
    {
        case SYSTICK_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_SYSTICKACT);
        break;
        case PEND_SV_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_PENDSVACT);
        break;
        case MONITOR_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_MONITORACT);
        break;
        case SV_CALL_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_SVCALLACT);
        break;
        case BUS_FAULT_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_BUSFAULTACT);
        break;
        case MEMORY_FAULT_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_MEMFAULTACT);
        break;
        case USAGE_FAULT_ACTIVE:
            CLR_BIT((SCB->SHCSR), SHCSR_USGFAULTACT);
        break;
        default:
        break;
    }
}

u8 MSCB_u8GetUsageFaultStatus(u8 Copy_u8UFType)
{
    u16 Local_u16RegValue = GET_REG((SCB->UFSR));
    u8 Local_u8Flag;
    switch (Copy_u8UFType)
    {
        case DIVIDE_BY_0_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_DIVBYZERO);
        break;
        case UNALIGNED_ACCESS_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_UNALIGNED);
        break;
        case NO_COPROCESSOR_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_NOCP);
        break;
        case INVALID_PC_LOAD_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_INVPC);
        break;
        case INVALID_STATE_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_INVSTATE);
        break;
        case UNDEFINED_INSTRUCION_UF:
            Local_u8Flag = GET_BIT(Local_u16RegValue, UFSR_UNDEFINSTR);
        break;
        default:
        break;
    }
    return Local_u8Flag;
}

void MSCB_viodClearUsageFault(u8 Copy_u8UFType)
{
    switch (Copy_u8UFType)
    {
        case DIVIDE_BY_0_UF:
            SET_BIT((SCB->UFSR), UFSR_DIVBYZERO);
        break;
        case UNALIGNED_ACCESS_UF:
            SET_BIT((SCB->UFSR), UFSR_UNALIGNED);
        break;
        case NO_COPROCESSOR_UF:
            SET_BIT((SCB->UFSR), UFSR_NOCP);
        break;
        case INVALID_PC_LOAD_UF:
            SET_BIT((SCB->UFSR), UFSR_INVPC);
        break;
        case INVALID_STATE_UF:
            SET_BIT((SCB->UFSR), UFSR_INVSTATE);
        break;
        case UNDEFINED_INSTRUCION_UF:
            SET_BIT((SCB->UFSR), UFSR_UNDEFINSTR);
        break;
        default:
        break;
    }
}

u8 MSCB_u8GetBusFaultStatus(u8 Copy_u8BFType)
{
    u8 Local_u8RegValue = GET_REG((SCB->BFSR));
    u8 Local_u8Flag;
    switch (Copy_u8BFType)
    {
        case BFAR_VALID_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_BFARVALID);
        break;
        case LAZY_STATE_PRESERVATION_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_LSPERR);
        break;
        case STAKING_EXCEPTION_ENTRY_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_STKERR);
        break;
        case UNSTAKING_EXCEPTION_EXIT_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_UNSTKERR);
        break;
        case IMPRECISE_DATA_BUS_ERORR_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_IMPRECISERR);
        break;
        case PRECISE_DATA_BUS_ERORR_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_PRECISERR);
        break;
        case INSTRUCTION_BUS_ERORR_BF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, BFSR_IBUSERR);
        break;
        default:
        break;
    }
    return Local_u8Flag;
}

u8 MSCB_u8GetMemoryManagementFaultStatus(u8 Copy_u8MMFType)
{
    u8 Local_u8RegValue = GET_REG((SCB->MMFSR));
    u8 Local_u8Flag;
    switch (Copy_u8MMFType)
    {
        case MMAR_VALID_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_MMARVALID);
        break;
        case LAZY_STATE_PRESERVATION_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_MLSPERR);
        break;
        case STAKING_EXCEPTION_ENTRY_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_MSTKERR);
        break;
        case UNSTAKING_EXCEPTION_EXIT_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_MUNSTKERR);
        break;
        case DATA_ACCESS_VIOLATION_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_DACCVIOL);
        break;
        case INSTRUCTION_ACCESS_VIOLATION_MMF:
            Local_u8Flag = GET_BIT(Local_u8RegValue, MMFSR_IACCVIOL);
        break;
        default:
        break;
    }
    return Local_u8Flag;
}

void MSCB_voidClearForcedHardFault(void)
{
    SET_BIT((SCB->HFSR), HFSR_FORCED);
}

u8 MSCB_u8GetForceHardFaultStatus(void)
{
    u32 Local_u32RegValue = GET_REG((SCB->HFSR));
    return (GET_BIT(Local_u32RegValue, HFSR_FORCED));
}

void MSCB_voidClearVectorHardFault(void)
{
    SET_BIT((SCB->HFSR), HFSR_VECTTBL);
}

u8 MSCB_u8GetVectorHardFaultStatus(void)
{
    u32 Local_u32RegValue = GET_REG((SCB->HFSR));
    return (GET_BIT(Local_u32RegValue, HFSR_VECTTBL));
}

u32 MSCB_u32GetMemoryManagementFaultAddress(void)
{
    /* At MPU usage */
    return (GET_REG(SCB->MMFAR));
}

u32 MSCB_u32GetBusFaultAddress(void)
{
    return (GET_REG(SCB->BFAR));
}

u32 MSCB_u32GetAuxiliaryFaultStatus(void)
{
    return (GET_REG(SCB->AFSR));
}