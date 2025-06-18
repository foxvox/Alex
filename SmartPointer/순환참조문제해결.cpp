#include <iostream>
#include <memory> 

// std::weak_ptr을 사용하면 객체의 참조 카운트를 증가시키지 않으면서, 
// std::shared_ptr을 참조할 수 있습니다. 
// 이를 통해 순환 참조를 방지할 수 있습니다.

class B; 

class A {
public:
    std::weak_ptr<B> b_ptr;  // shared_ptr이 아니라 weak_ptr을 사용
    ~A() { std::cout << "A 객체 소멸!\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B 객체 소멸!\n"; }
};

/*
int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;  // weak_ptr을 사용하여 순환 참조 방지
    b->a_ptr = a;

    return 0;
}
*/