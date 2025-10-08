#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n, c;
vector<int> rank;
map<int, int> nums;
// -----------------------------------------------------------

void solution(map<int, int>& numbers, vector<int>& rank) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<pair<int, int>> v;
    for (const auto& [k, value] : numbers) {
        v.emplace_back(std::make_pair(k, value));
    }

    std::sort(v.begin(), v.end(),
              [rank](const pair<int, int>& a, const pair<int, int>& b) {
                  if (a.second == b.second) {  // 사전순이 아니라 먼저 선착순
                      return std::find(rank.begin(), rank.end(), a.first) <
                             std::find(rank.begin(), rank.end(), b.first);
                  }
                  return a.second > b.second;
              });

    for (const auto& p : v) {
        for (int i = 0; i < p.second; i++) {
            std::cout << p.first << " ";
        }
    }
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> n >> c;
        int temp;
        for (int i = 0; i < n; i++) {
            std::cin >> temp;
            nums[temp]++;
            if (std::find(rank.begin(), rank.end(), temp) == rank.end()) {
                rank.emplace_back(temp);
            }
        }
        solution(nums, rank);
    }

    return 0;
}