#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 353333
#define NOITEM 0;
#define ISITEM 1;
#define AVAILABLE 2;

class cell {
public:
    int key;
    int value;
    int flag;
    
    cell() {
        key = -1;
        value = -1;
        flag = NOITEM;
    }
    
    ~cell() {}
};

cell HashArr[MAX];
int sz = 0;

int hashfunc(int idx) {
    return idx % MAX;
}

int hashfunc2(int idx) {
    return (17 - (idx % 17));
}

void tableInsertLinear(int key) {
    int probing = 1;
    
    while (HashArr[hashfunc(key + probing - 1)].flag) {
        probing++;
    }
    
    HashArr[hashfunc(key + probing - 1)].key = key;
    HashArr[hashfunc(key + probing - 1)].flag = ISITEM;
    sz++;
}

void tableSearchLinear(int key) {
    int probing = 1;
    bool exist = false;
    
    while (HashArr[hashfunc(key + probing - 1)].flag) {
        if (HashArr[hashfunc(key + probing - 1)].key == key) {
            exist = true;
            break;
        }
        
        if (probing > sz) break;
        
        probing++;
    }
    
    if (!exist) { cout << 0 << " "; }
    else { cout << 1 << " "; }
    
    cout << probing << "\n";
}

void tableDeleteLinear(int key) {
    int probing = 1;
    
    while (HashArr[hashfunc(key + probing - 1)].flag) {
        if (HashArr[hashfunc(key + probing - 1)].key == key) {
            HashArr[hashfunc(key + probing - 1)].flag = AVAILABLE;
            HashArr[hashfunc(key + probing - 1)].key = -1;
            break;
        }
        
        probing++;
    }
    
    if (HashArr[hashfunc(key + probing - 1)].flag == 0) { cout << 0 << " "; }
    else { cout << 1 << " "; }
    
    cout << probing << "\n";
    
    
}

void tableInsertDouble(int key) {
    int probing = 1;
    
    while (HashArr[hashfunc(key) + (probing - 1) * hashfunc2(key)].flag) {
        probing++;
    }
    
    HashArr[hashfunc(key) + (probing - 1) * hashfunc2(key)].key = key;
    HashArr[hashfunc(key) + (probing - 1) * hashfunc2(key)].flag = ISITEM;
    sz++;
}

void tableSearchDouble(int key) {
    int probing = 1;
    bool exist = false;
    
    while (HashArr[hashfunc(key) + (probing - 1) * hashfunc2(key)].flag) {
        if(HashArr[hashfunc(key) + (probing - 1) * hashfunc2(key)].key == key){
            exist = true;
            break;
        }
        
        if (probing > sz) break;
        
        probing++;
    }
    
    if (!exist) cout << 0 << " ";
    else cout << 1 << " ";
    
    cout << probing << "\n";
}

void tableClear() {
    for (int i = 0; i < MAX; i++) {
        if (HashArr[i].flag) {
            HashArr[i].key = -1;
            HashArr[i].flag = NOITEM;
            HashArr[i].value = -1;
            
            sz--;
        }
        
        if (sz == 0) break;
    }
}

int main() {
    int T;
    
    cin >> T;
    
    while (T--) {
        int N, M;
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            int num;
            
            cin >> num;
            
            tableInsertDouble(num);
        }
        
        cin >> M;
        
        for (int i = 0; i < M; i++) {
            int num;
            
            cin >> num;
            
            tableSearchDouble(num);
        }
        
        tableClear();
    }
}
