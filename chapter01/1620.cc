#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
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

vector<string> solution(map<int, string>& pokemons, map<string, int>& pokemons2,
                        vector<string>& questions) {
    vector<string> answers;
    for (const auto& q : questions) {
        if (std::isdigit(q.front())) {
            auto number = std::stoi(q);
            answers.emplace_back(pokemons[number]);
        } else {
            answers.emplace_back(std::to_string(pokemons2[q]));
        }
    }
    return answers;
}

// 10^5 크기의 데이터, 10^5 개의 질문에 답해야 함
// find -> mlogn  => 10^5 log 10^5

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        // 포켓몬 이름 -> 포켓몬 번호 조회
        // 포켓몬 번호 -> 포켓몬 이름
        int n, m;
        std::cin >> n >> m;
        map<int, string> pokemons;
        map<string, int> pokemons2;
        for (int i = 1; i <= n; i++) {
            std::cin >> pokemons[i];
        }
        for (auto& [k, v] : pokemons) {
            pokemons2[v] = k;
        }
        vector<string> questions(m);
        for (auto& item : questions) {
            std::cin >> item;
        }
        auto answers = solution(pokemons, pokemons2, questions);
        for (const auto& a : answers) {
            std::cout << a << "\n";
        }
    }

    return 0;
}