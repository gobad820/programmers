#include <bits/stdc++.h>
#define Y first
#define X second
// 자주 사용하는 네임스페이스 및 타입 별칭
using std::pair;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, m;
int board[60][60];
int store_num = 0, house_num = 0, answer = INT_MAX;
vector<pair<int, int>> temp, store, house;

void selectStore(int start) {
    if (temp.size() == m) {  // 가게 m개를 선택
        int city_dist = 0;
        for (const auto& h : house) {
            // 치킨집 벡터와 거리 계산해서 최소값만 city_dist에 더해주면 됨
            int temp_dist = INT_MAX;
            for (const auto& s : temp) {
                // 각 치킨집마다 좌표 가져와서 집이랑 거리 계산
                // 가장 가까운 치킨집을 대상으로 치킨 거리 측정
                temp_dist = std::min(temp_dist,
                                     std::abs(s.Y - h.Y) + std::abs(s.X - h.X));
            }
            city_dist += temp_dist;  // 도시 거리는 각 집마다의 치킨 거리의 합계
        }
        // 다른 점포 삭제 경우와 도시 치킨 거리 비교하여 최저 치킨 거리 반환
        answer = std::min(answer, city_dist);
    }

    for (int i = start; i < store.size(); i++) {
        temp.emplace_back(store[i]);
        selectStore(i + 1);
        temp.pop_back();
    }
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> board[i][j];
            if (board[i][j] == 1) {
                house_num++;
                house.emplace_back(i, j);  // 1의 위치 입력
            } else if (board[i][j] == 2) {
                store_num++;
                store.emplace_back(i, j);  // 2의 위치 입력
            }
        }
    }
    selectStore(0);
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