/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   GPIO_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* A function to set pin mode */
void GPIO_voidSetPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

/* A function to set pin type */
void GPIO_voidSetPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type);

/* A function to set pin speed */
void GPIO_voidSetPinSpeed (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed);

/* A function to set pin AF */
void GPIO_voidSetPinAF (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AF);

/* A function to initialize a pin */
void GPIO_voidPinInit (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode, u8 Copy_u8Type, u8 Copy_u8Speed, u8 Copy_u8AF);

/* A function to set port mode */
void GPIO_voidSetPortMode (u8 Copy_u8Port, u8 Copy_u8Mode);

/* A function to set port type */
void GPIO_voidSetPortType(u8 Copy_u8Port, u8 Copy_u8Type);

/* A function to set port speed */
void GPIO_voidSetPortSpeed (u8 Copy_u8Port, u8 Copy_u8Speed);

/* A function to initialize a port */
void GPIO_voidPortInit (u8 Copy_u8Port, u8 Copy_u8Mode, u8 Copy_u8Type, u8 Copy_u8Speed);

/* A function to Get pin value */
u8 GPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin);

/* A function to set pin value */
void GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/* A function to set pin value atomic */
void GPIO_voidSetPinValueAtomic (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/* A function to lock register */
void GPIO_voidLockPin (u8 Copy_u8Port, u8 Copy_u8Pin);

/* A function to set port value */
void GPIO_voidSetPortValueu8NonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value);

/* Macros for port */
#define GPIO_PORTA					0
#define GPIO_PORTB					1
#define GPIO_PORTC					2

/* Macros for pin */
#define GPIO_PIN0					0
#define GPIO_PIN1					1
#define GPIO_PIN2					2
#define GPIO_PIN3					3
#define GPIO_PIN4					4
#define GPIO_PIN5					5
#define GPIO_PIN6					6
#define GPIO_PIN7					7
#define GPIO_PIN8					8
#define GPIO_PIN9					9
#define GPIO_PIN10					10
#define GPIO_PIN11					11
#define GPIO_PIN12					12
#define GPIO_PIN13					13
#define GPIO_PIN14					14
#define GPIO_PIN15					15

/* Macros for mode */
#define GPIO_INPUT					0
#define GPIO_OUTPUT					1
#define GPIO_AF			   			2
#define GPIO_ANALOG					3

/* Macros for type */
#define GPIO_PUSH_PULL				0
#define GPIO_OPEN_DRAIN				1
#define GPIO_NO_P_RESISTANCE		2
#define GPIO_PU_RESISTANCE			3
#define GPIO_PD_RESISTANCE			4

/* Macros for speed */
#define GPIO_LOW_SPEED				0
#define GPIO_MEDUIM_SPEED			1
#define GPIO_HIGH_SPEED				2

/* Macros for value */
#define GPIO_LOW					0
#define GPIO_HIGH					1

/* Macros for atomic value */
#define GPIO_RESET					0
#define GPIO_SET					1

#endif
