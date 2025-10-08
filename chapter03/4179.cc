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
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int row, col;
int board[1050][1050], fvis[1050][1050], jvis[1050][1050];
int minfire = INT_MAX;
int minj = INT_MAX;
vector<pair<int, int>> f, jh;
// -----------------------------------------------------------

void solution() {
    std::cin >> row >> col;
    for (int i = 0; i < row; i++) {
        string temp;
        std::cin >> temp;
        for (int j = 0; j < col; j++) {
            if (temp[j] == 'F') {
                board[i][j] = 2;  // 불은 2
                f.emplace_back(i, j);
            } else if (temp[j] == '#') {
                board[i][j] = 1;  // 벽은 1
            } else if (temp[j] == '.') {
                board[i][j] = 0;  // 통과 가능은 0
            } else if (temp[j] == 'J') {
                jh.emplace_back(i, j);
                board[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> q;
    for (auto& p : f) {
        q.emplace(p.Y, p.X);
        fvis[p.Y][p.X] = 1;
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + t.Y;
            int nx = dx[i] + t.X;
            if (ny < 0 || nx < 0 || ny >= row || nx >= col) {
                continue;
            }  // 벽이거나 이미 불길이 지나갔으나, 그 이전에 지나갔었던
               // 자리라면 최소값만 남김
            if (board[ny][nx] == 1 || fvis[ny][nx]) {
                continue;
            }

            fvis[ny][nx] = fvis[t.Y][t.X] + 1;
            q.emplace(ny, nx);
        }
    }

    queue<pair<int, int>> jq;
    jq.emplace(jh.front());  // j는 하나만 들어옴
    jvis[jh.front().Y][jh.front().X] = 1;
    if (jh.front().Y == 0 || jh.front().X == 0 || jh.front().Y == row - 1 ||
        jh.front().X == col - 1) {
        std::cout << 1;
        return;
    }
    while (!jq.empty()) {
        auto t = jq.front();
        jq.pop();
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + t.Y;
            int nx = dx[i] + t.X;
            if (ny < 0 || nx < 0 || ny >= row || nx >= col) {
                continue;
            }  // 이미 지나간 자리거나 벽 그리고 이미 불타고 있는 칸은 가지 못함
            if (board[ny][nx] == 1 || jvis[ny][nx] ||
                (fvis[ny][nx] && fvis[ny][nx] <= jvis[t.Y][t.X] + 1)) {
                continue;
            }
            jq.emplace(ny, nx);
            jvis[ny][nx] = jvis[t.Y][t.X] + 1;
            // 가장자리에 도착했다면
            if (ny == 0 || nx == 0 || ny == row - 1 || nx == col - 1) {
                // 해당 칸에 불보다 빨리 왔다면
                if (fvis[ny][nx] == 0 || fvis[ny][nx] > jvis[ny][nx]) {
                    minj = std::min(minj, jvis[ny][nx]);
                    std::cout << minj;
                    return;
                }
            }
        }
    }
    if (minj == INT_MAX) {
        std::cout << "IMPOSSIBLE";
    } else {
        std::cout << minj;
    }
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    while (t--) {
        solution();
    }

    return 0;
}