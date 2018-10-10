/*
 * Register.cpp
 *
 * Created: 23/09/2018 04:19:17 PM
 *  Author: Ramy Badr
 */ 


#include "Register.h"
#include "../../UTILS/basicmacros.h"
namespace MCAL{
	
	Register::Register(U8 address){
		//address validation goes here
		this->adress = address ;
	}

	void Register::Write(U8 val){
		//val validation & address validation goes here
		REG_GET(this->adress) = val;
	}

	void Register::Write(U8 bit_index, bool val){
		if(bit_index>=0&&bit_index<REG_WIDTH){
			if (val){
				SET_BIT(REG_GET(this->adress),bit_index);
			}else{
				CLR_BIT(REG_GET(this->adress),bit_index);
			}
		}
	}
	
	void Register::Write(U8 startPin , U8 endPin, U8 val){
		U8 i ;
		if(IS_PIN(startPin)&&IS_PIN(endPin)){
			if (startPin > endPin){
				startPin += endPin;
				endPin = startPin - endPin ;
				startPin -= endPin ;
			}
			for(i=startPin;i<=endPin;i++){
				if(READ_BIT(val,i)==0){
					CLR_BIT(REG_GET(this->adress),i);
				}else{
					SET_BIT(REG_GET(this->adress),i);
				}
			}
			
		}
	}
	
	void Register::Read(U8 * val){
		*val = REG_GET(this->adress);
	}
	
	void Register::Read(U8 bit_index, U8 * val){
		if(IS_PIN(bit_index)){
			*val = READ_BIT(REG_GET(this->adress),bit_index);
		}
		
	}
}
