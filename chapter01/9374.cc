#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::string;
using std::vector;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
// -----------------------------------------------------------
vector<int> solution(vector<map<string, vector<string>>> clothes) {
    // 종류의 조합
    vector<int> answers;
    for (const auto& m : clothes) {
        int answer = 1;
        for (const auto& [k, v] : m) {
            answer *= (v.size() + 1);
        }
        answer -= 1;
        answers.emplace_back(answer);
    }
    return answers;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int tc;
        std::cin >> tc;
        vector<map<string, vector<string>>> clothes;
        while (tc--) {
            int n;
            std::cin >> n;
            map<string, vector<string>> t;
            for (int i = 0; i < n; i++) {
                string kind, name;
                std::cin >> name >> kind;
                t[kind].emplace_back(name);
            }
            clothes.emplace_back(t);
        }
        auto answer = solution(clothes);
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}