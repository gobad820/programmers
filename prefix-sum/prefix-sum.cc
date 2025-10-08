#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::string;
using std::vector;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

// -----------------------------------------------------------

void solution(int n, int m) {
    vector<int> numbers(n + 1, 0), psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i + 1];
        psum[i + 1] = psum[i] + numbers[i + 1];
    }
    vector<pair<int, int>> questions(m, {0, 0});
    int start, end;
    for (int i = 0; i < m; i++) {
        std::cin >> start >> end;
        questions[i] = std::make_pair(start, end);
    }

    for (const auto& item : questions) {
        std::cout << psum[item.second] - psum[item.first - 1] << "\n";
    }
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        solution(n, m);
    }

    return 0;
}