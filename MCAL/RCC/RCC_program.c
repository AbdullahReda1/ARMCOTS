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


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"


static void (*pvCallBack)(void) = NULL;


void MRCC_voidInit(void)
{
    /* Set many as default */
    /* Choose CPU clock source, Set HSI */
    #if     CPU_CLK_SOURCE == HSI

        (RCC->CR) |= (HSI_TRIM << CR_HSITRIM);
        SET_BIT((RCC->CR), CR_HSION);
        CLR_BIT((RCC->CFGR), CFGR_SW0);
        CLR_BIT((RCC->CFGR), CFGR_SW1);

    #elif   CPU_CLK_SOURCE == HSE

        SET_BIT((RCC->CR), CR_HSEON);
        SET_BIT((RCC->CFGR), CFGR_SW0);
        CLR_BIT((RCC->CFGR), CFGR_SW1);

    #elif   CPU_CLK_SOURCE == PLL

        CLR_BIT((RCC->CR), CR_PLLI2SON);
        CLR_BIT((RCC->CR), CR_PLLON);

        #if ((PLL_PLLI2S_PRE_VCO_PRESCALER_M >= 2) && (PLL_PLLI2S_PRE_VCO_PRESCALER_M <= 63))
            (RCC->PLLCFGR) |= (PLL_PLLI2S_PRE_VCO_PRESCALER_M << PLLCFGR_PLLM);
        #else
            #error "RCC PLL_PLLI2S_PRE_VCO_PRESCALER_M, Configuration Error"
        #endif

        #if ((PLL_VCO_MULTIPLICATION_FACTOR_N >= 192) && (PLL_VCO_MULTIPLICATION_FACTOR_N <= 432))
            (RCC->PLLCFGR) |= (PLL_VCO_MULTIPLICATION_FACTOR_N << PLLCFGR_PLLN);
        #else
            #error "RCC PLL_VCO_MULTIPLICATION_FACTOR_N, Configuration Error"
        #endif

        #if ((PLL_USB_OTG_FS_SDIO_PRESCALER_Q >= 2) && (PLL_USB_OTG_FS_SDIO_PRESCALER_Q <= 15))
            (RCC->PLLCFGR) |= (PLL_USB_OTG_FS_SDIO_PRESCALER_Q << PLLCFGR_PLLQ);
        #else
            #error "RCC PLL_USB_OTG_FS_SDIO_PRESCALER_Q, Configuration Error"
        #endif

        (RCC->PLLCFGR) |= (PLL_OUTPUT_PRESCALER_P << PLLCFGR_PLLP);

        #if     PLL_PLLI2S_SOURCE == HSI
            CLR_BIT((RCC->PLLCFGR), PLLCFGR_PLLSRC);
            SET_BIT((RCC->CR), CR_HSION);
            CLR_BIT((RCC->CFGR), CFGR_SW0);
            SET_BIT((RCC->CFGR), CFGR_SW1);
        #elif   PLL_PLLI2S_SOURCE == HSE
            SET_BIT((RCC->PLLCFGR), PLLCFGR_PLLSRC);
            SET_BIT((RCC->CR), CR_HSEON);
            CLR_BIT((RCC->CFGR), CFGR_SW0);
            SET_BIT((RCC->CFGR), CFGR_SW1);
        #else
            #error "RCC PLL_PLLI2S_SOURCE, Configuration Error"
        #endif

        SET_BIT((RCC->CR), CR_PLLON);
    #else
        #error "RCC CPU_CLK_SOURCE, Configuration Error"
    #endif
    
    /* Choose Bus prescaler clock, Set AHP with (SYS_CLK/2) */
    #if     BUS_CLK == AHB
        (RCC->CFGR) |= (AHB_PRESCALER << CFGR_HPRE);
    #elif   BUS_CLK == APB1
        (RCC->CFGR) |= (APB_1_PRESCALER << CFGR_HPPRE1);
    #elif   BUS_CLK == APB2
        (RCC->CFGR) |= (APB_2_PRESCALER << CFGR_HPPRE2);
    #else
        #error "RCC BUS_CLK, Configuration Error"
    #endif

    /* HSE bypass: Disable */
    CLR_BIT((RCC->CR), CR_HSEBYP);

    /* Clock Security System */
    #if     CLOCK_SECURITY_SYSTEM == CLOCK_SECURITY_SYSTEM_ENABLE
		SET_BIT((RCC->CR), CR_CSSON);
	#elif   CLOCK_SECURITY_SYSTEM == CLOCK_SECURITY_SYSTEM_DISABLE
		CLR_BIT((RCC->CR), CR_CSSON);
	#else
		#error "RCC CLOCK_SECURITY_SYSTEM, Configuration Error"
	#endif
}

