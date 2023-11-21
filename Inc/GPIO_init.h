/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "STD_TYPES.h"
/***************    PULL  definition      *******************/
#define PULL_UP     0
#define PULL_DOWN   1

/***************   GPIO(PORT) definition  *******************/
#define GPIOA       0
#define GPIOB       1
#define GPIOC       2

/***************   PIN definition         *******************/
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

                 /* MODES OF OPERATION */

/***************   INPUT Mode definition   ******************/
#define INPUT_ANLOG                      (u32)(0b0000)
#define INPUT_FLOATING                   (u32)(0b0100)
#define INPUT_PULLUP		             (u32)(0b1000)
#define INPUT_PULLDOWN		             (u32)(0b1100) //RESERVED


/***************   OUTPUT Mode definition  ******************/
#define OUTPUT_10MHZ_PUSH_PULL          (u32)(0b0001)
#define OUTPUT_10MHZ_OPEN_DRAIN         (u32)(0b0101)
#define OUTPUT_10MHZ_AF_PUSH_PULL       (u32)(0b1001)
#define OUTPUT_10MHZ_AF_OPEN_DRAIN      (u32)(0b1101)

#define OUTPUT_2MHZ_PUSH_PULL           (u32)(0b0010)
#define OUTPUT_2MHZ_OPEN_DRAIN          (u32)(0b0110)
#define OUTPUT_2MHZ_AF_PUSH_PULL        (u32)(0b1010)
#define OUTPUT_2MHZ_AF_OPEN_DRAIN       (u32)(0b1110)

#define OUTPUT_50MHZ_PUSH_PULL          (u32)(0b0011)
#define OUTPUT_50MHZ_OPEN_DRAIN         (u32)(0b0111)
#define OUTPUT_50MHZ_AF_PUSH_PULL       (u32)(0b1011)
#define OUTPUT_50MHZ_AF_OPEN_DRAIN      (u32)(0b1111)


/*********************** pins options *************************/
#define HIGH            1
#define LOW             0
/*
 *        _______________________CRL___________________

  31 30      29 28     27 26      25 24     23 22    21 20      19 18      17 16
CNF7[1:0] MODE7[1:0] CNF6[1:0] MODE6[1:0] CNF5[1:0] MODE5[1:0] CNF4[1:0] MODE4[1:0]

  15 14      13 12     11 10       9 8       7 6      5 4        3 2       1 0
CNF3[1:0] MODE3[1:0] CNF2[1:0] MODE2[1:0] CNF1[1:0] MODE1[1:0] CNF0[1:0] MODE0[1:0]

*        _______________________ CRH____________________

  31 30       29 28       27 26     25 24       23 22      21 20      19 18      17 16
CNF15[1:0] MODE15[1:0] CNF14[1:0] MODE14[1:0] CNF13[1:0] MODE13[1:0] CNF12[1:0] MODE12[1:0]

  15 14       13 12       11 10     9 8          7 6        5 4        3 2        1 0
CNF11[1:0] MODE11[1:0] CNF10[1:0] MODE10[1:0] CNF9[1:0] MODE9[1:0] CNF8[1:0] MODE8[1:0]

 */

/***************   Function definition    ******************/

void  GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void  GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void  GPIO_voidTogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif // GPIO_INTERFACE_H
