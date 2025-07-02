#pragma once 
#include <iostream>
using namespace std; 

class Resource
{
private:
	shared_ptr<Resource> sharedPtr; 
public:
	Resource();
	~Resource(); 

	void Share(shared_ptr<Resource>& resrc);
};

