#include <iostream>
#include <string>
using namespace std;

class Array {
public:
    int n;
    int* arr;
    
    Array(int size) {
        this->n = 0;
        this->arr = new int[size];
        
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    
    int at(int idx) {
        if(arr[idx] == 0) {
            cout << 0 << "\n";
            return 0;
        }
        
        cout << arr[idx] << "\n";
        return arr[idx];
    }
    
    void set(int idx, int x) {
        if (arr[idx] != 0) {
            arr[idx] = x;
        } else {
            cout << 0 << "\n";
        }
    }
    
    void add(int idx, int num) {
            if (arr[idx] == 0) {
                arr[n] = num;
                n++;
                
            } else {
                for (int i = n; i > idx; i--) {
                    arr[i] = arr[i-1];
                }
                n++;
                arr[idx] = num;
            }
        
    }
    
    void remove(int idx) {
        if (arr[idx] == 0) {
            cout << 0 << "\n";
        }else {
            int tmp = arr[idx];
            for (int i = idx + 1; i < n; i++) {
                arr[i-1] = arr[i];
            }
            n--;
            arr[n] = 0;
            cout << tmp << "\n";
        }
    }
    
    void printArray() {
        if (n == 0) {
            cout << 0 << "\n";
        }else {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int m, n;
     int idx;
    string cmd;
    Array arr(10010);
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> cmd;
        
        if (cmd == "at") {
            cin >> n;
            arr.at(n);
        }else if(cmd == "set") {
            cin >> idx >> n;
            arr.set(idx, n);
        }else if (cmd == "add") {
            cin >> idx >> n;
            arr.add(idx, n);
        }else if(cmd == "remove") {
            cin >> idx;
            arr.remove(idx);
        }else if(cmd == "printArray") {
            arr.printArray();
        }
    }
}
