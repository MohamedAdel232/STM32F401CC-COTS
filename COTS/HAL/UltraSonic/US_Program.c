/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   US_Program.c                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include MCAL files */
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_Interface.h"

/* Include driver files */
#include "US_Interface.h"
#include "US_Config.h"
#include "US_Private.h"

/* A function to Initialize the Ultrasonic */
void US_voidInit (u8 Copy_u8TriggerPort, u8 Copy_u8TriggerPin, u8 Copy_u8EchoPort, u8 Copy_u8EchoPin)
{
	/* Initialize trigger pin as output pin */
	GPIO_voidPinInit(Copy_u8TriggerPort, Copy_u8TriggerPin, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_LOW_SPEED, 0);

	/* Initialize trigger pin as input pin */
	GPIO_voidPinInit(Copy_u8EchoPort, Copy_u8EchoPin, GPIO_INPUT, GPIO_NO_P_RESISTANCE, GPIO_LOW_SPEED, 0);

	/* Make sure that trigger pin is low */
	GPIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, GPIO_LOW);
}

/* A function to get the distance */
u32 US_u32GetDistance (u8 Copy_u8TriggerPort, u8 Copy_u8TriggerPin, u8 Copy_u8EchoPort, u8 Copy_u8EchoPin)
{
	/* Variables decelerations */
	u32 Local_u32Distance = 0;
	u32 Local_u32StartTime;
	u32 Local_u32EndTime;
	u32 Local_u32Time;

	/* Trigger the Trigger pin for 10 MS */
	GPIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, GPIO_HIGH);
	STK_voidSetBusyWait(10);
	GPIO_voidSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, GPIO_LOW);

	/* Load the STK with a big value */
	STK_voidLoadValue(1000000);

	/* Pool until the Echo pin become high */
	while ((GPIO_u8GetPinValue(Copy_u8EchoPort, Copy_u8EchoPin)) != 1);

	/* Save the Start Time */
	Local_u32StartTime = STK_u32GetElapsedTime();

	/* Pool until the Echo pin become low */
	while ((GPIO_u8GetPinValue(Copy_u8EchoPort, Copy_u8EchoPin)) == 1);

	/* Save the End Time */
	Local_u32EndTime = STK_u32GetElapsedTime();

	/* Calculate the time of the signal */
	Local_u32Time = Local_u32EndTime - Local_u32StartTime;


	/* Calculate the distance */
	Local_u32Distance = (Local_u32Time * 0.0343) / 2;

	/* Return the distance value */
	return Local_u32Distance;
}
