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
// -----------------------------------------------------------

vector<vector<int>> solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n, m;
    std::cin >> n >> m;

    vector<int> nums;
    vector<vector<int>> answer;
    vector<bool> used(n + 1, false);

    std::function<void()> backtrack = [&]() {
        if (nums.size() == m) {
            answer.emplace_back(nums);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            nums.emplace_back(i);
            backtrack();
            nums.pop_back();
            used[i] = false;
        }
    };

    backtrack();

    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for (const vector<int>& v : answer) {
            for (const int& i : v) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}