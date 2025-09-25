#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, m;
void getInput() { std::cin >> n >> m; }

// -----------------------------------------------------------

vector<vector<int>> solution(int n, int m) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<vector<int>> answer;
    vector<int> v;
    vector<bool> vis(n, false);
    std::function<void(int)> backtracking = [&](int start) -> void {
        if (v.size() == m) {
            answer.emplace_back(v);
            return;
        }

        for (int i = start; i <= n; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            v.emplace_back(i);
            backtracking(i);
            v.pop_back();
            vis[i] = false;
        }
    };

    backtracking(1);
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        getInput();
        auto result = solution(n, m);
        for (const vector<int>& v : result) {
            for (const int& i : v) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}