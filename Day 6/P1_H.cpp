#include <iostream>
#include <string>
using namespace std;

class Node {
private:
   Node* next;
   int elem;
public:
   Node(int e) :next{NULL}, elem{e}{}
   friend class LinkedList;
};

class LinkedList {
private:
   Node* head;
   Node* tail;
public:
   LinkedList() :head{NULL}, tail{NULL} {}
   void addBack(int e) {
      Node* newNode = new Node(e);
      if (empty()) {
         head = newNode;
         tail = newNode;
      }
      else {
         tail->next = newNode;
         tail = newNode;
      }
   }
   void removeFront() {
      if (!empty()) {
         Node* old = head;
         head = head->next;
         delete old;
      }
   }
   bool empty(){
      return head == NULL;
   }
   int front() {
      if (empty()) return -1;
      return head->elem;
   }
   int rear() {
      if (empty()) return -1;
      return tail->elem;
   }
};

class listQueue {
private:
   int f, r;
   int n = 0;
   int capacity;
   LinkedList list;
public:
   listQueue(int c) :f{NULL}, r{NULL}, capacity(c){}
   void enqueue(int e) {
      if (n == capacity) cout << "Full" << "\n";
      else {
         list.addBack(e);
         n++;
      }
   }
   void dequeue() {
      if (isEmpty()) cout << "Empty" << "\n";
      else {
         cout << list.front() << "\n";
         list.removeFront();
         n--;
      }
   }
   int size() { return n; }
   int isEmpty() {
      if (n) return 0;
      return 1;
   }
   void front() {
      if (isEmpty()) cout << "Empty" << "\n";
      else { cout << list.front() << "\n"; }
   }
   void rear() {
      if (isEmpty()) cout << "Empty" << "\n";
      else { cout << list.rear() << "\n"; }
   }
};

int main() {
    int s, n;
    string cmd;
    
    cin >> s >> n;
    
    listQueue q(s);
    
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        if (cmd == "enqueue") {
            int x;
            cin >> x;
            
            q.enqueue(x);
        }else if (cmd == "dequeue") {
            q.dequeue();
        }else if (cmd == "size") {
            cout << q.size() << "\n";
        }else if (cmd == "isEmpty") {
            cout << q.isEmpty() << "\n";
        }else if (cmd == "front") {
            q.front();
        }else if (cmd == "rear") {
            q.rear();
        }
    }
    
}
