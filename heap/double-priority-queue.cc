#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using min_pq = std::priority_queue<int, vi, std::greater<int>>;
using max_pq = std::priority_queue<int, vi, std::less<int>>;
using str = std::string;
using vs = std::vector<str>;
using vvs = std::vector<vs>;
using mi = std::map<int, int>;

// 루프 매크로
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i > (b); --i)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
vvs test_cases{{"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"},
               {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1",
                "D -1", "I 333"}};
min_pq minpq;
max_pq maxpq;
mi vis;
// -----------------------------------------------------------

vi solve(vs operations) {
    // 여기에 문제 풀이 코드를 작성하세요.
    for (auto& o : operations) {
        if (o.front() == 'I') {  // Insert Numbers
            auto number = std::stoi(o.substr(2));
            // std::cout << number << "\n";
            minpq.emplace(number);
            maxpq.emplace(number);
            vis[number]++;
        } else if (o.front() == 'D') {  // Delete Numbers
            auto branch = o.substr(2);  // -1 or 1
            int number;
            if (branch == "-1") {       // Delete Minimum Numbers
                while(!minpq.empty() && !vis[minpq.top()] ){ // pq not empty && vis[top] == 0
                    minpq.pop();
                }
                if(minpq.empty() ) { continue; }
                number = minpq.top();
                minpq.pop();
            } else if (branch == "1") {  // Delete Maximum Numbers
                while(!maxpq.empty() && !vis[maxpq.top()] ){ // pq not empty && vis[top] == 0
                    maxpq.pop();
                }
                number = maxpq.top();
                maxpq.pop();
            }
            vis[number]--;
        } else {
            continue;
        }
    }

    while(!minpq.empty() && !vis[minpq.top()] ){ // pq not empty && vis[top] == 0
        minpq.pop();
    }
    while(!maxpq.empty() && !vis[maxpq.top()] ){ // pq not empty && vis[top] == 0
        maxpq.pop();
    }
    if(minpq.empty() || maxpq.empty()){return {0,0};}
    return {maxpq.top(),minpq.top()};
}

int main(int argc, char** argv) {
    setup_io();

    for (auto& item : test_cases) {
        auto result_vector = solve(item);
        for (auto& i : result_vector) {
            std::cout << i << "  ";
        }
        std::cout << "\n";
    }

    return 0;
}