#include <stdint.h>
#include "Platform_Types.h"
#include "OS/Scheduler.h"
#include "HAL/LCD/lcd.h"
#include "Tasks/Tasks.h"
#include "HAL/LDR/LDR.h"
#include "MCAL/RCC/RCC.h"
#include  "HAL/MOTORS/motors.h"
#include "HAL/UltraSonic/Ultrasonic.h"
#include "HAL/Buttons/Buttons.h"
#define int_enable() __asm(" cpsie i")

void ECU_init(void)
{
    Buttons_init();
    PLL_Init();
    LDR_Init();
    int_enable();
    LCD_init();
    motor_initialisation();
    Ultrasonic_INIT();
}
u32 d=0;

int main(void)
{
    ECU_init();

    create_task(ldr_swing_car, 10);
    create_task(UltraSonic_t, 8);
    create_task(LCD_Show_T, 50);

    sheduler_init();
    tasks_scheduler();
    while(1)
    {

    }
}
