/*
 * Accele.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Amir
 */


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/
#include <ACC.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_init.h"
/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

/*Number of Dc motors to check on*/
u8 DC_NUM = DC_MAX_NUM;

/*Struct for cfg of each motor*/
DCMotor_t ACC_AstrAccConfig [DC_NUM] =
{
		{ GPIOA , MOTOR1_LEFTPIN , MOTOR1_RIGHTPIN },
		{ GPIOA , MOTOR2_LEFTPIN , MOTOR2_RIGHTPIN }
};

/*Array of Error to check if the dc motor is on or off */
u8	 DCmotorx_u8Error[DC_NUM];

/*DC Motor Speed */
u8   DCmotor_u8Speed = NOT_MOVE;


/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : ACC_vdCarSpeed
 * [Description]   : Function to set/read the dc motor speed by checking on the port pins if the motors are on
 * [Arguments]     : <>  NA  ->
 *                   <>  NA  ->
 * [return]        :   [ NA ]  The function returns void.
====================================================================================================================*/

void ACC_vdCarSpeed(void)
{
	/*State of the DCmotors variable*/
	u8 DC_MOTOR_STATE=0;

	/* STATION MODE Doesnt send readings in reverse Direction*/
	if(!reverse_dir)
	{
	/*Oring the PINS with the variable with shifting operator*/
	DC_MOTOR_STATE|=((GPIO_u8GetPinValue(GPIOA,ACC_AstrAccConfig[0]-> Left_Pin))<<0);
	DC_MOTOR_STATE|=((GPIO_u8GetPinValue(GPIOA,ACC_AstrAccConfig[0]->Right_Pin))<<1);
	DC_MOTOR_STATE|=((GPIO_u8GetPinValue(GPIOA,ACC_AstrAccConfig[1]-> Left_Pin))<<2);
	DC_MOTOR_STATE|=((GPIO_u8GetPinValue(GPIOA,ACC_AstrAccConfig[1]->Right_Pin))<<3);

	/*Switch case on the DCMOTOR STATES*/
	switch(DC_MOTOR_STATE)
	{
	case MOTOR_OFF:
		DCmotor_u8Speed = NOT_MOVE;
		break;

	case ONLY_LEFT_MOTOR1:
		DCmotor_u8Speed = NOT_MOVE;
			break;

	case ONLY_LEFT_MOTOR2:
		DCmotor_u8Speed = NOT_MOVE;
			break;

	case ONLY_RIGHT_MOTOR1:
		DCmotor_u8Speed = NOT_MOVE;
			break;

	case ONLY_RIGHT_MOTOR2:
		DCmotor_u8Speed = NOT_MOVE;
			break;

	case MOTORs_ON1:
		DCmotor_u8Speed = MOVE;
			break;

	case MOTORs_ON1:
		DCmotor_u8Speed = MOVE;
				break;

	case MOTORs_ON2:
		DCmotor_u8Speed = MOVE;
				break;

	case MOTORs_ON3:
		DCmotor_u8Speed = MOVE;
				break;

	case MOTORs_ON4:
		DCmotor_u8Speed = MOVE;
				break;

	default:
		break;
	}
	}
	else
	{
		//do nothing
	}
}





