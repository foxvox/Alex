#include <iostream> 
#include <cassert> 
using namespace std;

class Item
{
private:
	int* pPrice;
	char grade;
public:
	Item() : pPrice{ nullptr }, grade{ 'A' }
	{
		pPrice = new int;
		*pPrice = 1000;
	}

	Item(const Item& other) : pPrice{ other.pPrice }, grade{ other.grade }
	{
		pPrice = new int(*other.pPrice); 
	}

	~Item()
	{
		if (pPrice != nullptr)
		{
			delete pPrice;
		}
		pPrice = nullptr;
	}

	void Information() const
	{
		cout << "My Information" << endl;
		cout << "*pPrice: " << *pPrice << '\t' << "grade: " << grade << endl;
	}
	const int& GetPrice() const
	{
		return *pPrice;
	}
};

class Unit
{
private:
	int health;
	int defense;
	double xp;
public:
	Unit();
	virtual ~Unit();

	void Stats() const
	{
		cout << "Health: " << health << endl;
		cout << "Defense: " << defense << endl;
		cout << "XP: " << xp << endl;
	}

	virtual void Update();
	virtual void Render();
};

int* pt3;
int num;

static void Position(int x = 10, int y = 20, int z = 30)
{
	cout << "x: " << x << '\t' << "y: " << y << '\t' << "z: " << z << endl;
}

int main()
{
#pragma region 생성자 
	/*
	Unit marin;
	cout << "sizeof(marin): " << sizeof(marin) << endl;
	marin.Stats();
	Unit* medic = new Unit();
	medic->Stats();
	delete medic; 
	*/
#pragma endregion    
#pragma region 복사생성자
	/*
	Item it1;
	Item it2 = it1;

	it1.Information();
	it2.Information(); 
	*/
#pragma endregion 
#pragma region 얕은 복사 vs 깊은 복사 
	/*int tempNum;
	int* pt1 = new int(1000);
	int* pt2 = pt1;

	*pt2 = 2000;

	cout << "*pt1: " << *pt1 << endl;
	cout << "*pt2: " << *pt2 << endl;

	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;
	cout << "pt3: " << pt3 << endl;
	cout << "&num: " << &num << endl;
	cout << "&tempNum: " << &tempNum << endl; */

	/*Item item1;
	Item item2 = item1;
	item1.Information();
	item2.Information(); */
#pragma endregion 
#pragma region 기본매개변수
	/*Position();
	Position(1, 2, 3);
	Position(7000, 8000); */
#pragma endregion

}

Unit::Unit()
	: health{ 40 }, defense{ 0 }, xp{ 0.0 }
{
	cout << "Created Unit" << endl;
}
Unit::~Unit()
{
	cout << "Destroy Unit" << endl;
}
void Unit::Update()
{
}
void Unit::Render()
{
}
