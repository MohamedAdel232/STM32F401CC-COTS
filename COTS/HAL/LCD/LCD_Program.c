/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   LCD_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include MCAL files */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"

/* Include driver files */
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

// Delay Function
void APP_voidDelayMs(u32 Copy_u32Delay)
{
	for(u32 i=0 ; i < (Copy_u32Delay * 300) ; i++ )
	{
		asm("NOP");
	}
}

/* A function to send Command */
void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	/* Set PIN RS low for command */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, GPIO_LOW);

	/* Set PIN RW low for write */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, GPIO_LOW);

	/* Write command on data port */
    GPIO_voidSetPortValueu8NonAtomic (CLCD_u8DATA_PORT, Copy_u8Command);

	/* Send Enable pulse */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8E_PIN, GPIO_HIGH);
    //STK_voidSetBusyWait(2000);
    APP_voidDelayMs(2000);
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8E_PIN, GPIO_LOW);
}

/* A function to send Data */
void CLCD_voidSendData (u8 Copy_u8Data)
{
	/* Set PIN RS high for data */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RS_PIN, GPIO_HIGH);

	/* Set PIN RW low for write */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8RW_PIN, GPIO_LOW);

	/* Write data on data port */
    GPIO_voidSetPortValueu8NonAtomic (CLCD_u8DATA_PORT, Copy_u8Data);

	/* Send Enable pulse */
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8E_PIN, GPIO_HIGH);
    //STK_voidSetBusyWait(2000);
    APP_voidDelayMs(2000);
    GPIO_voidSetPinValue(CLCD_u8CTRL_PORT, CLCD_u8E_PIN, GPIO_LOW);
}

/* A function to Initialize CLCD */
void CLCD_voidInit(void)
{
	/* Wait for more than 30ms */
    //STK_voidSetBusyWait(4000);
	APP_voidDelayMs(3500);

	/* Send Command for function set, 2 lines, 5*8 font size */
	CLCD_voidSendCommand(0b00111000);

	/* Send Command for display on off control: display enable, disable cursor, no blink cursor */
	CLCD_voidSendCommand(0b00001100);

	/* Clear Display */
	CLCD_voidSendCommand(0b00000001);
}

/* A function to send a string */
void CLCD_voidSentString (const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData (Copy_pcString[Local_u8Counter]);
		Local_u8Counter ++;
	}
}

/* A function to go to specific location */
void CLCD_voidGoToXY (u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	/* Calculate the Address */
	u8 Local_u8Address;
	if (Copy_u8XPos == 0)
	{
		/* Location is on the first line  */
		Local_u8Address = Copy_u8YPos;
	}
	else if (Copy_u8XPos == 1)
	{
		/* location is on the second line */
		Local_u8Address = Copy_u8YPos + 0x40;
	}

	/* Send the Address to DDRAM */
	/* +128 is to SET BIT number 7 to 1 */
	CLCD_voidSendCommand(Local_u8Address + 128);
}

/* A function to send a special Character */
void CLCD_voidSendSpecialCharacter (u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAM_Address = 0;
	u8 Local_u8Iterator;

	/* Calculate the CGRAM  Address whose each block is 8 bytes */
	Local_u8CGRAM_Address = Copy_u8PatternNumber * 8;

	/* Send the Address to CGRAM */
	/* +64 is to SET BIT number 6 to 1 */
	CLCD_voidSendCommand(Local_u8CGRAM_Address + 64);

	/* Write the pattern into the SGRAM */
	for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}

	/* Go back to DDRAM to display pattern */
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

	/* Display the pattern written in CGRAM */
	CLCD_voidSendData(Copy_u8PatternNumber);
}

/* A function to send Digit */
void CLCD_voidSendDigit (u8 Copy_u8Digit)
{
	/* Convert the Digit to ASCII */
	u8 Local_u8Temp = Copy_u8Digit + 48;

	/* Send the Digit */
	CLCD_voidSendData(Local_u8Temp);
}

/* A function to send a number */
void CLCD_voidSendNumber (u16 Copy_u16Number)
{
	u8 Local_u8Counter = 0, Local_u8Digits = 0, Local_u8Current;
	u16 Local_u16CopyNumber = Copy_u16Number;

	if(0 == Copy_u16Number)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(Local_u16CopyNumber)
		{
			Local_u16CopyNumber /= 10;
			Local_u8Digits++;
		}
		Local_u16CopyNumber = Copy_u16Number;

		for(Local_u8Counter = 0; Local_u8Counter < Local_u8Digits; Local_u8Counter++)
		{
			Local_u8Current = Local_u16CopyNumber / (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
			CLCD_voidSendData(Local_u8Current + '0');
			Local_u16CopyNumber %= (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
		}
	}
}

/* A function to Get Power */
static u16 Private_u16GetPower(u8 Copy_u8Number1, u8 Copy_u8Number2)
{
	u16 Local_u16Result = 1;
	u16 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8Number2; Local_u8Counter++)
	{
		Local_u16Result *= Copy_u8Number1;
	}
	return Local_u16Result;
}
