/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define SW_RESET_MASK	(u32)(~0x3)
/*******************   Register Definition     ***********************/
typedef struct
{

	volatile u32 CR       ;
	volatile u32 CFGR     ;
	volatile u32 CIR      ;
	volatile u32 APB2RSTR ;
	volatile u32 APB1RSTR ;
	volatile u32 AHBENR   ;
	volatile u32 APB2ENR  ;
	volatile u32 APB1ENR  ;
	volatile u32 BDCR     ;
	volatile u32 CSR      ;
}RCC_t;

/*******************   BASE Address Definition    *********************/

#define RCC_BASE_ADDRESS	0x40021000		//define the boundary address of RCC

#define RCC ( ( volatile RCC_t* ) RCC_BASE_ADDRESS)


#endif // RCC_PRIVATE_H
