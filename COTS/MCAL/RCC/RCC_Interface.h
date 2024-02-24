/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   RCC_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* A function to initialize system clock */
void RCC_voidInitSystemClock (void);

/* A function to enable peripheral clock */
u8 RCC_u8EnablePeripheralClock (u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/* A function to disable peripheral clock */
u8 RCC_u8DisablePeripheralClock (u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

/* Macros for bus ID */
#define RCC_AHB1			0
#define RCC_AHB2			1
#define RCC_APB1			2
#define RCC_APB2			3

/* Macros for peripheral ID */
#define RCC_GPIOA			0
#define RCC_GPIOB			1
#define RCC_USART1			4
#define RCC_ADC1			8
#define RCC_SPI1			12
#define RCC_SYSCFG			14
#define RCC_FMI				15



#endif
