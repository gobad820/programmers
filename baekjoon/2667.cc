#include <bits/stdc++.h>

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

#define Y first
#define X second

// ------------------- 전역 변수, 함수 등 선언 -------------------
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

// -----------------------------------------------------------

vector<int> solution(int n, vector<vector<int>> board) {
    // 여기에 문제 풀이 코드를 작성하세요.
    int answer = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<int> house_size;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!board[i][j] || vis[i][j]) {
                continue;
            }
            q.emplace(i, j);
            vis[i][j] = 1;
            answer++;
            int temp_size = 1;
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = t.Y + dy[i];
                    int nx = t.X + dx[i];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                        continue;
                    }
                    if (!board[ny][nx] || vis[ny][nx]) {
                        continue;
                    }
                    q.emplace(ny, nx);
                    vis[ny][nx] = 1;
                    temp_size++;
                }
            }
            house_size.emplace_back(temp_size);
        }
    }
    std::sort(house_size.begin(), house_size.end());  // 오름차순 정렬
    vector<int> answer_vector;
    answer_vector.emplace_back(answer);
    for (const auto& item : house_size) {
        answer_vector.emplace_back(item);
    }
    return answer_vector;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    int n;
    string str;
    while (t--) {
        std::cin >> n;
        vector<vector<int>> board(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            std::cin >> str;
            for (int j = 0; j < str.size(); j++) {
                board[i][j] = str[j] - '0';
            }
        }
        auto result = solution(n, board);
        for (const auto& item : result) {
            std::cout << item << "\n";
        }
    }

    return 0;
}