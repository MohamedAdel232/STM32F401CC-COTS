/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   USART_Interface.h                                                               */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/* USART base address */
#define USAR1_BASE_ADDRESS				0x40011000					// USART1 base address
#define USAR2_BASE_ADDRESS				0x40004400					// USART2 base address
#define USAR6_BASE_ADDRESS				0x40011400					// USART6 base address

/* Struct for USART registers */
typedef struct
{
	volatile u32 USART_SR;						// Status register (USART_SR)
	volatile u32 USART_DR;						// Data register (USART_DR)
	volatile u32 USART_BRR;						// Baud rate register (USART_BRR)
	volatile u32 USART_CR1;						// Control register 1 (USART_CR1)
	volatile u32 USART_CR2;						// Control register 2 (USART_CR2)
	volatile u32 USART_CR3;						// Control register 3 (USART_CR3)
	volatile u32 USART_GTPR;					// Guard time and prescaler register (USART_GTPR)
}USART_Registers_t;

/* Access USART registers */
#define USART1								((USART_Registers_t*) (USAR1_BASE_ADDRESS))			// USART1
#define USART2								((USART_Registers_t*) (USAR2_BASE_ADDRESS))			// USART2
#define USART6								((USART_Registers_t*) (USAR6_BASE_ADDRESS))			// USART6

/* USART baud rates */
typedef enum
{
    B_1200   =  0x44505400,					// 1200   Baud rate
    B_2400   =  0x43d05800,					// 2400   Baud rate
    B_9600   =  0x683,						// 9600   Baud rate
    B_19200  =  0x42504000,					// 19200  Baud rate
    B_38400  =  0x41d08000,					// 38400  Baud rate
    B_57600  =  0x418b0000,					// 57600  Baud rate
    B_115200 =  0x410b0000					// 115200 Baud rate
}USART_BaudRate_t;

/* USART initialize */
typedef struct
{
	u32 USART_BaudRate;
	u8  USART_OverSampling;
	u8  USART_WordLength;
	u8  USART_ParityControl;
	u8  USART_ParitySelection;
	u8  USART_TransmissionDirection;
	u8  USART_StopBit;
}USART_Initialize_t;

/* USART clock initialize */
typedef struct
{
	u8 USART_ClockEnable;
	u8 USART_ClockPolarity;
	u8 USART_ClockPhase;
}USART_Clock_Initialize_t;

/* Over sampling mode */
#define OVER_SAMPLING_BY_16					0
#define OVER_SAMPLING_BY_8					1

/* Word length */
#define DATA_BITS_8							0
#define DATA_BITS_16						1

/* Parity control enable */
#define PARITY_CONTROL_DISABLE				0
#define PARITY_CONTROL_ENALBLE				1

/* Parity selection */
#define USART_EVEN_PARITY					0
#define USART_ODD_PARITY					1

/* Stop bits */
#define USART_ONE_STOP_BIT					0
#define USART_HALF_STOP_BIT					1
#define USART_TWO_STOP_BIT					2
#define USART_ONE_HALF_STOP_BIT				3

/* Transmission direction */
#define USART_TX							0
#define USART_RX							1
#define USART_TX_RX							2

/* Clock enable */
#define USART_CLOCK_DISABLE					0
#define USART_CLOCK_ENABLE					1

/* Clock polarity */
#define USART_STEADY_LOW_VALUE_ON_CLK		0
#define USART_STEADY_HIGH_VALUE_ON_CLK		1

/* Clock phase */
#define USART_CLOCK_PHASE_AT_FIRST_CLK		0
#define USART_CLOCK_PHASE_AT_SECOND_CLK		1

/* A function to initialize USART */
void USART_voidInitialize(USART_Registers_t* Copy_psUSART, USART_Initialize_t* Copy_psInitializeValue, USART_Clock_Initialize_t* Copy_psClockInitializeValue);

/* A function to enable USART */
void USART_voidEnable (USART_Registers_t* Copy_psUSART);

/* A function to disable USART */
void USART_voidDisable (USART_Registers_t* Copy_psUSART);

/* A function to transmit byte */
void USART_voidTransmitByte (USART_Registers_t* Copy_psUSART, u8 Copy_u8Byte);

/* A function to transmit string */
void USART_voidTransmitString(USART_Registers_t* Copy_psUSART, u8* Copy_pu8String);

/* A function to receive byte synchronous no blocking */
u8 USART_u8ReceiveByteSynchronousNoBlocking (USART_Registers_t* Copy_psUSART);

/* A function to receive string synchronous no blocking */
void USART_voidReceiveStringSynchronousNoBlocking (USART_Registers_t* Copy_psUSART, u8 Copy_Au8String []);

/* A function to clear flags */
void USART_voidClearFlags (USART_Registers_t* Copy_psUSART);

/* Call back function for USART1 */
void USART_voidCallBack1 (void (*Pf) (void));

/* Call back function for USART2 */
void USART_voidCallBack2 (void (*Pf) (void));

/* Call back function for USART6 */
void USART_voidCallBack6 (void (*Pf) (void));

#endif
