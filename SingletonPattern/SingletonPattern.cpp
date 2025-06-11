#include <iostream> 
using namespace std; 

// 이번 static 멤버함수 과제는 singleton pattern 구현에 핵심적인 요소라서 
// 알아보게 한 게 아닌가 생각해서 singleton pattern 간단 예제를 살펴보려고 한다. 

// 1. 객체가 아니라 클래스 차원에서 호출

// 2. 정적 멤버 함수는 객체가 아니라 클래스 자체에 속합니다. 
// 즉, 특정 인스턴스를 생성하지 않고도 ClassName::FunctionName() 형태로 호출할 수 있습니다. 

// 3. 정적 멤버 변수만 접근 가능
// 정적 멤버 함수 내부에서는 비정적 멤버 변수나 멤버 함수에 접근할 수 없습니다. 
// 왜냐하면 인스턴스와 관련이 없기 때문이죠. 
// 대신, 정적 멤버 변수나 다른 정적 멤버 함수는 자유롭게 사용할 수 있습니다. 

// 4. 공용 유틸리티 역할 수행 
// 특정한 객체 없이 호출되므로 보통 클래스의 공통적인 기능 
// (예: 수학적 계산, 설정 관리, 팩토리 메서드)을 구현하는 데 사용됩니다.

// 5. 다형성(Polymorphism) 적용 불가 
// 정적 멤버 함수는 가상 함수(virtual function)가 될 수 없으며, 
// 상속 관계에서 오버라이딩(Overriding)이 불가능합니다. 

// 6. 클래스 외부에서도 독립적으로 사용 가능 
// 인스턴스 없이 사용 가능하기 때문에 특정 객체를 만들 필요 없는 기능을 정의하는 데 적합합니다.

class Singleton
{
private:
    static Singleton* instance;
    Singleton() {} // private 생성자로 외부에서 객체 생성 방지

public:
    static Singleton* GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }

    void ShowMessage()
    {
        cout << "Singleton instance created!" << endl;
    }
};

// 정적 멤버 변수 초기화
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton* singleton = Singleton::GetInstance();
    singleton->ShowMessage();

    return 0;
}
