/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)        VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)        VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)        ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)        VAR ^=  (1 << (BIT))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#endif // BIT_MATH_H
