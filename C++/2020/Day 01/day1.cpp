//
//  main.cpp
//  hello
//
//  Created by kibeom park on 2020/06/29.
//  Copyright © 2020 kibeom park. All rights reserved.
//

#include <iostream>
using namespace std;

void question2(int b) {
    b = b * 2;
}

void question1(int* a) {
    question2(*a);
}
int main() {
    int mainval(5);
    int* ptrMain = &mainval;
    
    question1(ptrMain);
    question2(mainval);
    
    cout << mainval << endl;
}
