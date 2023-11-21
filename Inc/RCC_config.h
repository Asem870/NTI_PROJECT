/*********************************************************************************/
/* Author    : nourhan nowier                                                    */
/* Version   : V01                                                               */
/* Date      : 30/7/2023                                                         */
/*********************************************************************************/


/******************************************************/
/*** guard of file will call one time in .c     *******/
/******************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*
	1- Clock source
	2- clock enable, disable
	3- pll source
	4- pll multiplier
	5- hse divider
	6- mechanical or electrical clock
	7- clock security system
	8- mco clock source
*/


/************* Options:     RCC_HSE_CRYSTAL
                            RCC_HSE_RC
                            RCC_HSI
                            RCC_PLL                     ****************/

#define RCC_CLOCK_TYPE      RCC_PLL


/************* Options:     RCC_PLL_IN_HSI_DIV_2
                            RCC_PLL_IN_HSE_DIV_2
                            RCC_PLL_IN_HSE             ****************/

/*** Note: Select value only if you  have PLL as input clock source ***/

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT       RCC_PLL_IN_HSE
#endif

/************************ 				 Options:  						***********************/
/* 								 ClockFactor For PLL  Maybe :                                */
/*                              1-PLL_CLOCKk_MULTIPLE_BY_2                                   */
/*                              2-PLL_CLOCKk_MULTIPLE_BY_3                                   */
/*                              3-PLL_CLOCKk_MULTIPLE_BY_4                                   */
/*                              4-PLL_CLOCKk_MULTIPLE_BY_5                                   */
/*                              5-PLL_CLOCKk_MULTIPLE_BY_6                                   */
/*                              6-PLL_CLOCKk_MULTIPLE_BY_7                                   */
/*                              7-PLL_CLOCKk_MULTIPLE_BY_8                                   */
/*                              8-PLL_CLOCKk_MULTIPLE_BY_9                                   */
/*                              9-PLL_CLOCKk_MULTIPLE_BY_10                                  */
/*                              10-PLL_CLOCKk_MULTIPLE_BY_11                                 */
/*                              11-PLL_CLOCKk_MULTIPLE_BY_12                                 */
/*                              12-PLL_CLOCKk_MULTIPLE_BY_13                                 */
/*                              13-PLL_CLOCKk_MULTIPLE_BY_14                                 */
/*                              14-PLL_CLOCKk_MULTIPLE_BY_15                                 */
/*                              15-PLL_CLOCKk_MULTIPLE_BY_16                                 */
/*                                                                                           */
/*																						   	 */
/*** Note: Select value only if you  have PLL as input clock source ***/

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL     PLL_CLOCK_MULTIPLE_BY_9
#endif

#define HSE_CLOCK_TIMEOUT (u32)100000

#define HSI_CLOCK_TIMEOUT (u32)100000

#define PLL_CLOCK_TIMEOUT (u32)100000



#endif // RCC_CONFIG_H
