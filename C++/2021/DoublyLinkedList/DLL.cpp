#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node* prev;
    
public:
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    
    friend class DLinkedList;
};

class DLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    DLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    
    bool empty() {
        return size == 0;
    }
    
    void print() {
        if (empty()) {
            cout << "empty\n";
        }else {
            for (Node* curr = head; curr != NULL; curr = curr->next) {
                cout << curr->data << " ";
            }
            cout << "\n";
        }
    }
    
    void append(int data) {
        Node* newNode = new Node(data);
        
        if (empty()) {
            head = newNode;
            tail = newNode;
        }else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        
        size++;
        
        print();
    }
    
    int Delete(int idx) {
        if (empty() || idx >= size) {
            return -1;
        }else {
            Node* curr = head;
            
            while (idx--) {
                curr = curr->next;
            }
            
            int ret;
            
            if (curr == head) {
                ret = curr->data;
                head = curr->next;
            }else if (curr == tail) {
                ret = curr->data;
                tail = curr->prev;
            }else {
                ret = curr->data;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            
            size--;
            
            Node* temp = curr;
            
            delete temp;
            return ret;
        }
    }
    
    void print_reverse() {
        if (empty()) {
            cout << "empty\n";
        }else {
            for (Node* curr = tail; curr != NULL; curr = curr->prev) {
                cout << curr->data << " ";
            }
            
            cout << "\n";
        }
    }
    
    void max() {
        int ret = -987654321;
        
        if (empty()) {
            cout << "empty\n";
        }else{
            for (Node* curr = head; curr != NULL; curr = curr->next) {
                if (curr->data > ret) {
                    ret = curr->data;
                }
            }
            
            cout << ret << "\n";
        }
    }
};

int main() {
    string cmd;
    DLinkedList dll;
    int M;
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        
        if (cmd == "Print") {
            dll.print();
        }else if (cmd == "Append") {
            int data;
            
            cin >> data;
            
            dll.append(data);
        }else if (cmd == "Delete") {
            int idx;
            
            cin >> idx;
            
            cout << dll.Delete(idx) << "\n";
        }else if (cmd == "Print_reverse") {
            dll.print_reverse();
        }else if (cmd == "Max") {
            dll.max();
        }
    }
}
