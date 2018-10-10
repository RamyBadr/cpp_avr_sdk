/*
 * avratmega32_config.h
 *
 * Created: 24/09/2018 05:00:06 PM
 *  Author: Ramy Badr
 */ 


#ifndef AVRATMEGA32_CONFIG_H_
#define AVRATMEGA32_CONFIG_H_
#define F_CPU 8000000UL
#include "../GPIO/GPIO.h"
//#include "../../UTILS/singleton.h"
#include "AVRAtmega32_consts.h"
#include <stddef.h>

using namespace MCAL;
namespace MCAL{
	class AvrAtmega32{
		public:		
			static AvrAtmega32* GetInstance(){
				if (_instance==NULL){
					AvrAtmega32();
				}
				return (AvrAtmega32 *)_instance;
			}
			Port  PortA;
			Port  PortB;
			Port  PortC;
			Port  PortD;
			
			Register StatusReg;

		private :
			static AvrAtmega32 * _instance;
			
			Register  _A_Output;
			Register  _A_DDR;
			Register  _A_Input;

			Register  _B_Output;
			Register  _B_DDR;
			Register  _B_Input;

			Register  _C_Output;
			Register  _C_DDR;
			Register  _C_Input;
						
			Register  _D_Output;
			Register  _D_DDR;
			Register  _D_Input;

			AvrAtmega32():
				StatusReg(0x5F),
				_A_DDR(0x3A) , _A_Output(0x3B) , _A_Input(0x39),PortA(&(_A_DDR),&(_A_Input),&(_A_Output)),
				_B_DDR(0x37) , _B_Output(0x38) , _B_Input(0x36),PortB(&(_B_DDR),&(_B_Input),&(_B_Output)),
				_C_DDR(0x34) , _C_Output(0x35) , _C_Input(0x33),PortC(&(_C_DDR),&(_C_Input),&(_C_Output)),
				_D_DDR(0x31) , _D_Output(0x32) , _D_Input(0x30),PortD(&(_D_DDR),&(_D_Input),&(_D_Output))
			{
				_instance =  this;
			}
			
		};
		AvrAtmega32 * AvrAtmega32::_instance;
}



#endif /* AVRATMEGA32_CONFIG_H_ */