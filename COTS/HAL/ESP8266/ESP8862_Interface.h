/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   ESP8862_Interface.h                                                             */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef ESP8862_INTERFACE_H
#define ESP8862_INTERFACE_H

/* A function to initialize the ESP8862 */
void ESP8862_voidInit (void);

/* A function to connect the ESP8862 to a router */
void ESP8862_voidConnectToRouter (u8* Copy_pu8Name, u8* Copy_pu8Password);

/* A function to connect the ESP8862 to a server */
void ESP8862_voidAccessServer (u8* Copy_pu8ServerIP, u8* Copy_pu8Port);

/* A function to send HTTP request */
void ESP8862_voidSendHTTPRequest (u8* Copy_pu8DataLength, u8* Copy_pu8URL, u8 Copy_u8ReceivedData []);

/* A function to validate the command */
u8 ESP8862_u8ValidateCommand (void);



#endif
