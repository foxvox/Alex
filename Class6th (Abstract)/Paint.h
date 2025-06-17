#pragma once

#include <iostream> 
using namespace std; 

class Paint
{
public:
	Paint();
	virtual ~Paint(); 
public:
	virtual void Draw() = 0; 
protected: 
	int thickness; 
};

