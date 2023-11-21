/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define MODE_RESET_MASK		0b1111

typedef struct {

	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO_t;

/*******************   BASE Address Definition    *********************/

#define GPIOA_Base_Address      0x40010800      //define the boundary address of GPIOA
#define GPIOB_Base_Address      0x40010C00      //define the boundary address of GPIOB
#define GPIOC_Base_Address      0x40011000      //define the boundary address of GPIOC

/***********   REGISTER ADDRESSES FOR GPIOx     ***********************/
#define GPIO_A						( ( volatile GPIO_t* ) GPIOA_Base_Address )
#define GPIO_B						( ( volatile GPIO_t* ) GPIOB_Base_Address )
#define GPIO_C						( ( volatile GPIO_t* ) GPIOC_Base_Address )

#endif // GPIO_PRIVATE_H
