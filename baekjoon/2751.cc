#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
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
int n;
std::vector<int> v;
void getInput(){
    std::cin >> n;
    v.assign(n,0);
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}


// -----------------------------------------------------------



void solution() {
    getInput();
    std::sort(v.begin(),v.end());
    for(const int& item : v){
        std::cout << item <<"\n";
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