#include <iostream>
using namespace std;
class Arr {
private:
    int* arr;
    int size;
    
public:
    int& operator[] (int idx) {
        return arr[idx];
    }
    
    int operator[] (int idx) const {
        return arr[idx];
    }
    
    Arr(int s) {
        this -> size = s;
        
        arr = new int[s];
        
        // 배열 생성과 동시에 초기화
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }
    
    // 배열이 비었는 지 확인한다.
    bool isEmpty() {
        if (arr[0] == 0)
            return true;
        
        return false;
    }
    
    int at(int i) {
        if(arr[i] == 0)
            return 0;
        else
            return arr[i];
    }
    
    void set(int idx, int X) {
        if (arr[idx] == 0)
            cout << 0 << "\n";
        else {
            arr[idx] = X;
        }
    }
    
    void add(int idx, int X) {
        arr[idx] = X;
    }
    
    void remove(int idx) {
        if (arr[idx] == 0) {
            cout << 0 << "\n";
        } else {
            int* tmp = new int[this -> size];
            
            for (int i = 0; i < size; i++)
                tmp[i] = arr[i];
            
            cout << arr[idx] << "\n";
            
            for (int i = idx; i < size - 1; i++) {
                if (arr[i + 1] == 0) {
                    tmp[i] = 0;
                    break;
                }
                
                tmp[i] = arr[i + 1];
            }
            
            arr = tmp;
        }
    }
    
    void printArray() {
        if (isEmpty())
            cout << 0 << "\n";
        else {
            for (int i = 0; i < this -> size; i++) {
                if (arr[i] == 0)
                    break;
                
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
    
    ~Arr() {
        delete [] arr;
    }
};
