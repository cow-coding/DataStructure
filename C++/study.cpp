#include <iostream>
#include <cstdio> // c언어 활용 헤더
#include <string>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P; // x, y축을 저장함

char map[110][110]; // i, j -> i행, j열 => i : y, j : x
bool visit[110][110]; // i, j -> i행, j열 => i : y, j : x
int depth[110][110]; // i행 j열까지 오는데 사용되는 최소 칸 수
int N, M;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void BFS(int x, int y) { // 시작 칸의 좌표
    // 1. 그래프상의 연결관계 -> 다음 칸으로 갈 수 있는가?
    // 2. 다음 칸이 이미 탐색을 했는가? -> 지나온 곳인가?
    // 3. 주어진 전체 탐색영역을 벗어나지 않는 지를 확인
    // 3 > 1, 2
    queue<P> Q;
    visit[y][x] = true;
    Q.push(P(x, y)); // Pair(x, y) -> x:first, y:second

    while (!Q.empty()) {
        // 현재 탐색지점 값을 가져옴
        int currx = Q.front().first; // Pair(x, y) -> x:first, y:second
        int curry = Q.front().second; // Pair(x, y) -> x:first, y:second
        Q.pop();

        for (int i = 0; i < 4; i++) {
            // 다음 탐색 지점을 가져옴 -> 탐색 지점 아닐 수도 있음 : 범위를 벗어날 수도 있음(3을 위배할 수 있음)
            int nx = currx + dx[i];
            int ny = curry + dy[i];

            // 1. 그래프상의 연결관계 -> 다음 칸으로 갈 수 있는가?
            // 2. 다음 칸이 이미 탐색을 했는가? -> 지나온 곳인가?
            // 3. 주어진 전체 탐색영역을 벗어나지 않는 지를 확인
            // 3 > 1, 2
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                // 3번 조건 확인
                if (map[ny][nx] == '1' && !visit[ny][nx]) {
                    // 1, 2번 조건 확인
                    visit[ny][nx] = true;
                    Q.push(P(nx, ny));
                    depth[ny][nx] = depth[ny][nx] + 1;
                }
            }
        }
    }
}

int main() {
    string in;

    // cin >> N >> M;

    // map 생성 코드
    /*
     for (int i = 0; i < N; i++) {
        cin >> in;

        for (int j = 0; j < M; j++) {
            if (in[j] == '1') map[i][j] = '1';
            else map[i][j] = '0';
        }
    }
    */
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1s", &map[i][j]);

}
