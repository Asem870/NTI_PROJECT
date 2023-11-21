/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H


/*******************   Register Definition     ***********************/

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

/*******************   BASE Address Definition    *********************/

#define AFIO_BASE_ADDRESS	0x40010000		//define the boundary address of AFIO

#define AFIO 		((volatile AFIO_t *) AFIO_BASE_ADDRESS)

#define RESET_MASK		0b1111

#endif // AFIO_PRIVATE_H
