/*
 * BTN.h
 *
 * Created: 24/09/2018 09:13:10 PM
 *  Author: Ramy Badr
 */ 


#ifndef BTN_H_
#define BTN_H_

#include "../device.h"

using namespace HAL;
namespace HAL{
	class Btn:Device{
		DevicePin * _btn_pin;
		public:
			Btn(DevicePin * pin,ActiveState state):
				Device(1,state,Dinput)
			{
				//validation goes here
				if (pin!=NULL)
				{
					this->_btn_pin = pin ;
					this->_btn_pin->Init(input);			
				}	
				
			}
			void GetVal(U8 *val){
				this->_btn_pin->Read(val);
			}
			bool isPressed(){
				U8 * val;
				_delay_ms(25);
				this->GetVal(val);
				return (*val==this->_active_state);
			}
		};
		
}



#endif /* BTN_H_ */