#include "Vector2D.h"

Vector2D::Vector2D() 
	: x{}, y{} 
{}

Vector2D::Vector2D(const float& _x, const float& _y)
{
	x = _x; 
	y = _y; 
}

Vector2D::~Vector2D() 
{}

const Vector2D& Vector2D::operator+(const Vector2D& rhs)
{
	return Vector2D(x + rhs.x, y + rhs.y); 
}

const Vector2D& Vector2D::operator-(const Vector2D& rhs)
{
	return Vector2D(x - rhs.x, y - rhs.y); 
}

const Vector2D& Vector2D::operator*(const Vector2D& rhs)
{
	return Vector2D(x * rhs.x, y * rhs.y); 
}

const Vector2D& Vector2D::operator/(const Vector2D& rhs)
{
	return Vector2D(x / rhs.x, y / rhs.y); 
} 

// ++ 전위연산자 
const Vector2D& Vector2D::operator++() 
{
    x++;
    y++;
    return *this;
}

// ++후위연산자 
const Vector2D& Vector2D::operator++(int) 
{
    Vector2D temp = *this; 
    x++;
    y++;
    return temp; 
}

const Vector2D& Vector2D::operator=(const Vector2D& rhs) 
{
    if (this != &rhs) 
    {
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
}

void Vector2D::Print() const
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
