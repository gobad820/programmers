#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, answer = 0;
int board[20][20];
const int dr[] = {1, -1, 1, -1};
const int dc[] = {-1, -1, 1, 1};

bool isValid(int row, int col) {
    // 열 또는 행에 이미 퀸이 있다면 return false
    for (int i = 0; i < n; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // 대각선 방향으로 검증
    for (int i = 0; i < 4; i++) {
        for (int step = 1; step < n; step++) {
            int nr = row + dr[i] * step;
            int nc = col + dc[i] * step;

            if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                break;
            }
            if (board[nr][nc]) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int row) {  // 한 행 마다 퀸을 두어야 함
    if (row == n) {  // 모든 행에 퀸이 채워졌다면
        answer++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!isValid(row, i)) {  // 해당 좌표에 퀸을 놓을 수 있는지 확인
            continue;
        }
        board[row][i] = 1;  // 퀸 두기
        dfs(row + 1);       // 다음 행
        board[row][i] = 0;  // 퀸 회수
    }
    return;
}

// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n;
    dfs(0);
    std::cout << answer;
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