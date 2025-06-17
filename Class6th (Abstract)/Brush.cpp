#include "Brush.h"

Brush::Brush() 
	: color{} 
{
	cout << "Brush()가 호출되었습니다." << endl; 
}

Brush::~Brush()
{
	cout << "~Brush()가 호출되었습니다." << endl; 
}

void Brush::Draw()
{
	cout << "Brush::Draw()가 호출되었습니다." << endl; 
}
