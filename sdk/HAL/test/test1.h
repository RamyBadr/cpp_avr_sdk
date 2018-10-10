/*
 * test1
 *
 * Created: 23/09/2018 12:25:17 PM
 *  Author: Ramy Badr
 */ 


#ifdef TEST1_Run


#include "../config/config1.h"
using namespace HAL;

int main(void)
{
	U8  val;
    while(1)
    {
		if(btn0.isPressed()){
			led0.On();
		}else{
			led0.Off();
		}
		
		if(btn1.isPressed()){
			led1.On();
		}else{
			led1.Off();
		}
		
		if(btn2.isPressed()){
			led2.Flash(500,500);
		}else{
			led2.Off();
		}
    }
}
#endif
