#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    
public:
    Node() {
        this->data = NULL;
        this->next = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    
    friend class SLinkedList;
};

class SLinkedList {
private:
    Node* head;
    Node* tail;
    int list_size;
    
public:
    SLinkedList() {
        head = NULL;
        tail = NULL;
        list_size = 0;
    }
    
    bool empty() {
        return list_size == 0;
    }

    void AddFront(int data) {
        Node* newNode = new Node(data);
        
        if (empty()) {
            head = newNode;
            tail = newNode;
        }else {
            newNode->next = head;
            head = newNode;
        }
        
        list_size++;
    }
    
    int deleteFront() {
        if (empty()) {
            return -1;
        }else {
            Node* delNode = head;
            int ret = delNode->data;
            
            head = head->next;
            
            delete delNode;
            return ret;
        }
    }
    
    int back() {
        return tail->data;
    }
    
    int front() {
        return head->data;
    }
    
    friend class Stack;
};

class Stack {
private:
    SLinkedList stack_list;
    int stack_size;
    
public:
    Stack() {
        stack_size = 0;
    }
    
    bool empty() {
        return stack_size == 0;
    }
    
    int top() {
        if (empty()) {
            return -1;
        }else {
            return stack_list.front();
        }
    }
    
    void push(int X) {
        stack_list.AddFront(X);
        
        stack_size++;
    }
    
    int size() {
        return stack_size;
    }
    
    int pop() {
        if (empty()) {
            return -1;
        }else {
            stack_size--;
            return stack_list.deleteFront();
        }
    }
};

int main() {
    int N;
    Stack stack;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string cmd;
        
        cin >> cmd;
        
        if (cmd == "empty") {
            cout << stack.empty() << "\n";
        }else if (cmd == "top") {
            cout << stack.top() << "\n";
        }else if (cmd == "push") {
            int number;
            
            cin >> number;
            
            stack.push(number);
        }else if (cmd == "pop") {
            cout << stack.pop() << "\n";
        }else if (cmd == "size") {
            cout << stack.size() << "\n";
        }
    }
}
