//
//  basic.cpp
//  08-thread
//
//  Created by 김규리 on 6/24/24.
//

#include <iostream>
#include <thread>

void function_1() {
    std::cout << "Function 1 has been called." << std::endl;
}
void function_2() {
    std::cout << "Function 2 has been called." << std::endl;
}

// int main() {
//     std::thread thread_1(function_1); // 첫 번째 스레드 생성
//     std::thread thread_2(function_2); // 두 번째 스레드 생성

//     thread_1.join(); // 첫 번째 스레드가 끝날 때까지 대기
//     thread_2.join(); // 두 번째 스레드가 끝날 때까지 대기
// }