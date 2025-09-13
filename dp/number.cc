#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;
using ll = long long;

// 루프 매크로
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); --(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORE(x) for (const auto& item : x)

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

/*
1 = 1
2 = 1+1, 2
3 = 1+1+1, 2+1, 3
4 = 1+1+1+1, 2+1+1, 2+2, 3+1
5 = 1+1+1+1+1, 2+1+1+1, 2+2+1, 3+1+1, 3+2
6 = 1+1+1+1+1+1, 2+1+1+1, 2+2+1+1, 2+2+2, 3+1+1+1, 3+2+1, 3+3
 *
 */
// ------------------- 전역 변수, 함수 등 선언 -------------------
ll t, n, dp[10005];
vector<ll> answer;
// -----------------------------------------------------------

vector<ll> solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    dp[0] = 1;  // 아무것도 선택하지 않음
    for (std::size_t i = 1; i <= 3; ++i) {
        for (std::size_t j = 1; j < 10001; ++j) {
            if (j - i >= 0) {
                dp[j] += dp[j - i];
            }
        }
    }

    std::cin >> t;
    while (t--) {
        std::cin >> n;
        answer.emplace_back(dp[n]);
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();
    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        vector<ll> s = solution();
        for (auto& item : s) {
            std::cout << item << "\n";
        }
    }

    return 0;
}