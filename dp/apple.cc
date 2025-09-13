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

/*
큰돌은 1번과 2번 사과 나무에서 떨어지는 사과만 받아먹을 수 있으며, 땅에 떨어지면 못 먹음

매 초마다, 두개 중 하나의 나무에서 사과과 떨어짐
큰돌이 사과를 자븡려면 나무 아래에 서 있어야 하며, 큰돌에게 빠르게 다른 나무로 이동 가능

큰돌은 S초 동안 사과를 잡을 수 있음
M번만 이동할 수 있음

매초마다 어느 사과나무에서 사과과 떨어지는 지에대한 정보가 주어졌을 때, 큰돌이 받을 수 있는 사과의 최대 개수

큰돌은 초기 1번 사과나무 아래에 위치

정리
상태값: S(활동시간), M(이동횟수), P(현재 위치)

*/

// ------------------- 전역 변수, 함수 등 선언 -------------------
int dp[104][2][34], n, m, b[104];
/**
 * Params: idx=현재 시간 idx, cnt=움직인 횟수
 */
int go(int idx, int tree, int cnt){
    if(cnt < 0) return -1e9; // 가동 횟수 제한 
    if(idx == n) return 0; // 현재 시간이 끝남을 의미
    int &ret = dp[idx][tree][cnt];
    if(ret != -1) return ret; // memoization

    // 현재 나무 아래에 그대로 머무르는 경우
    // 다른 나무로 이동하느 경우, 이는 cnt 하나를 차감시켜줌

    // 그리고 서 있는 나무에 사과가 하나 떨어지는 나무라면
    return ret = std::max(go(idx+1, tree ^ 1, cnt - 1), go(idx+1, tree, cnt)) + (tree == b[idx]-1);
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요
    std::memset(dp,-1,sizeof(dp));
    std::cin >> n >> m;
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    // n = s(활동 가능 시간), m(이동 제한 횟수)
    std::cout << std::max(go(0,1,m-1), go(0,0,m));
    return;
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