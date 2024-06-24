//
//  mutex.cpp
//  08-thread
//
//  Created by 김규리 on 6/24/24.
//

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // 뮤텍스 객체 생성

void print_block(int n, char c) {
    mtx.lock(); // 뮤텍스 잠금
    for ( int i = 0; i < n; ++i ) {
        std::cout << c;
    } 
    std::cout << '\n';
    mtx.unlock(); // 뮤텍스 해제
}

int main() {
    std::thread th1(print_block, 50, '*');
    std::thread th2(print_block, 50, '$');

    th1.join();
    th2.join();
}