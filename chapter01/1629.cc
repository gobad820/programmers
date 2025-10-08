#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;
using ll = long long;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int c;
ll go(ll a, ll b) {
    if (b == 1) {
        return a % c;
    }
    ll ret = go(a, b / 2);
    ret = (ret * ret) % c;
    if (b % 2) {
        ret = (ret * a) % c;
    }
    return ret;
}

// -----------------------------------------------------------

ll solution() {
    // 여기에 문제 풀이 코드를 작성하세요.

    ll a, b, c, answer;
    std::cin >> a >> b >> c;
    ::c = c;
    answer = go(a, b);
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cout << solution();
    }

    return 0;
}