/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   STK_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef STK_REGISTER_H
#define RCC_REGISTER_H

/* Macros for SysTick registers */
#define STK_CTRL						*((volatile u32*)0xE000E010)
#define STK_LOAD						*((volatile u32*)0xE000E014)
#define STK_VAL							*((volatile u32*)0xE000E018)
#define STK_CALIB						*((volatile u32*)0xE000E01C)

#endif
