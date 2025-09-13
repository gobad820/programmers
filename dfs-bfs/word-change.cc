#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using str = std::string;
using vs = std::vector<str>;
using vc = std::vector<char>;

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
str begin = "hit", target = "cog";
// vs words = {"hot", "dot", "dog", "lot", "log"};
vs words = {"hot", "dot", "dog", "lot", "log", "cog"};
// 각 자리수마다 해당 알파벳을 vector 또는 map으로 넣는다?
int result = INT32_MAX;
std::map<str, int> vis;
// -----------------------------------------------------------

bool checkWord(const str& f, const str& s) {
    if (f.size() != s.size()) {
        return false;
    }
    int check = 0;
    for (std::size_t i = 0; i < f.size(); ++i) {
        if (f[i] != s[i]) {
            check++;
        }
    }
    return check == 1;
}

void go(int here, str here_str) {
    if (here_str == target) {
        result = std::min(result, here);
        return;
    }
    for (auto& item : words) {
        if(vis[item] || !checkWord(here_str,item)){continue;}
        vis[item]++;
        go(here+1,item);
        vis[item]--;
    }
    return;
}


int solution(str begin, str target, vs words) {
    go(0, begin);
    if (result == INT32_MAX) return 0;
    return result;
}

int main(int argc, char** argv) {
    setup_io();
    std::cout << solution(begin, target, words);
    return 0;
}