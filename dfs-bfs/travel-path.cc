#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::string;
using std::vector;

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
// vector<vector<string>> t{{"ICN", "SFO"},
//                          {"ICN", "ATL"},
//                          {"SFO", "ATL"},
//                          {"ATL", "ICN"},
//                          {"ATL", "SFO"}};
vector<vector<string>> t {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK","HND"}};
vector<vector<string>> r;  // 현재 방문한 공항을 넣음
vector<string> tr;
int vis[20100];
vector<string> last_ticket;

// -----------------------------------------------------------

bool checkTicket(int ticket_size) {
    for (std::size_t i = 0; i < ticket_size; ++i) {
        if (!vis[i]) {
            return false;
        }
    }
    return true;
}

void go(string here) {
    if (checkTicket(t.size())) {  // 티켓을 모두 소진했다면
        r.emplace_back(tr);
        return;
    }

    for (std::size_t i = 0; i < t.size(); ++i) {
        if (t[i][0] == here && !vis[i]) {
            auto temp_ticket = t[i];
            if(!tr.empty()){
                tr.pop_back();
            }
            tr.emplace_back(t[i][0]);
            tr.emplace_back(t[i][1]);
            vis[i] = 1;
            last_ticket = t[i];
            go(t[i][1]);
            tr.pop_back();
            vis[i] = 0;
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 여기에 문제 풀이 코드를 작성하세요.
    string departure = "ICN";
    go(departure);
    std::sort(r.begin(), r.end());
    return r.front();
}

int main(int argc, char** argv) {
    setup_io();
    auto result = solution(t);
    std::cout << result.size() << "\n";
    for (auto& airport : result) {
        std::cout << airport << " ";
    }
    return 0;
}