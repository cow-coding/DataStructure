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
    int size;
    int summage;
    
public:
    SLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
        this->summage = 0;
    }
    
    // return empty
    bool empty() {
        return size == 0;
    }
    
    // print node data
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
    
    // add node at last
    void append(int data) {
        Node* newNode = new Node(data);
        
        if (empty()) {
            head = newNode;
            tail = newNode;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        
        size++;
        
        summage += data;
        
        print();
    }
    
    // delete node
    int Delete(int idx) {
        if (empty() || idx >= size) {
            return -1;
        }else {
            Node* curr = head;
            Node* prev = NULL;
            
            while (idx--) {
                prev = curr;
                curr = curr->next;
            }
            
            int ret = curr->data;
            
            prev->next = curr->next;
            
            summage -= ret;
            
            delete curr;
            return ret;
        }
    }
    
    // insert data
    void insert(int idx, int data) {
        Node* newNode = new Node(data);
        
        if (idx > size) {
            cout << "Index Error\n";
        }else {
            Node* curr = head;
            Node* prev = head;
            
            while (idx--) {
                prev = curr;
                curr = curr->next;
            }
            
            if (prev == curr) {
                // insert idx is 0
                newNode->next = curr;
                head = newNode;
            }else {
                // insert idx is not 0
                newNode->next = curr;
                prev->next = newNode;
            }
            
            print();
        }
    }
    
    // summage
    int sum() {
        if (empty()) {
            return 0;
        }else {
            return summage;
        }
    }
    
};

int main() {
    string cmd;
    SLinkedList sll;
    int M;
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        
        if (cmd == "Print") {
            sll.print();
        }else if (cmd == "Append") {
            int data;
            
            cin >> data;
            
            sll.append(data);
        }else if (cmd == "Delete") {
            int idx;
            
            cin >> idx;
            
            cout << sll.Delete(idx) << "\n";
        }else if (cmd == "Insert") {
            int idx;
            int data;
            
            cin >> idx >> data;
            
            sll.insert(idx, data);
        }else if (cmd == "Sum") {
            cout << sll.sum() << "\n";
        }
    }
}
