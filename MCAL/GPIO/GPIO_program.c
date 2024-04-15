/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 MCAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         7 MAY, 2023       Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"


void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8Mode)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->MODER) &= (~ ((MGPIO_OUTPUT_MODE_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOA->MODER) |= (Copy_u8Mode << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTB:
            (GPIOB->MODER) &= (~ ((MGPIO_OUTPUT_MODE_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOB->MODER) |= (Copy_u8Mode << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTC:
            (GPIOC->MODER) &= (~ ((MGPIO_OUTPUT_MODE_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOC->MODER) |= (Copy_u8Mode << (Copy_u8PinNumaber * 2));
        break;
        default:
        break;
    }
}

void MGPIO_voidSetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8OutputType)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->OTYPER) &= (~ ((MGPIO_OUTPUT_TYPE_MASK) << Copy_u8PinNumaber));
            (GPIOA->OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNumaber));
        break;
        case MGPIO_PORTB:
            (GPIOB->OTYPER) &= (~ ((MGPIO_OUTPUT_TYPE_MASK) << Copy_u8PinNumaber));
            (GPIOB->OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNumaber));
        break;
        case MGPIO_PORTC:
            (GPIOC->OTYPER) &= (~ ((MGPIO_OUTPUT_TYPE_MASK) << Copy_u8PinNumaber));
            (GPIOC->OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNumaber));
        break;
        default:
        break;
    }
}

void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8OutputSpeed)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->OSPEEDR) &= (~ ((MGPIO_OUTPUT_SPEED_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOA->OSPEEDR) |= (Copy_u8OutputSpeed << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTB:
            (GPIOB->OSPEEDR) &= (~ ((MGPIO_OUTPUT_SPEED_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOB->OSPEEDR) |= (Copy_u8OutputSpeed << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTC:
            (GPIOC->OSPEEDR) &= (~ ((MGPIO_OUTPUT_SPEED_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOC->OSPEEDR) |= (Copy_u8OutputSpeed << (Copy_u8PinNumaber * 2));
        break;
        default:
        break;
    }
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8PinValue)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            switch (Copy_u8PinValue)
            {
                case HIGH:
                    SET_BIT((GPIOA->ODR), Copy_u8PinNumaber);
                break;
                case LOW:
                    CLR_BIT((GPIOA->ODR), Copy_u8PinNumaber);
                break;
                default:
                break;
            }
        break;
        case MGPIO_PORTB:
            switch (Copy_u8PinValue)
            {
                case HIGH:
                    SET_BIT((GPIOB->ODR), Copy_u8PinNumaber);
                break;
                case LOW:
                    CLR_BIT((GPIOB->ODR), Copy_u8PinNumaber);
                break;
                default:
                break;
            }
        break;
        case MGPIO_PORTC:
            switch (Copy_u8PinValue)
            {
                case HIGH:
                    SET_BIT((GPIOC->ODR), Copy_u8PinNumaber);
                break;
                case LOW:
                    CLR_BIT((GPIOC->ODR), Copy_u8PinNumaber);
                break;
                default:
                break;
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8AlternativeNumber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8PinNumaber <= 7)
            {
                (GPIOA -> AFRL) &= ~(MGPIO_ALTERNATIVE_MASK << (Copy_u8PinNumaber * 4));
                (GPIOA -> AFRL) |= (Copy_u8AlternativeNumber << (Copy_u8PinNumaber * 4));
            }
            else if (Copy_u8PinNumaber <= 15)
            {
                (GPIOA -> AFRH) &= ~(MGPIO_ALTERNATIVE_MASK << ((Copy_u8PinNumaber - 8) * 4));
                (GPIOA -> AFRH) |= (Copy_u8AlternativeNumber << ((Copy_u8PinNumaber - 8) * 4));
            }
        break;
        case MGPIO_PORTB:
            if (Copy_u8PinNumaber <= 7)
            {
                (GPIOB -> AFRL) &= ~(MGPIO_ALTERNATIVE_MASK << (Copy_u8PinNumaber * 4));
                (GPIOB -> AFRL) |= (Copy_u8AlternativeNumber << (Copy_u8PinNumaber * 4));
            }
            else if (Copy_u8PinNumaber <= 15)
            {
                (GPIOB -> AFRH) &= ~(MGPIO_ALTERNATIVE_MASK << ((Copy_u8PinNumaber - 8) * 4));
                (GPIOB -> AFRH) |= (Copy_u8AlternativeNumber << ((Copy_u8PinNumaber - 8) * 4));
            }
        break;
        case MGPIO_PORTC:
            if (Copy_u8PinNumaber <= 7)
            {
                (GPIOC -> AFRL) &= ~(MGPIO_ALTERNATIVE_MASK << (Copy_u8PinNumaber * 4));
                (GPIOC -> AFRL) |= (Copy_u8AlternativeNumber << (Copy_u8PinNumaber * 4));
            }
            else if (Copy_u8PinNumaber <= 15)
            {
                (GPIOC -> AFRH) &= ~(MGPIO_ALTERNATIVE_MASK << ((Copy_u8PinNumaber - 8) * 4));
                (GPIOC -> AFRH) |= (Copy_u8AlternativeNumber << ((Copy_u8PinNumaber - 8) * 4));
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidTogPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            TOG_BIT((GPIOA->ODR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTB:
            TOG_BIT((GPIOB->ODR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTC:
            TOG_BIT((GPIOC->ODR), Copy_u8PinNumaber);
        break;
        default:
        break;
    }
}

void MGPIO_voidSetPortMode(u8 Copy_u8PortName, u32 Copy_u32PortMode)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->MODER), Copy_u32PortMode);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->MODER), Copy_u32PortMode);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->MODER), Copy_u32PortMode);
        break;
        default:
        break;
    }
}

void MGPIO_voidSetPortOutputType(u8 Copy_u8PortName, u16 Copy_u16PortType)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->OTYPER), Copy_u16PortType);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->OTYPER), Copy_u16PortType);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->OTYPER), Copy_u16PortType);
        break;
        default:
        break;
    }
}

