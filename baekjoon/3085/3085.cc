#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
#define Y first
#define X second

using std::map;
using std::pair;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

// -----------------------------------------------------------

/***
 * NxN 크기에 사탕이 있는 배열
 * 사탕의 색은 모두 같지 않을 수도 있음
 * 색이 다른 인접한 두칸을 선택, 2개의 사탕의 위치를 서로 교환
 * 이제 모두 같은 색으로 이루어져있는 가장 긴 부분(행 또는 열)을 고른 다음 사탕
 * 제거
 *
 * 사탕이 채워진 상태로 보드 입력
 * 제거할 수 있는 사탕의 최대 개수 리턴
 *
 */

int n;
constexpr char colors[] = {'C', 'P', 'Z', 'Y'};
vector<string> board;
map<vector<pair<int, int>>, bool> vis;

void findSameColor() {  // 행 또는 열 벡터에 대해서 같은 색이 있는지 확인
    // 행에 대해서 검사
    int board_size = board.size();
    for (int row = 0; row < board_size; row++) {
        for (int col = 0; col < board_size - 1; col++) {
            if (board[row][col] != board[row][col + 1]) {
                vector<pair<int, int>> temp = {{row, col}, {row, col + 1}};
                vis[temp] = true;
            }
        }
    }

    for (int col = 0; col < board_size; col++) {
        for (int row = 0; row < board_size - 1; row++) {
            if (board[row][col] != board[row + 1][col]) {
                vector<pair<int, int>> temp = {{row, col}, {row + 1, col}};
                vis[temp] = true;
            }
        }
    }
}

void swapCandies(const pair<int, int>& fst, const pair<int, int>& snd) {
    std::swap(board[fst.Y][fst.X], board[snd.Y][snd.X]);
}

int eatCandies() {
    int max_value = 0;
    int board_size = board.size();

    for (const auto& line : board) {
        int cur_len = 1;
        for (int i = 1; i < board_size; i++) {
            if (line[i - 1] == line[i]) {
                cur_len++;
            } else {
                max_value = std::max(max_value, cur_len);
                cur_len = 1;
            }
        }
        max_value = std::max(max_value, cur_len);
    }

    for (int c = 0; c < board_size; c++) {
        int cur_len = 1;
        for (int r = 1; r < board_size; r++) {
            if (board[r][c] != board[r - 1][c]) {
                max_value = std::max(max_value, cur_len);
                cur_len = 1;
            } else {
                cur_len++;
            }
        }
        max_value = std::max(max_value, cur_len);
    }
    return max_value;
}

int solution(int n, vector<string> board) {
    // 여기에 문제 풀이 코드를 작성하세요.
    ::n = n;
    ::board = board;
    int answer = 0;
    vis.clear();
    // 모든 경우의 수에 대입할 필요 있음
    findSameColor();
    answer = std::max(eatCandies(), answer);
    for (auto& [k, v] : vis) {
        auto first = k[0];
        auto second = k[1];
        swapCandies(first, second);
        answer = std::max(eatCandies(), answer);
        swapCandies(first, second);
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n;
        std::cin >> n;
        vector<string> board(n);
        for (int i = 0; i < n; i++) {
            std::cin >> board[i];
        }
        std::cout << solution(n, board);
    }

    return 0;
}