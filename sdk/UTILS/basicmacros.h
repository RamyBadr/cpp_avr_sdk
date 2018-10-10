/*
 * basicmacros.h
 *
 * Created: 09/09/2018 10:22:05 PM
 *  Author: Ramy Badr
 */ 


#ifndef BASICMACROS_H_
#define BASICMACROS_H_

#define TOGGLE_BIT(reg,pin)		(reg^=(1<<pin))
#define READ_BIT(reg,pin)		((reg&(1<<pin))>>pin)
#define SET_BIT(reg,pin)		(reg|=(1<<pin))
#define CLR_BIT(reg,pin)		(reg&=~(1<<pin))
#define REG_GET(address) (*(volatile U8 *const)address)


#endif /* BASICMACROS_H_ */