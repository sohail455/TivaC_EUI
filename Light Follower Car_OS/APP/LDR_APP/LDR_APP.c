//#include "HAL/LDR/LDR.h"
//#include "LDR_APP.h"
//
//DIRECTION_t direction;
//
//
//
//void ldr_swing_car_init(void)
//{
//
//    LDR_Init();
//    direction = FORWARD;
//}
//void ldr_swing_car(void)
//{
//
//
//
//    left_value = Ldr_getValue(LDR0);
//    right_value = Ldr_getValue(LDR1);
//
//    if (left_value > right_value + DIRECTION_THRES)
//    {
//        direction = RIGHT;
//    }
//    else if (right_value > left_value + DIRECTION_THRES)
//    {
//        direction = LEFT;
//    }
//    else
//    {
//        direction = FORWARD;
//    }
//}
//
//DIRECTION_t swing_car_getDirection(void)
//{
//    return direction;
//}
//
