/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   NVIC_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"
#include "NVIC_Register.h"

u8 Global_u8PriorityOption = 0;

/* A function to enable peripheral interrupt */
void NVIC_voidEnablePeripheralINT (u8 Copy_u8INTID)
{
	NVIC_REGISTER -> NVIC_ISER [(Copy_u8INTID / 32)] = (1 << (Copy_u8INTID % 32));
}

/* A function to disable peripheral interrupt */
void NVIC_voidDisablePeripheralINT (u8 Copy_u8INTID)
{
	NVIC_REGISTER -> NVIC_ICER [(Copy_u8INTID / 32)] = (1 << (Copy_u8INTID % 32));
}

/* A function to set pending flag */
void NVIC_voidSetPendingFlag (u8 Copy_u8INTID)
{
	NVIC_REGISTER -> NVIC_ISPR [(Copy_u8INTID / 32)] = (1 << (Copy_u8INTID % 32));
}

/* A function to clear pending flag */
void NVIC_voidClearPendingFlag (u8 Copy_u8INTID)
{
	NVIC_REGISTER -> NVIC_ICPR [(Copy_u8INTID / 32)] = (1 << (Copy_u8INTID % 32));
}

/* A function to set priority configurations */
void NVIC_voidSetPriorityConfiguration (u8 Copy_u8PriorityOption)
{
	Global_u8PriorityOption = Copy_u8PriorityOption;
	SCB_AIRCR = VECTOR_KEY | (Copy_u8PriorityOption << 8);
}

/* A function to set INT priority */
void NVIC_voidSetINTPriority (u8 Copy_u8INTID, u8 Copy_u8GroupID, u8 Copy_u8SubGroupID)
{
	 u8 Local_u8Priority = Copy_u8SubGroupID | (Copy_u8GroupID << (Global_u8PriorityOption - GR4BITS_SUBGR0BITS));
	 NVIC_REGISTER -> NVIC_IPR[Copy_u8INTID] = (Local_u8Priority << 4);
}
