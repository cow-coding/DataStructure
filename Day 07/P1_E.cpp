#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
private:
    int data;
    Node* parent;
    vector<Node*> children;
    
public:
    Node() {
        this->data = NULL;
        this->parent = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->parent = NULL;
    }
    
    ~Node() {}
    
    void insertChild(Node* chi) {
        this->children.push_back(chi);
        return;
    }
    
    void delChilde(Node* chi) {
        for (int i = 0; i < this->children.size(); i++) {
            if (this->children[i] == chi) {
                this->children.erase(this->children.begin() + i);
                break;
            }
        }
        return;
    }
    
    friend class Tree;
};

class Tree {
private:
    Node* root;
    vector<Node*> node_list;
    
public:
    Tree() {
        root = NULL;
    }
    
    Tree(int data) {
        root = new Node(data);
        node_list.push_back(root);
    }
    
    ~Tree() {}
    
    void setRoot(int data) {
        root = new Node(data);
        node_list.push_back(root);
    }
    
    Node* getRoot() {
        return root;
    }
    
    void insertNode(int parenet_data, int data) {
        for (int i = 0; i < this->node_list.size(); i++) {
            if (node_list[i]->data == parenet_data) {
                // 찾는 부모 노드 발견시
                Node* v = new Node(data);
                
                node_list.push_back(v);
                node_list[i]->insertChild(v);
                v->parent = node_list[i];
                break;
            }
        }
    }
    
    void printChild(int data) {
        for (int i = 0; i < this->node_list.size(); i++) {
            if (node_list[i]->data == data) {
                int s = node_list[i]->children.size();
                
                for (int j = 0; j < s; j++) {
                    cout << node_list[i]->children[j]->data << " ";
                }
                cout << "\n";
                break;
            }
        }
    }
    
    /*
    void delNode(int data) {
        
    }
    
    Node* findNode(int data) {
    
    }
     
    int countdepth(int data) {
         int d = 0; // return value;
         
         for (int i = 0; i < node_list.size(); i++) {
             if (node_list[i]->data == data) {
                 // depth 계산 시작 노드 탐색 완료 거꾸로 올라간다
                 
                 for (Node* curr = node_list[i]; curr != NULL; curr = curr->parent) {
                     d++;
                 }
             }
         }
         
         return d;
     }
    
    void preorder(Node* node) {
        
    }
    
    void postorder(Node* node) {
        
    }
     */
};

int main() {
    int n;
    int p,c;
    
    Tree T;
    
    T.setRoot(1);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string cmd;
        
        cin >> cmd;
        
        if (cmd == "insert") {
            cin >> p >> c;
            
            T.insertNode(p, c);
        }else if (cmd == "printChild") {
            cin >> p;
            T.printChild(p);
        }
    }
}
