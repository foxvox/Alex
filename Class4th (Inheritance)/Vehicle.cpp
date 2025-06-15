#include "Vehicle.h"

Vehicle::Vehicle() 
	: speed{0}  
{
	cout << "Created Vehicle" << endl; 	
}

Vehicle::~Vehicle()
{
	cout << "Destroy Vehicle" << endl; 
}

void Vehicle::Move()
{} 
