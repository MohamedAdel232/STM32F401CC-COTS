/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   FM_Program.c                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/* Include driver files */
#include "FM_Interface.h"
#include "FM_Config.h"
#include "FM_Register.h"
#include "FM_Private.h"

/* A function to erase application area */
void FM_voidEraseApplicationArea (void)
{
	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < 6; Local_u8Iterator++)
	{
		FM_voidEraseSector(Local_u8Iterator);
	}
}

/* A function to erase a sector */
void FM_voidEraseSector (u8 Copy_u8Sector)
{
	/* Polling until busy flag is cleared */
	while ((GET_BIT(FM_REGISTER -> FLASH_SR, 16)) == 1);

	/* Unlock flash register */
	if ((GET_BIT(FM_REGISTER -> FLASH_CR, 31)) == 1)
	{
		FM_REGISTER -> FLASH_KEYR = FM_CR_KEY_1;
		FM_REGISTER -> FLASH_KEYR = FM_CR_KEY_2;
	}

	/* Select sector number to erase */
	FM_REGISTER -> FLASH_CR &= ~ ((u32) (0b1111 << 3));
	FM_REGISTER -> FLASH_CR |=   (Copy_u8Sector << 3);

	/* Select erase operation */
	SET_BIT(FM_REGISTER -> FLASH_CR, 1);

	/* Start erase mode */
	SET_BIT(FM_REGISTER -> FLASH_CR, 16);

	/* Polling until busy flag is cleared */
	while ((GET_BIT(FM_REGISTER -> FLASH_SR, 16)) == 1);

	/* Clear end of operation flag */
	CLR_BIT(FM_REGISTER -> FLASH_SR, 0);

	/* Deselect erase mode */
	CLR_BIT(FM_REGISTER -> FLASH_CR, 1);
}

/* A function to write data on a sector */
void FM_voidWriteData (u32 Copy_u32Address, u16* Copy_pu16Data, u16 Copy_u16DataSize)
{
	/* Polling until busy flag is cleared */
	while ((GET_BIT(FM_REGISTER -> FLASH_SR, 16)) == 1);

	/* Unlock flash register */
	if ((GET_BIT(FM_REGISTER -> FLASH_CR, 31)) == 1)
	{
		FM_REGISTER -> FLASH_KEYR = FM_CR_KEY_1;
		FM_REGISTER -> FLASH_KEYR = FM_CR_KEY_2;
	}

	/* Select program size 16 */
	FM_REGISTER -> FLASH_CR &= ~ ((u32) 0b11 << 8);
	FM_REGISTER -> FLASH_CR |=   (0b01 << 8);

	/* Select programming mode */
	SET_BIT(FM_REGISTER -> FLASH_CR, 0);

	/* Write the data */
	for(u16 Local_u16Iterator = 0; Local_u16Iterator < Copy_u16DataSize; Local_u16Iterator++)
	{
		/* Access the address of the flash memory and write on it */
		*((volatile u16*)Copy_u32Address) = Copy_pu16Data[Local_u16Iterator];

		/* Increment the address */
		Copy_u32Address += 2 ;

		/* Polling until busy flag is cleared */
		while ((GET_BIT(FM_REGISTER -> FLASH_SR, 16)) == 1);

		/* Clear end of operation flag */
		CLR_BIT(FM_REGISTER -> FLASH_SR, 0);
	}

	/* Deselect programming mode */
	CLR_BIT(FM_REGISTER -> FLASH_CR, 0);
}
