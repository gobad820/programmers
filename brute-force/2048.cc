#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
constexpr int LIMIT = 5;
vector<int> v;
int board[30][30], t_board[30][30];
bool vis[30][30];
int answer = 0, n;

// 이동
void moveNumbers(int board[30][30], int dir) {
    if (dir == 0) {  // 상으로 움직임
        int bsize = n;
        for (int r = 1; r < bsize; ++r) {
            // 최 상단이 아닌 행
            for (int c = 0; c < bsize; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                int t = 1;
                while (r - t >= 0 &&
                       !board[r - t][c]) {  // 칸이 비지 않을 때 까지 이동
                    t++;
                }
                int temp = board[r][c];
                board[r][c] = 0;
                if (board[r - t][c] == temp && !vis[r - t][c]) {
                    board[r - t][c] *= 2;
                    vis[r - t][c] = true;
                    continue;
                }
                board[r - t + 1][c] = temp;
            }
        }
    } else if (dir == 1) {
        // 하로 이동
        for (int r = n - 2; r >= 0; --r) {
            // 최 상단이 아닌 행
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                int t = 1;
                while (r + t < n &&
                       !board[r + t][c]) {  // 칸이 비지 않을 때 까지 이동
                    t++;
                }
                int temp = board[r][c];
                board[r][c] = 0;
                if (board[r + t][c] == temp && !vis[r + t][c]) {
                    board[r + t][c] *= 2;
                    vis[r + t][c] = true;
                    continue;
                }
                board[r + t - 1][c] = temp;
            }
        }

    } else if (dir == 2) {
        // 좌로 이동
        for (int c = 1; c < n; c++) {
            for (int r = 0; r < n; r++) {
                if (board[r][c] == 0) {
                    continue;
                }
                int t = 1;
                while (c - t >= 0 && !board[r][c - t]) {
                    t++;
                }
                int temp = board[r][c];
                board[r][c] = 0;
                if (board[r][c - t] == temp && !vis[r][c - t]) {
                    board[r][c - t] *= 2;
                    vis[r][c - t] = true;
                    continue;
                }
                board[r][c - t + 1] = temp;
            }
        }

    } else if (dir == 3) {
        // 우로 이동
        for (int c = n - 2; c >= 0; c--) {
            for (int r = 0; r < n; r++) {
                if (board[r][c] == 0) {
                    continue;
                }
                int t = 1;
                while (c + t < n && !board[r][c + t]) {
                    t++;
                }
                int temp = board[r][c];
                board[r][c] = 0;
                if (board[r][c + t] == temp && !vis[r][c + t]) {
                    board[r][c + t] *= 2;
                    vis[r][c + t] = true;
                    continue;
                }
                board[r][c + t - 1] = temp;
            }
        }
    }
}

// 보드 탐색
int getMaximumNum() {
    int result = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            result = std::max(result, t_board[r][c]);
        }
    }
    return result;
}

// 완전 탐색을 이용
void dfs(int depth) {
    if (depth >= LIMIT) {  // 5번 모두 이동 시
        // 순서대로 모두 이동
        std::memcpy(t_board, board, sizeof(board));
        for (const int& item : v) {
            std::memset(vis, 0, sizeof(vis));
            moveNumbers(t_board, item);
        }
        // 보드의 최대값 탐색
        answer = std::max(answer, getMaximumNum());
        return;
    }

    for (int i = 0; i < 4; i++) {  // 상하좌우
        v.emplace_back(i);         // 이동 시킴?
        dfs(depth + 1);            // 다음 단계 진입
        v.pop_back();
    }
    return;
}

void getInput() {
    std::cin >> n;
    int t;
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            std::cin >> t;
            board[i][j] = t;
        }
    }
}
// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    getInput();
    dfs(0);
    return answer;
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