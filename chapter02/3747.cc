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

vector<int> solution(vector<int>& num) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<int> answer;
    // n! = 1 * 2 * 3 * 4 * 5 *... *n
    // 5! = 120
    // 5 4 3 2 1
    // 5 = 1
    for (auto& item : num) {
        // 5의 개수를 찾는 문제
        int count = 0;
        double p = 1;
        while (std::pow(5, p) <= item) {
            double number = std::pow(5, p);
            for (; number <= item; number) {
                count++;
            }
            p++;
        }
        answer.emplace_back(count);
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
        vector<int> num(n);
        for (auto& item : num) {
            std::cin >> item;
        }
        auto answer = solution(num);
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}