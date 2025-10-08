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
int n;
vector<string> v;
// -----------------------------------------------------------

vector<string> solution(const vector<string>& homework) {
    // 여기에 문제 풀이 코드를 작성하세요.
    vector<string> numbers;
    for (const auto& h : homework) {
        string tnum;
        for (const auto& c : h) {
            if (std::isdigit(c)) {
                tnum += c;
            } else {
                if (!tnum.empty()) {  
                    while (tnum.front() == '0' && tnum.size() > 1) {
                        tnum.erase(0,1);
                    }
                    numbers.emplace_back(tnum);
                    tnum.clear();
                }
            }
        }
        if (!tnum.empty()) {
            while (tnum.front() == '0' && tnum.size() > 1) {
                tnum.erase(0, 1);
            }
            numbers.emplace_back(tnum);
            tnum.clear();
        }
    }

    // 문자열의 숫자 비교
    std::sort(numbers.begin(), numbers.end(),
              [](const string& a, const string& b) {
                  if (a.size() == b.size()) {
                      return a < b;
                  }
                  return a.size() < b.size();
              });
    return numbers;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> n;
        string item;
        for (int i = 0; i < n; i++) {
            std::cin >> item;
            v.emplace_back(item);
        }
        auto answer = solution(v);
        for (const auto& item : answer) {
            std::cout << item << "\n";
        }
    }

    return 0;
}