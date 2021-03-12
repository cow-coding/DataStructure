#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* parent;
    Node* right;
    Node* left;
    int d = 0;
    int tmp = 0;
    
    Node() {
        this->data = NULL;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    
    ~Node() {}
    
    void insertLeft(Node* left) {
        this->left = left;
        left->parent = this;
    }
    
    void insertRight(Node* right) {
        this->right = right;
        right->parent = this;
    }
    
    int printDegree() {
        int c = 0;
        
        if (this->left != NULL) {
            c++;
            if (this->right != NULL) {
                c++;
                
                return c;
            }
            
            return c;
        }else{
            if(this->right != NULL) {
                c++;
                
                return c;
            }
            
            return c;
        }
        
        return c;
    }
    
    int depth() {
        if (parent == NULL) {
            return 0;
        }
        
        return parent->depth() + 1;
    }
    
    void printDepth() {
        cout << depth();
    }
};

class BST {
public:
    Node* root;
    int height = 0;
    int tmp = 0;
    
    BST() {
        root = NULL;
        height = 0;
    }
    
    ~BST() {
        this->treeDestructor(this->root);
    }
    
    void insertNode(int data) {
        int height = 0;
        
        if (root == NULL) {
            Node* v = new Node(data);
            
            root = v;
        }else{
            Node* temp = root;
            Node* v = new Node(data);
            bool right = false;
            
            while (1) {
                height++;
                if (temp->data < data) {
                    right = true;
                    if (temp->right == NULL)
                        break;
                    
                    temp = temp->right;
                }else {
                    right = false;
                    if (temp->left == NULL)
                        break;
                    
                    temp = temp->left;
                }
            }
            
            if(right)
                temp->insertRight(v);
            else
                temp->insertLeft(v);
                
        }
        
        if (height > this->height) {
            this->height = height;
        }
    }
    
    Node* findNode(int data) {
        Node* tmp = root;
        
        while (tmp != NULL) {
            if (tmp->data == data) {
                return tmp;
            }else {
                if (tmp->data < data) {
                    tmp = tmp->right;
                }else{
                    tmp = tmp->left;
                }
            }
        }
        return NULL;
    }
    
    void printHeight() {
        cout << height;
    }
    
    void deleteNode(int data) {
        Node* tmp = findNode(data); // 삭제를 위한 노드 찾기
        
        if (tmp->left == NULL) {
            transplant(tmp, tmp->right);
        }else if (tmp->right == NULL) {
            transplant(tmp, tmp->left);
        }else {
            Node* min = findMinimum(tmp); // tmp 기준 right의 가장 left
            
            if (min->parent != tmp) {
                transplant(min, min->right);
                min->right = tmp->right;
                min->right->parent = min;
            }
            
            transplant(tmp, min);
            min->left = tmp->left;
            min->left->parent = min;
        }
    }
    
    void transplant(Node* u, Node* v) {
        if (u->parent == NULL) {
            this->root = v;
        }else if (u == u->parent->left) {
            u->parent->left = v;
        }else {
            u->parent->right = v;
        }
        
        if (v != NULL)
            v->parent = u->parent;
    }
    
    Node* findMinimum(Node* node) {
        Node* tmp = node;
        
        tmp = tmp->right;
        
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
        
        return tmp;
    }
    
    void printPreorderTraversal(Node* root) {
        cout << root->data << " ";
        
        if (root->left != NULL) {
            printPreorderTraversal(root->left);
        }
        
        if (root->right != NULL) {
            printPreorderTraversal(root->right);
        }
    }
    
    void treeDestructor(Node* root) {
        if (root == NULL)
            return;
        
        if (root->left != NULL)
            this->treeDestructor(root->left);
        if (root->right != NULL)
            this->treeDestructor(root->right);
        
        delete root;
    }
};

int main() {
    int T;
    
    cin >> T;
    while (T--) {
        BST bst;
        
        int N;
        
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            
            bst.insertNode(n);
        }
        
        bst.printHeight();
        cout << "\n";
    }
}
