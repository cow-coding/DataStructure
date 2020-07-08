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
        bool isExist = true;
        
        for (int i = 0; i < this->node_list.size(); i++) {
            if (node_list[i]->data == parenet_data) {
                // 찾는 부모 노드 발견시
                Node* v = new Node(data);
                
                node_list.push_back(v);
                node_list[i]->insertChild(v);
                v->parent = node_list[i];
                
                isExist = false;
                break;
            }
        }
        
        if (isExist) {
            cout << -1 << "\n";
        }
    }
    
    void printChild(int data) {
        bool isExist = true;
        
        for (int i = 0; i < this->node_list.size(); i++) {
            if (node_list[i]->data == data) {
                int s = node_list[i]->children.size();
                
                if (s == 0) {
                    cout << 0 << "\n";
                }else {
                    for (int j = 0; j < s; j++) {
                        cout << node_list[i]->children[j]->data << " ";
                    }
                    cout << "\n";
                }
                
                isExist = false;
                break;
            }
        }
        
        if (isExist) {
            cout << -1 << "\n";
        }
    }
    
    int countdepth(int data) {
        int d = 0; // return value;
        bool isExist = true;
        
        for (int i = 0; i < node_list.size(); i++) {
            if (node_list[i]->data == data) {
                isExist = false;
                // depth 계산 시작 노드 탐색 완료 거꾸로 올라간다
                
                for (Node* curr = node_list[i]; curr->parent != NULL; curr = curr->parent) {
                    d++;
                }
            }
        }
        
        
        if(isExist)
            return -1;
        
        return d;
    }
    
    void preorder(Node* node) {
        cout << node->data << " ";
        
        if (node->children.size() != 0) {
            for (int i = 0; i < node->children.size(); i++) {
                preorder(node->children[i]);
            }
        }
    }
    
    void postorder(Node* node) {
        if (node->children.size() != 0) {
            for (int i = 0; i < node->children.size(); i++) {
                postorder(node->children[i]);
            }
        }
        
        cout << node->data << " ";
    }
    
    /*
    void delNode(int data) {
        
    }
    
    Node* findNode(int data) {
    
    }
    */
};

int main() {
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int n;
        
        cin >> n;
        
        Tree T;
        
        T.setRoot(1);
        
        for (int j = 0; j < n; j++) {
            int p, c;
            
            cin >> p >> c;
            T.insertNode(p, c);
        }
        
        T.preorder(T.getRoot());
        cout << "\n";
        T.postorder(T.getRoot());
        cout << "\n";
    }
}
