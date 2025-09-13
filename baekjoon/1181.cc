#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::set;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n;
    std::cin >> n;
    map<int, set<string>> sorted_word;
    for (std::size_t i = 0; i < n; ++i) {
        string t;
        std::cin >> t;
        sorted_word[t.size()].insert(t);
    }

    for (const auto& [length, words] : sorted_word) {
        for (const string& word : words) {
            std::cout << word << "\n";
        }
    }
    return;
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