void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8PortName, u32 Copy_u32PortSpeed)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->OSPEEDR), Copy_u32PortSpeed);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->OSPEEDR), Copy_u32PortSpeed);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->OSPEEDR), Copy_u32PortSpeed);
        break;
        default:
        break;
    }
}

void MGPIO_voidSetPortValue(u8 Copy_u8PortName, u16 Copy_u16PinValue)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->ODR), Copy_u16PinValue);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->ODR), Copy_u16PinValue);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->ODR), Copy_u16PinValue);
        break;
        default:
        break;
    }
}

void MGPIO_voidSetHalfPortValue(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition,u8 Copy_u8HalfPortValue)
{
    u8 Local_u8Iterator;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, Local_u8Iterator, GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, (Local_u8Iterator + 8), GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
        break;
        case MGPIO_PORTB:
            if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, Local_u8Iterator, GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, (Local_u8Iterator + 8), GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
        break;
        case MGPIO_PORTC:
            if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, Local_u8Iterator, GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 7; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, (Local_u8Iterator + 8), GET_BIT(Copy_u8HalfPortValue, Local_u8Iterator));
                }
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetHalfPortMode(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8Mode)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTA, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTB, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTC, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetHalfPortOutputType(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8OutputType)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTA, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTB, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTC, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetHalfPortOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8OutputSpeed)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTA, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTB, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTC, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetNipplePortMode(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8Mode)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 3;
    }
    else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
    {
        Local_u8StartCounter = 4;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 11;
    }
    else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
    {
        Local_u8StartCounter = 12;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTA, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTB, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetPinMode(MGPIO_PORTC, Local_u8Iterator, Copy_u8Mode);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetNipplePortOutputType(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8OutputType)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 3;
    }
    else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
    {
        Local_u8StartCounter = 4;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 11;
    }
    else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
    {
        Local_u8StartCounter = 12;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTA, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTB, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputType(MGPIO_PORTC, Local_u8Iterator, Copy_u8OutputType);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetNipplePortOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8OutputSpeed)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 3;
    }
    else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
    {
        Local_u8StartCounter = 4;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 11;
    }
    else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
    {
        Local_u8StartCounter = 12;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTA, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTB, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidSetOutputSpeed(MGPIO_PORTC, Local_u8Iterator, Copy_u8OutputSpeed);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetNipplePortValue(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition,u8 Copy_u8NipplePortValue)
{
    u8 Local_u8Iterator;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, Local_u8Iterator, GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, (Local_u8Iterator + 4), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, (Local_u8Iterator + 8), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTA, (Local_u8Iterator + 12), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
        break;
        case MGPIO_PORTB:
            if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, Local_u8Iterator, GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, (Local_u8Iterator + 4), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, (Local_u8Iterator + 8), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTB, (Local_u8Iterator + 12), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
        break;
        case MGPIO_PORTC:
            if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, Local_u8Iterator, GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, (Local_u8Iterator + 4), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, (Local_u8Iterator + 8), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
            else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
            {
                for (Local_u8Iterator = 0; Local_u8Iterator <= 3; Local_u8Iterator++)
                {
                    MGPIO_voidSetPinValue(MGPIO_PORTC, (Local_u8Iterator + 12), GET_BIT(Copy_u8NipplePortValue, Local_u8Iterator));
                }
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidTogPortValue(u8 Copy_u8PortName)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->ODR), (~ (GPIOA->ODR)));
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->ODR), (~ (GPIOB->ODR)));
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->ODR), (~ (GPIOC->ODR)));
        break;
        default:
        break;
    }
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumaber)
{
    u8 Local_u8ReturnValue = 0;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            Local_u8ReturnValue = GET_BIT((GPIOA->IDR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTB:
            Local_u8ReturnValue = GET_BIT((GPIOB->IDR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTC:
            Local_u8ReturnValue = GET_BIT((GPIOC->IDR), Copy_u8PinNumaber);
        break;
        default:
        break;
    }
    return Local_u8ReturnValue;
}

u16 MGPIO_u16GetPortValue(u8 Copy_u8PortName)
{
    u16 Local_u8ReturnValue = 0x0000;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            Local_u8ReturnValue = GET_REG((GPIOA->IDR));
        break;
        case MGPIO_PORTB:
            Local_u8ReturnValue = GET_REG((GPIOB->IDR));
        break;
        case MGPIO_PORTC:
            Local_u8ReturnValue = GET_REG((GPIOC->IDR));
        break;
        default:
        break;
    }
    return Local_u8ReturnValue;
}

void MGPIO_voidPullUpPullDownPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber, u8 Copy_u8PullUpDown)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->PUPDR) &= (~ ((MGPIO_OUTPUT_PULL_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOA->PUPDR) |= (Copy_u8PullUpDown << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTB:
            (GPIOB->PUPDR) &= (~ ((MGPIO_OUTPUT_PULL_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOB->PUPDR) |= (Copy_u8PullUpDown << (Copy_u8PinNumaber * 2));
        break;
        case MGPIO_PORTC:
            (GPIOC->PUPDR) &= (~ ((MGPIO_OUTPUT_PULL_MASK) << (Copy_u8PinNumaber * 2)));
            (GPIOC->PUPDR) |= (Copy_u8PullUpDown << (Copy_u8PinNumaber * 2));
        break;
        default:
        break;
    }
}

void MGPIO_voidPullUpPullDownPort(u8 Copy_u8PortName, u32 Copy_u32PullUpDown)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->PUPDR), Copy_u32PullUpDown);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->PUPDR), Copy_u32PullUpDown);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->PUPDR), Copy_u32PullUpDown);
        break;
        default:
        break;
    }
}

