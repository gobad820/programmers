#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::vector;
using std::string;
using std::pair;

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
void go(int people){
    if(people == temp.size()){
        int temp_answer = 0;
        auto temp_dep = temp.front().second;
        for(int i = 1 ; i < temp.size() ; i++){
            if(temp[i].first >= temp_dep){
                temp_dep = temp[i].second;
                temp_answer++;
            }
        }
        answer = std::max(answer, temp_answer+1);
        return;
    }

    for(const auto& item: students){
        temp.emplace_back(item);
        go(people);
        temp.pop_back();
    }
}

int solution_just(int n, vector<pair<int,int>> students) {
    std::sort(students.begin(), students.end());
    for(int i = 1 ; i <= students.size() ; i++){
        go(i);
    }
    return answer;
}

int solution(int n, vector<pair<int,int>> students) {
    std::sort(students.begin(), students.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if(a.second == b.second){
            return a > b;
        }
        return a.second < b.second;
    });

    int temp_dep = 0;
    for(const auto& t : students){
        if(t.first >= temp_dep){
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
        for(int i = 0 ; i < n ; i++){
            int arrival,departure;
            std::cin >> arrival >> departure;
            students.emplace_back(std::make_pair(arrival, departure));
        }
        std::cout << solution_just(n, students);
    }

    return 0;
}