#pragma once
#include "Vehicle.h"
class Boat : public Vehicle
{
public: 
	Boat(); 
	~Boat();
public:
	void Move() override; 
private:
	int fuel; 
	const char* name; 
};

