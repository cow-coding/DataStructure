#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
    vector<int> v;
    int heap_size;
    int root_index;
    int direction;
    
public:
    Heap(int direction) {
        v.push_back(-1);
        this->heap_size = 0;
        this->root_index = 1;
        this->direction = direction;
    }
    
    void swap(int idx1, int idx2) {
        int tmp = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = tmp;
    }
    
    void upHeap(int idx) {
        if (direction == 1) {
            while (v[idx/2] > v[idx]) {
                swap(idx/2, idx);
                upHeap(idx/2);
            }
        }else {
            while (v[idx/2] < v[idx]) {
                swap(idx/2, idx);
                upHeap(idx/2);
            }
        }
    }
    
    void insert(int e) {
        v.push_back(e);
        heap_size++;
        
        upHeap(heap_size);
    }
    
    int top() {
        return v[root_index];
    }
    
    int size() {
        return heap_size;
    }
    
    bool empty() {
        return heap_size == 0;
    }
    
    void print() {
        if (empty()) {
            cout << -1 << "\n";
        }else{
            for (int i = 1; i < heap_size + 1; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    string cmd;
    Heap h(MIN);
    
    cin >> n;
    
    while (n--) {
        cin >> cmd;
        
        if (cmd == "insert") {
            int x;
            
            cin >> x;
            h.insert(x);
        }else if (cmd == "size") {
            cout << h.size() << "\n";
        }else if (cmd == "isEmpty") {
            cout << h.empty() << "\n";
        }else if (cmd == "print") {
            h.print();
        }
    }
}
