/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   RCC_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Private.h"
#include "RCC_Register.h"

/* A function to initialize system clock */
void RCC_voidInitSystemClock (void)
{
	/* Select clock source */
#if RCC_CLOCK_SOURCE == HSI
	/* HSI clock enable */
	SET_BIT(RCC_CR, 0);
	/* Select HSI as a clock source */
	CLR_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);
#elif RCC_CLOCK_SOURCE == HSE_RC
	/* Enable bypass */
	SET_BIT(RCC_CR, 18);
	/* HSE clock enable */
	SET_BIT(RCC_CR, 16);
	/* Select HSE as a clock source */
	SET_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);
#elif RCC_CLOCK_SOURCE == HSE_OSC
	/* Disable bypass */
	CLR_BIT(RCC_CR, 18);
	/* HSE clock enable */
	SET_BIT(RCC_CR, 16);
	/* Select HSE as a clock source */
	SET_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);
#elif RCC_CLOCK_SOURCE == PLL
	/* To do */
#else
	/* Error */
#error Invalid RCC_CLOCK_SOURCE selection
#endif

	/* Select AHB prescaler */
#if RCC_AHB_PRESCALLER == SYSTEM_CLOCK_DIVIDED_BY_2
	/* Select AHB divided by 2 */
	CLR_BIT(RCC_CFGR, 4);
	CLR_BIT(RCC_CFGR, 5);
	CLR_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 7);
#elif RCC_AHB_PRESCALLER == SYSTEM_CLOCK_DIVIDED_BY_4
	/* Select AHB divided by 2 */
	SET_BIT(RCC_CFGR, 4);
	CLR_BIT(RCC_CFGR, 5);
	CLR_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 7);
#elif RCC_AHB_PRESCALLER == SYSTEM_CLOCK_DIVIDED_BY_8
	/* Select AHB divided by 2 */
	CLR_BIT(RCC_CFGR, 4);
	SET_BIT(RCC_CFGR, 5);
	CLR_BIT(RCC_CFGR, 6);
	SET_BIT(RCC_CFGR, 7);
#else
	/* Error */
#error Invalid RCC_AHB_PRESCALLER selection
#endif
}

/* A function to enable peripheral clock */
u8 RCC_u8EnablePeripheralClock (u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	/* Error state */
	u8 Local_u8ErrorState = OK;
	/* Validation for Copy_u8PeripheralID */
	if (Copy_u8PeripheralID > 31)
	{
		Local_u8ErrorState = NOK;
	}
	else
	{
		switch (Copy_u8BusID)
		{
		case RCC_AHB1: SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralID);		break;
		case RCC_AHB2: SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralID);		break;
		case RCC_APB1: SET_BIT(RCC_APB1ENR, Copy_u8PeripheralID);		break;
		case RCC_APB2: SET_BIT(RCC_APB2ENR, Copy_u8PeripheralID);		break;
		default: Local_u8ErrorState = NOK;								break;
		}
	}
	/* Return error state */
	return Local_u8ErrorState;
}

/* A function to disable peripheral clock */
u8 RCC_u8DisablePeripheralClock (u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	/* Error state */
	u8 Local_u8ErrorState = OK;
	/* Validation for Copy_u8PeripheralID */
	if (Copy_u8PeripheralID > 31)
	{
		Local_u8ErrorState = NOK;
	}
	else
	{
		switch (Copy_u8BusID)
		{
		case RCC_AHB1: CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralID);		break;
		case RCC_AHB2: CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralID);		break;
		case RCC_APB1: CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralID);		break;
		case RCC_APB2: CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralID);		break;
		default: Local_u8ErrorState = NOK;								break;
		}
	}
	/* Return error state */
	return Local_u8ErrorState;
}
