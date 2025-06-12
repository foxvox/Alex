#include "Boat.h"

Boat::Boat() 
	: fuel{ 250 }, name{"Boat"} 
{
	cout << "Created Boat" << endl; 
	cout << "My name is " << name << endl;
	speed = 200; 
}

Boat::~Boat()
{
	cout << "Destroy Boat" << endl; 
}

void Boat::Move()
{
	cout << "Boat Moving..." << endl; 
}
