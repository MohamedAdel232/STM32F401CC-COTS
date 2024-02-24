/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   STK_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Private.h"
#include "STK_Register.h"

/* Global pointer to function */
void (*CallBack) (void) = NULL;

/* Global variable for single or periodic interval */
u8 STK_u8IntervalMode = 0;

/* A function to initialize SysTick */
void STK_voidInit (void)
{
	/* Start by disabling SysTick */
	STK_voidStopInterval();

	/* Select clock source */
#if STK_CLOCK_SOURCE == STK_AHB_CLOCK
	SET_BIT(STK_CTRL, 2);
#elif STK_CLOCK_SOURCE == STK_AHB_CLOCK_DIVIDED_BY_8
	CLR_BIT(STK_CTRL, 2);
#endif
}

/* A function to set busy wait */
void STK_voidSetBusyWait (u32 Copy_u32TimeMs)
{
	/* Put the value in LOAD register */
	STK_LOAD = Copy_u32TimeMs;

	/* Enable SysTik */
	SET_BIT(STK_CTRL, 0);

	/* Polling until count down is complete */
	while ((GET_BIT(STK_CTRL, 16)) == 0);

	/* Stop SysTik to clear past data */
	STK_voidStopInterval();
}

/* A function to set single interval */
void STK_voidSetIntervalSingle (u32 Copy_u32TimeMs, void (*Copy_ptr) (void))
{
	/* Make sure that the pointer is not equal to NULL */
	if (Copy_ptr != NULL)
	{
		/* Stop SysTick */
		CLR_BIT(STK_CTRL, 0);
		STK_VAL = 0;

		/* Put the value in LOAD register */
		STK_LOAD = Copy_u32TimeMs;

		/* Enable SysTik */
		SET_BIT(STK_CTRL, 0);

		/* Save Call Back */
		CallBack = Copy_ptr;

		/* Set single interval */
		STK_u8IntervalMode = STK_SINGLE_INTERVAL;

		/* Enable SysTick Interrupt */
		SET_BIT(STK_CTRL, 1);
	}
}

/* A function to set periodic interval */
void STK_voidSetIntervalPeriodic (u32 Copy_u32TimeMs, void (*Copy_ptr) (void))
{
	/* Make sure that the pointer is not equal to NULL */
	if (Copy_ptr != NULL)
	{
		/* Stop SysTick */
		CLR_BIT(STK_CTRL, 0);
		STK_VAL = 0;

		/* Put the value in LOAD register */
		STK_LOAD = Copy_u32TimeMs;

		/* Enable SysTik */
		SET_BIT(STK_CTRL, 0);

		/* Save Call Back */
		CallBack = Copy_ptr;

		/* Set periodic interval */
		STK_u8IntervalMode = STK_PERIODIC_INTERVAL;

		/* Enable SysTick Interrupt */
		SET_BIT(STK_CTRL, 1);
	}
}

/* A function to stop SysTick */
void STK_voidStopInterval (void)
{
	/* Disable Interrupt */
	CLR_BIT(STK_CTRL, 1);

	/* Disable SysTick */
	CLR_BIT(STK_CTRL, 0);

	/* Clear registers */
	STK_VAL = 0;
	STK_LOAD = 0;
}

/* A function to get remaining time */
u32 STK_u32GetRemainingTime (void)
{
	u32 Local_u32Temp = STK_VAL;
	return Local_u32Temp;
}

/* A function to get elapsed time */
u32 STK_u32GetElapsedTime (void)
{
	u32 Local_u32Temp = STK_LOAD - STK_VAL;
	return Local_u32Temp;
}

/* A function to Load the register */
void STK_voidLoadValue (u32 Copy_u32Value)
{
	/* Put the value in LOAD register */
	STK_LOAD = Copy_u32Value;

	/* Enable SysTik */
	SET_BIT(STK_CTRL, 0);
}

/* ISR for SysTick */
void SysTick_Handler (void)
{
	/* Check interval mode */
	if (STK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		STK_voidStopInterval();
	}

	/* Make sure that the pointer is not equal to NULL */
	if (CallBack != NULL)
	{
		CallBack();
	}

	/* Clear interrupt flag by reading it */
	u8 Local_u8Temp = 0 ;
	Local_u8Temp = GET_BIT(STK_CTRL,16);
}
