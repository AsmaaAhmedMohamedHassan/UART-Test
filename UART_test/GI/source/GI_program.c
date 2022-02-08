/********************************************************/
/*****   NAME : Asmaa     ***/
/*****   Date : 17/1/2021  ***/
/*****Version : 1.0 V     ***/
/*****SWC     : INT       ***/
/********************************************************/


/*lib layer*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*MCAL layer*/
#include"DIO_interface.h"

#include"GI_interface.h"
#include"GI_private.h"
#include"GI_config.h"

void  GI_voidEnable    (void)
{
	SET_BIT(GI_U8_SREG_REG,GI_U8_BIT_NUMBER);
	
}
void  GI_voidDisable   (void)
{
	CLR_BIT(GI_U8_SREG_REG,GI_U8_BIT_NUMBER);
	
}
