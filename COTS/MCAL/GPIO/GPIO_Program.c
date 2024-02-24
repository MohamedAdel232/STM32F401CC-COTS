/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   GPIO_Program.c                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/* Date:        1/12/2023                                                                       */
/************************************************************************************************/

/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include driver files */
#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
#include "GPIO_Register.h"

/* A function to set pin mode */
void GPIO_voidSetPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
	case GPIO_INPUT:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_OUTPUT:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_AF:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOA_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOB_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOC_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_ANALOG:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOA_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOB_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_REGISTER -> GPIO_MODER,(2*Copy_u8Pin));
			SET_BIT(GPIOC_REGISTER -> GPIO_MODER,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
		default:
			break;
	}
}

/* A function to set pin type */
void GPIO_voidSetPinType (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Type)
{
	switch (Copy_u8Type)
	{
	case GPIO_PUSH_PULL:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_OTYPER,Copy_u8Pin);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_OTYPER,Copy_u8Pin);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_OTYPER,Copy_u8Pin);
			break;
		default:
			break;
		}
		break;
	case GPIO_OPEN_DRAIN:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA_REGISTER -> GPIO_OTYPER,(Copy_u8Pin));
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_REGISTER -> GPIO_OTYPER,(Copy_u8Pin));
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_REGISTER -> GPIO_OTYPER,(Copy_u8Pin));
			break;
		default:
			break;
		}
		break;
	case GPIO_NO_P_RESISTANCE:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_PU_RESISTANCE:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_PD_RESISTANCE:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			SET_BIT(GPIOA_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			SET_BIT(GPIOB_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_PUPDR,(2*Copy_u8Pin));
			SET_BIT(GPIOC_REGISTER -> GPIO_PUPDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
		default:
			break;
	}
}

/* A function to set pin speed */
void GPIO_voidSetPinSpeed (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Speed)
{
	switch (Copy_u8Speed)
	{
	case GPIO_LOW_SPEED:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_MEDUIM_SPEED:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			CLR_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	case GPIO_HIGH_SPEED:
		switch (Copy_u8Port)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			SET_BIT(GPIOA_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			SET_BIT(GPIOB_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,(2*Copy_u8Pin));
			SET_BIT(GPIOC_REGISTER -> GPIO_OSPEEDR,((2*Copy_u8Pin)+1));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

/* A function to set pin AF */
void GPIO_voidSetPinAF (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AF)
{
	if (Copy_u8Pin < 8)
	{
		switch (Copy_u8Port)
		{
			case GPIO_PORTA:
                GPIOA_REGISTER->GPIO_AFRL &= ~(0b1111 << ((Copy_u8Pin)*4));
                GPIOA_REGISTER->GPIO_AFRL |= (Copy_u8AF << ((Copy_u8Pin)*4));
				break;
			case GPIO_PORTB:
                GPIOB_REGISTER->GPIO_AFRL &= ~(0b1111 << ((Copy_u8Pin)*4));
                GPIOB_REGISTER->GPIO_AFRL |= (Copy_u8AF << ((Copy_u8Pin)*4));
				break;
			case GPIO_PORTC:
                GPIOC_REGISTER->GPIO_AFRL &= ~(0b1111 << ((Copy_u8Pin)*4));
                GPIOC_REGISTER->GPIO_AFRL |= (Copy_u8AF << ((Copy_u8Pin)*4));
				break;
			default:
				break;
		}
	}
	else if (Copy_u8Pin >= 8 && Copy_u8Pin < 16)
	{
		switch (Copy_u8Port)
		{
			case GPIO_PORTA:
                GPIOA_REGISTER->GPIO_AFRH &= ~(0b1111 << ((Copy_u8Pin - 8)*4));
                GPIOA_REGISTER->GPIO_AFRH |= (Copy_u8AF << ((Copy_u8Pin - 8)*4));
				break;
			case GPIO_PORTB:
                GPIOB_REGISTER->GPIO_AFRH &= ~(0b1111 << ((Copy_u8Pin - 8)*4));
                GPIOB_REGISTER->GPIO_AFRH |= (Copy_u8AF << ((Copy_u8Pin - 8)*4));
				break;
			case GPIO_PORTC:
                GPIOC_REGISTER->GPIO_AFRH &= ~(0b1111 << ((Copy_u8Pin - 8)*4));
                GPIOC_REGISTER->GPIO_AFRH |= (Copy_u8AF << ((Copy_u8Pin - 8)*4));
				break;
			default:
				break;
		}
	}
}

/* A function to initialize a pin */
void GPIO_voidPinInit (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode, u8 Copy_u8Type, u8 Copy_u8Speed, u8 Copy_u8AF)
{
	GPIO_voidSetPinMode(Copy_u8Port, Copy_u8Pin, Copy_u8Mode);
	GPIO_voidSetPinType(Copy_u8Port, Copy_u8Pin, Copy_u8Type);

	if (Copy_u8Mode == GPIO_OUTPUT)
	{
		GPIO_voidSetPinSpeed(Copy_u8Port, Copy_u8Pin, Copy_u8Speed);
	}
	if (Copy_u8Mode == GPIO_AF)
	{
		GPIO_voidSetPinAF(Copy_u8Port, Copy_u8Pin, Copy_u8AF);
	}
}

/* A function to set port mode */
void GPIO_voidSetPortMode (u8 Copy_u8Port, u8 Copy_u8Mode)
{
	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < 16; Local_u8Iterator++)
	{
		GPIO_voidSetPinMode(Copy_u8Port, Local_u8Iterator, Copy_u8Mode);
	}
}

/* A function to set port type */
void GPIO_voidSetPortType(u8 Copy_u8Port, u8 Copy_u8Type)
{
	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < 16; Local_u8Iterator++)
	{
		GPIO_voidSetPinType(Copy_u8Port, Local_u8Iterator, Copy_u8Type);
	}
}

/* A function to set port speed */
void GPIO_voidSetPortSpeed (u8 Copy_u8Port, u8 Copy_u8Speed)
{
	u8 Local_u8Iterator = 0;
	for (Local_u8Iterator = 0; Local_u8Iterator < 16; Local_u8Iterator++)
	{
		GPIO_voidSetPinSpeed(Copy_u8Port, Local_u8Iterator, Copy_u8Speed);
	}
}

/* A function to initialize a port */
void GPIO_voidPortInit (u8 Copy_u8Port, u8 Copy_u8Mode, u8 Copy_u8Type, u8 Copy_u8Speed)
{
	GPIO_voidSetPortMode(Copy_u8Port, Copy_u8Mode);
	GPIO_voidSetPortType(Copy_u8Port, Copy_u8Type);

	if (Copy_u8Mode == GPIO_OUTPUT)
	{
		GPIO_voidSetPortSpeed(Copy_u8Port, Copy_u8Speed);
	}
}

/* A function to Get pin value */
u8 GPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8Value = 0;
	switch (Copy_u8Port)
	{
		case GPIO_PORTA:
			Local_u8Value = GET_BIT(GPIOA_REGISTER->GPIO_IDR, Copy_u8Pin);
			break;
		case GPIO_PORTB:
			Local_u8Value = GET_BIT(GPIOB_REGISTER->GPIO_IDR, Copy_u8Pin);
				break;
		case GPIO_PORTC:
			Local_u8Value = GET_BIT(GPIOC_REGISTER->GPIO_IDR, Copy_u8Pin);
				break;
		default:
			break;
	}
	return Local_u8Value;
}

