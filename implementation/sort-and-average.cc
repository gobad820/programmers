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
// -----------------------------------------------------------

void solution(int n) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<int> v(n, 0);
    for (auto& item : v) {
        std::cin >> item;
    }

    std::sort(v.begin(), v.end());
    double avg = 0.0;
    for (const auto& item : v) {
        std::cout << item << " ";
        avg += item;
    }
    std::cout << "\n";
    avg /= n;
    std::cout << std::defaultfloat << std::setprecision(2) << avg << '\n';
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> ::n;
        solution(::n);
    }

    return 0;
}