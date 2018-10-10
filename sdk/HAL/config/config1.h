/*
 * config1.h
 *
 * Created: 25/09/2018 08:46:36 PM
 *  Author: Ramy Badr
 */ 


#ifndef CONFIG1_H_
#define CONFIG1_H_

#include "../Device/BTN/BTN.h"
#include "../Device/LED/LED.h"
using namespace HAL;

static AvrAtmega32 * mcuConfig = AvrAtmega32::GetInstance();
static Port * Port_D = &(mcuConfig->PortD) ;

/*
* Initialize buttons
*/
static DevicePin Btn0Pin(Port_D,0);
static DevicePin Btn1Pin(Port_D,1);
static DevicePin Btn2Pin(Port_D,2);

extern Btn btn0(&Btn0Pin,activeHigh);
extern Btn btn1(&Btn1Pin,activeHigh);
extern Btn btn2(&Btn2Pin,activeHigh);

/*-----------------------------*/

/*
*Initialize LEDS
*/

static DevicePin LED0Pin(Port_D,5);
static DevicePin LED1Pin(Port_D,6);
static DevicePin LED2Pin(Port_D,7);


extern LED led0(&LED0Pin,activeHigh);
extern LED led1(&LED1Pin,activeHigh);
extern LED led2(&LED2Pin,activeHigh);

#endif /* CONFIG1_H_ */