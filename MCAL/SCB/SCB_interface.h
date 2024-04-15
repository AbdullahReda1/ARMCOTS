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


#ifndef MCAL_SCB_SCB_INTERFACE_H
#define MCAL_SCB_SCB_INTERFACE_H


#define ENABLE      1
#define DISABLE     0

#define SET         1
#define CLR         0

/* Exceptions Names */
#define NMI         0
#define SV          1
#define SYSTICK     2

/* Put IVE */
#define SRAM        1
#define CODE        0

/* Groups Distripution */
#define MSCB_GRP_4_SUB_0_BITS    0b000
#define MSCB_GRP_3_SUB_1_BITS    0b100
#define MSCB_GRP_2_SUB_2_BITS    0b101
#define MSCB_GRP_1_SUB_3_BITS    0b110
#define MSCB_GRP_0_SUB_4_BITS    0b111

/* Wakeup CPU Condition */
#define ENABLE_DISABLE      1
#define ENABLE_ONLY         0

/* Sleeping Type */
#define SLEEP               0
#define DEEP_SLEEP          1

/* Sleep At Thread Mode Status */
#define DO_NOT_SLEEP        0
#define ENTER_SLEEP         1

/* Alignment Options */
#define ALIGNE_4_BYTE       0
#define ALIGNE_8_BYTE       1

/* Traps */
#define DIV_0_TRAP          0
#define UNALIGN_TRAP        1

/* How Enter Thread Mode */
#define NO_EXCEPTION_IS_ACTIVE   0
#define ENTER_FROM_EXC_RETURN    1

/* Exceptional Handlers */
#define MEMORY_FAULT_HANDLER     0
#define BUS_FAULT_HANDLER        1
#define USAGE_FAULT_HANDLER      2
#define SV_CALL_HANDLER          3
#define PEND_SV_HANDLER          4
#define SYSTICK_HANDLER          5

/* Faults */
#define MEMORY_FAULT             0
#define BUS_FAULT                1
#define USAGE_FAULT              2

/* Exception Pending */
#define SV_CALL_PEND             0
#define MEMORY_FAULT_PEND        1
#define BUS_FAULT_PEND           2
#define USAGE_FAULT_PEND         3

/* Exception Active */
#define SYSTICK_ACTIVE           0
#define PEND_SV_ACTIVE           1
#define MONITOR_ACTIVE           2
#define SV_CALL_ACTIVE           3
#define USAGE_FAULT_ACTIVE       4
#define BUS_FAULT_ACTIVE         5
#define MEMORY_FAULT_ACTIVE      6

/* Usage Faults (UF) */
#define DIVIDE_BY_0_UF           0
#define UNALIGNED_ACCESS_UF      1
#define NO_COPROCESSOR_UF        2
#define INVALID_PC_LOAD_UF       3
#define INVALID_STATE_UF         4
#define UNDEFINED_INSTRUCION_UF  5

/* Bus Faults (BF) */
#define BFAR_VALID_BF                0
#define LAZY_STATE_PRESERVATION_BF   1
#define STAKING_EXCEPTION_ENTRY_BF   2
#define UNSTAKING_EXCEPTION_EXIT_BF  3
#define IMPRECISE_DATA_BUS_ERORR_BF  4
#define PRECISE_DATA_BUS_ERORR_BF    5
#define INSTRUCTION_BUS_ERORR_BF     6

/* Memory Management Faults (MMF) */
#define MMAR_VALID_MMF                      0
#define LAZY_STATE_PRESERVATION_MMF         1
#define STAKING_EXCEPTION_ENTRY_MMF         2
#define UNSTAKING_EXCEPTION_EXIT_MMF        3
#define DATA_ACCESS_VIOLATION_MMF           4
#define INSTRUCTION_ACCESS_VIOLATION_MMF    5


void MSCB_voidFPUInstructionsWithIntStatus(u8 Copy_u8FunctionStatus);
void MSCB_voidAutomaticUpdateOfCONTROLFPCAStatus(u8 Copy_u8FunctionStatus);
void MSCB_voidITFoldingStatus(u8 Copy_u8FunctionStatus);
void MSCB_voidWriteBufferStatus(u8 Copy_u8FunctionStatus);
void MSCB_voidInterruptMultCycleInstructionsStatus(u8 Copy_u8FunctionStatus);

