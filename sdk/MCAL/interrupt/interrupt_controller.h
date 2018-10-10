/*
 * interrupt_controller.h
 *
 * Created: 26/09/2018 01:46:51 AM
 *  Author: Ramy Badr
 */ 


#ifndef INTERRUPT_CONTROLLER_H_
#define INTERRUPT_CONTROLLER_H_


#include "../Register/Register.h"
#include "../MCU/avratmega32_config.h"
#include "interrupt_Consts.h"
using namespace MCAL;

namespace MCAL{
	enum GICR_Bit{_IVCE	=	0x00,_IVSEL	=	0x01,_INT2	=	0x05,_INT0	=	0x06,_INT1	=	0x07};

	enum ExInterrupt{
		Interrupt0,Interrupt1,Interrupt2
	};

	enum InterruptSense{
		LowLevel		= 0x00,
		LogicChange		= 0x01,
		FallingEdge		= 0x02,
		RisingEdge		=0x03,
	};

	enum MCUCR_Bit{
		_ISC00	=	0x00,
		_ISC01	=	0x01,
		_ISC10	=	0x02,
		_ISC11	=	0x03,
		_SM0		=	0x04,
		_SM1		=	0x05,
		_SM2		=	0x06,
		_SE		=	0x07
	};

	
	class  InterruptControler
	{
		private:
		Register  _GICR;
		Register _MCUCR;
		InterruptControler():
		_GICR(0x5B),_MCUCR(0x55)
		{
			_instance = this ;
		}
		public:
		
		static InterruptControler* GetInstance(){
			if (_instance==NULL){
				InterruptControler();
			}
			return _instance;
		}
		
		void EnableGlobal(){
			AvrAtmega32* mcu = AvrAtmega32::GetInstance();
			Register * st_reg =&(mcu->StatusReg);
			st_reg->Write(7,1);
		}
		void DisableGlobal(){
			AvrAtmega32* mcu = AvrAtmega32::GetInstance();
			Register * st_reg = &(mcu->StatusReg);
			st_reg->Write(7,0);
		}
		
		void Enable(ExInterrupt Intr){
			EnableGlobal();
			
			GICR_Bit bit;
			switch(Intr){
				case Interrupt0:
				bit = _INT0 ;
				//General Interrupt Control Register : External Interrupt Request 0 Enable
				//_GICR.Write(6,true);
				SET_BIT(REG_GET(0x5B),6);
				break;
				case Interrupt1:
				bit = _INT1 ;
				break;
				case Interrupt2:
				bit = _INT2 ;
				break;
				default:
				return;
			}
			//_GICR.Write(bit,1);
			return;
		}
		
		void ControlSense(ExInterrupt intr,InterruptSense state){
			MCUCR_Bit bit0,bit1;
			switch(intr){
				case Interrupt0:
				bit0=_ISC00;
				bit1=_ISC01;
				break;
				case Interrupt1:
				bit0 = _ISC10;
				bit1 = _ISC11;
				break;
				case Interrupt2:
				//to be done
				return;
				break;
			}
			_MCUCR.Write(bit0,bit1,state);
		}
		
		static InterruptControler * _instance ;
	};
	InterruptControler* InterruptControler::_instance ;
}




#endif /* INTERRUPT_CONTROLLER_H_ */