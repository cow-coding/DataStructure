#include <iostream>
#include <string>
#include <cmath>
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
    
    bool empty() {
        return n == 0;
    }
    
    int at(int idx) {
        return arr[idx];
    }
    
    void set(int idx, int x) {
        arr[idx] = x;
        n++;
    }
    
    void printArray() {
        if (empty()) {
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
    int m, n, x;
    
    
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> n;
        Array arr(n);
        int ksum = 0, jpsum = 0, chsum = 0;
        int k = 0, jp = 0, ch = 0;
        int ka = 0, ja = 0, ca = 0;
        
        for (int j = 0; j < n; j++) {
            cin >> x;
            
            arr.set(j, x);
        }
        
        for (int i = 0; i < n; i++) {
            if (i % 3 == 0) {
                ksum += arr.at(i);
                
                if (arr.at(i) != 0) k++;
            }else if (i % 3 ==1) {
                jpsum += arr.at(i);
                
                if (arr.at(i) != 0) jp++;
            }else {
                chsum += arr.at(i);
                
                if (arr.at(i) != 0) ch++;
            }
        }
        if (k != 0)
            ka = floor(ksum/k);
        
        if (jp != 0)
            ja = floor(jpsum/jp);
        
        if (ch != 0)
            ca = floor(chsum/ch);
        
            
        
        cout << ksum << " " << jpsum << " " << chsum << "\n";
        cout << ka << " " << ja << " " << ca << "\n";
    }
    
    
    
}
