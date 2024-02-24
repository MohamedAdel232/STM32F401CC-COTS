/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   EXTI_Program.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "../RCC/RCC_Interface.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"

/* Global array of pointer to functions */
void (*ECallBack [16]) (void) = {NULL};

/* A function to initialize pin */
u8 EXTI_u8PinInit (EXTI_PinConfig_t* Copy_pstrPinInit)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8ShiftValue;
	if ((Copy_pstrPinInit != NULL) || (Copy_pstrPinInit->PortID <= EXTI_GPIOC) || (Copy_pstrPinInit->PinID <= EXTI_PIN15))
	{
		/* Enable SYSCFG clock source */
		RCC_u8EnablePeripheralClock(RCC_APB2, RCC_SYSCFG);

		/* Enable Interrupt */
		EXTI_u8EnableINT(Copy_pstrPinInit->PinID);

		/* to do */
		Local_u8ShiftValue = (Copy_pstrPinInit->PinID % 4) * 4 ;
		SYSCFG_REGISTER->SYSCFG_EXTICR[(Copy_pstrPinInit->PinID / 4)] &= ~( 0b1111 << Local_u8ShiftValue ) ;
		SYSCFG_REGISTER->SYSCFG_EXTICR[(Copy_pstrPinInit->PinID / 4)] |=  ( (Copy_pstrPinInit->PortID) << Local_u8ShiftValue );

		/* Select trigger control levels */
		switch (Copy_pstrPinInit -> TriggerLevel)
		{
		case EXTI_RAISING_EDGE:
			CLR_BIT(EXTI_REGISTER -> EXTI_FTSR, Copy_pstrPinInit->PinID);
			SET_BIT(EXTI_REGISTER -> EXTI_RTSR, Copy_pstrPinInit->PinID);
			break;
		case EXTI_FALLING_EDGE:
			CLR_BIT(EXTI_REGISTER -> EXTI_RTSR, Copy_pstrPinInit->PinID);
			SET_BIT(EXTI_REGISTER -> EXTI_FTSR, Copy_pstrPinInit->PinID);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(EXTI_REGISTER -> EXTI_RTSR, Copy_pstrPinInit->PinID);
			SET_BIT(EXTI_REGISTER -> EXTI_FTSR, Copy_pstrPinInit->PinID);
			break;
		default: Local_u8ErrorState = NOK;
		break;
		}

		/* Set call back */
		ECallBack [Copy_pstrPinInit->PinID] = Copy_pstrPinInit -> PF;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/* A function to enable INT */
u8 EXTI_u8EnableINT (u8 Copy_u8EXTINum)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8EXTINum <= 15)
	{
		SET_BIT(EXTI_REGISTER -> EXTI_IMR, Copy_u8EXTINum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/* A function to disable INT */
u8 EXTI_u8DisableINT (u8 Copy_u8EXTINum)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8EXTINum <= 15)
	{
		CLR_BIT(EXTI_REGISTER -> EXTI_IMR, Copy_u8EXTINum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/* A function to clear pending flag */
u8 EXTI_u8ClearPendingFlag (u8 Copy_u8EXTINum)
{
	u8 Local_u8ErrorState = OK;
	if (Copy_u8EXTINum <= 15)
	{
		SET_BIT(EXTI_REGISTER -> EXTI_PR, Copy_u8EXTINum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/* ISR functions */
void EXTI0_IRQHandler (void)
{
	if (ECallBack[EXTI_PIN0] != NULL)
	{
		ECallBack[EXTI_PIN0] ();
	}
	EXTI_u8ClearPendingFlag(EXTI_PIN0);
}
