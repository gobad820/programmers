#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

// 루프 매크로
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for (int(i) = (a); (i) >= (b); --(i))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, m, ret = 1, idx;
vector<int> prev_list, numbers, cnt, result;

void go(int idx) {
    if (idx == -1) {
        return;
    }  // 가장 최저 값은 처음 -1로 fill됨
    result.emplace_back(numbers[idx]);
    go(prev_list[idx]);
    return;
}
// -----------------------------------------------------------
void solution() {
    std::cin >> n;
    prev_list.resize(n);
    numbers.resize(n);
    cnt.resize(n);
    result.clear();

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::fill(ALL(prev_list), -1);
    std::fill(ALL(cnt), 1);

    ret = 1;
    idx = 0;

    FOR(i, 0, n) {
        FOR(j, 0, i) {
            if (numbers[j] < numbers[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    std::cout << ret << "\n";
    go(idx);

    // 역순으로 출력 (올바른 순서)
    std::reverse(ALL(result));
    for (auto& item : result) {
        std::cout << item << " ";
    }
    std::cout << "\n";
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