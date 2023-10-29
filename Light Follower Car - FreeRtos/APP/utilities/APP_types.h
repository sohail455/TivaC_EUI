

#ifndef APP_UTILITIES_APP_TYPES_H_
#define APP_UTILITIES_APP_TYPES_H_


#include "../tasks.h"
#define LIGHT_DETECTED_EVENT_FLAG   ( 1 << 0 )
#define COLLISION_EVENT_FLAG        ( 1 << 1 )
#define NORMAL_EVENT_FLAG           ( 1 << 2 )

#define SECONDS_MESSAGE_ID          0xAA
#define DISTANCE_MESSAGE_ID         0xBB

/*Tasks handles*/
#define LIGHT_DETECTION_TASK_HANDLE         ldr_h
#define COLLISION_AVOIDANCE_TASK_HANDLE     ultrasonic_h
#define SYSTME_TIMER_TASK_HANDLE            sys_h
#define MOTION_CONTROL_TASK_HANDLE          motors_h

typedef struct
{
    uint32_t reading;
    uint8_t id;
}Sensor_msg_t;

extern QueueHandle_t Displaying_Q;
extern uint8_t motor_state ;


EventGroupHandle_t events;
#endif /* APP_UTILITIES_APP_TYPES_H_ */
