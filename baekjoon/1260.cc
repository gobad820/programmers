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
int n, m, v;
// int vec[1050][1050];
vector<vector<int>> vec;
vector<int> temp;
bool vis[1050];

void bfs(int start) {
    queue<int> q;
    q.emplace(start);
    vis[start] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        std::cout << t + 1 << " ";
        for (const auto& item : vec[t]) {
            if (vis[item]) {
                continue;
            }
            q.emplace(item);
            vis[item] = true;
        }
    }
    std::cout << "\n";
}

void dfs(int start) {
    vis[start] = true;
    std::cout << start + 1 << " ";
    for (const auto& item : vec[start]) {
        if (vis[item]) {
            continue;
        }
        vis[item] = true;
        dfs(item);
    }
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    dfs(v - 1);
    std::cout << "\n";
    std::memset(vis, false, sizeof(vis));
    bfs(v - 1);
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> n >> m >> v;
        vec.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int first_node, second_node;
            std::cin >> first_node >> second_node;
            vec[first_node - 1].emplace_back(second_node - 1);
            vec[second_node - 1].emplace_back(first_node - 1);
        }

        for( auto& item: vec){
            std::sort(item.begin(), item.end());
        }

        solution();
    }

    return 0;
}