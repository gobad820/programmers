#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

int n;
map<int, int> m;
vector<int> v;
// -----------------------------------------------------------

void solution() {
    std::cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        v.emplace_back(t);
        m[t] = 1;
    }
    int temp = 0;
    for (auto& [k, v] : m) {
        v += temp++;
    }

    for (const auto& item : v) {
        std::cout << m[item] - 1 << " ";
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