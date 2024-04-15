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


#ifndef MCAL_FPU_FPU_INTERFACE_H
#define MCAL_FPU_FPU_INTERFACE_H


/* Exception Name */
#define INPUT_DENORMAL_CUMULATIVE_EXCEPTION         7
#define INEXACT_CUMULATIVE_EXCEPTION                4
#define UNDERFLOW_CUMULATIVE_EXCEPTION              3
#define OVERFLOW_CUMULATIVE_EXCEPTION               2
#define DIVISION_BY_ZERO_CUMULATIVE_EXCEPTION       1
#define INVALID_OPERATION_CUMULATIVE_EXCEPTION      0

/* Flag Name */
#define NEGATIVE_FLAG                               31
#define ZERO_FLAG                                   30
#define CARRY_FLAG                                  29
#define OVERFLOW_FLAG                               28

/* Default Data Name */
#define ALTERNATIVE_HALF_PRECISION_CONTROL          26
#define DEFAULT_NAN_MODE_CONTROL                    25
#define FLUSH_TO_ZERO_MODE_CONTROL                  24
#define ROUNDING_MODE_CONTROL_FIELD                 22

/* Rounding Mode */
#define ROUND_TO_NEAREST_MODE                       0b00
#define ROUND_TOWARDS_PLUS_INFINITY_MODE            0b01
#define ROUND_TOWARDS_MINUS_INFINITY_MODE           0b10
#define ROUND_TOWARDS_ZERO_MODE                     0b11

/* Flush To Zero Mode */
#define FLUSH_TO_ZERO_MODE_DISABLE                  0b0
#define FLUSH_TO_ZERO_MODE_ENABLE                   0b1

/* Default NaN Mode */
#define NAN_PROPAGATION_MODE                        0b0
#define DEFAULT_NAN_MODE                            0b1

/* Alternative Half Precision Control */
#define IEEE_HALF_PRECISION_FORMAT_SELECTED         0b0
#define ALTERNATIVE_HALF_PRECISION_FORMAT_SELECTED  0b1


void MFPU_voidInit(void);

void MFPU_voidSetContextAddress(u32 Copy_u32Address);
u32 MFPU_u32GetContextAddress(void);

void MFPU_voidClearAllExceptionFlags(void);
u8 MFPU_voidGetExceptionFlagStatus(u8 Copy_u8ExceptionName);
u8 MFPU_voidGetFPUSystemFlagStatus(u8 Copy_u8FlagName);

void MFPU_voidSetDefaultData(u8 Copy_u8RoundingMode, u8 Copy_u8FlushToZeroMode, u8 Copy_u8DefaultNaNMode, u8 Copy_u8AlternativeHalfPrecisionControl);
u8 MFPU_voidGetFPUDefaultDataStatus(u8 Copy_u8DefaultDataName);

void MFPU_voidSetContextMechanism(void);


#endif