#include <iostream> 
#include "Paint.h" 
#include "Brush.h" 
#include "Pencil.h" 
#include "Vector2D.h" 

using namespace std; 

int main()
{
#pragma region 추상클래스 
	// 함수의 특정한 내용이 구현되어 있지 않고, 
	// 선언만 되어 있는 클래스입니다. 
	// 추상클래스는 객체를 생성할 수 없습니다. 

	// Paint* paint = new Paint; 오류발생 
	/*Paint* brush = new Brush;  
	Paint* pencil = new Pencil; 
	
	brush->Draw(); 
	pencil->Draw(); 

	delete brush; 
	delete pencil; */
#pragma endregion 
#pragma region 연산자오버로딩 
	Vector2D vec1(2, 3), vec2(5, 6), vec3(0, 0);
	vec3 = vec1 + vec2; 
	vec3.Print(); 
	vec3 = vec1 - vec2;
	vec3.Print();
	vec3 = vec1 * vec2; 
	vec3.Print();
	vec3 = vec1 / vec2; 
	vec3.Print(); 
	vec3 = vec1++; 
	vec3.Print(); 
	vec1.Print(); 
	++vec2; 
	vec2.Print(); 
#pragma endregion 	
}