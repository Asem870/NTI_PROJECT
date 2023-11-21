/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_init.h"
#include "GPIO_private.h"


/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This Set Pin Direction                */
/*                 for GPIO                              */
/*                 Inputs :PortName,PinNum ,Mode         */
/*                 return : void                         */
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

void  GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            if (Copy_u8Pin <= 7)
            {//LOW
                GPIO_A->CRL &= ~((MODE_RESET_MASK)      << (Copy_u8Pin * 4));
                GPIO_A->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_A->CRH &= ~((MODE_RESET_MASK)      << ((Copy_u8Pin - 8) * 4));
                GPIO_A->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;

        /*** PORT B ***/

        case GPIOB:
            if (Copy_u8Pin <= 7)
            {//LOW
                GPIO_B->CRL &= ~((MODE_RESET_MASK)      << (Copy_u8Pin * 4));
                GPIO_B->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_B->CRH &= ~((MODE_RESET_MASK)      << ((Copy_u8Pin - 8) * 4));
                GPIO_B->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;

        /*** PORT C ***/

        case GPIOC:
            if (Copy_u8Pin <= 7)
            {//LOW
                GPIO_C->CRL &= ~((MODE_RESET_MASK)      << (Copy_u8Pin * 4));
                GPIO_C->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
            }
            else if (Copy_u8Pin <= 15)
            {//HIGH
                GPIO_C->CRH &= ~((MODE_RESET_MASK)      << ((Copy_u8Pin - 8) * 4));
                GPIO_C->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
            }
            break;
        default:       break;
    }
}

/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This Set Pin Value GPIO               */
/*                                                       */
/*                 Inputs : U8 , U8                      */
/*                 return : ENUM                         */
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */
/*                                                       */
/*********************************************************/


void  GPIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            if (Copy_u8Value == HIGH)
            {
                SET_BIT (GPIO_A->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Value == LOW)
            {
                CLR_BIT (GPIO_A->ODR, Copy_u8Pin);
            }
            break;

        /*** PORT B ***/

        case GPIOB:
            if (Copy_u8Value == HIGH)
            {
                SET_BIT (GPIO_B->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Value == LOW)
            {
                CLR_BIT (GPIO_B->ODR, Copy_u8Pin);
            }
            break;

        /*** PORT C ***/

        case GPIOC:
            if (Copy_u8Value == HIGH)
            {
                SET_BIT (GPIO_C->ODR, Copy_u8Pin);
            }
            else if (Copy_u8Value == LOW)
            {
                CLR_BIT (GPIO_C->ODR, Copy_u8Pin);
            }
            break;

        default :       break;
    }
}
/*********************************************************/
/**************  FUNCTION Implementation  ****************/
/*********************************************************/

/*********************************************************/
/* Description   : This Get Pin Value GPIO               */
/*                                                       */
/*                 Inputs : Pin                          */
/*                 return : Pin VAULE                    */
/*********************************************************/
/*********************************************************/
/* Pre_condition :                                       */
/*                                                       */
/*                                                       */
/*********************************************************/

u8 GPIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8Result = 0;
    switch (Copy_u8Port)
    {
         /*** PORT A ***/

        case GPIOA:
            Local_u8Result = GET_BIT (GPIO_A->IDR, Copy_u8Pin);
            break;

        /*** PORT B ***/

        case GPIOB:
            Local_u8Result = GET_BIT (GPIO_B->IDR, Copy_u8Pin);
            break;

        /*** PORT C ***/

        case GPIOC:
            Local_u8Result = GET_BIT (GPIO_C->IDR, Copy_u8Pin);
            break;

        default :       break;
    }
    return Local_u8Result;
}

/*************   Function OF Toggle Pin Value   **********************/

void  GPIO_voidTogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin)
{
    switch (Copy_u8Port)
	{
		 /*** PORT A ***/

		case GPIOA:
					TOG_BIT(GPIO_A->ODR,Copy_u8Pin);
		  break;

		/*** PORT B ***/

		case GPIOB:
					TOG_BIT(GPIO_B->ODR,Copy_u8Pin);
		  break;

		/*** PORT C ***/

		case GPIOC:
		            TOG_BIT(GPIO_C->ODR,Copy_u8Pin);
		  break;

		default :       break;
	}
}

