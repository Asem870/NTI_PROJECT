#ifndef _RUNNING_H_
#define _RUNNING_H_







#define KEY_FLAG	NOT_READY


/*enum for intilisation state*/
typedef enum 
{
	NOT_READY,
	READY_NOT_INTIALISED,
	READY_INTILISED,
}RUNNING_STATE_t;



typedef enum
{
	NOT_MOVE,
	MOVE
	
}speed_t;
/*************** macros definitions   ******************/


typedef enum
{
	FIRST_STOP,
	FIRST_LEFT_ANGLE,
	SECOND_STOP,
	SECOND_RIGHT_ANGLE,
	THIRD_STOP,

}ANGLE_t;

/*macros for angles*/
#define CENTER_Angle 0
#define RIGHT_Angle 1
#define LEFT_Angle 2

/*macros for directions*/
#define forward_dir      0
#define reverse_dir      1
#define change_dir		2


void RUNNING_VoidFUNC(Motor_t* Copy_pMotor_t_Obj)	;




#endif
