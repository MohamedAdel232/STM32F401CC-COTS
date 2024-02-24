/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   ADC_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef ADC_REGISTER_H
#define ADC_REGISTER_H

/* ADC base address */
#define ADC_BASE_ADDRESS			0x40012000

/* Struct for ADC registers */
typedef struct
{
	volatile u32 ADC_SR;
	volatile u32 ADC_CR1;
	volatile u32 ADC_CR2;
	volatile u32 ADC_SMPR1;
	volatile u32 ADC_SMPR2;
	volatile u32 ADC_JOFR1;
	volatile u32 ADC_JOFR2;
	volatile u32 ADC_JOFR3;
	volatile u32 ADC_JOFR4;
	volatile u32 ADC_HTR;
	volatile u32 ADC_LTR;
	volatile u32 ADC_SQR1;
	volatile u32 ADC_SQR2;
	volatile u32 ADC_SQR3;
	volatile u32 ADC_JSQR;
	volatile u32 ADC_JDR1;
	volatile u32 ADC_JDR2;
	volatile u32 ADC_JDR3;
	volatile u32 ADC_JDR4;
	volatile u32 ADC_DR;
}ADC_t;

/* Take value from the sturct to access the registers */
#define ADC_REGISTER        ((ADC_t*)ADC_BASE_ADDRESS)
#define	ADC_CCR				 (*(volatile u32 *)(ADC_BASE_ADDRESS+0x304))

#endif
