#include "Scooter.h"

Scooter::Scooter() 
	: fuel{ 100 }, name{"Scooter"} 
{
	cout << "Created Scooter" << endl; 
	cout << "My name is " << name << endl;
	speed = 50; 	
}

Scooter::~Scooter()
{
	cout << "Destroy Scooter" << endl; 
}

void Scooter::Move()
{
	cout << "Scooter Moving..." << endl; 
}
