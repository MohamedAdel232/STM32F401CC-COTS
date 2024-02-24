/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   FM_Register.h                                                                   */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef FM_REGISTER_H
#define FM_REGISTER_H

/* Flash memory interface base address */
#define FM_BASE_ADDRESS				0x40023C00

/* Struct for flash memory interface registers */
typedef struct
{
	volatile u32 FLASH_ACR;					// Flash access control register
	volatile u32 FLASH_KEYR;				// Flash key register
	volatile u32 FLASH_OPTKEYR;				// Flash option key register
	volatile u32 FLASH_SR;					// Flash status register
	volatile u32 FLASH_CR;					// Flash control register
	volatile u32 FLASH_OPTCR;				// Flash option control register
}FM_Register_t;

/* Access flash memory interface registers */
#define FM_REGISTER 		((FM_Register_t*)(FM_BASE_ADDRESS))

#endif
