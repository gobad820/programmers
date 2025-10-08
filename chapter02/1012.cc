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

vector<int> solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int t;
    std::cin >> t;
    vector<int> answer(t, 0);
    for (int tc = 0; tc < t; tc++) {
        int n, m, k;
        std::cin >> m >> n >> k;
        vector<vector<int>> board(n, vector<int>(m)), vis(n, vector<int>(m));
        int y, x;
        for (int i = 0; i < k; i++) {
            std::cin >> x >> y;
            board[y][x] = 1;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] && !vis[i][j]) {
                    vis[i][j] = 1;
                    answer[tc]++;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int ny = dy[i] + t.Y;
                            int nx = dx[i] + t.X;
                            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                                continue;
                            }
                            if (!board[ny][nx] || vis[ny][nx]) {
                                continue;
                            }
                            q.emplace(ny, nx);
                            vis[ny][nx] = 1;
                        }
                    }
                }
            }
        }
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}