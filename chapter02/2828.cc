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
vector<int> apples;
int n, m, j;
int answer = 0;
void go(int start, int step) {
    // 사과를 받기 위해 이동해야 하는 칸 수 계산
    if (step == j) {
        return;
    }
    int apple_pos = apples[step] - 1;
    int movement;
    if (apple_pos > start + m - 1) {
        movement = apple_pos - (start + m - 1);
    } else if (apple_pos < start) {
        movement = apple_pos - start;
    } else if (start <= apple_pos && apple_pos <= start + m - 1) {
        movement = 0;
    }
    answer += std::abs(movement);

    // 이동 로직
    go(start + movement, step + 1);
}

// -----------------------------------------------------------

void solution() {
    std::cin >> n >> m >> j;
    apples.assign(j, 0);
    for (auto& item : apples) {
        std::cin >> item;
    }
    go(0, 0);
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