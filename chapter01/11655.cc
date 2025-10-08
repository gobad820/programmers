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

string solution(string plain_text) {
    for (auto& item : plain_text) {
        // 소문자 또는 대문자인 경우에만
        if (std::isalpha(item)) {
            char plain = item;
            if (std::isupper(item)) {
                plain = (((plain - 'A') % 26) + (13 % 26)) % 26 + 'A';
            } else {
                plain = (((plain - 'a') % 26) + (13 % 26)) % 26 + 'a';
            }
            item = plain;
        }
    }
    return plain_text;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        string text;
        std::getline(std::cin, text);
        std::cout << solution(text);
    }
    return 0;
}