/************************************************************************************************/
/* Name:        Muhamed Adel                                                                    */
/* Layer:       MCAL                                                                            */
/* File Name:   STK_Interface.h                                                                 */
/* e-mail:      mohmdadl232@gmail.com                                                           */
/************************************************************************************************/

/* File guard */
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* A function to initialize SysTick */
void STK_voidInit (void);

/* A function to set busy wait */
void STK_voidSetBusyWait (u32 Copy_u32TimeMs);

/* A function to set single interval */
void STK_voidSetIntervalSingle (u32 Copy_u32TimeMs, void (*Copy_ptr) (void));

/* A function to set periodic interval */
void STK_voidSetIntervalPeriodic (u32 Copy_u32TimeMs, void (*Copy_ptr) (void));

/* A function to stop SysTick */
void STK_voidStopInterval (void);

/* A function to get remaining time */
u32 STK_u32GetRemainingTime (void);

/* A function to get elapsed time */
u32 STK_u32GetElapsedTime (void);

/* A function to Load the register */
void STK_voidLoadValue (u32 Copy_u32Value);


#endif
