#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

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

/**
 * 선형적으로 탐색하기에 너무 큰 수 -> 이진 탐색을 고려
 *
 */

// ------------------- 전역 변수, 함수 등 선언 -------------------

int number_of_friends, number_of_highlighters;
vector<int> highlighters;

bool search(int estimated_value) {
    int ret = 0;
    for (int i = 0; i < number_of_highlighters; i++) {
        ret += highlighters[i] / estimated_value;
        if (highlighters[i] % estimated_value) ret++;
    }
    return ret <= number_of_friends;  // 못 받는 학생이 있어서는 안됨
}

void binarySearch(vector<int> v) {
    int right = INT32_MIN, left = 0, result = INT32_MAX;
    for (const auto& item : v) {
        right = std::max(item, right);
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (search(mid)) {
            result = std::min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    std::cout << result << "\n";
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n, m;
    std::cin >> n >> m;
    vector<int> highlighters(m);
    for (int i = 0; i < m; i++) {
        std::cin >> highlighters[i];
    }
    ::number_of_friends = n;
    ::number_of_highlighters = m;
    ::highlighters = highlighters;

    binarySearch(highlighters);
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