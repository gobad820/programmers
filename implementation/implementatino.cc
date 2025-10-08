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

void solution(string dopa) {
    // 앞에서부터 3개의 문자열 출력
    string dopa_str = dopa.substr(0,3);
    std::cout << dopa_str << "\n";

    // 거꾸로 출력
    std::reverse(dopa.begin(), dopa.end());
    std::cout << dopa << "\n";

    // 거꾸로된 문자열 끝에 "umzunsik" 문자열 추가
    string reverse_umzunsik = dopa.append("umzunsik");
    std::cout << reverse_umzunsik << "\n";
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        solution("umzunsik");
    }

    return 0;
}