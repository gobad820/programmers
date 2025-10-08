#include <bits/stdc++.h>
#define Y first
#define X second
// 자주 사용하는 네임스페이스 및 타입 별칭
using std::deque;
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
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int row, col;
char board[330][330];
int vis[330][330];

// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> row >> col;
    int y1, x1, y2, x2;
    std::cin >> y1 >> x1 >> y2 >> x2;
    pair<int, int> j{y1 - 1, x1 - 1};
    pair<int, int> v{y2 - 1, x2 - 1};

    for (int i = 0; i < row; i++) {
        string str;
        std::cin >> str;
        for (int j = 0; j < col; j++) {
            board[i][j] = str[j];
        }
    }

    deque<pair<int, int>> q;
    q.emplace_front(j);
    vis[j.Y][j.X] = 1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + t.Y;
            int nx = dx[i] + t.X;
            if (ny < 0 || ny >= row || nx < 0 || nx >= col) {
                continue;
            }
            if (vis[ny][nx]) {  // 이미 파동이 지나간 곳
                continue;
            }

            if (board[ny][nx] == '0') {
                q.emplace_front(ny, nx);
                vis[ny][nx] = vis[t.Y][t.X];
            } else if (board[ny]
                            [nx]) {   // 사람이 있다면 연쇄 파동은 일어나지 않음
                board[ny][nx] = '0';  // 사람 쓰러짐
                q.emplace_back(ny, nx);
                vis[ny][nx] = vis[t.Y][t.X] + 1;
            }
            if (ny == v.Y && nx == v.X) {
                std::cout << vis[ny][nx] - 1;
                return;
            }
        }
    }
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