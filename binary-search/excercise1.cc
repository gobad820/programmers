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

// ------------------- 전역 변수, 함수 등 선언 -------------------
vector<vector<int>> n{{7, 3, 2, 5, 9, 11}, {3, 7, 10, 11}};

int binarySearch(const vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid =
            left + (right - left) / 2;  // (l+r)이 overstack이 될 가능성을
                                        // 배제하기 위해서 -> edge case 대비
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// -----------------------------------------------------------

void solution(vector<int>& cnote, vector<int>& snote) {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::sort(cnote.begin(), cnote.end());
    std::sort(snote.begin(), snote.end());

    for (const int& num : snote) {
        if (binarySearch(cnote, num) != -1) {
            std::cout << "큰돌이는 기억해!\n";
            continue;
        }
        std::cout << "큰돌이는 까먹었어!\n";
    }
}

int main(int argc, char** argv) {
    setup_io();
    solution(n[0], n[1]);
    return 0;
}