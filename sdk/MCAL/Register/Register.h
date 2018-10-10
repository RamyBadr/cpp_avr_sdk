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




namespace MCAL{
	
	#define REG_WIDTH 8
	class Register
	{
		private:
			U8  adress;
		public:
			Register(U8 address);
			void Write(U8 val);
			void Write(U8 bit_index, bool val);
			void Write(U8 startPin , U8 endPin, U8 val);
			
			void Read(U8 *val);
			void Read(U8 bit_index, U8 * val);
			void Read(U8 startPin , U8 endPin, U8 * val);
			
	};
}


#endif /* REGISTER_H_ */