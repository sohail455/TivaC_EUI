/****************************************************************************
 * Author:      Sohail Talaat
 * Module:      app.c
 * File Name:   app
 * Layer:       app
 * Description: Application to start transfer over CAN bus.
 ****************************************************************************/
#ifndef APP_H_
#define APP_H_

void start_transmit(void);
void GPIOFIntHandler(void);


#endif /* APP_H_ */
