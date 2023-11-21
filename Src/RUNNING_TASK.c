
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DC_motor.h"
#include "RUNNING_TASK.h"
#include "RUNNING_TASK_private.h"
#include "GPIO_init.h"


extern  u8   SERVO_u8AngleVal;
extern u8   DCmotor_u8Speed;
extern u8 IR_u8Read ;
extern ANGLE_t angle_state;
/*assign the state of car by not intialised*/
 	extern RUNNING_STATE_t state;
 	ANGLE_t angle_state=FIRST_STOP;

void RUNNING_VoidFUNC(Motor_t* Copy_pMotor_t_Obj)	/**/
{
	
		/*switch on state*/
		switch(state)
		{
			/*the car is not ready*/
			case NOT_READY:
				/*make the status equal to global flag to indicate is it ready or not*/
				state=state;
				break;
			/*the car is ready but not intialised*/
			case READY_NOT_INTIALISED:
				/*MOVE THE CAR WITH 4 DC MOTOR SPEED*/
				//DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
				//DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
				//DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
				//DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
				DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
		        DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+1);
				



				/*MAKE THE STATE EQUAL INTIALISED*/
				state==READY_INTILISED;
			break;
			/*the car is ready and moving*/
			case READY_INTILISED:
				/*switch on direction state*/
				switch(IR_u8Read)
				{
					/*direction forward*/
					case forward_dir:
						/*switch on the speed value*/
						switch(DCmotor_u8Speed)
						{
							/*case the car is forward but not moving*/
							case NOT_MOVE:
							/*stop the dc_motor*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							break;
							/*the car is forward and moving*/
							case MOVE:
							/*run the dc motor clock wise(forward direction)*/
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj);
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+1);
							
							break;
						}
					break;
					/*direction backward*/
					case reverse_dir:
						/*switch on the speed value*/
						switch(DCmotor_u8Speed)
						{
							/*case the car is backward but not moving*/
							case NOT_MOVE:
							/*stop the dc_motor*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							break;
							/*the car is backward and moving*/
							case MOVE:
							/*reverse the wheels to backward direction*/
							DCMotor_voidMotorRotateAnticlockwise(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorRotateAnticlockwise(Copy_pMotor_t_Obj+3);
							break;
						}
					break;
					case change_dir:
					switch(angle_state)
						{
							/*case the car is returned from backward direction*/
							case FIRST_STOP:
							/*stop the dc_motor*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj);							/*make the state equal to the next one*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							angle_state=FIRST_LEFT_ANGLE;
							break;/*or vtask dealy*/
							/*case the car is stoped and we need to change the angle*/
							case FIRST_LEFT_ANGLE:
							/*change the angle of servo motor to left*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+0);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+3);
							/*change the angle of struct not global variable*/
							SERVO_u8AngleVal=RIGHT_Angle;
							/*make the state equal to the next one*/
							angle_state= SECOND_STOP;
							break;/*or vtask dealy*/
							
							/*case the car change angle to left then moved and it will stop*/
							case SECOND_STOP:
							/*stop the dc_motor*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							/*make the state equal to the next one*/
							angle_state=SECOND_RIGHT_ANGLE;
							break;
							/*case the car is chnaged the angle then stoped and it will change angle to right*/
							case SECOND_RIGHT_ANGLE:
							/*change the angle of servo motor to right*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+0);
							DCMotor_voidMotorRotateClockwise(Copy_pMotor_t_Obj+2);
							/*make the state equal to next one*/
							angle_state=THIRD_STOP;
							break;
							/*case the car is changed to right and it will move*/
							/*case the car moved and i want to stop it*/
							case THIRD_STOP:
							/*stop the dc_motor*/
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+1);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+2);
							DCMotor_voidMotorStop(Copy_pMotor_t_Obj+3);
							/*return to the intial state*/
							state=READY_NOT_INTIALISED;
							/*make the direction forward*/
							IR_u8Read=FORWARD;
							break;
							
						}
					
				}
			
		}
		
}
