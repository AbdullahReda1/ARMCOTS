/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        11 MAY, 2023
 * Version:              v1.0
 * Compiler:			 GNU ARM-GCC
 * Controller:			 STM32F401CCU6
 * Layer:				 HAL
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         11 MAY, 2023      Abdullah R.Hebashi            Initial Creation 
*********************************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_config.h"
#include "LEDMATRIX_private.h"

#include "../../Services/LEDMATRIXArray.h"


void HLEDMATRIX_voidInit(void)
{
	/* Another way to make an array with these configurations 
	   doubled, then make a for loop for one line with (i=i+2) */
	/* But this better to free cofigurating wat to user (any pin, any port) */

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1, LEDMATRIX_ROW_PORT);
	MRCC_voidEnablePeripheralClock(RCC_AHB1, LEDMATRIX_COL_PORT);

	MSTK_voidInit();

	MGPIO_voidSetPinMode(LEDMATRIX_ROW0_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW1_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW2_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW3_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW4_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW5_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_ROW6_PIN, OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMATRIX_ROW7_PIN, OUTPUT_MODE);

    MGPIO_voidSetPinMode(LEDMATRIX_COL0_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL1_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL2_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL3_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL4_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL5_PIN, OUTPUT_MODE);
	MGPIO_voidSetPinMode(LEDMATRIX_COL6_PIN, OUTPUT_MODE);
    MGPIO_voidSetPinMode(LEDMATRIX_COL7_PIN, OUTPUT_MODE);


    MGPIO_voidSetOutputType(LEDMATRIX_ROW0_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW1_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW2_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW3_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW4_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW5_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_ROW6_PIN, PUSH_PULL);
    MGPIO_voidSetOutputType(LEDMATRIX_ROW7_PIN, PUSH_PULL);

    MGPIO_voidSetOutputType(LEDMATRIX_COL0_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL1_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL2_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL3_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL4_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL5_PIN, PUSH_PULL);
	MGPIO_voidSetOutputType(LEDMATRIX_COL6_PIN, PUSH_PULL);
    MGPIO_voidSetOutputType(LEDMATRIX_COL7_PIN, PUSH_PULL);


	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW0_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW1_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW2_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW3_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW4_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW5_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW6_PIN, LOW_SPEED_2MHZ);
    MGPIO_voidSetOutputSpeed(LEDMATRIX_ROW7_PIN, LOW_SPEED_2MHZ);

    MGPIO_voidSetOutputSpeed(LEDMATRIX_COL0_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL1_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL2_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL3_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL4_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL5_PIN, LOW_SPEED_2MHZ);
	MGPIO_voidSetOutputSpeed(LEDMATRIX_COL6_PIN, LOW_SPEED_2MHZ);
    MGPIO_voidSetOutputSpeed(LEDMATRIX_COL7_PIN, LOW_SPEED_2MHZ);

	voidDisableColumns();
}

static void voidDisableColumns(void)
{
    MGPIO_voidSetPinValue(LEDMATRIX_COL0_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL1_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL2_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL3_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL4_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL5_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL6_PIN,HIGH);
    MGPIO_voidSetPinValue(LEDMATRIX_COL7_PIN,HIGH);
}

void HLEDMATRIX_voidDisplay(const u8 * Copy_pu8DataArray)
{
    u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8BIT;
	static u8 RowArray[Arr_Size] = {LEDMATRIX_ROW0_PIN_ONLY, LEDMATRIX_ROW1_PIN_ONLY, LEDMATRIX_ROW2_PIN_ONLY, LEDMATRIX_ROW3_PIN_ONLY, LEDMATRIX_ROW4_PIN_ONLY, LEDMATRIX_ROW5_PIN_ONLY, LEDMATRIX_ROW6_PIN_ONLY, LEDMATRIX_ROW7_PIN_ONLY};
	static u8 ColArray[Arr_Size] = {LEDMATRIX_COL0_PIN_ONLY, LEDMATRIX_COL1_PIN_ONLY, LEDMATRIX_COL2_PIN_ONLY, LEDMATRIX_COL3_PIN_ONLY, LEDMATRIX_COL4_PIN_ONLY, LEDMATRIX_COL5_PIN_ONLY, LEDMATRIX_COL6_PIN_ONLY, LEDMATRIX_COL7_PIN_ONLY};
    voidDisableColumns();
    for(Local_u8ColIndex = INIT_LOOP; Local_u8ColIndex < NUM_COLS; Local_u8ColIndex++)
    {
		voidDisableColumns();
		for (Local_u8RowIndex = INIT_LOOP; Local_u8RowIndex < NUM_ROWS; Local_u8RowIndex++)
		{
			Local_u8BIT = GET_BIT(Copy_pu8DataArray[Local_u8ColIndex], Local_u8RowIndex);
			MGPIO_voidSetPinValue(LEDMATRIX_ROW_PORT, RowArray[Local_u8RowIndex], Local_u8BIT);
		}
		MGPIO_voidSetPinValue(LEDMATRIX_COL_PORT, ColArray[Local_u8ColIndex], LOW);
		MSTK_voidSetMicroBusyWait(2500);
	}
}

