#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::vector;
using std::string;


// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, used1[20],used2[40], used3[40],answer=0;

void backTracking(int cur_row){
    if(cur_row == n){
        answer++;
        return;
    }

    for(int cur_col = 0 ; cur_col < n ;cur_col ++){
        if(used1[cur_col] || used2[cur_col+cur_row] || used3[cur_row - cur_col + n - 1]){continue;}
        used1[cur_col] = 1;
        used2[cur_col+cur_row] = 1;
        used3[cur_row - cur_col + n - 1] = 1;
        backTracking(cur_row+1);
        used1[cur_col] = 0;
        used2[cur_col+cur_row] = 0;
        used3[cur_row - cur_col + n - 1] = 0;
    }
}

// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n;
    backTracking(0);
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