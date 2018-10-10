/*
 * GPIO.h
 *
 * Created: 24/09/2018 04:04:10 PM
 *  Author: Ramy Badr
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../Register/Register.h"
using namespace MCAL;
namespace MCAL{
	enum Direction{
		input ,
		output  
		};
	class Port
	{
		private:
		Register * dirReg ;
		Register * inputReg;
		Register * outputReg;
		protected:
		public:
		Port(Register * dir_reg,Register * input_reg, Register * output_reg){
			this->dirReg = dir_reg;
			this->outputReg = output_reg;
			this->inputReg = input_reg ;
		}
		void Direct(Direction dir);
		void Direct(U8 pin,Direction dir);
		
		void Write(U8 val);
		void Write(U8 pin,bool val);
		
		void Toggle();
		void Toggle(U8 bit_index);
		void Toggle(U8 start_bit,U8 end_bit);

		void Read(U8 * val);
		void Read(U8 bit_index, U8 * val);
		
	};	
	}

#endif /* GPIO_H_ */