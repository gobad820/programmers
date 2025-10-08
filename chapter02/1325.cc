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

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, m;
int vis[10600];
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n >> m;
    vector<vector<int>> computers(n + 1);
    // A -> B 라면 B 해킹하면 A를 해킹할 수 있음
    for (int i = 0; i < m; i++) {
        int root, leaf;
        std::cin >> root >> leaf;
        computers[leaf].emplace_back(root);
    }
    vector<pair<int, int>> result;
    int max_infested = INT_MIN;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (computers[i].empty()) {
            if (max_infested <= 1) {
                result.emplace_back(i, 1);
                max_infested = 1;
            }
            continue;
        }
        queue<int> q;
        q.emplace(i);
        vis[i] = 1;
        int temp_count = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (const auto& item : computers[t]) {
                if (vis[item]) {
                    continue;
                }
                q.emplace(item);
                vis[item] = 1;
                temp_count++;
            }
        }
        if (temp_count >= max_infested) {
            if (temp_count != max_infested) {
                result.clear();
            }
            result.emplace_back(i, temp_count);
            max_infested = temp_count;
        }
    }

    for (const auto& p : result) {
        std::cout << p.first << " ";
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