u8 MRCC_u8GetHSIHardwareCalebration(void)
{
    u8 Local_u16Calebration;
    Local_u16Calebration = (u8)((RCC->CR) >> CR_HSICAL);
    return Local_u16Calebration;
}

void MRCC_voidEnableHSEByPass(void)
{
    CLR_BIT((RCC->CR), CR_HSEON);
    SET_BIT((RCC->CR), CR_HSEBYP);
}

void MRCC_voidClockSecuritySystem(u8 Copy_u8Status)
{
    switch (Copy_u8Status)
    {
        case ENABLE:
            SET_BIT((RCC->CR), CR_CSSON);
        break;
        case DISABLE:
            CLR_BIT((RCC->CR), CR_CSSON);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidI2SClock(void)
{
    #if     I2S_SOURCE == INTERNAL_PLLI2S

        CLR_BIT((RCC->CFGR), CFGR_I2SSCR);
        CLR_BIT((RCC->CR), CR_PLLI2SON);
        CLR_BIT((RCC->CR), CR_PLLON);

        #if ((PLL_PLLI2S_PRE_VCO_PRESCALER_M >= 2) && (PLL_PLLI2S_PRE_VCO_PRESCALER_M <= 63))
            (RCC->PLLCFGR) |= (PLL_PLLI2S_PRE_VCO_PRESCALER_M << PLLCFGR_PLLM);
        #else
                #error "RCC PLL_PLLI2S_PRE_VCO_PRESCALER_M, Configuration Error"
        #endif

        #if ((PLLI2S_VCO_MULTIPLICATION_FACTOR_N >= 192) && (PLLI2S_VCO_MULTIPLICATION_FACTOR_N <= 432))
            (RCC->PLLI2SCFGR) |= (PLLI2S_VCO_MULTIPLICATION_FACTOR_N << PLLI2SCFGR_PLLI2SN);
        #else
            #error "RCC PLLI2S_VCO_MULTIPLICATION_FACTOR_N, Configuration Error"
        #endif

        #if ((PLLI2S_OUTPUT_PRESCALER_R >= 2) && (PLLI2S_OUTPUT_PRESCALER_R <= 7))
            (RCC->PLLI2SCFGR) |= (PLLI2S_OUTPUT_PRESCALER_R << PLLI2SCFGR_PLLI2SR);
        #else
            #error "RCC PLLI2S_OUTPUT_PRESCALER_R, Configuration Error"
        #endif

        #if     PLL_PLLI2S_SOURCE == HSI
            CLR_BIT((RCC->PLLCFGR), PLLCFGR_PLLSRC);
            SET_BIT((RCC->CR), CR_HSION);
            CLR_BIT((RCC->CFGR), CFGR_SW0);
            SET_BIT((RCC->CFGR), CFGR_SW1);
        #elif   PLL_PLLI2S_SOURCE == HSE
            SET_BIT((RCC->PLLCFGR), PLLCFGR_PLLSRC);
            SET_BIT((RCC->CR), CR_HSEON);
            CLR_BIT((RCC->CFGR), CFGR_SW0);
            SET_BIT((RCC->CFGR), CFGR_SW1);
        #else
            #error "RCC PLL_PLLI2S_SOURCE, Configuration Error"
        #endif

        SET_BIT((RCC->CR), CR_PLLI2SON);

    #elif   I2S_SOURCE == EXTERNAL_I2S_CKIN

        SET_BIT((RCC->CFGR), CFGR_I2SSCR);

    #else
        #error "RCC I2S_SOURCE, Configuration Error"
    #endif
}

void MRCC_voidRTCClock(void)
{
    #if     RTC_STATUS == RTC_ENABLE
        SET_BIT((RCC->BDCR), BDCR_RTCEN);
        #if     RTC_CLOCK_SOURCE == LSE
            CLR_BIT((RCC->BDCR), BDCR_LSEBYP);
            SET_BIT((RCC->BDCR), BDCR_LSEON);
            SET_BIT((RCC->BDCR), BDCR_RTCSEL0);
            CLR_BIT((RCC->BDCR), BDCR_RTCSEL1);
        #elif   RTC_CLOCK_SOURCE == LSI
            SET_BIT((RCC->CSR), CSR_LSION);
            CLR_BIT((RCC->BDCR), BDCR_RTCSEL0);
            SET_BIT((RCC->BDCR), BDCR_RTCSEL1);
        #elif   RTC_CLOCK_SOURCE == HSE
            #if ((RTC_CLOCK_BY_HSE_PRESCALER == 1) || (RTC_CLOCK_BY_HSE_PRESCALER == NO_CLK) || (RTC_CLOCK_BY_HSE_PRESCALER >= 2) && (RTC_CLOCK_BY_HSE_PRESCALER <= 31))
                (RCC->CFGR) |= (RTC_CLOCK_BY_HSE_PRESCALER << CFGR_RTCPRE);
            #else
                    #error "RCC RTC_CLOCK_BY_HSE_PRESCALER, Configuration Error"
            #endif
            SET_BIT((RCC->CR), CR_HSEON);
            SET_BIT((RCC->CFGR), CFGR_SW0);
            CLR_BIT((RCC->CFGR), CFGR_SW1);
            SET_BIT((RCC->BDCR), BDCR_RTCSEL0);
            SET_BIT((RCC->BDCR), BDCR_RTCSEL1);
        #else
            #error "RCC RTC_CLOCK_SOURCE, Configuration Error"
        #endif
    #elif   RTC_STATUS == RTC_DISABLE
        CLR_BIT((RCC->BDCR), BDCR_RTCEN);
    #else
        #error "RCC RTC_STATUS, Configuration Error"
    #endif
}

void MRCC_voidEnableLSEByPass(void)
{
    CLR_BIT((RCC->BDCR), BDCR_LSEON);
    SET_BIT((RCC->BDCR), BDCR_LSEBYP);
}

void MRCC_voidSetLowSpeedClockSource(void)
{
    #if     LOW_SPEED_CLK_SOURCE == LSE
        CLR_BIT((RCC->BDCR), BDCR_LSEBYP);
        SET_BIT((RCC->BDCR), BDCR_LSEON);
    #elif   LOW_SPEED_CLK_SOURCE == LSI
        SET_BIT((RCC->CSR), CSR_LSION);
    #else
        #error "RCC LOW_SPEED_CLK_SOURCE, Configuration Error"
    #endif
}

void MRCC_voidSetMCO1Source(void)
{
    (RCC->CFGR) |= (MCO1_PRESCALER << CFGR_MCO1PRE);
    (RCC->CFGR) |= (MCO1_SOURCE << CFGR_MCO1);
}

u8 MRCC_u8GetMCO1Prescaler(void)
{
    u8 Local_u8BreScalerVal;
    u32 Local_u32RegVal = GET_REG(RCC->CFGR);
    (Local_u8BreScalerVal) = ((Local_u32RegVal << (31 - CFGR_MCO1PRE2)) >> CFGR_MCO2PRE2 );
    return Local_u8BreScalerVal;
}

void MRCC_voidSetMCO2Source(void)
{
    (RCC->CFGR) |= (MCO2_PRESCALER << CFGR_MCO2PRE);
    (RCC->CFGR) |= (MCO2_SOURCE << CFGR_MCO2);
}

u8 MRCC_u8GetMCO2Prescaler(void)
{
    u8 Local_u8BreScalerVal;
    u32 Local_u32RegVal = GET_REG(RCC->CFGR);
    (Local_u8BreScalerVal) = ((Local_u32RegVal << (31 - CFGR_MCO2PRE2)) >> CFGR_MCO2PRE2 );
    return Local_u8BreScalerVal;
}

u8 MRCC_u8GetFlagStatus(u8 Copy_u8Flag)
{
    u8 Local_u8FlagValue;
    switch (Copy_u8Flag)
    {
        case LSE:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_LSERDYF);
        break;
        case LSI:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_LSIRDYF);
        break;
        case HSE:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_HSERDYF);
        break;
        case HSI:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_HSIRDYF);
        break;
        case PLL:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_PLLRDYF);
        break;
        case PLLI2S:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_PLLI2SRDYF);
        break;
        case CSS:
            Local_u8FlagValue = GET_BIT((RCC->CIR), CIR_CSSF);
        break;
        default:
            /* DO Nothing */
        break;
    }
    return Local_u8FlagValue;
}

