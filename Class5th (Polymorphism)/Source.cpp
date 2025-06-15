#include <iostream> 
#include <iomanip> 
#include "Consumable.h" 
#include "Potion.h" 
#include "Lantern.h" 
#include "Bandage.h" 
#include "Antidote.h" 

using namespace std;

static int Square(int x)
{
	return x * x;
}
static double Square(double x)
{
	return x * x;
}

typedef enum
{
	potion = 1, lantern, antidote, bandage
} Con;

int main()
{
#pragma region 다형성 
#pragma region 함수오버로딩 	
	/*cout << Square(5) << endl;
	cout << fixed << setprecision(2) << Square(3.0) << endl;*/
#pragma endregion 
#pragma region 함수오버라이딩 
	/*Consumable* pCon;
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "1. Potion    2.Lantern    3.Antidote    4.Bandage" << endl;
		cin >> num;

		switch (Con(num))
		{
		case potion:
			pCon = new Potion;
			pCon->Use();
			delete pCon;
			break;
		case lantern:
			pCon = new Lantern;
			pCon->Use();
			delete pCon;
			break;
		case antidote:
			pCon = new Antidote;
			pCon->Use();
			delete pCon;
			break;
		case bandage:
			pCon = new Bandage;
			pCon->Use();
			delete pCon;
			break;
		default:
			cout << "잘못입력했습니다." << endl;
			break;
		}
	}*/
#pragma endregion 
#pragma endregion 
}