#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::vector;
using std::string;


// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

// -----------------------------------------------------------

int solution(string s) {
    // 여기에 문제 풀이 코드를 작성하세요.
    string original = s;
    std::reverse(s.begin(), s.end());
    return s == original; 
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        string input;
        std::cin >> input;
        std::cout << solution(input);
    }

    return 0;
}