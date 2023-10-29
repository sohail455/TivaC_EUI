#include "display.h"
void Display_task(void *pvParameters)
{
    Sensor_msg_t recieved_msg; /*sensor msg strut for holding and processing received messages to the displaying queue  */
    while (1)
    {
        xQueueReceive(Displaying_Q,&recieved_msg,0);/*get the received messages from the queue*/
        if((recieved_msg.id == DISTANCE_MESSAGE_ID)) /*check if the received message is message of the measured distance*/
        {
            /*display distance msg at its specified location*/
            LCD_moveCursor(0, 9);
            LCD_vidWriteNumber(recieved_msg.reading);
            LCD_vidWriteString("     ");
        }
        else if(recieved_msg.id == SECONDS_MESSAGE_ID )/*check if the received message is message of the current seconds' count*/
        {
            /*display timer msg at its specified location*/
            LCD_moveCursor(1, 6);
            LCD_vidWriteNumber(recieved_msg.reading);
        }

    }
}

void Display_init(void)
{
    LCD_moveCursor(0,0);
    LCD_vidWriteString("DISTANCE:");
    LCD_moveCursor(1,0);
    LCD_vidWriteString("TIME:");
}



