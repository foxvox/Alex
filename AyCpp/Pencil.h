#pragma once
#include "Paint.h"
class Pencil : public Paint
{
public:
	Pencil();
	~Pencil(); 
public:
	virtual void Draw() override;
private:
	float color; 	
};

