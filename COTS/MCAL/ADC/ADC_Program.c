/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   ADC_Program.c                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Register.h"

/* A function to initialize ADC */
void ADC_voidInit (void)
{
	/* Disable ADC first */
	CLR_BIT(ADC_REGISTER->ADC_CR2, 0);

	/* Select Right alignment */
	CLR_BIT(ADC_REGISTER->ADC_CR2, 11);

	/* Select prescaller divided by 8 */
	SET_BIT(ADC_CCR, 16);
	SET_BIT(ADC_CCR, 17);

	/* Select 8-bit */
	CLR_BIT(ADC_REGISTER-> ADC_CR1, 24);
	SET_BIT(ADC_REGISTER-> ADC_CR1, 25);

	/* Enable ADC */
	SET_BIT(ADC_REGISTER->ADC_CR2, 0);
}

/* A function to get channel reading synchronous */
u16 ADC_u16GetChannelReading (u8 Copy_u8Channel)
{
	/* Select the channel */
	ADC_REGISTER->ADC_SQR3=0x00000000;
	ADC_REGISTER->ADC_SQR3=Copy_u8Channel;

	/* Start conversion */
	SET_BIT(ADC_REGISTER->ADC_CR2, 30);

	/* Poll until conversion complete */
	while ((GET_BIT(ADC_REGISTER->ADC_SR,1)) == 0);

	/* Return the value */
	return ADC_REGISTER->ADC_DR;
}
