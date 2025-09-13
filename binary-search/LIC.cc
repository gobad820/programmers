#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

// 루프 매크로
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++i)
#define RFOR(i, a, b) for (int(i) = (a); (i) > (b); --i)
#define FORE(x) for (const auto& item : x)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

bool check(int m, int n, vector<int> h) {
    // 해당 m 즉 질투(=가진 형광펜의 개수)가 문제의 주어진 조건을 만족하는가?

    // 모든 형광펜을 다 나누어주되, 종류가 섞일수는 없으며 형광펜을 받지 못해도
    // 괜찮 m -> 형광펜의 개수
    int sent = 0;
    FORE(h) {
        sent += item / m;  // 받은 사람
        if (item % m) sent++;
    }
    return sent <= n;
}

int binarySearch(vector<int> highlighters, int n) {
    int result = INT32_MAX, left = 1,
        right = *std::max_element(highlighters.begin(), highlighters.end()),
        mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (check(mid, n, highlighters)) {
            result = std::min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

vector<int> inputVector(int m) {
    vector<int> highlighters;
    int t;
    for (int i = 0; i < m; i++) {
        std::cin >> t;
        highlighters.emplace_back(t);
    }
    return highlighters;
}
// -----------------------------------------------------------

int solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n, m, t, max_highlight = 0;
    std::cin >> n >> m;
    vector<int> highlighters = inputVector(m);
    return binarySearch(highlighters, n);
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