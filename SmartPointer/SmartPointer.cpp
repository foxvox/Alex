#include <iostream>
#include <memory>  // 스마트 포인터를 사용하기 위한 헤더 

/* 
스마트 포인터 설명
std::unique_ptr 
하나의 스마트 포인터만 객체를 소유하고, 다른 포인터와 공유할 수 없습니다. 
객체 소멸 시 자동으로 메모리를 정리합니다. 
std::make_unique<T>()를 사용하여 간편하게 객체를 생성할 수 있습니다. 
std::shared_ptr 
여러 개의 스마트 포인터가 동일한 객체를 공유할 수 있습니다. 
객체를 참조하는 스마트 포인터가 마지막으로 해제될 때 메모리가 자동으로 반환됩니다. 
std::make_shared<T>()를 사용하여 객체를 생성하면 메모리 할당이 효율적입니다. 
std::weak_ptr 
std::shared_ptr과 함께 사용되며, 객체 소유권을 가지지 않는 참조 역할을 합니다. 
순환 참조(Circular Reference) 문제를 방지하는 데 유용합니다. 
이제 스마트 포인터를 활용하면 new와 delete를 직접 사용할 필요 없이 
안전하게 메모리를 관리할 수 있습니다. 
코드의 유지보수가 쉬워지고, 메모리 누수 걱정을 덜 수 있어요. 
*/

class Example {
public:
    Example() { std::cout << "Example 객체 생성!\n"; }
    ~Example() { std::cout << "Example 객체 소멸!\n"; }
    void show() { std::cout << "Hello from Example!\n"; }
};

/*
int main() {
    // unique_ptr 사용 - 하나의 포인터만 해당 객체를 소유
    std::unique_ptr<Example> uniqueEx = std::make_unique<Example>();
    uniqueEx->show();  // 객체 메서드 호출

    // shared_ptr 사용 - 여러 개의 포인터가 객체를 공유 가능
    std::shared_ptr<Example> sharedEx1 = std::make_shared<Example>();
    std::shared_ptr<Example> sharedEx2 = sharedEx1; // shared_ptr 복사 가능 

    sharedEx1->show(); 
    sharedEx2->show();  // 동일한 객체를 참조

    return 0;
}
*/