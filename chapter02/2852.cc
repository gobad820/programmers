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

int times[48 * 60];
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    int n;
    std::cin >> n;
    int team;
    string time_stamp;
    for (int i = 0; i < n; i++) {
        std::cin >> team >> time_stamp;
        int minute = std::stoi(time_stamp.substr(0, 2));
        int second = std::stoi(time_stamp.substr(3, 2));
        int temp_time = minute * 60 + second;
        if (team == 1) {
            for (int i = temp_time; i < 48 * 60; i++) {
                times[i]--;
            }
        } else {
            for (int i = temp_time; i < 48 * 60; i++) {
                times[i]++;
            }
        }
    }
    int team1_time = 0, team2_time = 0;
    for (int i = 0; i < 48 * 60; i++) {
        if (times[i] < 0) {
            team1_time++;
        } else if (times[i] > 0) {
            team2_time++;
        }
    }

    int m1 = team1_time / 60;
    int s1 = team1_time % 60;
    int m2 = team2_time / 60;
    int s2 = team2_time % 60;

    std::cout << std::setfill('0') << std::setw(2) << m1 << ":" << std::setw(2)
              << s1 << "\n";
    std::cout << std::setfill('0') << std::setw(2) << m2 << ":" << std::setw(2)
              << s2 << "\n";
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