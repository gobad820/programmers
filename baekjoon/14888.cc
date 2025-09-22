#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

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

// ------------------- 전역 변수, 함수 등 선언 -------------------
/**
 * N개의 수로 이루어진 수열
 * 수와 수 사이에 끼어넣을 수 있는 N-1개 사칙연산
 *
 * 수식: 수와 수 사이의 연산자
 * 이 때 수식은 피연산자와 피연산자의 순서를 바꿀 수는 없다
 *
 * A = {1,2,3,4,5,6 }
 * op = [+,+,-,*,/]
 *
 * 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하라
 *
 *
 */

const int NUM_OF_OP = 4;

int n;
vector<int> nums, op, temp_op;
int min_value = INT_MAX, max_value = INT_MIN;

void getInput() {
    std::cin >> n;
    nums.assign(n, 0);
    op.assign(n, 0);
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    for (std::size_t i = 0; i < NUM_OF_OP; ++i) {
        std::cin >> op[i];
    }
}

int operatorSelector(int a, int op, int b) {
    if (op == 0) {
        return a + b;
    }
    if (op == 1) {
        return a - b;
    }
    if (op == 2) {
        return a * b;
    }
    if (op == 3) {
        return a / b;
    }
    return 0;
}

void dfs(int count) {
    if (temp_op.size() == n - 1) {  // A o B
        int temp = nums[0];
        for (int i = 0; i < n - 1; i++) {
            temp = operatorSelector(temp, temp_op[i], nums[i + 1]);
        }
        min_value = std::min(min_value, temp);
        max_value = std::max(max_value, temp);
        return;
    }

    for (std::size_t j = 0; j < NUM_OF_OP; ++j) {
        if (!op[j]) {
            continue;
        }
        temp_op.emplace_back(j);
        op[j]--;
        dfs(count + 1);
        temp_op.pop_back();
        op[j]++;
    }
}

// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    getInput();
    dfs(0);
    std::cout << max_value << "\n" << min_value;
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