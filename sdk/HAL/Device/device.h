/*
 * device.h
 *
 * Created: 24/09/2018 11:27:57 PM
 *  Author: Ramy Badr
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_
#include "../../MCAL/MCU/avratmega32_config.h"
#include <util/delay.h>

namespace HAL{
	enum ActiveState{
		activeLow,activeHigh
		};
	enum DeviceDirection{
		Dinput,Doutput,Dboth
		};
	class DevicePin{
		private:
			Port*	_port ;
			U8		_pin_index ;	
		public:	
			DevicePin(Port * port,U8 pin_index){
				if (IS_PIN(pin_index)){
					this->_pin_index = pin_index ;
					this->_port = port ;
				}
			}
			void Init(Direction dir){
				this->_port->Direct(this->_pin_index,dir);
				
			}
			void Read(U8 * val){
				this->_port->Read(this->_pin_index,val);
			}
			void Write(bool val){
				this->_port->Write(this->_pin_index,val);
			}
			void Toggle(){
				this->_port->Toggle(this->_pin_index);
			}
	};
	
	class Device{
		protected:
			U8				_pin_count;
			ActiveState		_active_state;
			DeviceDirection		_dev_dir;
		public:
			Device(U8 pin_count,ActiveState state,DeviceDirection dir):
				_pin_count(pin_count),_active_state(state),_dev_dir(dir)
				{
					
				}
		};
}



#endif /* DEVICE_H_ */