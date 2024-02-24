/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   DMA_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

/* A function to initialize DMA */
void DMA_voidInit (void);

/* A function to set stream */
void DMA_voidSetSteram (u8 Copy_u8StreamID,
						u32* Copy_pu32SrcAddress,
						u32* Copy_pu32DesAddress,
						u32 Copy_u32BloclSize
						);

/* A function to clear flags */
void DMA_voidClearFlag(void);

/* A function to enable steam */
void DMA_voidEnableStream (u8 Copy_u8StreamID);

/* Call back function */
void DMA_voidSetCallBack (u8 Copy_u8StreamID, void (*pf) (void));

#endif