void HLEDMATRIX_voidRotateCharacter(const u8 * Copy_pu8DataArray)
{
	u8 Local_u8Colums;
	u8 Local_u8Rows;
	u8 Local_u8Rotation;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8BIT;

    static u8 RowArray[Arr_Size] = {LEDMATRIX_ROW0_PIN_ONLY, LEDMATRIX_ROW1_PIN_ONLY, LEDMATRIX_ROW2_PIN_ONLY, LEDMATRIX_ROW3_PIN_ONLY, LEDMATRIX_ROW4_PIN_ONLY, LEDMATRIX_ROW5_PIN_ONLY, LEDMATRIX_ROW6_PIN_ONLY, LEDMATRIX_ROW7_PIN_ONLY};
    static u8 ColArray[Arr_Size] = {LEDMATRIX_COL0_PIN_ONLY, LEDMATRIX_COL1_PIN_ONLY, LEDMATRIX_COL2_PIN_ONLY, LEDMATRIX_COL3_PIN_ONLY, LEDMATRIX_COL4_PIN_ONLY, LEDMATRIX_COL5_PIN_ONLY, LEDMATRIX_COL6_PIN_ONLY, LEDMATRIX_COL7_PIN_ONLY};

    // Create a copy of the character pattern to rotate.
    u8 DisplayData[NUM_COLS][NUM_ROWS];

    for (Local_u8Colums = INIT_LOOP; Local_u8Colums < NUM_COLS; Local_u8Colums++)
    {
        for (Local_u8Rows = INIT_LOOP; Local_u8Rows < NUM_ROWS; Local_u8Rows++)
        {
            DisplayData[Local_u8Colums][Local_u8Rows] = GET_BIT(Copy_pu8DataArray[Local_u8Colums], Local_u8Rows);
        }
    }

    // Rotate the character pattern
    for (Local_u8Rotation = INIT_LOOP; Local_u8Rotation < NUM_COLS; Local_u8Rotation++)
    {
        // Display the rotated pattern
        for (Local_u8ColIndex = INIT_LOOP; Local_u8ColIndex < NUM_COLS; Local_u8ColIndex++)
        {
            voidDisableColumns();
            for (Local_u8RowIndex = INIT_LOOP; Local_u8RowIndex < NUM_ROWS; Local_u8RowIndex++)
            {
                Local_u8BIT = DisplayData[(Local_u8ColIndex + Local_u8Rotation) % NUM_COLS][Local_u8RowIndex];
                MGPIO_voidSetPinValue(LEDMATRIX_ROW_PORT, RowArray[Local_u8RowIndex], Local_u8BIT);
            }
            MGPIO_voidSetPinValue(LEDMATRIX_COL_PORT, ColArray[Local_u8ColIndex], LOW);
            MSTK_voidSetMicroBusyWait(2500);
        }
        MSTK_voidSetMicroBusyWait(100000);
    }
}

