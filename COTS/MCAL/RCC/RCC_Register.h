/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   RCC_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef RCC_REGISTER_H
#define RCC_REGISTER_H

/* A macro for RCC base address */
#define RCC_BASE_ADDRESS					0x40023800

/* Macros for RCC registers */
#define RCC_CR								*((volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR							*((volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR							*((volatile u32*)(RCC_BASE_ADDRESS + 0x30))
#define RCC_AHB2ENR							*((volatile u32*)(RCC_BASE_ADDRESS + 0x34))
#define RCC_APB1ENR							*((volatile u32*)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR							*((volatile u32*)(RCC_BASE_ADDRESS + 0x44))

#endif
