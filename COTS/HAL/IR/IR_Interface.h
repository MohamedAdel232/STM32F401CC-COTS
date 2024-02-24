/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   IR_Interface.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

/* A function to initialize the IR sensor */
void IR_voidInit (u8 Copy_u8IRPort, u8 Copy_u8IRPin);

/* A function to tell if there is an object infront of the sensor */
u8 IR_u8Sense (u8 Copy_u8IRPort, u8 Copy_u8IRPin);

#endif
