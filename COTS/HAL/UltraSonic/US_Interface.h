/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   US_Interface.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef US_INTERFACE_H
#define US_INTERFACE_H

/* A function to Initialize the Ultrasonic */
void US_voidInit (u8 Copy_u8TriggerPort, u8 Copy_u8TriggerPin, u8 Copy_u8EchoPort, u8 Copy_u8EchoPin);

/* A function to get the distance */
u32 US_u32GetDistance (u8 Copy_u8TriggerPort, u8 Copy_u8TriggerPin, u8 Copy_u8EchoPort, u8 Copy_u8EchoPin);

#endif
