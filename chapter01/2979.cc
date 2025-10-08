#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;
using std::pair;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
const int NUM_CAR = 3;
// -----------------------------------------------------------

int solution(vector<int> cost, vector<pair<int, int>> car_time) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<vector<int>> timeline(100, vector<int>(0));
    for (const auto& item : car_time) {
        int start = item.first;
        int end = item.second;
        vector<int> a(end - start );
        std::iota(a.begin(), a.end(), start);
        for (const auto& i : a) {
            timeline[i].emplace_back(1);
        }
    }
    int answer= 0;
    for(const auto& time : timeline){
        answer += time.size() * cost[time.size()];
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int start, end;
        vector<pair<int, int>> car_time;
        for (int i = 0; i < NUM_CAR; i++) {
            std::cin >> start >> end;
            car_time.emplace_back(std::make_pair(start, end));
        }
        std::cout << solution({0, a, b, c}, car_time);
    }

    return 0;
}