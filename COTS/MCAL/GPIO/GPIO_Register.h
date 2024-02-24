/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   GPIO_Register.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

/* A macro for GPIOA base address */
#define GPIOA_BAASE_ADDRESS					0x40020000

/* A macro for GPIOB base address */
#define GPIOB_BAASE_ADDRESS					0x40020400

/* A macro for GPIOc base address */
#define GPIOC_BAASE_ADDRESS					0x40020800

/* Define a struct for GPIO registers */
typedef struct
{
	u32 GPIO_MODER;
	u32 GPIO_OTYPER;
	u32 GPIO_OSPEEDR;
	u32 GPIO_PUPDR;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_LCKR;
	u32 GPIO_AFRL;
	u32 GPIO_AFRH;
}GPIO_T;

/* Take value from the struct to define GPIO registers */
#define GPIOA_REGISTER					((volatile GPIO_T*)(GPIOA_BAASE_ADDRESS))
#define GPIOB_REGISTER					((volatile GPIO_T*)(GPIOB_BAASE_ADDRESS))
#define GPIOC_REGISTER					((volatile GPIO_T*)(GPIOC_BAASE_ADDRESS))

#endif
