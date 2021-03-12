#include <iostream>
#include <string>
using namespace std;

class Array {
public:
    int n;
    int* arr;

    Array(int size) {
        this->n = 0;
        this->arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    int at(int idx) {
        if(arr[idx] == 0) {
            cout << 0 << "\n";
            return 0;
        }

        cout << arr[idx] << "\n";
        return arr[idx];
    }

    void set(int idx, int x) {
        if (arr[idx] != 0) {
            arr[idx] = x;
        } else {
            cout << 0 << "\n";
        }
    }

    void add(int idx, int num) {
        if (arr[idx] == 0) {
            arr[n] = num;
            n++;

        } else {
            for (int i = n; i > idx; i--) {
                arr[i] = arr[i-1];
            }
            n++;
            arr[idx] = num;
        }
    }
};


int main() {
    int m, n;
    string cmd;
    Array arr(10010);

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> cmd;

        if (cmd == "at") {
            cin >> n;
            arr.at(n);
        }else if(cmd == "set") {
            int idx;

            cin >> idx >> n;
            arr.set(idx, n);
        }else if (cmd == "add") {
            int idx;

            cin >> idx >> n;
            arr.add(idx, n);
        }
    }
}
