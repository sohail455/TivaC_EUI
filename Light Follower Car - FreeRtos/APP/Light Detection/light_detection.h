/*
 * light_detection.h
 *
 *  Created on: Oct 9, 2023
 *      Author: C-LAB
 */


#ifndef APP_LIGHT_DETECTION_LIGHT_DETECTION_H_
#define APP_LIGHT_DETECTION_LIGHT_DETECTION_H_

#include "../utilities/APP_types.h"

#define LIGHT_DETECTION__TASK_PERIODICITY_MILLI_SEC  100
#define LIGHT_INTENSITY_DIFF_THRISHOLD   150
void light_detection_task(void *pvParameters);

#endif /* APP_LIGHT_DETECTION_LIGHT_DETECTION_H_ */
