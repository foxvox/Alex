#include <iostream> 
#include "Vehicle.h" 
#include "Scooter.h" 
#include "Boat.h" 
#include "Bicycle.h" 

using namespace std; 

class Monster
{
public:
	Monster() : health{ 0 }, defense{ 0 }
	{} 
	virtual ~Monster() {} 	
	int health;
	int defense; 

	virtual void ShowStats() const 
	{
		cout << "health: " << health << endl; 
		cout << "defense: " << defense << endl; 
	}
};
class Goblin : public Monster
{
public:
	Goblin() : Monster(), attack{ 30 } 
	{
		health = 100; 
		defense = 5; 
	} 
	virtual ~Goblin() {}  

	virtual void ShowStats() const override 
	{
		cout << "Goblin" << endl; 
		cout << "health: " << health << endl;
		cout << "defense: " << defense << endl; 
		cout << "attack: " << attack << endl; 
	}
private:
	int attack; 
};
class JuniorGolem : public Monster
{
public:
	JuniorGolem() : Monster(), attack{ 50 } 
	{
		health = 200;
		defense = 10;
	} 
	virtual ~JuniorGolem() {} 

	virtual void ShowStats() const override
	{
		cout << "JuniorGolem" << endl; 
		cout << "health: " << health << endl;
		cout << "defense: " << defense << endl;
		cout << "attack: " << attack << endl;
	}
private:
	int attack;
};
class Slime : public Monster
{
public:
	Slime() : Monster()  
	{
		health = 50;
		defense = 1;
	} 
	virtual ~Slime() {} 

	virtual void ShowStats() const override
	{
		cout << "Slime" << endl; 
		cout << "health: " << health << endl;
		cout << "defense: " << defense << endl;	
	}
};

int main()
{
#pragma region 상속 
	/*Monster* goblin = new Goblin(); 
	Monster* juniorGolem = new JuniorGolem();
	Monster* slime = new Slime(); 

	goblin->ShowStats(); 
	juniorGolem->ShowStats(); 
	slime->ShowStats(); */ 

	Vehicle		vehicle; 
	Scooter		scooter; 
	Boat		boat; 
	Bicycle		bicycle; 

	scooter.Move(); 
	boat.Move();
	bicycle.Move(); 

	cout << "sizeof(Scooter): " << sizeof(Scooter) << endl; 
	cout << "sizeof(Boat): " << sizeof(Boat) << endl; 
	cout << "sizeof(Bicycle): " << sizeof(Bicycle) << endl; 
#pragma endregion 
}