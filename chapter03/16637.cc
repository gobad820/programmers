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
int n;
string expr;
vector<int> nums;
vector<char> ops;
int answer = INT_MIN;

int calculate(const int& a, const char& op, const int& b) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    }
    return 0;
}
void compute(int s, int r) {
    if (s == ops.size()) {
        answer = std::max(answer, r);
        return;
    }
    compute(s + 1, calculate(r, ops[s], nums[s + 1]));
    if (s + 1 < ops.size()) {
        compute(s + 2,
                calculate(r, ops[s],
                          calculate(nums[s + 1], ops[s + 1], nums[s + 2])));
    }
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n;
    std::cin >> expr;
    for (auto& i : expr) {
        if (std::isdigit(i)) {
            nums.emplace_back(i - '0');  // int로 변형하여 입력
        } else {
            ops.emplace_back(i);
        }
    }

    compute(0, nums.front());
    std::cout << answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        solution();
    }

    return 0;
}