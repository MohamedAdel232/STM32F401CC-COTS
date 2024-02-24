/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   USART_Private.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* Status register (USART_SR) bits */
#define USART_SR_TXE									7						// Transmit data register empty
#define USART_SR_TC									    6						// Transmission complete
#define USART_SR_RXNE									5						// Read data register not empty

/* Control register 1 (USART_CR1) bits */
#define USART_CR1_OVER8 								15						// Oversampling mode bit
#define USART_CR1_UE									13						// USART enable bit
#define USART_CR1_M										12						// Word length
#define USART_CR1_PCE									10						// Parity control enable
#define USART_CR1_PS									9						// Parity selection
#define USART_CR1_TE									3						// Transmission enable
#define USART_CR1_RE									2						// Receiver enable

/* Control register 2 (USART_CR2) bits */
#define USART_CR2_STOP13								13						// STOP bit 13
#define USART_CR2_STOP12								12						// STOP bit 12
#define USART_CR2_CLKEN									11						// Clock enable
#define USART_CR2_CPOL									10						// Clock polarity
#define USART_CR2_CPHA									9						// Clock phase



#endif
