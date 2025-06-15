#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
public: 
	Bicycle(); 
	~Bicycle(); 
public:
	void Move() override; 
private: 
	const char* name; 
};

