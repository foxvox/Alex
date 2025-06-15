#include "Bicycle.h"

Bicycle::Bicycle() 
	: name{"Bicycle"} 
{
	cout << "Created Bicycle" << endl; 
	cout << "My name is " << name << endl;
	speed = 25; 
}

Bicycle::~Bicycle()
{
	cout << "Destroy Bicycle" << endl; 
}

void Bicycle::Move()
{
	cout << "Bicycle Moving..." << endl; 
}
