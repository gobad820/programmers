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

int solution(vector<int> temperatures, int days) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<int> psums;
    psums.emplace_back(0);
    int answer = INT_MIN;
    for (auto& item : temperatures) {
        psums.emplace_back(psums.back() + item);
    }
    for (int i = days; i < psums.size(); i++) {
        answer = std::max(answer, psums[i] - psums[i - days]);
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        vector<int> temperatures(n);
        for (auto& t : temperatures) {
            std::cin >> t;
        }
        auto answer = solution(temperatures, k);
        std::cout << answer;
    }

    return 0;
}