void MGPIO_voidPullUpPullDownHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition, u8 Copy_u8PullUpDown)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTA, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTB, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTC, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidPullUpPullDownNipplePort(u8 Copy_u8PortName, u8 Copy_u8NipplePortPosition, u8 Copy_u8PullUpDown)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8NipplePortPosition == F1ST_NIPPLE_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 3;
    }
    else if (Copy_u8NipplePortPosition == S2ND_NIPPLE_PORT)
    {
        Local_u8StartCounter = 4;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8NipplePortPosition == T3RD_NIPPLE_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 11;
    }
    else if (Copy_u8NipplePortPosition == F4TH_NIPPLE_PORT)
    {
        Local_u8StartCounter = 12;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTA, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTB, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidPullUpPullDownPin(MGPIO_PORTC, Local_u8Iterator, Copy_u8PullUpDown);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicSetPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_BIT((GPIOA->BSRR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTB:
            SET_BIT((GPIOB->BSRR), Copy_u8PinNumaber);
        break;
        case MGPIO_PORTC:
            SET_BIT((GPIOC->BSRR), Copy_u8PinNumaber);
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicResetPin(u8 Copy_u8PortName, u8 Copy_u8PinNumaber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_BIT((GPIOA->BSRR), (Copy_u8PinNumaber + 16));
        break;
        case MGPIO_PORTB:
            SET_BIT((GPIOB->BSRR), (Copy_u8PinNumaber + 16));
        break;
        case MGPIO_PORTC:
            SET_BIT((GPIOC->BSRR), (Copy_u8PinNumaber + 16));
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicSetPort(u8 Copy_u8PortName)
{
    u16 Local_u16PortValue = ALL_HIGH;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->BSRR), Local_u16PortValue);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->BSRR), Local_u16PortValue);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->BSRR), Local_u16PortValue);
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicResetPort(u8 Copy_u8PortName)
{
    u16 Local_u16PortValue = ALL_HIGH;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        case MGPIO_PORTB:
            (GPIOB->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        case MGPIO_PORTC:
            (GPIOC->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicSetSpecificPins(u8 Copy_u8PortName, u16 Copy_u16PortValue)
{
    u16 Local_u16PortValue = Copy_u16PortValue;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_REG((GPIOA->BSRR), Local_u16PortValue);
        break;
        case MGPIO_PORTB:
            SET_REG((GPIOB->BSRR), Local_u16PortValue);
        break;
        case MGPIO_PORTC:
            SET_REG((GPIOC->BSRR), Local_u16PortValue);
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicResetSpecificPins(u8 Copy_u8PortName, u16 Copy_u16PortValue)
{
    u16 Local_u16PortValue = Copy_u16PortValue;
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            (GPIOA->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        case MGPIO_PORTB:
            (GPIOB->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        case MGPIO_PORTC:
            (GPIOC->BSRR) |= (Local_u16PortValue << (BSRR_BR0));
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicSetHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicSetPin(MGPIO_PORTA, Local_u8Iterator);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicSetPin(MGPIO_PORTB, Local_u8Iterator);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicSetPin(MGPIO_PORTC, Local_u8Iterator);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidAtomicResetHalfPort(u8 Copy_u8PortName, u8 Copy_u8HalfPortPosition)
{
    u8 Local_u8Iterator;
    u8 Local_u8StartCounter;
    u8 Local_u8EndCounter;
    if (Copy_u8HalfPortPosition == LOW_HALF_PORT)
    {
        Local_u8StartCounter = 0;
        Local_u8EndCounter   = 7;
    }
    else if (Copy_u8HalfPortPosition == HIGH_HALF_PORT)
    {
        Local_u8StartCounter = 8;
        Local_u8EndCounter   = 15;
    }
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicResetPin(MGPIO_PORTA, Local_u8Iterator);
            }
        break;
        case MGPIO_PORTB:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicResetPin(MGPIO_PORTB, Local_u8Iterator);
            }
        break;
        case MGPIO_PORTC:
            for (Local_u8Iterator = Local_u8StartCounter; Local_u8Iterator <= Local_u8EndCounter; Local_u8Iterator++)
            {
                MGPIO_voidAtomicResetPin(MGPIO_PORTC, Local_u8Iterator);
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidSetLockKey(u8 Copy_u8PortName, u8 Copy_u8LockStatus)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            switch (Copy_u8LockStatus)
            {
            case ENABLE_LOCK_KEY:
                SET_BIT((GPIOA->LCKR),LCKR_LCKk);
            break;
            case DISABLE_LOCK_KEY:
                CLR_BIT((GPIOA->LCKR),LCKR_LCKk);
            break;
            default:
            break;
            }
        break;
        case MGPIO_PORTB:
            switch (Copy_u8LockStatus)
            {
            case ENABLE_LOCK_KEY:
                SET_BIT((GPIOB->LCKR),LCKR_LCKk);
            break;
            case DISABLE_LOCK_KEY:
                CLR_BIT((GPIOB->LCKR),LCKR_LCKk);
            break;
            default:
            break;
            }
        break;
        case MGPIO_PORTC:
            switch (Copy_u8LockStatus)
            {
            case ENABLE_LOCK_KEY:
                SET_BIT((GPIOC->LCKR),LCKR_LCKk);
            break;
            case DISABLE_LOCK_KEY:
                CLR_BIT((GPIOC->LCKR),LCKR_LCKk);
            break;
            default:
            break;
            }
        break;
        default:
        break;
    }
}

void MGPIO_voidLockPinConfiguration(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            SET_BIT((GPIOA->LCKR), Copy_u8PinNumber);
        break;
        case MGPIO_PORTB:
            SET_BIT((GPIOB->LCKR), Copy_u8PinNumber);
        break;
        case MGPIO_PORTC:
            SET_BIT((GPIOC->LCKR), Copy_u8PinNumber);
        break;
        default:
        break;
    }
}

void MGPIO_voidUnlockPinConfiguration(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    switch (Copy_u8PortName)
    {
        case MGPIO_PORTA:
            CLR_BIT((GPIOA->LCKR), Copy_u8PinNumber);
        break;
        case MGPIO_PORTB:
            CLR_BIT((GPIOB->LCKR), Copy_u8PinNumber);
        break;
        case MGPIO_PORTC:
            CLR_BIT((GPIOC->LCKR), Copy_u8PinNumber);
        break;
        default:
        break;
    }
}

void MGPIO_voidSPI1MasterConfiguration(void)
{
    MGPIO_voidSetPinMode(MGPIO_PORTA, PIN4, OUTPUT_MODE);	                        /* NSS pin */
	MGPIO_voidSetPinValue(MGPIO_PORTA, PIN4, HIGH);

	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN5, ALTERNATE_FUNCTION_MODE);	            /* CLK pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN6, ALTERNATE_FUNCTION_MODE);				/* MISO pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN7, ALTERNATE_FUNCTION_MODE);	            /* MOSI pin */

	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN4, HIGH_SPEED_50MHZ);	                /* NSS pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN5, HIGH_SPEED_50MHZ);	                /* CLK pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN6, HIGH_SPEED_50MHZ);	                /* MISO pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN7, HIGH_SPEED_50MHZ);	                /* MOSI pin */

	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN5, AF5_SPI1_4);            	/* CLK pin */
	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN6, AF5_SPI1_4);	            /* MISO pin */
	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN7, AF5_SPI1_4);	            /* MOSI pin */
}

void MGPIO_voidSPI1SlaveConfiguration(void)
{
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN4, INPUT_MODE);				            /* NSS pin */
	MGPIO_voidPullUpPullDownPin(MGPIO_PORTA, PIN4, PULL_DOWN);

	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN5, INPUT_MODE);				            /* CLK pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN6, ALTERNATE_FUNCTION_MODE);	            /* MISO pin */
	MGPIO_voidSetPinMode(MGPIO_PORTA, PIN7, INPUT_MODE);				            /* MOSI pin */

	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN4, HIGH_SPEED_50MHZ);	                /* NSS pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN5, HIGH_SPEED_50MHZ);	                /* CLK pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN6, HIGH_SPEED_50MHZ);	                /* MISO pin */
	MGPIO_voidSetOutputSpeed(MGPIO_PORTA, PIN7, HIGH_SPEED_50MHZ);	                /* MOSI pin */

	MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, PIN6, AF5_SPI1_4);	            /* MISO pin */
}