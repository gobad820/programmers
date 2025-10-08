#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::stack;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------

int n;
int arr[1000100], answer[1000100];
// -----------------------------------------------------------

void solution() {
    // 인덱스를 stack에 저장
    // answer 배열을 -1로 초기화
    std::cin >> n;
    stack<int> stk;
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()] < arr[i]) {
            answer[stk.top()] = arr[i];
            stk.pop();
        }
        stk.emplace(i);
    }
    for (int i = 0; i < n; i++) {
        std::cout << answer[i] << " ";
    }
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