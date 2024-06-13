//
//  main.cpp
//  01-basic
//
//  Created by 김규리 on 6/11/24.
//

#include <iostream>
#include <vector> // 2. Array + Vector
#include <list> // 3. List

using namespace std;


int isFour(int value){
    return value == 4;
}
int main() {
//    1. 함수 사용법
//    int a, b;
//    
//    std::cin >> a;
//    std::cin >> b;
//        
//    std::cout << add(a,b);
    
//    2. Array
    std::string city[5] = {"korea", "america","spain","france","italy"};
    for ( std::string txt : city ){
        std::cout << txt + "\n";
    }
//    포인터 : 메모리의 주소를 가진 변수로 *를 이용하여 선언 가능하다.
    int *p;
    int n= 10;
    p = &n;
    n = 20;
    *p = 30;
    std::cout << p << std::endl; // 00000000000 형태의 주소값
    std::cout << *p << std::endl; // *p는 주소값에 저장되어 있는 실제 값에 접근하는 방법
//    동적배열 : 포인터 변수와 new 키워드 사용 필요
    int n2;
    std::cout << "Insert Number : ";
    std::cin >> n2;
    
    int *arr = new int[n2];
    for ( int i = 0; i < n2; i++ ){
        arr[i] = i+1; // 동적 배열 사용
    }
    
    std::cout << "배열 출력" << std::endl;
    std::cout << arr << std::endl;//포인터 값 출력
    std::cout << *arr << std::endl;// 첫 번째 요소 출력
    delete[] arr; // 동적 배열 반납 ( 동적 메모리 사용 후 반납 )
    std::cout << arr << std::endl;
    std::cout << *arr << std::endl;// 댕글링 포인터 역참조 (정의되지 않은 동작
    std::cout << "배열 출력 완료1" << std::endl;
    /// Question1. 동적 배열을 반납하고 다시 arr을 출력해도 동일한 주소가 나온다. 반납하더라도 이전 주소를 확인 가능한 것인가? 아니면 반납이 제대로 이루어지지 않은 것인가?
    /// Answer. std::cout << *arr << std::endl;는 해제된 메모리를 역참조합니다. 이 경우 정의되지 않은 동작(UB, Undefined Behavior)이 발생합니다. 여기서는 우연히 0이 출력된 것입니다. 이는 다른 값이 나올 수도 있으며, 프로그램이 비정상적으로 종료될 수도 있습니다.


    // Vector : 자동으로 메모리를 할당해주는 배열 ( 포인터를 쓰지 않아도 크기를 추후 지정 가능 + 배열의 크기 변경 가능 )
    vector<int> v = {1,2,3,4,5};
    vector<int> v1(4);
    vector<int> v2(5,3);
    
    v.assign(5,10);
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }
    for(int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << endl;
    }
    
//    3. List
    std::list<int> myList = {5,4,3,2,1};
//    • remove() – 특정 값 삭제
//    • remove_if(함수) – 특정 함수의 조건에 맞는 값 삭제 • splice() – 리스트간 요소 이동
//    • merge() – 정렬된 리스트 병합
//    • unique() – 중복 요소 제거
//    • sort() - 정렬
}
