/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   IR_Program.c                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include MCAL files */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"

/* Include driver files */
#include "IR_Interface.h"
#include "IR_Config.h"
#include "IR_Private.h"

/* A function to initialize the IR sensor */
void IR_voidInit (u8 Copy_u8IRPort, u8 Copy_u8IRPin)
{
	/* Make the OUT pin in the sensor input pin */
	GPIO_voidPinInit(Copy_u8IRPort, Copy_u8IRPin, GPIO_INPUT, GPIO_PU_RESISTANCE, GPIO_LOW_SPEED, 0);
}

/* A function to tell if there is an object infront of the sensor */
u8 IR_u8Sense (u8 Copy_u8IRPort, u8 Copy_u8IRPin)
{
	/* Local variable to carry the pin value */
	u8 Local_u8Value;

	/* Get the value of the pin */
	Local_u8Value = GPIO_u8GetPinValue(Copy_u8IRPort, Copy_u8IRPin);

	/* Return the value of the pin */
	return Local_u8Value;
}

