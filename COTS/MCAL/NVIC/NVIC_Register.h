/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   NVIC_Register.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef NVIC_REGISTER_H
#define NVIC_REGISTER_H

/* NVIC base address */
#define NVIC_BASE_ADDRESS			0xE000E100

/* Define struct to carry NVIC Registers */
typedef struct
{
	volatile u32 NVIC_ISER[32];
	volatile u32 NVIC_ICER[32];
	volatile u32 NVIC_ISPR[32];
	volatile u32 NVIC_ICPR[32];
	volatile u32 NVIC_IABR[32];
	u32 RESERVED [32];
	volatile u8 NVIC_IPR[48];
	volatile u32 NVIC_STIR;
}NVIC_T;

/* Take Value from struct to access the registers */
#define NVIC_REGISTER			 ((volatile NVIC_T*) NVIC_BASE_ADDRESS)

/* System control block register address */
#define SCB_AIRCR				*((volatile u32*)0xE000ED0C)

#endif
