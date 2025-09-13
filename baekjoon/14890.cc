#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, l, board[120][120], slope[120][120];
bool row_vis[120], col_vis[120];
int answer = 0;

void getInput() {
    std::cin >> n >> l;
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }
}

bool canUpSlope(vector<bool>& used, vector<int>& line, int col) {
    if (col - l + 1 < 0) return false;

    // col부터 col-l+1까지 L개 칸 체크
    for (int i = col; i > col - l; i--) {
        if (line[i] != line[col] || used[i]) return false;
    }

    // 경사로 설치
    for (int i = col; i > col - l; i--) {
        used[i] = true;
    }
    return true;
}

bool canDownSlope(vector<bool>& used, vector<int>& line, int col) {
    if (col + l >= n) return false;  // 배열 범위 체크

    // col+1부터 col+l까지 L개 칸 체크
    for (int i = col + 1; i <= col + l; i++) {
        if (line[i] != line[col + 1] || used[i]) return false;
    }

    // 경사로 설치
    for (int i = col + 1; i <= col + l; i++) {
        used[i] = true;
    }
    return true;
}

vector<int> getRow(int row) {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = board[row][i];
    }
    return result;
}

vector<int> getCol(int col) {
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = board[i][col];
    }
    return result;
}

bool isPath(vector<int>& line) {
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; i++) {
        int diff = line[i + 1] - line[i];
        if (diff == 0) {
            continue;
        } else if (diff == 1) {
            if (!canUpSlope(used, line, i)) {
                return false;
            }
        } else if (diff == -1) {
            if (!canDownSlope(used, line, i)) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    getInput();
    for (int i = 0; i < n; i++) {
        vector<int> row = getRow(i);
        vector<int> col = getCol(i);
        if (isPath(row)) {
            answer++;
        }
        if (isPath(col)) {
            answer++;
        }
    }
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