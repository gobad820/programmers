#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::stack;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

// -----------------------------------------------------------

int solution(vector<string> words) {
    // 여기에 문제 풀이 코드를 작성하세요.
    int answer = 0;
    for (const auto& w : words) {
        stack<char> stk;
        for (const auto& c : w) {
            if (!stk.empty() && stk.top() == c) {
                stk.pop();
                continue;
            }
            stk.emplace(c);
        }
        if (stk.empty()) {
            answer++;
        }
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n;
        std::cin >> n;
        vector<string> w(n);
        for (auto& item : w) {
            std::cin >> item;
        }
        std::cout <<solution(w);
    }

    return 0;
}