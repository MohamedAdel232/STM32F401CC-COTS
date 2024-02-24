/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   SPI_Program.c                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/* Include MCAL files */
#include "../../MCAL/GPIO/GPIO_Interface.h"

/* Include driver files */
#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Register.h"
#include "SPI_Private.h"

/* A function to initialize SPI */
void SPI_voidInit (void)
{
	/* Select 8-bit data */
	CLR_BIT(SPI_REGISTER -> SPI_CR1, 11);

	/* Enable Hardware slave management */
	CLR_BIT(SPI_REGISTER -> SPI_CR1, 9);

	/* Select MSB frame format */
	CLR_BIT(SPI_REGISTER -> SPI_CR1, 7);

	/* Select fPCLK/256 frequency */
	SET_BIT(SPI_REGISTER -> SPI_CR1, 5);
	SET_BIT(SPI_REGISTER -> SPI_CR1, 4);
	SET_BIT(SPI_REGISTER -> SPI_CR1, 3);

	/* Select master or slave */
#if SPI_NODE_STATUE == SPI_MASTER
	SET_BIT(SPI_REGISTER -> SPI_CR1, 2);
#elif SPI_NODE_STATUE == SPI_SLAVE
	CLR_BIT(SPI_REGISTER -> SPI_CR1, 2);
#endif

	/* Select high state as idle clock polarity */
	SET_BIT(SPI_REGISTER -> SPI_CR1, 1);

	/* Select The second clock transition is the first data capture edge */
	SET_BIT(SPI_REGISTER -> SPI_CR1, 0);

	/* Enable SPI */
	SET_BIT(SPI_REGISTER -> SPI_CR1, 6);
}

/* A function to transmit and receive data synchronous */
void SPI_voidTransmitReceiveSynch (u8 Copy_u8TransmittedData, u8* Copy_pu8ReceivedData)
{
	/* Transmit data to data register */
	SPI_REGISTER -> SPI_DR = Copy_u8TransmittedData;

	/* Polling until transfer complete */
	while ((GET_BIT(SPI_REGISTER -> SPI_SR, 7)) == 1);

	/* Receive data to data register */
	*Copy_pu8ReceivedData = SPI_REGISTER -> SPI_DR;
}

/* A function to transmit and receive data Asynchronous */
void SPI_voidTransmitReceiveAsynch (u8 Copy_u8TransmittedData, void (*PF)(u8))
{
	/* To do */

}

