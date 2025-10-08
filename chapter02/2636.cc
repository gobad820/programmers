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
int n, m;
int board[120][120], vis[120][120];
int zero_board[120][120];
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> board[i][j];
        }
    }

    vector<pair<int, int>> boundary;
    int count = 0;
    while (true) {
        if (memcmp(zero_board, board, sizeof(board)) == 0) {
            break;
        }
        boundary.clear();
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vis[0][0] = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + t.Y;
                int nx = dx[i] + t.X;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    continue;
                }
                if (vis[ny][nx]) {
                    continue;
                }
                if (board[ny][nx] == 1) {  // 경계면, 비방문
                    boundary.emplace_back(ny, nx);
                    vis[ny][nx] = 1;
                    continue;
                }
                q.emplace(ny, nx);
                vis[ny][nx] = 1;
            }
        }
        for (const auto& item : boundary) {
            board[item.Y][item.X] = 0;
            std::cout << item.Y << " : " << item.X << "\n";
        }
        std::cout << "\n\n";
        count++;
    }
    std::cout << count << "\n" << boundary.size();
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