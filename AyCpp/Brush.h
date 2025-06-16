#pragma once
#include "Paint.h"
class Brush : public Paint
{
public:
	Brush();
	~Brush(); 
public:
	virtual void Draw() override; 
private:
	float color; 
};

