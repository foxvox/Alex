#pragma once
#include "Vehicle.h" 

class Scooter : public Vehicle
{
public: 
	Scooter(); 
	~Scooter();
public: 
	void Move() override; 
private:
	int   fuel; 
	const char* name; 
};

