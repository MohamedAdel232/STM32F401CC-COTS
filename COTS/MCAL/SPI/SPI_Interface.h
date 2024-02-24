/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   SPI_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* A function to initialize SPI */
void SPI_voidInit (void);

/* A function to transmit and receive data synchronous */
void SPI_voidTransmitReceiveSynch (u8 Copy_u8TransmittedData, u8* Copy_pu8ReceivedData);

/* A function to transmit and receive data Asynchronous */
void SPI_voidTransmitReceiveAsynch (u8 Copy_u8TransmittedData, void (*PF)(u8));

#endif
