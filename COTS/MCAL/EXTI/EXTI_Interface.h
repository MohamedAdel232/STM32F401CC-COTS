/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   EXTI_Interface.h                                                                */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Struct for EXTI pin initialization */
typedef struct
{
	u8 PortID;
	u8 PinID;
	u8 TriggerLevel;
	void (*PF) (void);
}EXTI_PinConfig_t;

/* A function to initialize pin */
u8 EXTI_u8PinInit (EXTI_PinConfig_t* Copy_pstrPinInit);

/* A function to enable INT */
u8 EXTI_u8EnableINT (u8 Copy_u8EXTINum);

/* A function to disable INT */
u8 EXTI_u8DisableINT (u8 Copy_u8EXTINum);

/* A function to clear pending flag */
u8 EXTI_u8ClearPendingFlag (u8 Copy_u8EXTINum);

/* Macros for PORT */
#define EXTI_GPIOA            0b0000
#define EXTI_GPIOB            0b0001
#define EXTI_GPIOC            0b0010

/* Macros for trigger control levels */
#define EXTI_RAISING_EDGE	  0
#define EXTI_FALLING_EDGE	  1
#define EXTI_ON_CHANGE	  	  2

/* enum for Pin */
enum
{
    EXTI_PIN0,
    EXTI_PIN1,
    EXTI_PIN2,
    EXTI_PIN3,
    EXTI_PIN4,
    EXTI_PIN5,
    EXTI_PIN6,
    EXTI_PIN7,
    EXTI_PIN8,
    EXTI_PIN9,
    EXTI_PIN10,
    EXTI_PIN11,
    EXTI_PIN12,
    EXTI_PIN13,
    EXTI_PIN14,
    EXTI_PIN15,
};

#endif
