/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   ESP8862_Program.c                                                               */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include MCAL files */
#include "../../MCAL/STK/STK_Interface.h"
#include "../../MCAL/USART/USART_Interface.h"

/* Include driver files */
#include "ESP8862_Interface.h"
#include "ESP8862_Config.h"
#include "ESP8862_Private.h"

/* A function to initialize the ESP8862 */
void ESP8862_voidInit (void)
{
	/* Local variable for the ACK value */
	u8 Local_u8Result = 0;

	/* Disable the ECHO */
	while (Local_u8Result == 0)
	{
		USART_voidTransmitString(USART1_REGISTER, "ATE0\r\n");
		Local_u8Result = ESP8862_u8ValidateCommand();
	}

	/* Wait for half a second */
	Local_u8Result = 0;
	STK_voidSetBusyWait(500);

	/* Select station mode */
	while (Local_u8Result == 0)
	{
		USART_voidTransmitString(USART1_REGISTER, "AT+CWMODE=1\r\n");
		Local_u8Result = ESP8862_u8ValidateCommand();
	}
	Local_u8Result = 0;
}

/* A function to connect the ESP8862 to a router */
void ESP8862_voidConnectToRouter (u8* Copy_pu8Name, u8* Copy_pu8Password)
{
	/* Send the route name and password */
	USART_voidTransmitString(USART1_REGISTER,"AT+CWJAP_CUR=\"");
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8Name);
	USART_voidTransmitString(USART1_REGISTER,"\",\"");
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8Password);
	USART_voidTransmitString(USART1_REGISTER,"\"\r\n");

	/* Wait for half a second */
	STK_voidSetBusyWait(500);
}

/* A function to connect the ESP8862 to a server */
void ESP8862_voidAccessServer (u8* Copy_pu8ServerIP, u8* Copy_pu8Port)
{
	/* Send TCP mode, the IP and port */
	USART_voidTransmitString(USART1_REGISTER,"AT+CIPSTART=\"TCP\",\"");
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8ServerIP);
	USART_voidTransmitString(USART1_REGISTER,"\",");
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8Port);
	USART_voidTransmitString(USART1_REGISTER,"\r\n");

	/* Wait for a second */
	STK_voidSetBusyWait(1000);
}

/* A function to send HTTP request */
void ESP8862_voidSendHTTPRequest (u8* Copy_pu8DataLength, u8* Copy_pu8URL, u8 Copy_u8ReceivedData [])
{
	/* Send the data length */
	USART_voidTransmitString(USART1_REGISTER,"AT+CIPSEND=");
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8DataLength);
	USART_voidTransmitString(USART1_REGISTER,"\r\n");

	/* Wait for 0.1 second */
	STK_voidSetBusyWait(100);

	/* Send HTTP request */
	USART_voidTransmitString(USART1_REGISTER,Copy_pu8URL);
	USART_voidTransmitString(USART1_REGISTER,"\r\n");

	/* Receive the string */
	USART_voidReceiveStringSynchronousNoBlocking(USART1_REGISTER, Copy_u8ReceivedData);
}

/* A function to validate the command */
u8 ESP8862_u8ValidateCommand (void)
{
	/* Local variables for the response values */
	u8 Local_u8Response [100] = {0};
	u8 Local_u8TempValue = 0;
	u8 Local_u8Iterator = 0;
	u8 Local_u8ReturnValue = 0;

	/* Polling until the ESP8862 is done transmitting data */
	while (Local_u8TempValue != 255)
	{
		Local_u8TempValue = USART_voidReceiveByteSynchronousNoBlocking(USART1_REGISTER);
		Local_u8Response [Local_u8Iterator] = Local_u8TempValue;
		Local_u8Iterator ++;
	}

	/* Check if the data send is 'OK' */
	if (Local_u8Response [0] == 'O' && Local_u8Response [1] == 'K')
	{
		Local_u8ReturnValue = 1;
	}

	/* Return the value */
	return Local_u8ReturnValue;
}