void HLEDMATRIX_voidRotateString(const u8* Copy_pu8StringArray, u8 Copy_u8CharecterWidth)
{
	u8 Local_u8Colums;
	u8 Local_u8Rows;
	u8 Local_u8Rotation;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8BIT;

	u32 Copy_u32StringLength = Copy_u8CharecterWidth * 8;

    static u8 RowArray[Arr_Size] = {LEDMATRIX_ROW0_PIN_ONLY, LEDMATRIX_ROW1_PIN_ONLY, LEDMATRIX_ROW2_PIN_ONLY, LEDMATRIX_ROW3_PIN_ONLY, LEDMATRIX_ROW4_PIN_ONLY, LEDMATRIX_ROW5_PIN_ONLY, LEDMATRIX_ROW6_PIN_ONLY, LEDMATRIX_ROW7_PIN_ONLY};
    static u8 ColArray[Arr_Size] = {LEDMATRIX_COL0_PIN_ONLY, LEDMATRIX_COL1_PIN_ONLY, LEDMATRIX_COL2_PIN_ONLY, LEDMATRIX_COL3_PIN_ONLY, LEDMATRIX_COL4_PIN_ONLY, LEDMATRIX_COL5_PIN_ONLY, LEDMATRIX_COL6_PIN_ONLY, LEDMATRIX_COL7_PIN_ONLY};

    // Create a copy of the character pattern to rotate
    u8 DisplayData[Copy_u32StringLength][NUM_ROWS];

    for (Local_u8Colums = 0; Local_u8Colums < Copy_u32StringLength; Local_u8Colums++)
    {
        for (Local_u8Rows = 0; Local_u8Rows < NUM_ROWS; Local_u8Rows++)
        {
            DisplayData[Local_u8Colums][Local_u8Rows] = GET_BIT(Copy_pu8StringArray[Local_u8Colums], Local_u8Rows);
        }
    }

    // Rotate the character pattern
    for (Local_u8Rotation = 0; Local_u8Rotation < Copy_u32StringLength; Local_u8Rotation++)
    {
        // Display the rotated pattern
        for (Local_u8ColIndex = 0; Local_u8ColIndex < NUM_COLS; Local_u8ColIndex++)
        {
            voidDisableColomns();
            for (Local_u8RowIndex = 0; Local_u8RowIndex < NUM_ROWS; Local_u8RowIndex++)
            {
                Local_u8BIT = DisplayData[((Local_u8ColIndex + Local_u8Rotation) % Copy_u32StringLength)][Local_u8RowIndex];
                MGPIO_voidSetPinValue(LEDMATRIX_ROW_PORT, RowArray[Local_u8RowIndex], Local_u8BIT);
            }
            MGPIO_voidSetPinValue(LEDMATRIX_COL_PORT, ColArray[Local_u8ColIndex], LOW);
            MSTK_voidSetMicroBusyWait(2500);
        }
        MSTK_voidSetMicroBusyWait(100000);
    }
}

void HLEDMATRIX_voidRotateCustomSentence(const u8* Copy_pu8SentenceArray, u32 Copy_u32SentenceColumLength)
{
	u8 Local_u8Colums;
	u8 Local_u8Rows;
	u8 Local_u8Rotation;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8BIT;

    static u8 RowArray[Arr_Size] = {LEDMATRIX_ROW0_PIN_ONLY, LEDMATRIX_ROW1_PIN_ONLY, LEDMATRIX_ROW2_PIN_ONLY, LEDMATRIX_ROW3_PIN_ONLY, LEDMATRIX_ROW4_PIN_ONLY, LEDMATRIX_ROW5_PIN_ONLY, LEDMATRIX_ROW6_PIN_ONLY, LEDMATRIX_ROW7_PIN_ONLY};
    static u8 ColArray[Arr_Size] = {LEDMATRIX_COL0_PIN_ONLY, LEDMATRIX_COL1_PIN_ONLY, LEDMATRIX_COL2_PIN_ONLY, LEDMATRIX_COL3_PIN_ONLY, LEDMATRIX_COL4_PIN_ONLY, LEDMATRIX_COL5_PIN_ONLY, LEDMATRIX_COL6_PIN_ONLY, LEDMATRIX_COL7_PIN_ONLY};

    // Create a copy of the character pattern to rotate
    u8 DisplayData[Copy_u32SentenceColumLength][NUM_ROWS];

    for (Local_u8Colums = 0; Local_u8Colums < Copy_u32SentenceColumLength; Local_u8Colums++)
    {
        for (Local_u8Rows = 0; Local_u8Rows < NUM_ROWS; Local_u8Rows++)
        {
            DisplayData[Local_u8Colums][Local_u8Rows] = GET_BIT(Copy_pu8SentenceArray[Local_u8Colums], Local_u8Rows);
        }
    }

    // Rotate the character pattern
    for (Local_u8Rotation = 0; Local_u8Rotation < Copy_u32SentenceColumLength; Local_u8Rotation++)
    {
        // Display the rotated pattern
        for (Local_u8ColIndex = 0; Local_u8ColIndex < NUM_COLS; Local_u8ColIndex++)
        {
            voidDisableColomns();
            for (Local_u8RowIndex = 0; Local_u8RowIndex < NUM_ROWS; Local_u8RowIndex++)
            {
                Local_u8BIT = DisplayData[((Local_u8ColIndex + Local_u8Rotation) % Copy_u32SentenceColumLength)][Local_u8RowIndex];
                MGPIO_voidSetPinValue(LEDMATRIX_ROW_PORT, RowArray[Local_u8RowIndex], Local_u8BIT);
            }
            MGPIO_voidSetPinValue(LEDMATRIX_COL_PORT, ColArray[Local_u8ColIndex], LOW);
            MSTK_voidSetMicroBusyWait(2500);
        }
        MSTK_voidSetMicroBusyWait(100000);
    }
}