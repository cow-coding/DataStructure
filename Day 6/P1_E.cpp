#include <iostream>
using namespace std;

class ArrayQ {
public:
    int* q;
    int f;
    int r;
    int n;
    int s;
    
    ArrayQ(int size) {
        this->q = new int[size];
        this->s = size;
        this->n = 0;
        this->f = 0;
        this->r = -1;
    }
    
    int size() {
        return n;
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    void enqueue(int e) {
        if (size() == s) {
            cout << "Full\n";
        }else{
            n++;
            r++;
            q[r] = e;
        }
    }
    
    ~ArrayQ() {}
};

int main() {
    int s, n;
    string cmd;
    
    cin >> s >> n;
    
    ArrayQ q(s);
    
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        if (cmd == "enqueue") {
            int x;
            cin >> x;
            
            q.enqueue(x);
        }else if (cmd == "size") {
            cout << q.size() << "\n";
        }else if (cmd == "isEmpty") {
            cout << q.isEmpty() << "\n";
        }
    }
    
}
