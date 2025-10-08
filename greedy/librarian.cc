#include <bits/stdc++.h>

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
int n, answer = 0;
vector<pair<int, int>> students;
// -----------------------------------------------------------

vector<pair<int, int>> temp;
void go(int people) {
    if (people == temp.size()) {
        int temp_answer = 0;
        auto temp_dep = temp.front().second;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].first >= temp_dep) {
                temp_dep = temp[i].second;
                temp_answer++;
            }
        }
        answer = std::max(answer,
                          temp_answer + 1);  // 첫번째 시간은 자동으로 들어가짐
        return;
    }

    for (const auto& item : students) {
        temp.emplace_back(item);
        go(people);
        temp.pop_back();
    }
}

map<vector<pair<int, int>>, int> dp;

vector<pair<int, int>> dynamicProgramming(vector<pair<int, int>> p) {
    if (p.size() == 1) {
        return p;
    }
    int& ret = dp[p];
    if (ret) {
        retrun dp[p];
    }
    vector<pair<int, int>> first, second;
    for (int i = 0; i < p.size(); i++) {
        if (i <= p.size() / 2) {
            first.emplace_back(p[i]);
            continue;
        }
        second.emplace_back(p[i]);
    }
    ret = dynamicProgramming(first) + dynamicProgramming(second);
}

int solutionDP(int n, vector<pair<int, int>> students) {
    // 초기메롱
    for (const auto& item : students) {
        vector<pair<int, int>> v(item);
        dp[v] = 1;
    }
}

int solutionJust(int n, vector<pair<int, int>> students) {
    std::sort(students.begin(), students.end());
    for (int i = 1; i <= students.size(); i++) {
        go(i);
    }
    return answer;
}

int solution(int n, vector<pair<int, int>> students) {
    std::sort(students.begin(), students.end(),
              [](const pair<int, int>& a, const pair<int, int>& b) {
                  if (a.second == b.second) {
                      return a > b;
                  }
                  return a.second < b.second;
              });

    int temp_dep = 0;
    for (const auto& t : students) {
        if (t.first >= temp_dep) {
            answer++;
            temp_dep = t.second;
        }
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int arrival, departure;
            std::cin >> arrival >> departure;
            students.emplace_back(std::make_pair(arrival, departure));
        }
        std::cout << solutionJust(n, students);
    }

    return 0;
}