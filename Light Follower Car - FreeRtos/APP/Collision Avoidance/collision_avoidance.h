/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLICATION LAYER (APP)                                 */
/*                                                                            */
/* !Module          : COLLISION AVOIDANCE                                     */
/* !Description     : Avoiding the detected objects in the range of configured*/
/*                    distance.                                               */
/*                                                                            */
/* !File            : collision_avoidance.h                                   */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Autonomous car Project @EME - EUI                       */
/*                                                                            */
/* !Target          : TIVA-C TM4C123GH6PM                                     */
/*                                                                            */
/* !Compiler        : Code Composer Studio 8.3.1                              */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
#ifndef APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_
#define APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_

/******************************* Includes *************************************/
#include "HAL/Ultrasonic/Ultrasonic.h"
#include "../utilities/APP_types.h"


#define COLLISION_AVOIDANCE_TASK_PERIODICITY_MILLI_SEC    60
#define COLLISION_DISTANCE_CM                             10U


/******************************************************************************/
/*! \Description : Initialize ADC Sequencer                                   */
/*! \return      None                                                         */
/*! \arguments   Copy_enuSeq to select sequencer                              */
/******************************************************************************/
void collisionAvoidance_task(void *pvParameters);
#endif /* APP_COLLISION_AVOIDANCE_COLLISION_AVOIDANCE_H_ */
