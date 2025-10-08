#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::stack;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

// -----------------------------------------------------------

vector<string> solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    string str;
    vector<string> answer;
    while (getline(std::cin, str) && str != ".") {
        stack<char> s;
        bool flag = false;
        for (const auto& item : str) {
            if (item == ']') {
                if (s.empty() || s.top() != '[') {
                    answer.emplace_back("no");
                    flag = true;
                    break;
                } else {
                    s.pop();
                }
            } else if (item == ')') {
                if (s.empty() || s.top() != '(') {
                    answer.emplace_back("no");
                    flag = true;
                    break;
                } else {
                    s.pop();
                }
            } else if (item == '(') {
                s.emplace(item);
            } else if (item == '[') {
                s.emplace(item);
            }
        }
        if (!flag) {
            if (!s.empty()) {
                answer.emplace_back("no");
            } else {
                answer.emplace_back("yes");
            }
        }
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}