/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   EXTI_Register.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H

/* EXTI base address */
#define EXTI_BASE_ADDRESS			0x40013C00

/* Define a struct for EXTI registers */
typedef struct
{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
}EXTI_T;

/* Take value from struct to access the registers */
#define EXTI_REGISTER 				((EXTI_T*) EXTI_BASE_ADDRESS)

/* SYSCFG base address */
#define SYSCFG_BASE_ADDRESS			0x40013800

/* Define a struct for SYSCFG registers */
typedef struct
{
	volatile u32 SYSCFG_MEMRMP;
	volatile u32 SYSCFG_PMC;
	volatile u32 SYSCFG_EXTICR[4];
	volatile u32 SYSCFG_CMPCR;
}SYSCFG_T;

/* Take value from struct to access the registers */
#define SYSCFG_REGISTER 				((SYSCFG_T*) SYSCFG_BASE_ADDRESS)

#endif
