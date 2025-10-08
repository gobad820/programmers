#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::queue;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
struct t {
    int a, b, c;
    t(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

const int d[6][3] = {  // 이동 방향을 의미
    {1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}};
int vis[60][60][60];  // 체력의 값과, 체력 상태값의 경우의 수 방문 체크

// -----------------------------------------------------------

void solution(vector<int>& scvs) {
    queue<t> q;
    q.emplace(scvs[0], scvs[1], scvs[2]);
    vis[scvs[0]][scvs[1]][scvs[2]] = 1;
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int na = std::max(0, temp.a - d[i][0]);
            int nb = std::max(0, temp.b - d[i][1]);
            int nc = std::max(0, temp.c - d[i][2]);

            if (vis[na][nb][nc]) {
                continue;
            }
            q.emplace(na, nb, nc);
            vis[na][nb][nc] = vis[temp.a][temp.b][temp.c] + 1;
        }  // queue를 사용하면 최단 거리 시간으로 특정 상태에 도달 가능
    }
    std::cout << vis[0][0][0] - 1;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n;
        std::cin >> n;
        vector<int> scvs(n);
        for (int i = 0; i < n; i++) {
            std::cin >> scvs[i];
        }

        solution(scvs);
    }

    return 0;
}