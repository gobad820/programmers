#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;

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
vi numbers{1, 1, 1, 1, 1};
int target = 3;
int answer = 0;
void go(int here, int sum) {
    if (here == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    go(here + 1, sum + numbers[here]);
    go(here + 1, sum - numbers[here]);
}
// -----------------------------------------------------------

/**
 * n개의 음이 아닌 정수
 * vi numbers를 각각 더하거나 빼서 target 이 되는 경우의 수를 리턴하라
 * numbers.size() <= 20, 1 <= numbers[i] <= 50, 1 <= target <= 1000
 * DFS 가능(Recursion)
 *
 */
int solution(std::vector<int> numbers, int target) {
    // 여기에 문제 풀이 코드를 작성하세요.
    ::numbers = numbers;
    ::target = target;

    go(0, 0);
    return answer;
}

int main(int argc, char** argv) {
    setup_io();
    std::cout << solution(numbers, target);

    return 0;
}