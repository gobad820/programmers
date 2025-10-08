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
vector<vector<int>> board;
string answer;
void quadTree(int y, int x, int length) {
    // 모두 동동일한 값ㅣㅏ면 answer에 첫 글자만 넣고 괄호 닫기
    int test = board[y][x];
    bool flag = false;
    for (int i = y; i < y + length && !flag; i++) {
        for (int j = x; j < x + length; j++) {
            if (board[i][j] != test) {
                flag = true;
                break;
            }
        }
    }
    if (flag) {
        answer += "(";
        quadTree(y, x, length / 2);
        quadTree(y, x + length / 2, length / 2);
        quadTree(y + length / 2, x, length / 2);
        quadTree(y + length / 2, x + length / 2, length / 2);
        answer += ")";
    } else {
        answer += std::to_string(board[y][x]);
    }
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n;
    std::cin >> n;
    board.assign(n, vector<int>(n));
    string input;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        for (int j = 0; j < n; j++) {
            board[i][j] = input[j] - '0';
        }
    }
    quadTree(0, 0, n);
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