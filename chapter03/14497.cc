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
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int row, col;
int board[330][330], vis[330][330];

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
            if (std::isdigit(str[j])) {
                board[i][j] = str[j] - '0';
            } else if (str[j] == '#') {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    int answer = 0;
    queue<pair<int, int>> q;
    q.emplace(j);
    vis[j.Y][j.X] = 1;
    while (true) {
        answer++;
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + t.Y;
                int nx = dx[i] + t.X;
                if (ny < 0 || ny >= row || nx < 0 || nx >= col) {
                    continue;
                }
                if (vis[ny][nx]) {  // 이미 파동이 지나간 곳
                    continue;
                }
                vis[ny][nx] = 1;
                if (ny == v.Y && nx == v.X) {
                    std::cout << answer;
                    return;
                }

                if (board[ny][nx]) {  // 사람이 있다면 연쇄 파동은 일어나지 않음
                    board[ny][nx] = 0;  // 사람 쓰러짐
                    nq.emplace(ny, nx);
                } else {
                    q.emplace(ny, nx);
                }
            }
        }
        q = nq;
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