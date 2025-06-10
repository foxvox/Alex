#include <iostream> 
using namespace std;

// 이번 static 멤버함수 과제는 singleton pattern 구현에 핵심적인 요소라서 
// 알아보게 한 게 아닌가 생각해서 singleton pattern 간단 예제를 살펴보려고 한다. 

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
