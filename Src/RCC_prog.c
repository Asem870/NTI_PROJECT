/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V02                                                               */
/* Date      : 17 NOV 2021                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_init.h"
#include "RCC_config.h"
#include "RCC_priv.h"

/*
 * Initialization clock of micro-controller
 *
 */
#define OK	0
#define NOK	1

void RCC_u8SetClkSource(u32 Copy_u32ClkSrc)
{
	RCC->CFGR &= SW_RESET_MASK;
	RCC->CFGR|= Copy_u32ClkSrc;
}

u8 RCC_u8SetClkStatus(u8 Copy_u8Clk, u8 Copy_u8Status)
{
	u8 Local_u8ErrorStatus=OK;
	u32 Local_u32Counter=0;
	switch(Copy_u8Clk)
	{
		case RCC_HSE:
		if (Copy_u8Status==0)
		{
			CLR_BIT(RCC->CR,16);
		}
		else
		{
			SET_BIT(RCC->CR,16);
			while((GET_BIT(RCC->CR,17)==0) && (Local_u32Counter!= HSE_CLOCK_TIMEOUT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter==HSE_CLOCK_TIMEOUT)
			{
				Local_u8ErrorStatus=NOK;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		break;
		case RCC_HSI:
		if (Copy_u8Status==0)
		{
			CLR_BIT(RCC->CR,0);
		}
		else
		{
			SET_BIT(RCC->CR,0);
			while((GET_BIT(RCC->CR,1)==0) && (Local_u32Counter!= HSI_CLOCK_TIMEOUT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter==HSI_CLOCK_TIMEOUT)
			{
				Local_u8ErrorStatus=NOK;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		break;
		case RCC_PLL:
		if (Copy_u8Status==0)
		{
			CLR_BIT(RCC->CR,24);
		}
		else
		{
			SET_BIT(RCC->CR,24);
			while((GET_BIT(RCC->CR,25)==0) && (Local_u32Counter!= PLL_CLOCK_TIMEOUT))
			{
				Local_u32Counter++;
			}
			if(Local_u32Counter==PLL_CLOCK_TIMEOUT)
			{
				Local_u8ErrorStatus=NOK;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		break;
	}
	return Local_u8ErrorStatus;
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8Bus, u32 Copy_u32Peripheral)
{
	switch(Copy_u8Bus)
	{
		case RCC_AHB:	SET_BIT(RCC->AHBENR , Copy_u32Peripheral); break;
		case RCC_APB2:	SET_BIT(RCC->APB2ENR , Copy_u32Peripheral); break;
		case RCC_APB1:	SET_BIT(RCC->APB1ENR , Copy_u32Peripheral); break;
	}
}

void RCC_voidDisablePeripheralClock(u8 Copy_u8Bus, u32 Copy_u32Peripheral)
{
	switch(Copy_u8Bus)
	{
		case RCC_AHB:	CLR_BIT(RCC->AHBENR , (Copy_u32Peripheral)); break;
		case RCC_APB2:	CLR_BIT(RCC->APB2ENR, (Copy_u32Peripheral)); break;
		case RCC_APB1:	CLR_BIT(RCC->APB1ENR ,(Copy_u32Peripheral)); break;
	}
}

