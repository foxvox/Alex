#include "Resource.h"

Resource::Resource()
{
	cout << "Constructor" << endl; 
}

Resource::~Resource()
{
	cout << "Destructor" << endl; 
}

void Resource::Share(shared_ptr<Resource>& _sharedPtr)
{	
	sharedPtr = _sharedPtr; 
}
