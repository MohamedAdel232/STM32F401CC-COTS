/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   ADC_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* A function to initialize ADC */
void ADC_voidInit (void);

/* A function to get channel reading synchronous */
u16 ADC_u16GetChannelReading (u8 Copy_u8Channel);

#endif
