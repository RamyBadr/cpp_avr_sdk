/*
 * Register.h
 *
 * Created: 23/09/2018 04:19:06 PM
 *  Author: Ramy Badr
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_



#include "../../UTILS/datatypes.h"
#include "../../UTILS/basicmacros.h"
#include "../avratmega32.h"



namespace MCAL{
	
	#define REG_WIDTH 8
	#define IS_PIN(pin) (pin>=0&&pin<REG_WIDTH)
	
	class Register
	{
		protected:
			U8  address;
		public:
			Register(U8 address);
			void Write(U8 val);
			void Write(U8 bit_index, bool val);
			void Write(U8 startPin , U8 endPin, U8 val);
			
			void Toggle();
			void Toggle(U8 bit_index);
			void Toggle(U8 startPin , U8 endPin);
			
			void Read(U8 *val);
			void Read(U8 bit_index, U8 * val);
			void Read(U8 startPin , U8 endPin, U8 * val);
			
			
			
			
	};
}


#endif /* REGISTER_H_ */