#include <iostream>
#include <memory> 

// std::shared_ptr을 사용하면 여러 개의 스마트 포인터가 하나의 객체를 공유할 수 있습니다. 
// 하지만 두 개의 객체가 서로를 std::shared_ptr로 참조하는 경우, 
// 참조 카운트가 0이 되지 않아 객체가 소멸되지 않는 문제가 발생할 수 있습니다. 

// 객체 a와 b가 서로를 std::shared_ptr로 참조하는 바람에, 
// 참조 카운트가 0이 되지 않아 
// 메모리에서 해제되지 않고 그대로 남아 있게 됩니다. 
// 즉, 메모리 누수가 발생합니다.

class B;  // 클래스 B를 미리 선언 

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A 객체 소멸!\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B 객체 소멸!\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;
    b->a_ptr = a;  

    return 0;
}
