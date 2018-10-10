/*
 * singleton.h
 *
 * Created: 26/09/2018 01:20:37 AM
 *  Author: Ramy Badr
 */ 


#ifndef SINGLTON_H_
#define SINGLTON_H_
#include <stddef.h>
class  Singleton
{
public:
	static Singleton* GetInstance(){
		if (_instance==NULL){
			Singleton();
		}
		return _instance;
	}
protected:
	Singleton(){
		_instance = this ;
	}
	static Singleton * _instance ;
private:
};
Singleton* Singleton::_instance ;




#endif /* SINGLTON_H_ */