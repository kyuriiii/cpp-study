//
//  main.cpp
//  06-class,object
//
//  Created by 김규리 on 6/15/24.
//

#include <iostream>

class Rectangle {
    int width, height;
public:
    void set(int width, int height) {
        this->width = width;
        this->height = height;
    }
};

class MyClass {
public:
    static int staticVar;
};
int MyClass::staticVar = 0;

class GameCharacter {
public:
    static int gameScore;
    void addScore(int score){
        gameScore += score;
    }
};
int GameCharacter::gameScore = 0;

int main(){
    Rectangle rect;
    rect.set(10,20);
    
    std::cout << "staticVar : " << MyClass::staticVar << std::endl;
    
    GameCharacter character1, character2;
    character1.addScore(20);
    character2.addScore(50);
    
    std::cout << "Total Game Score : " << GameCharacter::gameScore << std::endl;
}
