/********************************************************/
/*****   NAME : Asmaa           ***/
/*****   Date : 23/1/2021       ***/
/*****Version : 1.0 V           ***/
/*****SWC     : UART       ***/
/********************************************************/

#ifndef  UART_PRIVATE_H
#define  UART_PRIVATE_H



#define  UART_u8_UBRRH_REG      *((volatile u8  *)0x40)
#define  UART_u8_UCSRC_REG      *((volatile u8  *)0x40)
#define  UART_u8_UCSRA_REG      *((volatile u8  *)0x2B)
         
#define  UART_u8_UCSRB_REG      *((volatile u8  *)0x2A)
#define  UART_u8_UBRRL_REG      *((volatile u8  *)0x29)
#define  UART_u8_UBRR_REG       *((volatile u8  *)0x29)
#define  UART_u8_UDR_REG        *((volatile u8  *)0x2C)

#endif

