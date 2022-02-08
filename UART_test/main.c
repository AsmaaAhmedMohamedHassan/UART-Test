/*
 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: ZAS
 */





/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include<util/delay.h>
/*MCAL layer*/
#include"DIO_interface.h"
#include"UART_interface.h"

void UART_voidEndNotification(void);
volatile u8 End_flag = 0;

int main(void)
{
	DIO_voidInit();
	UART_voidInit();
   u8 arr[20] ="asmaa";
	while(1)
	{
		//UART_voidTransmit(2);

		UART_voidSendBufferAsynch(arr,20,UART_voidEndNotification);
		_delay_ms(500);
	}



	return 0;

}



void UART_voidEndNotification(void)
{
	End_flag =1;

}

