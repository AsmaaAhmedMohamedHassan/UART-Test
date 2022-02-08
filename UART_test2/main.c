/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: ZAS
 */





/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"


/*MCAL layer*/
#include"DIO_interface.h"
#include"UART_interface.h"

#include"LCD_interface.h"

void UART_voidEndNotification(void);
volatile u8 End_flag = 0;

int main(void)
{
	u8 data[20] ;
	DIO_voidInit();
	LCD_voidInit();
	UART_voidInit();
//
//	UART_voidReciveBufferAsynch(data ,5,UART_voidEndNotification);
//	LCD_voidSendChar(data[0]);
//	LCD_voidSendChar(data[1]);
//	LCD_voidSendChar(data[2]);
//	LCD_voidSendChar(data[3]);
//	LCD_voidSendChar(data[4]);

//	data = UART_voidRecive();

		//DIO_u8SetPinValue(0,0,HIGH);
	UART_voidReciveBufferAsynch(data,20,UART_voidEndNotification);
    LCD_voidSendStr(data);

	while(1)
	{


	}


	return 0;

}


void UART_voidEndNotification(void)
{
	End_flag =1;

}
