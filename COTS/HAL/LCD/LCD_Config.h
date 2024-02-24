/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       HAL                                                                             */
/* File Name:   LCD_Config.h                                                                    */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/* Macro for Data PORT */
#define CLCD_u8DATA_PORT			GPIO_PORTB

/* Macro for Control PORT */
#define CLCD_u8CTRL_PORT			GPIO_PORTA

/* Macro for Control PINS */
#define CLCD_u8RS_PIN				GPIO_PIN1
#define CLCD_u8RW_PIN				GPIO_PIN2
#define CLCD_u8E_PIN				GPIO_PIN3

#endif
