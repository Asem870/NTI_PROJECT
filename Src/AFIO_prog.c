/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_init.h"

#include "AFIO_init.h"
#include "AFIO_priv.h"


/*************	 Function OF Set EXTI Configuration  **************************/

void  AFIO_voidSetEXTIConfiguration(u8 Copy_u8EXTI_Line, u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	/* Assign to EXTICRx register */
	Local_u8RegIndex = Copy_u8EXTI_Line / 4 ;
	Copy_u8EXTI_Line = Copy_u8EXTI_Line % 4 ;

	//These bits are written by software to select the source input for EXTIx external interrupt.
	AFIO->EXTICR[Local_u8RegIndex] &= ~((RESET_MASK) << (Copy_u8EXTI_Line * 4));
	AFIO->EXTICR[Local_u8RegIndex] |=  ((Copy_u8PortMap) << (Copy_u8EXTI_Line * 4));
}

/*************	 Function OF Remap Periphral Pins **************************/
void  AFIO_voidRemapPeripheralPins(u8 Copy_u8RemapingOptionsPort)
{
	switch(Copy_u8RemapingOptionsPort)
	{
            case AFIO_REMAP_SPI1               : SET_BIT(AFIO->MAPR,0); break;
            case AFIO_REMAP_I2C1               : SET_BIT(AFIO->MAPR,1); break;
            case AFIO_REMAP_USART1             : SET_BIT(AFIO->MAPR,2); break;
            case AFIO_REMAP_USART2             : SET_BIT(AFIO->MAPR,3); break;
            case AFIO_REMAP_USART3_MAP1        : SET_BIT(AFIO->MAPR,4);  CLR_BIT(AFIO->MAPR,5);  break;
            case AFIO_REMAP_USART3_MAP2        : SET_BIT(AFIO->MAPR,4);  SET_BIT(AFIO->MAPR,5);  break;
            case AFIO_REMAP_TIM1_MAP1          : SET_BIT(AFIO->MAPR,6);  CLR_BIT(AFIO->MAPR,7);  break;
            case AFIO_REMAP_TIM1_MAP2          : SET_BIT(AFIO->MAPR,6);  SET_BIT(AFIO->MAPR,7);  break;
            case AFIO_REMAP_TIM2_MAP1          : SET_BIT(AFIO->MAPR,8);  CLR_BIT(AFIO->MAPR,9);  break;
            case AFIO_REMAP_TIM2_MAP2          : CLR_BIT(AFIO->MAPR,8);  SET_BIT(AFIO->MAPR,9); break;
            case AFIO_REMAP_TIM2_MAP3          : SET_BIT(AFIO->MAPR,8);  SET_BIT(AFIO->MAPR,9);  break;
            case AFIO_REMAP_TIM3_MAP1          : CLR_BIT(AFIO->MAPR,10); SET_BIT(AFIO->MAPR,11); break;
            case AFIO_REMAP_TIM3_MAP2          : SET_BIT(AFIO->MAPR,10); SET_BIT(AFIO->MAPR,11); break;
            case AFIO_REMAP_TIM4_MAP1          : SET_BIT(AFIO->MAPR,12);                         break;
            case AFIO_REMAP_CAN_MAP1           : CLR_BIT(AFIO->MAPR,13); CLR_BIT(AFIO->MAPR,14); break;
            case AFIO_REMAP_CAN_MAP2           : CLR_BIT(AFIO->MAPR,13); SET_BIT(AFIO->MAPR,14); break;
            case AFIO_REMAP_CAN_MAP3           : SET_BIT(AFIO->MAPR,13); SET_BIT(AFIO->MAPR,14); break;
            case AFIO_REMAP_PD0                : SET_BIT(AFIO->MAPR,15); break;
            case AFIO_REMAP_TIM5CH4_MAP1       : CLR_BIT(AFIO->MAPR,16); break;
            case AFIO_REMAP_TIM5CH4_MAP2       : SET_BIT(AFIO->MAPR,16); break;
            case AFIO_REMAP_ADC1_INJEC_MAP1    : CLR_BIT(AFIO->MAPR,17); break;
            case AFIO_REMAP_ADC1_INJEC_MAP2    : SET_BIT(AFIO->MAPR,17); break;
            case AFIO_REMAP_ADC1_REGULAR_MAP1  : CLR_BIT(AFIO->MAPR,18); break;
            case AFIO_REMAP_ADC1_REGULAR_MAP2  : SET_BIT(AFIO->MAPR,18); break;
	        case AFIO_REMAP_ADC2_INJEC_MAP1    : CLR_BIT(AFIO->MAPR,19); break;
            case AFIO_REMAP_ADC2_INJEC_MAP2    : SET_BIT(AFIO->MAPR,19); break;
            case AFIO_REMAP_ADC2_REGULAR_MAP1  : CLR_BIT(AFIO->MAPR,20); break;
            case AFIO_REMAP_ADC2_REGULAR_MAP2  : SET_BIT(AFIO->MAPR,20); break;
            case AFIO_REMAP_JTAG_MAP1          : CLR_BIT(AFIO->MAPR,24); CLR_BIT(AFIO->MAPR,25); CLR_BIT(AFIO->MAPR,26); break;
            case AFIO_REMAP_JTAG_MAP2          : SET_BIT(AFIO->MAPR,24); CLR_BIT(AFIO->MAPR,25); CLR_BIT(AFIO->MAPR,26); break;
            case AFIO_REMAP_JTAG_MAP3          : CLR_BIT(AFIO->MAPR,24); SET_BIT(AFIO->MAPR,25); CLR_BIT(AFIO->MAPR,26); break;
            case AFIO_REMAP_JTAG_MAP4          : CLR_BIT(AFIO->MAPR,24); CLR_BIT(AFIO->MAPR,25); SET_BIT(AFIO->MAPR,26); break;

            case AFIO_REMAP_TIM9               : SET_BIT(AFIO->MAPR2,5);  break;
            case AFIO_REMAP_TIM10              : SET_BIT(AFIO->MAPR2,6);  break;
            case AFIO_REMAP_TIM11              : SET_BIT(AFIO->MAPR2,7);  break;
            case AFIO_REMAP_TIM13              : SET_BIT(AFIO->MAPR2,8);  break;
            case AFIO_REMAP_TIM114             : SET_BIT(AFIO->MAPR2,9);  break;
            case AFIO_REMAP_FSMC_NADV          : SET_BIT(AFIO->MAPR2,10); break;
	}
}


