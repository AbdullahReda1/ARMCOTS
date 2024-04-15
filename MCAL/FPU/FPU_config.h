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


#ifndef MCAL_FPU_FPU_CONFIG_H
#define MCAL_FPU_FPU_CONFIG_H


/*
    OPTIONS:
    ACCESS_DENIED
    PRIVILEGED_ACCESS_ONLY
    FULL_ACCESS
*/
#define FPU_COPROCESSOR_ACCESS      FULL_ACCESS

/*
    OPTIONS:
    USER_PRIVILEGED
    USER_NOT_PRIVILEGED
*/
#define FPU_USER_MODE               USER_PRIVILEGED

/*
    OPTIONS:
    THREAD_MODE_OFF
    THREAD_MODE_ON
*/
#define FPU_THREAD_MODE             THREAD_MODE_OFF

/*
    OPTIONS:
    DISABLE_FAULTS_HANDLER
    ENABLE_FAULTS_HANDLER
*/
#define FPU_FAULTS_HANDLER          ENABLE_FAULTS_HANDLER

/*
    OPTIONS:
    NO_FLOATING_POINT_REGISTER_SAVING
    LAZY_FLOATING_POINT_REGISTER_SAVE_RESTORE
    AUTOMATIC_FLOATING_POINT_REGISTER_SAVE_RESTORE
*/
#define FPU_CONTEXT_SAVE_RESTORE    AUTOMATIC_FLOATING_POINT_REGISTER_SAVE_RESTORE


#endif