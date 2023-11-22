/*
 * Accele.h
 *
 *  Created on: Nov 21, 2023
 *      Author: LENOVO
 */

#ifndef ACC_H_
#define ACC_H_



#define DC_MAX_NUM		2

/*************** options for directions   ******************/
#define forward_dir      0
#define reverse_dir      1
#define change_dir		  2


/*Runnning task Objecst*/
#define MOVE		5
#define NOT_MOVE	0

/*DC Motors Pins*/
#define MOTOR1_LEFTPIN			PIN1
#define MOTOR1_RIGHTPIN			PIN2
#define MOTOR2_LEFTPIN			PIN3
#define MOTOR2_RIGHTPIN			PIN4


/*MOTOR STATES*/
#define MOTOR_OFF       	 0x00
#define ONLY_LEFT_MOTOR1	 0x01
#define ONLY_LEFT_MOTOR2	 0x02
#define ONLY_RIGHT_MOTOR1 	 0x04
#define ONLY_RIGHT_MOTOR2 	 0x08
#define MOTORs_ON1			 0x0A
#define MOTORs_ON2			 0x09
#define MOTORs_ON3			 0x05
#define MOTORs_ON4			 0x06

/************STRUCT TO GET THE DCMOTOR PORT AND PINS FOR CHECKING*************/
typedef struct
{
	u8 Port;
	u8 Left_Pin;
	u8 Right_Pin;
}DCMotor_t;



/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/
void ACC_vdCarSpeed(void);


/*typedef struct
{

}PINs_t;*/

#endif /* ACC_H_ */
