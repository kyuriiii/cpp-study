//
//  main.cpp
//  07-virtual
//
//  Created by 김규리 on 6/24/24.
//

#include <iostream>
#include <stdio.h>

class A
{
    public:
    virtual void Print() {
        printf("A 클래스의 Print() 함수\n");
    }
};

class B: public A
{
    virtual void Print() {
        printf("B 클래스의 Print() 함수\n");
    }
};

int main() {
    printf("Main() 함수\n");

    A obj_a;
    B obj_b;

    A* ptr = &obj_a;
    ptr->Print(); // A클래스의 프린트 함수 호출

    A* ptr2 = &obj_b;
    ptr2->Print(); // B클래스의 프린트 함수 호출

    // 가상함수가 아닌 그냥 일반적인 멤버함수로 만들었다면 A의 프린트 함수 호출
    // => 컴파일러는 포인터가 가리키는 객체가 아닌 "포인터 변수의 자료형 기준"으로 결정하기 때문
    // 하지만 가상함수를 사용하면 "포인터가 가리키는 객체를 기준"으로 호출함수를 결정하기 때문에
    // B클래스의 프린트 함수가 호출되는 것이다.

}
