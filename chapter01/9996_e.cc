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

vector<string> solution(string pattern, vector<string> directories) {
    vector<string> answers;
    for (auto& d : directories) {
        auto it = pattern.find('*');
        // 앞 부분이 동일하면
        if (std::equal(pattern.begin(), pattern.begin() + it, d.begin()) &&
            // 뒷 부분도 동일하다면
            std::equal(pattern.rbegin(), pattern.rbegin() + size - 1 - it, d.rbegin()) &&
            d.size() >= pattern.size() - 1) {
            answers.emplace_back("DA");
            continue;
        }
        answers.emplace_back("NE");
    }
    return answers;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n;
        std::cin >> n;
        string pattern;
        std::cin >> pattern;
        vector<string> directories(n);
        for (auto& item : directories) {
            std::cin >> item;
        }

        auto answer = solution(pattern, directories);
        for (const auto& item : answer) {
            std::cout << item << '\n';
        }
    }

    return 0;
}