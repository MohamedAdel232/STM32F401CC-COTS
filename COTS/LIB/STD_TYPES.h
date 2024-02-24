/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       LIB                                                                             */
/* File Name:   STD_TYPES.h                                                                     */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef STD_TYPES_h
#define STD_TYPES_h

typedef unsigned char u8;               /* 0 to 255 */
typedef unsigned short int u16;         /* 0 to 65,535 */
typedef unsigned int u32;               /* 0 to 4294967295 */
typedef char s8;                        /* -128 to 127 */
typedef short int s16;                  /* -32,768 to 32,767*/
typedef int s32;                        /* -2,147,483,647 to 2,147,483,647 */
typedef float f32;                      /* 1.175494351 E - 38 to 3.402823466 E + 38 */
typedef double f64;                     /* 2.2250738585072014 E - 308 to 1.7976931348623158 E + 308 */

#define NULL 		0				    /* Define NULL */

/* Define Macros for Error state */
#define OK				0
#define NOK				1
#define NULL_POINTER 	2

#endif
