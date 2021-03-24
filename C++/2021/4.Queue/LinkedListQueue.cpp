#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    
public:
    Node(int data){
        this->data = data;
        next = NULL;
    }
    
    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    bool isEmpty() { return size == 0; }
    
    void addBack(int data){
        Node* newNode = new Node(data);
        
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        
        size++;
    }
    
    int removeFront() {
        if (isEmpty()) {
            return -1;
        }else {
            Node* delNode = head;
            int ret = delNode->data;
            
            head = head->next;
            
            size--;
            delete delNode;
            return ret;
        }
    }
    
    int front() {
        if (isEmpty()) {
            return -1;
        }else {
            return head->data;
        }
    }
    
    int rear() {
        if (isEmpty()) {
            return -1;
        }else {
            return tail->data;
        }
    }
};

class Queue {
private:
    LinkedList sll;
    int capacity;
    int size;
    
public:
    Queue(int c) {
        capacity = c;
        size = 0;
    }
    
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Full\n";
        }else {
            sll.addBack(x);
            size++;
        }
    }
    
    int getSize() { return size; }
    
    bool isEmpty() { return size == 0; }
    
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }else {
            return sll.removeFront();
        }
    }
    
    void front() {
        if (isEmpty()) {
            cout << "Empty\n";
        }else {
            cout << sll.front() << "\n";
        }
    }
    
    void rear() {
        if (isEmpty()) {
            cout << "Empty\n";
        }else {
            cout << sll.rear() << "\n";
        }
    }
};

int main() {
    int capacity;
    int N;
    string cmd;
    
    cin >> capacity >> N;
    
    Queue q(capacity);
    
    while (N--) {
        cin >> cmd;
        
        if (cmd == "enqueue") {
            int num;
            
            cin >> num;
            
            q.enqueue(num);
        }else if (cmd == "dequeue") {
            if (q.dequeue() == -1) {
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
