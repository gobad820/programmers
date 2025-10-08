#include <bits/stdc++.h>
#define Y first
#define X second
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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j]-'0';
        }
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    vis[0][0] = 1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + t.Y;
            int nx = dx[i] + t.X;
            if (ny < 0 || nx < 0 || ny >= n || ny >= m) {
                continue;
            }
            if (!board[ny][nx] || vis[ny][nx]) {
                continue;
            }
            q.emplace(ny, nx);
            vis[ny][nx] = vis[t.Y][t.X] + 1;
        }
    }
    return vis[n - 1][m - 1];
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cout << solution();
    }

    return 0;
}