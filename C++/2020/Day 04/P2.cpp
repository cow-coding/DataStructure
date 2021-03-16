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

    bool empty() {
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
    int n;
    linkedStack s;
    string cmd;
    string operation;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int result = 0;

        cin >> operation;

        for (int j = 0; j < operation.size(); j++) {

            if (operation[j] >= '1' && operation[j] <= '9') {
                // operation에서 현재 읽은 문자가 숫자인 경우는 스택에 넣는다.
                s.push(operation[j]-'0');
            }else {
                // 현재 문자가 숫자가 아니라 연산자인 경우
                int tmp1 = s.pop(); // 뒤 숫자
                int tmp2 = s.pop(); // 앞 숫자

                switch (operation[j]) {
                    case '+':
                        result = tmp2 + tmp1;
                        s.push(result);
                        break;

                    case '-':
                        result = tmp2 - tmp1;
                        s.push(result);
                        break;

                    case '*':
                        result = tmp2 * tmp1;
                        s.push(result);
                        break;

                    default:
                        break;
                }
            }
        }

        cout << s.pop() << "\n";
    }

}
