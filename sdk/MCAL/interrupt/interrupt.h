/*
 * interrupt.h
 *
 * Created: 25/09/2018 11:14:31 PM
 *  Author: Ramy Badr
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../Register/Register.h"
using namespace MCAL;
namespace MCAL{
	enum InterruptSense{
			LowLevel		= 0x00,
			LogicChange		= 0x01,
			FallingEdge		= 0x02,
			RisingEdge		=0x03,
		};
	
	
}



#endif /* INTERRUPT_H_ */