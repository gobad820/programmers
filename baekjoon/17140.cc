#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::pair;
using std::string;
using std::vector;

// 루프 매크로
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); --(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), ().rend()
#define FORE(x) for (const auto& item : x)

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

/**
 * 배열 크기가 3x3
 * R op: 행 정렬, 행 수 >= 열 수일 때
 * C op: 열 정렬: 열 수 > 행 수
 *
 * 각각의 수가 몇 번 나왔는지 알아야 함
 * 수의 등장 회수를 기준으로 오름차순
 * 배열 A에 다시 결과를 넣어야함.
 * 수와 등장 회수를 모두? -> pair 순서는 수가 먼저(수, 횟수)
 *
 * [3, 1, 1] => [3, 1, 1, 2] => [2, 1, 3, 1, 1, 2]
 *
 * 정렬된 결과를 배열에 넣으면 행 또는 열의 크기가 달라짐
 * R 연산이 적용된 경우, 가장 큰 행을 기준으로 모든 행의 크기 설정
 * C연산일 경우 가장 큰 열을 기준
 * 수를 정렬할 때 0은 무시 즉 수 0은 치지 않음
 *
 * 행 또는 열의 크기가 100을 넘기게 되면 초과값을 절사, 또한 시간이 100초 초과
 *시에는 -1을 리턴 간
 *
 *
 */

// ------------------- 전역 변수, 함수 등 선언 -------------------
const int TIME_LIMIT = 100;
const int SPACE_LIMIT = 100;
std::size_t row_size = 3, col_size = 3;
int r, c, k;  // row, col, k -> A[r][c]에 들어 있는 값이 k가 되기 위한 최소 시간
int board[110][110];

void getInput() {
    std::cin >> r >> c >> k;
    r--;
    c--;
    for (std::size_t i = 0; i < row_size; ++i) {
        for (std::size_t j = 0; j < col_size; ++j) {
            std::cin >> board[i][j];
        }
    }
}

vector<int> getRow(int row) {
    vector<int> r;
    for (int i = 0; i < col_size; i++) {
        r.emplace_back(board[row][i]);
    }
    return r;
}

vector<int> getCol(int col) {
    vector<int> c;
    for (std::size_t row = 0; row < row_size; ++row) {
        c.emplace_back(board[row][col]);
    }
    return c;
}

// 연산
void sortOperation(vector<int>& line) {
    map<int, int> count_map;
    vector<pair<int, int>> new_line;
    for (const auto& item : line) {
        if (item == 0) {
            continue;
        }
        count_map[item]++;
    }
    for (const auto& [k, v] : count_map) {
        new_line.emplace_back(k, v);
    }
    std::sort(new_line.begin(), new_line.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) {
                  if (a.second != b.second) {
                      return a.second < b.second;
                  }
                  return a.first < b.first;
              });
    line.clear();
    for (const auto& p : new_line) {  // k: 수, v: 횟수
        line.emplace_back(p.first);
        line.emplace_back(p.second);
    }
}

// 1초마다 R또는 C연산을 반복해야 함

int getOp() {
    if (r < row_size && c < col_size && board[r][c] == k) {
        return 0;
    }
    for (int i = 1; i <= TIME_LIMIT; i++) {
        if (row_size >= col_size) {
            for (std::size_t i = 0; i < row_size; ++i) {
                std::vector<int> line = getRow(i);
                sortOperation(line);  // line size == column
                col_size = std::max(col_size, line.size());
                for (int j = 0; j < col_size; j++) {
                    if (j >= SPACE_LIMIT) {  // 0~99까지 원소만 살림
                        break;
                    }
                    if (j < line.size()) {
                        board[i][j] = line[j];
                        continue;
                    }
                    board[i][j] = 0;
                }
            }
        } else {
            for (std::size_t i = 0; i < col_size; ++i) {
                std::vector<int> line = getCol(i);
                sortOperation(line);
                row_size = std::max(row_size, line.size());
                for (std::size_t j = 0; j < row_size; ++j) {
                    if (j >= SPACE_LIMIT) {
                        break;
                    }
                    if (j < line.size()) {
                        board[j][i] = line[j];
                        continue;
                    }
                    board[j][i] = 0;
                }
            }
        }
        if (r < row_size && c < col_size && board[r][c] == k) {
            return i;
        }
    }
    return -1;
}

// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    getInput();
    return getOp();
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