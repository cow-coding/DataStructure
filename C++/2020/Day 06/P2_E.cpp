#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node() {}
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {}
};

class Linkedlist {
public:
    int n; // count of element
    int capacity; // size of queue
    Node* f;
    Node* r;
    
    Linkedlist() {
        this->n = 0;
        this->f = NULL;
        this->r = NULL;
    }
    
    Linkedlist(int n) {
        this->n = 0;
        this->capacity = n;
        this->f = NULL;
        this->r = NULL;
    }
    
    int isEmpty() {
        return n == 0;
    }
    
    int front() {
        if (isEmpty())
            return -1;
        else
            return f->data;
    }
    
    int rear() {
        if (isEmpty())
            return -1;
        else
            return r->data;
    }
    
    int size() {
        return n;
    }
    
    void enqueue(int e) {
        Node* v = new Node(e);
        
        if (n == capacity) {
            cout << "Full\n";
        }else {
            if (isEmpty()) {
                f = v;
                r = v;
            }else {
                r->next = v;
                r = v;
            }
            n++;
        }
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Empty\n";
        }else {
            Node* old = f;
            
            f = f->next;
            delete old;
            n--;
        }
    }
};

int main() {
    int t;
    
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        int score1 = 0;
        int score2 = 0;
        
        cin >> n;
        
        Linkedlist p1(n);
        Linkedlist p2(n);
        
        for (int j = 0; j < n; j++) {
            int card;
            
            cin >> card;
            p1.enqueue(card);
        }
        
        for (int j = 0; j < n; j++) {
            int card;
            
            cin >> card;
            p2.enqueue(card);
        }
        
        for (int j = 0; j < n; j++) {
            if (p1.front() > p2.front())
                score1++;
            else if (p1.front() < p2.front())
                score2++;
            
            p1.dequeue();
            p2.dequeue();
        }
        
        if (score1 > score2)
            cout << 1 << "\n";
        else if (score1 < score2)
            cout << 2 << "\n";
        else
            cout << 0 << "\n";
    }
}
