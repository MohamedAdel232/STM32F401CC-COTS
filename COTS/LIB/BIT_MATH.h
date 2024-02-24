/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       LIB                                                                             */
/* File Name:   BIT_MATH.h                                                                      */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set a certain bit in a register */
#define SET_BIT(reg,n)     reg |= (1<<n)

/* Clear a certain bit in a register */
#define CLR_BIT(reg,n)     reg &= ~(1<<n)

/* Togal a certain bit in a register */
#define TOG_BIT(reg,n)     reg ^= (1<<n)

/* Get a certain bit in a register */
#define GET_BIT(reg,n)     (reg>>n)&1

#endif
