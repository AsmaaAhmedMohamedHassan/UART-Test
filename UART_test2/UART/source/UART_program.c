



/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GI_interface.h"

#include"UART_interface.h"
#include"UART_private.h"
#include"UART_config.h"

volatile u8 busy_flag ,INDEX=0,SIZE;
volatile u8 *PtrBuffer = NULL ;
/*global pointers to functions*/
static void (*UART_ptrtofun)(void) = NULL;
static void (*UART_ptrtofun2)(void) = NULL;

void UART_voidInit(void)
{
	UART_u8_UBRR_REG =  51 ;
	SET_BIT(UART_u8_UCSRB_REG,3);
	SET_BIT(UART_u8_UCSRB_REG,4);
	//UART_u8_UCSRC_REG = (1<<7);
	UART_u8_UCSRC_REG = (1<<7) | (1<<1) | (1<<2);
	
}

void UART_voidTransmit(u8 copy_u8Data)
{
	while(!GET_BIT(UART_u8_UCSRA_REG,5));
	UART_u8_UDR_REG = copy_u8Data;
	
	
	
}

u8 UART_voidRecive(void)
{
	
	while(!GET_BIT(UART_u8_UCSRA_REG,7));

	return UART_u8_UDR_REG;
	
}


void UART_voidSendBufferSynch(u8 *PtrArr, u8 size)
{
	u8 local_u8Index = 0;
	while(local_u8Index <size)
	{
		UART_voidTransmit(PtrArr[local_u8Index]);
		local_u8Index ++;
	}


}


void UART_voidReceiveBufferSynch(u8 *PtrArr, u8 size)
{
	u8 local_u8Index = 0;
	while(local_u8Index <size)
	{
		PtrArr[local_u8Index] = UART_voidRecive();
		local_u8Index ++;
	}

}




void UART_voidSendBufferAsynch(u8 *PtrArr, u8 size, void (*PFNotification)(void))
{

	busy_flag =1;
	PtrBuffer = PtrArr;
	SIZE = size;
	UART_ptrtofun = PFNotification;
	GI_voidEnable();
	/*send first byte*/
	while(!GET_BIT(UART_u8_UCSRA_REG,5));
	UART_u8_UDR_REG = PtrBuffer[INDEX];

	SET_BIT(UART_u8_UCSRB_REG,5);  /*enable interrupt of empty data register*/

}

void UART_voidReciveBufferAsynch(u8 *PtrArr, u8 size, void (*PFNotification)(void))
{
	busy_flag =1;
	SIZE = size;
	PtrBuffer = PtrArr;
	UART_ptrtofun2 = PFNotification;
	GI_voidEnable();
	/*receive first byte*/
	while(!GET_BIT(UART_u8_UCSRA_REG,7));
	PtrBuffer[INDEX] = UART_u8_UDR_REG ;

	SET_BIT(UART_u8_UCSRB_REG,7);  /*enable interrupt of receive byte*/




}


/*ISR function prototype to transmit buffer empty*/
void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{
	INDEX++;
	if(INDEX == SIZE )
	{
		CLR_BIT(UART_u8_UCSRB_REG,5);
		busy_flag = 0;
		UART_ptrtofun();
	}
	else
	{
	   while(!GET_BIT(UART_u8_UCSRA_REG,5));
	   UART_u8_UDR_REG = PtrBuffer[INDEX];
	}

}

/*ISR function prototype to receive complete*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	INDEX++;
	if(INDEX == SIZE )
	{
		CLR_BIT(UART_u8_UCSRB_REG,7);
		busy_flag = 0;
		UART_ptrtofun2();
	}
	else
	{
	   while(!GET_BIT(UART_u8_UCSRA_REG,7));
	   PtrBuffer[INDEX] =  UART_u8_UDR_REG ;
	}


}