u32 MSCB_u32GetCPUID(void);
u8 MSCB_u8GetCPURevisionID(void);
u16 MSCB_u16GetCPUPartNoID(void);
u8 MSCB_u8GetCPUConstantID(void);
u8 MSCB_u8GetCPUVariantID(void);
u8 MSCB_u8GetCPUImplementerID(void);

void MSCB_voidSetNMIExceptionPending(void);
void MSCB_voidSVExceptionPendingStatus(u8 Copy_u8Status);
void MSCB_voidSYSTICKExceptionPendingStatus(u8 Copy_u8Status);
u8 MSCB_u8GetExceptionPendingStatus(u8 Copy_u8PendingName);
u8 MSCB_u8GetISRPendingStatus(void);
u8 MSCB_u8GetCurrentVectorPending(void);
u8 MSCB_u8checkPreemptionActiveException(void);
u16 MSCB_u16GetCurrentVectorActive(void);
void MSCB_voidSetThreadMode(void);
void MSCB_viodActiveExceptionID(u16 Copy_u16ExceptionID);

void MSCB_viodSetVectorTableRegion(u8 Copy_u8MemoryRegion);
u8 MSCB_u8GetVectorTableRegion(void);
void MSCB_viodSetVectorOffset(u32 Copy_u32Offset);
u32 MSCB_u32GetVectorOffset(void);

u16 MSCB_u16GetVectorKeyStatus(void);
void MSCB_voidSetVectorKey(void);
u8 MSCB_u8GetEndianness(void);
void MSCB_viodSetInterruptPriorityGrouping(u8 Copy_u8GroupingValue);
void MSCB_viodSystemResetRequest(u8 Copy_u8Status);

void MSCB_voidWakeupCPUCondition(u8 Copy_u8InterruptCondition);
u8 MSCB_u8GetWakeupCPUCondition(void);
void MSCB_voidSelectSleepType(u8 Copy_u8SleepType);
void MSCB_voidSleepAtThreadModeStatus(u8 Copy_u8SleepStatus);

void MSCB_voidConfigureStackAlignmentOnExceptionEntry(u8 Copy_u8StackAlignmentType);
void MSCB_viodIgnoreDataBusFaults(void);
void MSCB_viodAllowDataBusFaults(void);
void MSCB_viodEnableTrap(u8 Copy_u8TrapType);
void MSCB_viodDisableTrap(u8 Copy_u8TrapType);
void MSCB_viodSTIRPrivileging(u8 Copy_u8Status);
void MSCB_viodChooseHowEnterThreadMode(u8 Copy_u8Status);

void MSCB_voidSetExceptionPriority(u8 Copy_u8HandlerType, u8 Copy_u8Priority);
u8 MSCB_voidGetExceptionPriority(u8 Copy_u8HandlerType);

void MSCB_viodEnableFault(u8 Copy_u8FaultType);
void MSCB_viodDisableFault(u8 Copy_u8FaultType);
void MSCB_viodSetPending(u8 Copy_u8PendingType);
void MSCB_viodClearPending(u8 Copy_u8PendingType);
void MSCB_viodSetActive(u8 Copy_u8ActiveType);
void MSCB_viodClearActive(u8 Copy_u8ActiveType);

u8 MSCB_u8GetUsageFaultStatus(u8 Copy_u8UFType);
void MSCB_viodClearUsageFault(u8 Copy_u8UFType);

u8 MSCB_u8GetBusFaultStatus(u8 Copy_u8BFType);

u8 MSCB_u8GetMemoryManagementFaultStatus(u8 Copy_u8MMFType);

void MSCB_voidForceHardFaultStatus(u8 Copy_u8Status);

void MSCB_voidClearForcedHardFault(void);
u8 MSCB_u8GetForceHardFaultStatus(void);
void MSCB_voidClearVectorHardFault(void);
u8 MSCB_u8GetVectorHardFaultStatus(void);

u32 MSCB_u32GetMemoryManagementFaultAddress(void);

u32 MSCB_u32GetBusFaultAddress(void);

u32 MSCB_u32GetAuxiliaryFaultStatus(void);


#endif