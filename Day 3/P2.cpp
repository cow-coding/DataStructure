#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {}
    Node(int x) {
        this->data = x;
        this->next = NULL;
    }
    ~Node(){}
};

class CLinkedList {
public:
    Node* head;
    Node* tail;

    CLinkedList() {
        head = NULL;
        tail = NULL;
    }

    bool empty() {
        if (head == NULL && tail == NULL)
            // head tail 모두 null이면 빔
            return true;
        else
            return false;
    }

    void add(int x) {
        Node* v = new Node(x);

        if (empty()) {
            head = tail = v;
            tail->next = head;
        }else {
            tail->next = v;
            tail = v;
            tail->next = head;
        }


    }

    void remove(int idx) {
        Node* curr = head;
        Node* tmp = new Node();

        while (idx--) {
            tmp = curr;
            curr = curr->next;
        }

        if (curr == head) {
            head = curr->next; // head 이동
            tail->next = head;
            delete curr;
        } else if (curr == tail) {
            tmp->next = curr->next;
            tail = tmp;
            delete curr;
        } else {
            tmp->next = curr->next;
            delete curr;
        }
    }

    void show() {

        for (Node* curr = head; ; curr = curr->next) {
            if (curr == tail) {
                cout << curr->data;
                break;
            }

            cout << curr->data << " ";
        }
        cout << "\n";
    }
};

int main() {
    int M;
    string cmd;


    cin >> M;

    for (int i = 0 ; i < M; i++) {
        CLinkedList cll;
        for (int i = 0; i < 10; i++) {
            int n;
            cin >> n;

            cll.add(n);
        }

        for (int i = 0; i < 3; i++) {
            int idx;
            cin >> cmd >> idx;
            cll.remove(idx);
        }

        cll.show();
    }
}
