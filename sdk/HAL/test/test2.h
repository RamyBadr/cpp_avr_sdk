/*
 * test2.h
 *
 * Created: 26/09/2018 01:57:37 AM
 *  Author: Ramy Badr
 */ 


#ifdef TEST2
#include "../../MCAL/interrupt/interrupt_controller.h"
#include "../config/config1.h"
#include "avr/interrupt.h"
using namespace MCAL;
int main(){
	
	InterruptControler * intrC = InterruptControler::GetInstance();
	intrC->EnableGlobal();
	intrC->Enable(Interrupt0);
	intrC->ControlSense(Interrupt0, LowLevel);
	while(1){
		led2.Flash(500,500);
	}
}


ISR (INT0_vect){
	led0.Toggle();
	
}

#endif // TEST2