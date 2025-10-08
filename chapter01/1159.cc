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

const string GIVE_UP = "PREDAJA";
const int NUM_OF_PLAYER = 5;
// -----------------------------------------------------------

string solution(int n, vector<string> last_names) {
    // 5명을 모을 수 있따면 성의 첫 글자들을 더한 문자열 그렇지 않다면 PREDAJA
    string answer;
    vector<vector<char>> players(26, vector<char>());
    for (const auto& l : last_names) {
        players[l.front() - 'a'].emplace_back(l.front());
    }
    for (const auto& alphabet : players) {
        if (alphabet.size() >= NUM_OF_PLAYER) {
            answer += alphabet.front();
        }
    }
    return answer.size() >= 1 ? answer : GIVE_UP;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int n;
        std::cin >> n;
        vector<string> last_names(n);

        for (auto& item : last_names) {
            std::cin >> item;
        }
        std::cout << solution(n, last_names);
    }

    return 0;
}