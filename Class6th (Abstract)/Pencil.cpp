#include "Pencil.h"

Pencil::Pencil() 
	: color{} 
{
	cout << "Pencil()이 호출되었습니다." << endl; 
}

Pencil::~Pencil()
{
	cout << "~Pencil()이 호출되었습니다" << endl; 
}

void Pencil::Draw()
{
	cout << "Pencil::Draw()가 호출되었습니다." << endl; 
}
