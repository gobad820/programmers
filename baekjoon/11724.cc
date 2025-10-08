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
int n, m, answer = 0;
vector<int> adj[1050];
bool vis[1050];
// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int fst, snd;
        std::cin >> fst >> snd;
        adj[fst].emplace_back(snd);
        adj[snd].emplace_back(fst);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        q.emplace(i);

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (const auto& item : adj[t]) {
                if (vis[item]) {
                    continue;
                }
                vis[item] = true;
                q.emplace(item);
            }
        }
        answer++;
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