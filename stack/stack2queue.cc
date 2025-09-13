#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using si = std::stack<int>;
// 루프 매크로
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i > (b); --i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
std::vector<std::string> input{"empty()", "push(1)", "pop()",  "push(2)",
                               "push(3)", "peek()",  "pop()",  "pop()",
                               "pop()",   "pop()",   "empty()"};
si stk1, stk2;

void push(int i) { stk1.emplace(i); }

bool empty() { return stk1.empty(); }
int pop() {
    if (empty()) {
        return -1;
    }
    while (!stk1.empty()) {
        stk2.emplace(stk1.top());
        stk1.pop();
    }
    int result = stk2.top();
    stk2.pop();
    while (!stk2.empty()) {
        stk1.emplace(stk2.top());
        stk2.pop();
    }
    return result;
}

int peek() {
    if (empty()) {
        return -1;
    }
    while (!stk1.empty()) {
        stk2.emplace(stk1.top());
        stk1.pop();
    }
    int result = stk2.top();
    while (!stk2.empty()) {
        stk1.emplace(stk2.top());
        stk2.pop();
    }
    return result;
}

// -----------------------------------------------------------

void solve(std::vector<std::string> i) {
    // 여기에 문제 풀이 코드를 작성하세요.
    // 2개의 stack으로 queue를 구현 // FIFO
    std::regex push_regex("push\\((\\d+)\\)");
    std::regex command_regex("(pop|peek|empty)\\(\\)");

    std::smatch match;
    int extracted_number = 0;

    for (auto& order : i) {
        if (std::regex_search(order, match, push_regex)) {
            extracted_number = std::stoi(match[1].str());
            push(extracted_number);
        } else if (std::regex_search(order, match, command_regex)) {
            auto command = match[1].str();
            if (command == "pop") {
                std::cout << pop() << "\n";
            } else if (command == "peek") {
                std::cout << peek() << "\n";
            } else if (command == "empty") {
                auto answer = empty() == true ? "EMPTY" : "NOT_EMPTY";
                std::cout << answer << "\n";
            }
        }
    }
}

int main(int argc, char** argv) {
    setup_io();
    solve(input);
    return 0;
}