#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::vector;
using std::string;

// 루프 매크로
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int (i) = (a); (i) > (b); --(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORE(x) for(const auto& item : x)

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
// Fn = F(n-1) + F(n-2)

// ------------------- 전역 변수, 함수 등 선언 -------------------
int dp[100], n;

int fibo(int n){
    if(n <= 1) { return n; }
    int& ret = dp[n];
    if(ret != -1){return ret;}
    return ret = fibo(n-1) + fibo(n-2);
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::memset(dp,-1,sizeof(dp));
    std::cin >> n;
    std::cout << fibo(n);
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