#pragma once

#include <iostream> 
using namespace std; 

class Vehicle
{
protected:
	int speed; 
public: 
	Vehicle(); 
	virtual ~Vehicle(); 
public:
	virtual void Move(); 
};

