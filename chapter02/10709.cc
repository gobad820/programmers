#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::queue;
using std::string;
using std::vector;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
char board[150][150];
int vis[150][150], answer[150][150];
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string temp;
        std::cin >> temp;
        for (int j = 0; j < w; j++) {
            board[i][j] = temp[j];
        }
    }
    memset(answer, -1, sizeof(answer));

    for (int c = w - 1; c >= 0; c--) {
        for (int r = 0; r < h; r++) {
            if (board[r][c] == 'c' && !vis[r][c]) {
                queue<pair<int, int>> q;
                q.emplace(r, c);
                vis[r][c] = 1;
                answer[r][c] = 0;
                while (!q.empty()) {
                    auto t = q.front();
                    q.pop();
                    int ny = t.first;
                    int nx = t.second + 1;
                    if (nx < 0 || nx >= w) {
                        continue;
                    }
                    if (vis[ny][nx]) {
                        continue;
                    }
                    q.emplace(ny, nx);
                    vis[ny][nx] = 1;
                    answer[ny][nx] = answer[t.first][t.second] + 1;
                }
            }
        }
    }

    for(int i = 0 ; i < h;  i++){
        for(int j = 0 ; j < w ; j++){
            std::cout << answer[i][j] << " ";
        }std::cout << "\n";
    }
    return;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        solution();
    }

    return 0;
}