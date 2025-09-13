#include <vector>

using std::vector;

int width, height;
// 좌표가 (1,1)부터 시작하는 좌표계
/**

1,1부터 m,n까지
우, 하 방향으로만 이동 가능, 물에 잠긴 지역은 이동 불가
집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지

<조건>
1 <= m,n <= 100, m,n 모두 1인 경우는 주어지지 않음
물에 잠긴 지역은 0개 이상 10개 이하
집과 학교 모두 물에 잠긴 경우는 주어지지 않음


dp는 움직인 횟수에 따른 위치값
map<int, set<pair<int, int>>> dp; // 움직인 회수에 따른 좌표값(y,x)

*/
const int MOD = 1000000007;

// map<pair<int, int>, int> dp; // map의 좌표에 따른 최소 이동 거리
// int dp[130][130];
vector<vector<int>> dp;

int getPosition(int y, int x) {
    // 기저사례
    if (y >= height || y < 0) {  // 범위를 벗어난 높이
        return 0;
    }
    if (x >= width || x < 0) {  // 범위를 벗어난 너비
        return 0;
    }
    if (dp[y][x] == -1) {  // 물 웅덩이인 경우
        return 0;
    }
    // 메모이제이션
    int& ret = dp[y][x];
    if (ret) {
        return ret;
    }

    return ret =
               ((getPosition(y - 1, x) % MOD) + (getPosition(y, x - 1) % MOD)) %
               MOD;  // 최단거리로 상, 좌에서 내려왔을 때 각각 최단거리의 수
}

void setPuddles(const vector<vector<int>>& puddles) {
    for (const auto& puddle : puddles) {
        if (puddle.size() != 2) {
            continue;
        }
        int x = puddle[0] - 1;
        int y = puddle[1] - 1;
        dp[y][x] = -1;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    width = m--;
    height = n--;
    dp.assign(height, vector<int>(width));
    // 초기화 우선
    dp[0][1] = 1;
    dp[1][0] = 1;
    setPuddles(puddles);  // 조건 적용
    return getPosition(n, m);
}