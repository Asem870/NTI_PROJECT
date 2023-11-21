
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"RCC_init.h"
#include "GPIO_private.h"
#include "GPIO_init.h"
#include "DC_motor.h"
#include "RUNNING_TASK.h"

/********used pins in running task**************
 * PINA0
 * PINA1
 * PINA2
 * PINA3
 * PINA4
 * PINA5
 * PINA6
 * PINA7
 * /


/**************options for angles*****************/
//1- CENTER_Angle 0
//2- RIGHT_Angle 1
//3- LEFT_Angle 2

/*************** options for directions   ******************/
//1- forward_dir      0
//2- reverse_dir      1
//3- change_dir		2

/****************options for dc_motor speed*****************/
//1-	NOT_MOVE
//2-	MOVE

/*****************options for key of the car ***************/
//1-	NOT_READY,
//2-	READY_NOT_INTIALISED,

/*************** global variables *****************/
/*direction state*/
u8 IR_u8Read = forward_dir;
/*ultrasonic distance*/
 u32  ULTRASONIC_u32Distance;
 /*servo angle */
 u8   SERVO_u8AngleVal=CENTER_Angle;
 /*dc motor speed intialised */
 RUNNING_STATE_t   DCmotor_u8Speed=MOVE;
 /************the key of the car*********/
 RUNNING_STATE_t state=NOT_READY;
/*****************************************************/



 Motor_t Copy_pMotor_t_Obj[4]={{0,0,1,0},{2,0,3,0},{4,0,5,0},{6,0,7,0}};

int main(void)
{
//	u8 i;
//    /* Loop forever */
//	RCC_u8SetClkSource(RCC_HSI);
//	RCC_u8SetClkStatus(RCC_HSI, 1);
//	RCC_voidEnablePeripheralClock(RCC_APB2, APB2_GPIOA_EN);
//	for(i=2;i<=9;i++)
//	{
//		GPIO_voidSetPinDirection(GPIOA, i, OUTPUT_10MHZ_PUSH_PULL);
//		GPIO_voidSetPinValue(GPIOA, i, LOW);
//	}

	RUNNING_VoidFUNC(Copy_pMotor_t_Obj);

	for(;;);
}
