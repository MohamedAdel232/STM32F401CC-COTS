/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   LCD_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/* A function to send Command */
void CLCD_voidSendCommand (u8 Copy_u8Command);

/* A function to send Data */
void CLCD_voidSendData (u8 Copy_u8Data);

/* A function to Initialize CLCD */
void CLCD_voidInit(void);

/* A function to send a string */
void CLCD_voidSentString (const char* Copy_pcString);

/* A function to go to specific location */
void CLCD_voidGoToXY (u8 Copy_u8XPos, u8 Copy_u8YPos);

/* A function to send a special Character */
void CLCD_voidSendSpecialCharacter (u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

/* A function to send Digit */
void CLCD_voidSendDigit (u8 Copy_u8Digit);

/* A function to send a number */
void CLCD_voidSendNumber (u16 Copy_u16Number);

void APP_voidDelayMs(u32 Copy_u32Delay);

#endif