/* A function to set pin value */
void GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch (Copy_u8Value)
	{
	case GPIO_LOW:
		switch (Copy_u8Port)
		{
			case GPIO_PORTA:
				CLR_BIT(GPIOA_REGISTER -> GPIO_ODR, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIOB_REGISTER -> GPIO_ODR, Copy_u8Pin);
					break;
			case GPIO_PORTC:
				CLR_BIT(GPIOC_REGISTER -> GPIO_ODR, Copy_u8Pin);
					break;
			default:
				break;
		}
		break;
	case GPIO_HIGH:
		switch (Copy_u8Port)
		{
			case GPIO_PORTA:
				SET_BIT(GPIOA_REGISTER -> GPIO_ODR, Copy_u8Pin);
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB_REGISTER -> GPIO_ODR, Copy_u8Pin);
					break;
			case GPIO_PORTC:
				SET_BIT(GPIOC_REGISTER -> GPIO_ODR, Copy_u8Pin);
					break;
			default:
				break;
		}
		break;
	default:
		break;
	}
}

/* A function to set pin value atomic */
void GPIO_voidSetPinValueAtomic (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    switch (Copy_u8Value)
    {
    case GPIO_RESET:
    switch(Copy_u8Port)
        {
        case GPIO_PORTA:
        GPIOA_REGISTER->GPIO_BSRR = (1<<(Copy_u8Pin+16));
        break;
        case GPIO_PORTB:
        GPIOB_REGISTER->GPIO_BSRR = (1<<(Copy_u8Pin+16));
        break;
        case GPIO_PORTC:
        GPIOC_REGISTER ->GPIO_BSRR = (1<<(Copy_u8Pin+16));
        break;
        default:
        break;
        }
        break;
    case GPIO_SET:
    switch(Copy_u8Port)
        {
            case GPIO_PORTA:
            GPIOA_REGISTER->GPIO_BSRR = (1<<Copy_u8Pin);
            break;
            case GPIO_PORTB:
            GPIOB_REGISTER->GPIO_BSRR = (1<<Copy_u8Pin);
            break;
            case GPIO_PORTC:
            GPIOC_REGISTER->GPIO_BSRR = (1<<Copy_u8Pin);
            break;
            default:
            break;
        }
        break;
    default:
    break;
    }
}

/* A function to lock register */
void GPIO_voidLockPin (u8 Copy_u8Port, u8 Copy_u8Pin)
{
 /* To do */
}

/* A function to set port value */
void GPIO_voidSetPortValueu8NonAtomic (u8 Copy_u8PortID,u8 Copy_u8Value)
{
    switch(Copy_u8PortID)   // Set Char Number at the first 8 bit on GPIOx
    {
        case GPIO_PORTA :   GPIOA_REGISTER->GPIO_ODR = ( ((u8)GPIOA_REGISTER->GPIO_ODR) & 0x00 ) | Copy_u8Value ;    break;
        case GPIO_PORTB :   GPIOB_REGISTER->GPIO_ODR = ( ((u8)GPIOB_REGISTER->GPIO_ODR) & 0x00 ) | Copy_u8Value ;    break;
        default    :                                                                        break;
    }
}
