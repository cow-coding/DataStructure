#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
private:
    int* queue;
    int capacity;
    int size;
    int f;
    int r;
    
public:
    // full condition = (rear + 1) % capacity == front
    
    // circular array queue
    arrayQueue(int capacity) {
        this->capacity = capacity + 1;
        size = 0;
        queue = new int[capacity + 1];
        f = r =  0;
    }
    
    bool isEmpty() {
        return f == r;
    }
    
    bool isFull() {
        return (r + 1) % capacity == f;
    }
    
    void enqueue(int x) {
        if (isFull()) {
            cout << "Full\n";
        }else {
            r = (r + 1) % capacity;
            queue[r] = x;
            
            size++;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }else {
            f = (f + 1) % capacity;
            size--;
            
            return queue[f];
        }
    }
    
    int getSize() { return size; }
    
    void front() {
        if (isEmpty()) {
            cout << "Empty\n";
        }else {
            cout << queue[f + 1] << "\n";
        }
    }
    
    void rear() {
        if (isEmpty()) {
            cout << "Empty\n";
        }else {
            cout << queue[r] << "\n";
        }
    }
};

int main() {
    int capacity;
    int N;
    string cmd;
    
    cin >> capacity >> N;
    
    arrayQueue q(capacity);
    
    while (N--) {
        cin >> cmd;
        
        if (cmd == "enqueue") {
            int num;
            
            cin >> num;
            
            q.enqueue(num);
        }else if (cmd == "dequeue") {
            if (q.isEmpty()) {
                cout << "Empty\n";
            }else {
                cout << q.dequeue() << "\n";
            }
        }else if (cmd == "size") {
            cout << q.getSize() << "\n";
        }else if (cmd == "front") {
            q.front();
        }else if (cmd == "rear") {
            q.rear();
        }
    }
}
