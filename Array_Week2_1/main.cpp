#include <iostream>
#include <string>
#include "Arr.cpp"
using namespace std;

int main() {
    Array test(10000);
    string cmd;
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        if (cmd == "at") {
            int idx;
            
            cin >> idx;
            
            cout << test.at(idx) << "\n";
        } else if (cmd == "set") {
            int idx, x;
            
            cin >> idx >> x;
            
            test.set(idx, x);
        } else if (cmd == "add") {
            int idx, x;
            
            cin >> idx >> x;
            
            test.add(idx, x);
        } else if (cmd == "remove") {
            int idx;
            
            cin >> idx;
            
            test.remove(idx);
        } else if (cmd == "printArray") {
            test.printArray();
        }
    }
}
