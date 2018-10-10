/*
 * GPIO.cpp
 *
 * Created: 24/09/2018 04:03:51 PM
 *  Author: Ramy Badr
 */ 
#include "GPIO.h"
using namespace MCAL;
namespace MCAL{
	void Port::Direct(Direction dir){
		if (dir==input){
			this->dirReg->Write(0x00);
		}else{
			this->dirReg->Write(0xFF);
		}
	}
	void Port::Direct(U8 pin,Direction dir){
		if (dir==input){
			this->dirReg->Write(pin,dir);
		}else{
			this->dirReg->Write(pin,dir);
		}
	}
	void Port::Write(U8 val){
		this->outputReg->Write(val);
	}
	void Port::Write(U8 pin,bool val){
		this->outputReg->Write(pin,val);
	}
	
	void Port::Toggle(){
		this->outputReg->Toggle();
	}
	void Port::Toggle(U8 bit_index){
		this->outputReg->Toggle(bit_index);
	}
	void Port::Toggle(U8 start_bit,U8 end_bit){
		this->outputReg->Toggle(start_bit,end_bit);
	}
	
	void Port::Read(U8 * val){
		this->inputReg->Read(val);
	}
	void Port::Read(U8 bit_index, U8 * val){
		this->inputReg->Read(bit_index,val);
	}
}