//
//  main.cpp
//  04-pointer
//
//  Created by 김규리 on 6/13/24.
//

#include <iostream>
#include <format>

int main(int argc, const char * argv[]) {
    // & : 주소 연산자 ( = 번지 연산자 )
    // * : 참조 연산자
    int n = 100; // 변수의 선언
    int* ptr = &n; // 포인트 선언 

    // 잘못된 예제
    // int* ptr1, ptr2;
    // 올바른 예제
    int* ptr1, * ptr2;

    ////// 포인터 배열
    // 포인터 배열 : 포인터의 배열을 의미한다.
    int a = 10;
    int b = 20;
    int c = 30;

    int *ptr_array[3] = {&a, &b, &c};

    std::cout << std::format("Size of an int in C++ : {}", sizeof(int)) << std::endl; // Formatting library of C++20
    for ( int i = 0; i < 3; i++) {
        std::cout << "addr : " << ptr_array[i] << " value : " << *ptr_array[i] << std::endl;
    }

    ////// 배열 포인터
    // 배열 포인터 : 배열을 가리키는 포인터
    int arr[3] = {10,20,30};
    int (*arr_ptr)[3] = &arr;
    
    // 배열 포인터를 통해서 각 배열에 접근하는 방법 1)
    for ( int i = 0; i < 3; i++ ){
        std::cout << *(*arr_ptr+1) << std::endl;
    }
    
    // 배열 포인터를 통해서 각 배열에 접근하는 방법 2)
    for ( int i = 0; i < 3; i++ ){
        std::cout << (*arr_ptr)[i] << std::endl;
    }
}
