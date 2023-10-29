/*
 * motors.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Mahmoud A. Monaim
 */

#ifndef MOTORS_H_
#define MOTORS_H_

#include "Platform_Types.h"
#include "Std_Types.h"
#include "tm4c123gh6pm.h"
#include "Bit_Math.h"


/***************************************************************************************************************************
* Syntax          : void motor_initialisation(void)
* Description     : Initialize all the pins used to drive the motors ("b2,b3,b4,b5" for direction & "b6,b7" for speed)
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : NULL
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void motor_initialisation(void);


/***************************************************************************************************************************
* Syntax          : void Speed (int speed_percentage_A , int speed_percentage_B)
* Description     : Converts the "speed percentage" to a PWM signal and sends it to the motors
*                   Speed Percentage is (0% "stop") --> (100% "full speed")
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) : -> (int) speed_percentage_A:
*                       the speed of the left side motors of the car
*
*                  -> (int) speed_percentage_B:
*                       the speed of the right side motors of the car
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void Speed (int speed_percentage_A , int speed_percentage_B);


/***************************************************************************************************************************
* Syntax          : void current_direction(int direction)
* Description     : controls the car's direction of moving:
*                   ---------------------------------------
*                    1- Forward motion: both left side and right side motors are moving forward
*                    2- Backward motion: both left side and right side motors are moving backward
*                    3- Turning left : the "left side" motors are moving forward but with a higher speed than the "right side"
*                    4- Turning right : the "right side" motors are moving forward but with a higher speed than the "left side"
*                    5- Rotation : the "right side" and the "left side" are moving but in opposite directions
*
* Sync\Async      : Synchronous
* Reentrancy      : Non Reentrant
* Parameters (in) :  AN enum of the Direction {FORWARD , BACKWARD , TURN_LEFT, TURN_RIGH , ROTATE }
*                    Note: any other value = STOP
*
* Parameters (out): NULL
* Return value:   : NULL
***************************************************************************************************************************/
void current_direction(int direction);


enum {STRAIGHT,BACKWARD,TURN_LEFT,TURN_RIGHT,ROTATE,STOP};

#endif /* MOTORS_H_ */
