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
const string NOT_EXIST = "I'm Sorry Hansoo";
// -----------------------------------------------------------

string solution(string input) {
    string answer;
    map<char, int> m;
    for (const auto& item : input) {
        m[item]++;
    }
    int isOdd = 0;
    char centre;
    for ( auto& [k, v] : m) {
        if (v % 2 != 0) {
            isOdd++;
            centre = k;
            v--;
        }
        if (isOdd > 1) {
            return NOT_EXIST;
        }
    }

    for (const auto& [k, v] : m) {
        for (int i = 0; i < v / 2; i++) {
            answer += k;
        }
    }
    string r = answer;
    if (isOdd) {
        answer += centre;
    }
    std::reverse(r.begin(), r.end());
    answer += r;
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        string s;
        std::cin >> s;
        std::cout << solution(s);
    }

    return 0;
}