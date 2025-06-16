#pragma once 

#include <iostream> 

using namespace std; 

class Vector2D
{
private:
	float x; 
	float y; 
public:
	Vector2D(); 
	Vector2D(const float& x, const float& y); 
	virtual ~Vector2D();
public: 
	const Vector2D& operator+(const Vector2D& rhs); 
	const Vector2D& operator-(const Vector2D& rhs); 
	const Vector2D& operator*(const Vector2D& rhs); 
	const Vector2D& operator/(const Vector2D& rhs); 	
	const Vector2D& operator++(); 
	const Vector2D& operator++(int); 
	const Vector2D& operator=(const Vector2D& rhs);
public: 
	void SetX(float _x) { x = _x; } 
	void SetY(float _y) { y = _y; } 
	const float GetX() const { return x; } 
	const float GetY() const { return y; } 
	void Print() const;  
};

