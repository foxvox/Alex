#include "Paint.h"

Paint::Paint() 
	: thickness{ 0 } 
{
	cout << "Paint()가 호출되었습니다." << endl; 
}

Paint::~Paint()
{
	cout << "~Paint()가 호출되었습니다." << endl; 
}
