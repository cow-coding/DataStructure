#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(){}
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    ~Node(){}
};

class SLinkedlist {
public:
    Node* head;
    Node* tail;

    SLinkedlist() {
        head=NULL;
        tail=NULL;
    }

    int front() {
        return head->data;
    }

    void addFront(int e) {
        Node* v = new Node(e);

        if (head == NULL) {
            head = tail = v;
        }else {
            v->next = head;
            head = v;
        }
    }

    int removeFront() {
        Node* v = head;
        head = head->next;

        return v->data;
    }
};

class linkedStack {
public:
    int n;
    SLinkedlist* sll;

    linkedStack() {
        this->sll = new SLinkedlist();
        this->n = 0;
    }

    int size() {
        return n;
    }

    bool emppry() {
        return n == 0;
    }

    int top() {
        if (n == 0)
            return -1;
        else return sll->front();
    }

    void push(int e) {
        sll->addFront(e);
        n++;
    }

    int pop() {
        if (n == 0) {
            return -1;
        }else {
            n--;
            return sll->removeFront();
        }
    }
};

int main() {
    int n, m;
    linkedStack s;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (cmd == "empty") {
            cout << s.emppry() << "\n";
        }else if (cmd == "top") {
            cout << s.top() << "\n";
        }else if (cmd == "push") {
            cin >> m;

            s.push(m);
        }else if (cmd == "pop") {
            cout << s.pop() << "\n";
        }else if (cmd == "size") {
            cout << s.size() << "\n";
        }
    }
}
