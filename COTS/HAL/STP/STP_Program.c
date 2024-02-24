/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   STP_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/* Include MCAL files */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"

/* Include driver files */
#include "STP_Config.h"
#include "STP_Interface.h"
#include "STP_Private.h"

/* A function to convert from serial to parallel */
void STP_voidSendSerial (u8 Copy_u8Data)
{
	s8 Local_s8Counter;
	u8 Local_u8Bit;

	for (Local_s8Counter = 7; Local_s8Counter >= 0; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8Data, Local_s8Counter);
		GPIO_voidSetPinValue(STP_SERIAL_PIN_PORT, STP_SERIAL_PIN_PIN, Local_u8Bit);

		GPIO_voidSetPinValue(STP_SHIFT_REG_PORT, STP_SHIFT_REG_PIN, GPIO_HIGH);
		STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(STP_SHIFT_REG_PORT, STP_SHIFT_REG_PIN, GPIO_LOW);
		STK_voidSetBusyWait(1);
	}

	GPIO_voidSetPinValue(STP_STOGRAGE_REG_PORT, STP_STOGRAGE_REG_PIN, GPIO_HIGH);
	STK_voidSetBusyWait(1);
	GPIO_voidSetPinValue(STP_STOGRAGE_REG_PORT, STP_STOGRAGE_REG_PIN, GPIO_LOW);
	STK_voidSetBusyWait(1);
}



