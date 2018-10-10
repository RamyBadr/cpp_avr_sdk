/*
 * LED.h
 *
 * Created: 25/09/2018 10:03:05 PM
 *  Author: Ramy Badr
 */ 


#ifndef LED_H_
#define LED_H_


#include "../device.h"

using namespace HAL;
namespace HAL{
	class LED:Device{
			DevicePin * _led_pin;
		public:
			LED(DevicePin* pin,ActiveState state):
				Device(1,state,Doutput){
					if(pin!=NULL){
						this->_led_pin = pin ;
						this->_led_pin->Init(output);
					}
				}
			void On(){
				if (this->_active_state==activeHigh){
					this->_led_pin->Write(1);
				}else{
					this->_led_pin->Write(0);
				}
			}
			void Off(){
				if (this->_active_state==activeHigh){
					this->_led_pin->Write(0);
				}else{
					this->_led_pin->Write(1);
				}
			}
			void Toggle(){
				this->_led_pin->Toggle();
			}
			void Flash(U16 on_duration,U16 off_duration){
				U16 i ;
				this->On();
				for (i=0;i<on_duration;i++)
				{
					_delay_ms(1);
				}
				this->Off();
				for (i=0;i<off_duration;i++)
				{
					_delay_ms(1);
				}
			}
		};
}	




#endif /* LED_H_ */