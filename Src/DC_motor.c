#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_init.h"


#include "DC_motor.h"



void DCMotor_voidMotorInit(Motor_t* Copy_pMotor_t_Obj)
{
	GPIO_voidSetPinDirection (Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , OUTPUT_50MHZ_PUSH_PULL );
	GPIO_voidSetPinDirection (Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , OUTPUT_50MHZ_PUSH_PULL );

}

void DCMotor_voidMotorRotateClockwise(Motor_t* Copy_pMotor_t_Obj)
{
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , HIGH);
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}

void DCMotor_voidMotorRotateAnticlockwise(Motor_t* Copy_pMotor_t_Obj)
{
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , HIGH);
}

void DCMotor_voidMotorStop(Motor_t* Copy_pMotor_t_Obj)
{
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorClockwisePort , Copy_pMotor_t_Obj->MotorClockwisePin , LOW);
	GPIO_voidSetPinValue(Copy_pMotor_t_Obj->MotorAnticlockwisePort , Copy_pMotor_t_Obj->MotorAnticlockwisePin , LOW);
}

