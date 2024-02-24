/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   DMA_Register.h                                                                  */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef DMA_REGISTER_H
#define DMA_REGISTER_H

/* DMA2 Base Address */
#define DMA2_BASE_ADDRESS           0x40026400

/* Struct for DMA registers */
typedef struct
{
    volatile u32 DMA_CR;
    volatile u32 DMA_NDTR;
    volatile u32 DMA_PAR;
    volatile u32 DMA_M0AR;
    volatile u32 DMA_M1AR;
    volatile u32 DMA_FCR;
}DMA_Stream_t;

/* Struct for DMA registers */
typedef struct
{
    volatile u32 DMA_LISR;
    volatile u32 DMA_HISR;
    volatile u32 DMA_LIFCR;
    volatile u32 DMA_HIFCR;
    DMA_Stream_t S[8];
}DMA_t;

/* Access the registers from the struct */
#define DMA2_REGISTER           ((DMA_t*) (DMA2_BASE_ADDRESS))

#endif
