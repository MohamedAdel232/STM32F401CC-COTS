/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   FM_Interface.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef FM_INTERFACE_H
#define FM_INTERFACE_H

/* A function to erase application area */
void FM_voidEraseApplicationArea (void);

/* A function to erase a sector */
void FM_voidEraseSector (u8 Copy_u8Sector);

/* A function to write data on a sector */
void FM_voidWriteData (u32 Copy_u32Address, u16* Copy_pu16Data, u16 Copy_u16DataSize);

#endif
