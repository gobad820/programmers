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
int n;
char board[50][50];
int answer = 0;

int getSameCandiesNumber() {
    int max_value = 1;
    // 행
    for (int r = 0; r < n; r++) {
        int cur = 1;
        for (int c = 1; c < n; c++) {
            if (board[r][c] != board[r][c - 1]) {
                max_value = std::max(cur, max_value);
                cur = 1;
            } else {
                cur++;
            }
        }
        max_value = std::max(cur, max_value);
    }
    for (int c = 0; c < n; c++) {
        int cur = 1;
        for (int r = 1; r < n; r++) {
            if (board[r][c] != board[r - 1][c]) {
                max_value = std::max(cur, max_value);
                cur = 1;
            } else {
                cur++;
            }
        }
        max_value = std::max(cur, max_value);
    }
    return max_value;
}

// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> board[i][j];
        }
    }

    answer = std::max(getSameCandiesNumber(), answer);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i + 1 < n && board[i][j] != board[i + 1][j]) {
                std::swap(board[i][j], board[i + 1][j]);
                answer = std::max(getSameCandiesNumber(), answer);
                std::swap(board[i][j], board[i + 1][j]);
            }
            if(j + 1 < n && board[i][j] != board[i][j+1]){
                std::swap(board[i][j], board[i ][j+1]);
                answer = std::max(getSameCandiesNumber(), answer);
                std::swap(board[i][j], board[i ][j+1]);

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
       std::cout << solution();
    }

    return 0;
}