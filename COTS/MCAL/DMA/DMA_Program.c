/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   DMA_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "DMA_Interface.h"
#include "DMA_Config.h"
#include "DMA_Private.h"
#include "DMA_Register.h"

/* Global pointer to function */
void (*Gpf) (void) = NULL;

/* A function to initialize DMA */
void DMA_voidInit (void)
{
	/* Make sure DMA is disabled at first */
	CLR_BIT(DMA2_REGISTER -> S[0].DMA_CR, 0);

	/* 4- Transfer complete interrupt enable
	 * 7- Memory-to-memory
	 * 8- Circular mode
	 * 9- Peripheral increment mode
	 * 10- Memory increment mode
	 * 12- Peripheral data size
	 * 14- Memory data size
	 */
	DMA2_REGISTER -> S[0].DMA_CR |= (1<<14) | (1<<12) | (1<<10) | (1<<9) | (1<<8) | (1<<7) | (1<<4);

	/* 0- FIFO threshold selection
	 * 1- FIFO threshold selection
	 * 2- Direct mode disable
	 */
	DMA2_REGISTER -> S[0].DMA_FCR |= (1<<0) | (1<<1) | (1<<2);
}

/* A function to set stream */
void DMA_voidSetSteram (u8 Copy_u8StreamID,
						u32* Copy_pu32SrcAddress,
						u32* Copy_pu32DesAddress,
						u32 Copy_u32BloclSize
						)
{
	DMA2_REGISTER -> S[Copy_u8StreamID].DMA_PAR = Copy_pu32SrcAddress;
	DMA2_REGISTER -> S[Copy_u8StreamID].DMA_M0AR = Copy_pu32DesAddress;
	DMA2_REGISTER -> S[Copy_u8StreamID].DMA_NDTR = Copy_u32BloclSize;
}

/* A function to clear flags */
void DMA_voidClearFlag(void)
{
	DMA2_REGISTER -> DMA_LIFCR |= (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5);
}

/* A function to enable steam */
void DMA_voidEnableStream (u8 Copy_u8StreamID)
{
	DMA_voidClearFlag();
	SET_BIT(DMA2_REGISTER -> S[Copy_u8StreamID].DMA_CR, 0);
}

/* Call back function */
void DMA_voidSetCallBack (u8 Copy_u8StreamID, void (*pf) (void))
{
	Gpf = pf;
}

/* DMA2 ISR */
void DMA2_Stream0_IRQHandler (void)
{
	Gpf();
	DMA_voidClearFlag();
	CLR_BIT(DMA2_REGISTER -> S[0].DMA_CR, 0);
}
