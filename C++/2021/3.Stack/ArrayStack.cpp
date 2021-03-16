#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    int* stack;
    int stack_size;
    int capacity;
    int top_pointer;
    
public:
    
    ArrayStack(int capacity) {
        this->capacity = capacity;
        stack = new int[capacity];
        stack_size = 0;
        top_pointer = -1;
    }
    
    bool empty() {
        return top_pointer == -1;
    }
    
    void push(int x) {
        if (stack_size == capacity) {
            cout << "Full\n";
        }else {
            top_pointer++;
            stack[top_pointer] = x;
            stack_size++;
        }
    }
    
    int size() {
        return stack_size;
    }
    
    int pop() {
        if (top_pointer == -1) {
            return -1;
        }else {
            int ret = stack[top_pointer];
            top_pointer--;
            stack_size--;
            
            return ret;
        }
    }
    
    int top() {
        if (empty()) {
            return -1;
        }else {
            return stack[top_pointer];
        }
    }
};
