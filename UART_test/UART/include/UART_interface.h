/********************************************************/
/*****   NAME : Asmaa           ***/
/*****   Date : 23/1/2021       ***/
/*****Version : 1.0 V           ***/
/*****SWC     : UART       ***/
/********************************************************/

#ifndef  UART_INTERFACE_H
#define  UART_INTERFACE_H


void UART_voidInit(void);
void UART_voidTransmit(u8 copy_u8Data);
u8 UART_voidRecive(void);
void UART_voidReceiveBufferSynch(u8 *PtrArr, u8 size);
void UART_voidSendBufferSynch(u8 *PtrArr, u8 size);
void UART_voidSendBufferAsynch(u8 *PtrArr, u8 size, void (*PFNotification)(void));
void UART_voidReciveBufferAsynch(u8 *PtrArr, u8 size, void (*PFNotification)(void));


void UART_ReceiveString( u8 *str);
void UART_SendString(const u8* Copy_Data);

#endif
