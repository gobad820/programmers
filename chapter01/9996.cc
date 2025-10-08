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

bool checkDirectory(string& directory, string& pattern,
                    vector<string>& answer) {
    if (directory.size() < pattern.size() - 1) { // *가 아무것도 없을 때 abcd*e의 최소 길이는 abcde가 되므로
        return false;
    }
    for (int i = 0; i < directory.size(); i++) {
        if (pattern[i] == '*') {
            break;
        }
        if (directory[i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------

vector<string> solution(string pattern, vector<string> directory) {
    // ㅍㅐ턴과 파일 이름이 일치하는지를 구해야됨
    vector<string> answer;
    auto original_pattern = pattern;
    std::reverse(pattern.begin(), pattern.end());
    auto reverse_pattern = pattern;

    for (auto& d : directory) {
        auto it = std::find(original_pattern.begin(), original_pattern.end(), '*');
        if (!checkDirectory(d, original_pattern, answer)) {
            answer.emplace_back("NE");
            continue;
        }
        std::reverse(d.begin(), d.end());
        if (!checkDirectory(d, reverse_pattern, answer)) {
            answer.emplace_back("NE");
            continue;
        }
        answer.emplace_back("DA");
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
        string p;
        std::cin >> p;
        vector<string> d(n);
        for (auto& item : d) {
            std::cin >> item;
        }
        auto answers = solution(p, d);
        for (const string& answer : answers) {
            std::cout << answer << "\n";
        }
    }

    return 0;
}