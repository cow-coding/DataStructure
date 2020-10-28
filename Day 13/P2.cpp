#include <iostream>
#include <vector>
#include <string>
using namespace std;

int map[2000][2000] = {0, };
bool visit[2000][2000];
bool node[2000] = {false, };
vector<string> word;

int main() {
    int N, M, K;
    string w;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        node[num - 1] = true;
    }

    int count = 1;

    for (int i = 1; i <= M; i++) {
        int start, end;

        cin >> start >> end >> w;

        if (!node[start - 1] || !node[end - 1]) {
            cout << -1 << "\n";
            continue;
        }

        if (visit[start - 1][end - 1] || visit[end - 1][start - 1]) {
            cout << -1 << "\n";
            continue;
        }

        visit[start - 1][end - 1] = true;
        visit[end - 1][start - 1] = true;
        map[start - 1][end - 1] = count;
        map[end - 1][start - 1] = count;
        count++;
        word.push_back(w);
    }

    int cnt = 0;

    for (int i = 0; i < 2000; i++) {
        for (int j = i + 1; j < 2000; j++) {
            if (visit[i][j]) cnt++;
            else continue;
        }
    }

    cout << N << " " << cnt << "\n";

    for (int i = 0; i < K; i++) {
        int numNode;

        cin >> numNode;

        if (!node[numNode - 1]) {
            cout << -1 << "\n";
            continue;
        }

        for (int j = 0; j < 2000; j++) {
            if (map[numNode - 1][j]) {
                // node delete
                word[map[numNode - 1][j] - 1] = "-1";
                map[numNode - 1][j] = 0;
                map[j][numNode - 1] = 0;
                cnt--;
                node[numNode - 1] = false;
            }
        }

        cout << cnt << " ";

        for (int j = 0; j < word.size(); j++) {
            if (word[j] == "-1") continue;
            cout << word[j] << " ";
        }
        cout << "\n";
    }
}
