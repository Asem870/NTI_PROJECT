#ifndef DC_Motor_interface_H_
#define DC_Motor_interface_H_


typedef enum
{
	clockwise,
	anticlockwise
}EN_rotation_t;


typedef struct
{
	u8 MotorClockwisePin;
	u8 MotorClockwisePort ;
	u8 MotorAnticlockwisePin ;
	u8 MotorAnticlockwisePort ;
}Motor_t ;


void DCMotor_voidMotorInit(Motor_t* Copy_pMotor_t_Obj);
void DCMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj);
void DCMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj);
void DCMotor_voidMotorStop(Motor_t* Copy_pMotor_t_Obj);


#endif