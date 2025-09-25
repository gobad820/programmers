#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;
using std::set;
// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------


// -----------------------------------------------------------

vector<vector<int>> solution() {
    int n, m;
    std::cin >> n >> m;
    // 길이가 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    vector<int> num(n);
    set<vector<int>> s;
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    do {
        vector<int> temp;
        for (int i = 0; i < m; i++) {
            temp.emplace_back(num[i]);
        }
        s.insert(temp);
    } while (std::next_permutation(num.begin(), num.end()));
    vector<vector<int>> answer;
    for(const vector<int>& v: s){
        answer.emplace_back(v);
    }
    return answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for(const auto& vec: answer){
            for(const auto& item : vec){
                std::cout << item << " ";
            }std::cout << "\n";
        }
    }

    return 0;
}