#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {}
    Node(int e) {
        this->data = e;
        this->next = NULL;
    }
    ~Node(){}
};

class SLinkedList {
public:
    Node* head;
    Node* tail;

    SLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addFront(int X) {
        Node* v = new Node(X); // new Node

        if (head == NULL) {
            // list is empty
            head = tail = v;
        }else {
            v->next = head;
            head = v;
        }
    }

    int removeFront() {
        if (head == NULL) {
            return -1;
        }else{
            Node* tmp = head;
            int result = head->data;

            head = head->next;
            delete tmp;
            return result;
        }
    }

    int front() {
        if (head == NULL) {
            return -1;
        }else {
            return head->data;
        }
    }

    int empty() {
        if (head == NULL) {
            return 1;
        }else {
            return 0;
        }
    }

    void showList() {
        if (head == NULL) {
            cout << -1 << "\n";
        }else {
            for (Node* curr = head; curr != NULL; curr=curr->next) {
                // head부터 tail(next가 null)까지 반복이동
                cout << curr->data << " ";
            }
            cout << "\n";
        }
    }

    void addBack(int X) {
        Node* v = new Node(X);

        if (head == NULL) {
            head = tail = v;
        }else {
            tail->next = v;
            tail = v;
        }
    }

    ~SLinkedList() {}
};


int main() {
    int N;
    string cmd;
    SLinkedList sll;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "addFront") {
            int x;
            cin >> x;

            sll.addFront(x);
        }else if (cmd == "removeFront") {
            cout << sll.removeFront() << "\n";
        }else if (cmd == "front") {
            cout << sll.front() << "\n";
        }else if (cmd == "empty"){
            cout << sll.empty() << "\n";
        }else if (cmd == "showList") {
            sll.showList();
        }else if (cmd == "addBack") {
            int x;
            cin >> x;

            sll.addBack(x);
        }
    }
}
