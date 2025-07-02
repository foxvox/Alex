#include "Packet.h"

Packet::Packet()
{
	cout << "Packet Contructor" << endl; 
}

Packet::~Packet()
{
	cout << "Packet Destructor" << endl; 
}

void Packet::Receive()
{
	cout << "Receive" << endl; 
}

