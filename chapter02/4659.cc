#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::set;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
set<char> vowel{'a', 'e', 'i', 'o', 'u'};
void sayNo(string p) { std::cout << "<" << p << "> is not acceptable.\n"; }
void sayYes(string p) { std::cout << "<" << p << "> is acceptable.\n"; }
// -----------------------------------------------------------

void solution(vector<string> passwords) {
    for (auto& p : passwords) {
        int vowel_count = 0;
        for(int i = 0 ; i < p.size() ; i++){
            if(vowel.count(p[i])){
                vowel_count++;
            }
        }

        for (; i < p.size(); i++) {
            if (vowel.count(p[i])) {
                break;
            }
        }
        if (i == p.size()) {
            sayNo(p);
            continue;
        }
        bool flag2 = false;
        for (int i = 1; i < p.size(); i++)
            if (p[i] == p[i - 1] && p[i] != 'o' && p[i] != 'e') {
                sayNo(p);
                flag2 = true;
                break;
            }
        if (flag2) {
            continue;
        }
        vector<int> temp;
        for (int i = 0; p.size() >= 3 && i < p.size(); i++) {
            temp.emplace_back(vowel.count(p[i]));
            if (temp.size() > 3) {
                temp.erase(temp.begin());
            }
            if (temp.size() == 3 && temp[0] == temp[1] && temp[0] == temp[2]) {
                sayNo(p);
                flag2 = true;
                break;
            }
        }
        if (flag2) {
            continue;
        }
        sayYes(p);
    }
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    while (t--) {
        vector<string> passwords;
        string p;
        while (true) {
            std::cin >> p;
            if (p == "end") {
                break;
            }
            passwords.emplace_back(p);
        }
        solution(passwords);
    }

    return 0;
}