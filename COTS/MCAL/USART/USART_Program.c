/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   USART_Program.c                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "USART_Interface.h"
#include "USART_Config.h"
#include "USART_Private.h"
#include "USART_Register.h"

/* Global pointers to function */
void (*GPF1) (void); 			// Global pointer to function for call back 1
void (*GPF2) (void); 			// Global pointer to function for call back 2
void (*GPF6) (void); 			// Global pointer to function for call back 6


/* A function to initialize USART */
void USART_voidInitialize(USART_Registers_t* Copy_psUSART, USART_Initialize_t* Copy_psInitializeValue, USART_Clock_Initialize_t* Copy_psClockInitializeValue)
{
	/* Initialize the baud rate */
	Copy_psUSART -> USART_BRR = Copy_psInitializeValue -> USART_BaudRate;

	/* Initialize Control register 1 */
	Copy_psUSART -> USART_CR1 = (Copy_psInitializeValue->USART_OverSampling    << USART_CR1_OVER8) 	|
								(Copy_psInitializeValue->USART_WordLength      << USART_CR1_M) 		|
								(Copy_psInitializeValue->USART_ParityControl   << USART_CR1_PCE) 	|
								(Copy_psInitializeValue->USART_ParitySelection << USART_CR1_PS) 	;

	switch (Copy_psInitializeValue->USART_TransmissionDirection)
	{
	case USART_TX: 		SET_BIT(Copy_psUSART-> USART_CR1, USART_CR1_TE); CLR_BIT(Copy_psUSART -> USART_CR1, USART_CR1_RE); break;
	case USART_RX: 		CLR_BIT(Copy_psUSART-> USART_CR1, USART_CR1_TE); SET_BIT(Copy_psUSART -> USART_CR1, USART_CR1_RE); break;
	case USART_TX_RX: 	SET_BIT(Copy_psUSART-> USART_CR1, USART_CR1_TE); SET_BIT(Copy_psUSART -> USART_CR1, USART_CR1_RE); break;
	default: break;
	}

	/* Initialize Control register 2 */
	Copy_psUSART -> USART_CR2 = 	(Copy_psInitializeValue      -> USART_StopBit    	   << USART_CR2_STOP12) 	|
									(Copy_psClockInitializeValue -> USART_ClockEnable      << USART_CR2_CLKEN) 		|
									(Copy_psClockInitializeValue -> USART_ClockPolarity    << USART_CR2_CPOL) 		|
									(Copy_psClockInitializeValue -> USART_ClockPhase       << USART_CR2_CPHA) 		;

	/* Clear the status register */
	Copy_psUSART -> USART_SR = 0;
}

/* A function to enable USART */
void USART_voidEnable (USART_Registers_t* Copy_psUSART)
{
	/* Enable USART */
	SET_BIT(Copy_psUSART->USART_CR1, USART_CR1_UE);
}

/* A function to disable USART */
void USART_voidDisable (USART_Registers_t* Copy_psUSART)
{
	/* Disable USART */
	CLR_BIT(Copy_psUSART->USART_CR1, USART_CR1_UE);
}

/* A function to transmit byte */
void USART_voidTransmitByte (USART_Registers_t* Copy_psUSART, u8 Copy_u8Byte)
{
	/* Polling until transmit data register empty */
	while ((GET_BIT(Copy_psUSART -> USART_SR, USART_SR_TXE)) == 0);

	/* Send the data */
	Copy_psUSART -> USART_DR = Copy_u8Byte;

	/* Polling until transfer is complete */
	while ((GET_BIT(Copy_psUSART -> USART_SR, USART_SR_TC)) == 0);

	/* Clear transmission comlete flag */
	CLR_BIT(Copy_psUSART -> USART_SR, USART_SR_TC);
}

/* A function to transmit string */
void USART_voidTransmitString(USART_Registers_t* Copy_psUSART, u8* Copy_pu8String)
{
	/* Local iterator variable */
	u8 Local_u8Iterator = 0;

	/* Send the string byte by byte until the end of the string '\0' */
	while (Copy_pu8String [Local_u8Iterator] != '\0')
	{
		USART_voidTransmitByte (Copy_psUSART, Copy_pu8String[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}

/* A function to receive byte synchronous no blocking */
u8 USART_u8ReceiveByteSynchronousNoBlocking (USART_Registers_t* Copy_psUSART)
{
	/* Local variable for the received data */
	u8 Local_u8ReceivedData = 0;

	/* Local variable for timeout value */
	u32 Local_u32TimeOut = 0;

	/* Polling until read data register is not empty */
	while (((GET_BIT(Copy_psUSART -> USART_SR, USART_SR_RXNE)) == 0) && (Local_u32TimeOut <  THREESHOULD_VALUE) )
	{
		Local_u32TimeOut ++;
	}

	/* Check why the loop is broken */
	if (Local_u32TimeOut == THREESHOULD_VALUE)
	{
		Local_u8ReceivedData = 255;
	}
	else
	{
		/* Get the received data */
		Local_u8ReceivedData = Copy_psUSART -> USART_DR;
	}

	/* Return the received data */
	return Local_u8ReceivedData;
}

/* A function to receive string synchronous no blocking */
void USART_voidReceiveStringSynchronousNoBlocking (USART_Registers_t* Copy_psUSART, u8 Copy_Au8String [])
{
	/* Local iterator variable */
	u8 Local_u8Iterator = 0;

	/* Local variable for received data */
	u8 Local_u8ReceivedDAta = 0;

	/* Send the string byte by byte until the end of the string '\0' */
	while (Local_u8ReceivedDAta != 255)
	{
		Local_u8ReceivedDAta = USART_u8ReceiveByteSynchronousNoBlocking (Copy_psUSART);
		Copy_Au8String [Local_u8Iterator] = Local_u8ReceivedDAta;
		Local_u8Iterator++;
	}
	Copy_Au8String [Local_u8Iterator] = '\0';
}

/* A function to clear flags */
void USART_voidClearFlags (USART_Registers_t* Copy_psUSART)
{
	/* Clear the status register */
	Copy_psUSART -> USART_SR = 0;
}

/* Call back function for USART1 */
void USART_voidCallBack1 (void (*Pf) (void))
{
	/* Assign the address of the given function to the global pointer to function */
	GPF1 = Pf;
}

/* Call back function for USART2 */
void USART_voidCallBack2 (void (*Pf) (void))
{
	/* Assign the address of the given function to the global pointer to function */
	GPF2 = Pf;
}

/* Call back function for USART6 */
void USART_voidCallBack6 (void (*Pf) (void))
{
	/* Assign the address of the given function to the global pointer to function */
	GPF6 = Pf;
}

/* ISR for USART1 */
void USART1_IRQHandler (void)
{
	/* Clear all flags */
	USART_voidClearFlags (USART1);

	/* Call the call back function */
	GPF1 ();
}

/* ISR for USART1 */
void USART2_IRQHandler (void)
{
	/* Clear all flags */
	USART_voidClearFlags (USART2);

	/* Call the call back function */
	GPF2 ();
}

/* ISR for USART1 */
void USART6_IRQHandler (void)
{
	/* Clear all flags */
	USART_voidClearFlags (USART6);

	/* Call the call back function */
	GPF6 ();
}
