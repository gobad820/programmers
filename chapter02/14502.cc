#include <bits/stdc++.h>
#define Y first
#define X second
// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::string;
using std::vector;
using std::queue;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, m, board[15][15], vis[15][15], temp_board[15][15];
// -----------------------------------------------------------

int solution() {
    vector<pair<int, int>> zeros, virus;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 0) {
                zeros.emplace_back(i, j);
            } else if (board[i][j] == 2) {
                virus.emplace_back(i, j);
            }
        }
    }
    int answer = -1;

    for (int i = 0; i < zeros.size() - 2; i++) {
        for (int j = i + 1; j < zeros.size() - 1; j++) {
            for (int k = j + 1; k < zeros.size(); k++) {
                int temp_answer = 0;
                memcpy(temp_board, board, sizeof(board));
                memset(vis,0,sizeof(vis));
                auto p1 = zeros[i];
                auto p2 = zeros[j];
                auto p3 = zeros[k];
                temp_board[p1.Y][p1.X] = temp_board[p2.Y][p2.X] =
                    temp_board[p3.Y][p3.X] = 1;

                for(const auto& v: virus){
                    if(vis[v.Y][v.X]){continue;}
                    queue<pair<int, int>> q;
                    q.emplace(v.Y,v.X);
                    vis[v.Y][v.X] = 1;
                    while(!q.empty()){
                        auto t= q.front();
                        q.pop();
                        for(int l = 0 ; l < 4 ; l++){
                            int ny = dy[l] + t.Y;
                            int nx = dx[l] + t.X;
                            if(ny < 0 || nx < 0 || ny >= n || nx >= m){continue;}
                            if(temp_board[ny][nx] || vis[ny][nx]){continue;}
                            q.emplace(ny,nx);
                            vis[ny][nx] = 1;
                        }
                    }
                }
                for(int a = 0 ; a < n ; a++){
                    for(int b = 0 ; b < m ; b++){
                        if(!temp_board[a][b] && !vis[a][b]){temp_answer++;}
                    }
                }

                answer = std::max(temp_answer, answer);
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