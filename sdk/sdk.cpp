/*
 * sdk.cpp
 *
 * Created: 23/09/2018 12:25:17 PM
 *  Author: Ramy Badr
 */ 


//#include <avr/io.h>
#include "MCAL/avratmega32.h"
#include "MCAL/Register/Register.h"
using namespace MCAL;

int main(void)
{

	
	Register Port_D(0x32);
	DDRD |= 0xFF;
	Port_D.Write(0xF0);
	Port_D.Write(6,0);
    while(1)
    {
        //TODO:: Please write your application code 
    }
}