#include <iostream>
using namespace std;

class Array {
private:
    int* arr; // 동적할당을 구현할 본체 포인터 입니다.
    int size; // 전체 배열의 크기를 받아 올 변수입니다.

public:
    Array(int s) {
        this -> size = s;
        
        arr = new int[size];

        for(int i = 0; i < size; i++)
            arr[i] = 0;
    }

    int at(int i) {
        if(arr[i] == 0)
            return 0;
        else
            return arr[i];
    }

    void set(int i, int X) {
        if(arr[i] == 0)
            cout << 0 << "\n";
        else
            arr[i] = X;
    }

    bool isEmpty() {
        if(arr[0] == 0)
            return true;
        else
            return false;
    }

    void printArray() {
        if(isEmpty())
            cout << 0 << "\n";
        else {
            for(int i = 0; i < this -> size; i++) {
                if(arr[i] == 0)
                     break;
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}
