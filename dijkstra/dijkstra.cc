#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::priority_queue;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
vector<pair<int, int>> adj[20004];  // 인접행렬 벡터
vector<int> dist(20004, INT_MAX);   // 최단거리배열

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;
    dist[start] = 0;  // 자기자신
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto node = pq.top();
        int here_cost = node.first;
        int u = node.second;
        pq.pop();

        std::cout << "PQTOP\n" << u << "\n";

        if (dist[u] != here_cost) continue;

        for (auto there : adj[u]) {
            int new_cost = here_cost + there.first;  // dist[u] + weight to v
            if (new_cost <
                dist[there.second]) {  // dist[there.second] == dist[v]
                dist[there.second] = new_cost;
                std::cout << there.second << " : " << new_cost << "\n";
                pq.emplace(new_cost, there.second);
            }
        }
    }
}

// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n, m, start;
    std::cin >> n >> m >> start;

    for (std::size_t i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].emplace_back(w, v);  // cost, node_name

        // u에 인접한 v노드의 엣지 웨이트는 w
    }

    dijkstra(start);

    for (std::size_t i = 1; i <= n; ++i) {
        if (dist[i] == INT_MAX) {
            std::cout << "INF\n";
            continue;
        }
        std::cout << "dist " << i << " : " << dist[i] << "\n";
    }
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