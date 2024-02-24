/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   SPI_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

/* SPI1 Base address */
#define BASE_ADDRESS 		0x40013000

/* Struct for SPI registers */
typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_Register_t;

/* Take value from the struct to access the registers */
#define SPI_REGISTER 			((SPI_Register_t*)(BASE_ADDRESS))

#endif
