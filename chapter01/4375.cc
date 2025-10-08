#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;
using ll = unsigned long long;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
// ---------------------------------------------------------

vector<int> solution() {
    vector<int> answer;
    ll n;
    while (std::cin >> n) {
        int i = 1;
        ll num = 1 % n;
        while (num != 0) {
            num = (num * 10 + 1) % n;
            i++;
        }
        answer.emplace_back(i);
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}