u8 MRCC_u8CheckClockSecutitySystem(void)
{
    return (GET_BIT((RCC->CIR), CIR_CSSF));
}

void MRCC_u8ClockSourceInterrupt(u8 Copy_u8ClockSource, u8 Copy_u8InterruptStatus)
{
    switch (Copy_u8ClockSource)
    {
        case LSE:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_LSERDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_LSERDYIE);
            }
        break;
        case LSI:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_LSIRDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_LSIRDYIE);
            }
        break;
        case HSE:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_HSERDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_HSERDYIE);
            }
        break;
        case HSI:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_HSIRDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_HSIRDYIE);
            }
        break;
        case PLL:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_PLLRDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_PLLRDYIE);
            }
        break;
        case PLLI2S:
            if (Copy_u8InterruptStatus == DISABLE)
            {
                CLR_BIT((RCC->CIR), CIR_PLLI2SRDYIE);
            }
            else
            {
                SET_BIT((RCC->CIR), CIR_PLLI2SRDYIE);
            }
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_u8ClearFlag(u8 Copy_u8Flag)
{
    switch (Copy_u8Flag)
    {
        case LSE:
            SET_BIT((RCC->CIR), CIR_LSERDYC);
        break;
        case LSI:
            SET_BIT((RCC->CIR), CIR_LSIRDYC);
        break;
        case HSE:
            SET_BIT((RCC->CIR), CIR_HSERDYC);
        break;
        case HSI:
            SET_BIT((RCC->CIR), CIR_HSIRDYC);
        break;
        case PLL:
            SET_BIT((RCC->CIR), CIR_PLLRDYC);
        break;
        case PLLI2S:
            SET_BIT((RCC->CIR), CIR_PLLI2SRDYC);
        break;
        case CSS:
            SET_BIT((RCC->CIR), CIR_CSSC);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidResetPeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    /* Note that software reset type is an internal reset caused by SCB peripheral throw AIRCR register 3RD BIT */
    switch (Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT((RCC->AHB1RSTR), Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            SET_BIT((RCC->AHB2RSTR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            SET_BIT((RCC->APB1RSTR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            SET_BIT((RCC->APB2RSTR), Copy_u8PeripheralID);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT((RCC->AHB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            SET_BIT((RCC->AHB2ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            SET_BIT((RCC->APB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            SET_BIT((RCC->APB2ENR), Copy_u8PeripheralID);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            CLR_BIT((RCC->AHB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            CLR_BIT((RCC->AHB2ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            CLR_BIT((RCC->APB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            CLR_BIT((RCC->APB2ENR), Copy_u8PeripheralID);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidEnablePeripheralClockDuringSleepMode(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT((RCC->AHB1LPENR), Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            SET_BIT((RCC->AHB2LPENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            SET_BIT((RCC->APB1LPENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            SET_BIT((RCC->APB2LPENR), Copy_u8PeripheralID);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidDisablePeripheralClockDuringSleepMode(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralID)
{
    switch (Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            CLR_BIT((RCC->AHB1LPENR), Copy_u8PeripheralID);
        break;
        case RCC_AHB2:
            CLR_BIT((RCC->AHB2LPENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            CLR_BIT((RCC->APB1LPENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            CLR_BIT((RCC->APB2LPENR), Copy_u8PeripheralID);
        break;
        default:
            /* DO Nothing */
        break;
    }
}

void MRCC_voidBackupDomainReset(void)
{
    SET_BIT((RCC->BDCR), BDCR_BDRST);
}

u8 MRCC_u8GetResetFlagStatus(u8 Copy_u8ResetFlag)
{
    /* Note that software reset type is an internal reset caused by SCB peripheral throw AIRCR register 3RD BIT */
    u8 Local_u8FlagValue;
    switch (Copy_u8ResetFlag)
    {
        case LOW_POWER_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_LPWRRSTF);
        break;
        case WINDOW_WATCHDOG_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_WWDGRSTF);
        break;
        case INDEPENDENT_WATCHDOG_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_IWDGRSTF);
        break;
        case SOFTWARE_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_SFTRSTF);
        break;
        case POR_PDR_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_PORRSTF);
        break;
        case PIN_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_PINRSTF);
        break;
        case BOR_RESET:
            Local_u8FlagValue = GET_BIT((RCC->CSR), CSR_BORRSTF);
        break;
        default:
            /* DO Nothing */
        break;
    }
    return Local_u8FlagValue;
}

void MRCC_voidClearResetFlags(void)
{
    SET_BIT((RCC->CSR), CSR_RMVF);
}

void MRCC_voidSpreadSpectrumClockGeneration(void)
{
    (RCC->SSCGR) |= (SPREAD_SPECTRUM_MUDULATION << SSCGR_SSCGEN);
    (RCC->SSCGR) |= (SPREAD_SPECTRUM_TYPE << SSCGR_SPREADSEL);
    (RCC->SSCGR) |= (MODULATION_PERIOD << SSCGR_MODPER);
    (RCC->SSCGR) |= (INCREMENTATION_STEP << SSCGR_INCSTEP);
}

void MRCC_voidTimersclocksprescalers(void)
{
    (RCC->DCKCFGR) |= (TIMERS_CLOCK_PRESCALER_SELECTION << DCKCFGR_TIMPRE);
}

void MRCC_voidSetCallBack(void (*pvNotificationFunction)(void))
{
	pvCallBack = pvNotificationFunction;
}

/************* RCC ISR ******************/

void RCC_IRQHandler(void)
{
    if (pvCallBack != NULL)
    {
        pvCallBack();
    }
}