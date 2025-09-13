#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
// 자주 사용하는 네임스페이스 및 타입 별칭
using ll = long long;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using ms = std::multiset<int, std::greater<int>>;
using str = std::string;
using vs = std::vector<str>;
using vvs = std::vector<vs>;
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
// -----------------------------------------------------------

std::optional<int> safe_stoi(const str& s) {
    try {
        return std::stoi(s);
    } catch (...) {
        return std::nullopt;
    }
}

std::vector<int> solution(std::vector<std::string> operations) {
    ms pq;
    // 여기에 문제 풀이 코드를 작성하세요.
    for (const auto& o : operations) {
        if (o.length() < 3) {
            continue;
        }
        auto oper = o.front();
        auto number_part = o.substr(2);
        auto result = safe_stoi(number_part);
        if (!result.has_value()) {
            continue;
        }
        int number = result.value();
        if (oper == 'I') {
            pq.insert(number);
        } else if (oper == 'D') {
            if (number == -1) {
                pq.extract(*pq.crbegin());
            } else if (number == 1) {
                pq.extract(*pq.cbegin());
            }
        } else {
            continue;
        }
    }
    if (pq.empty()) {
        return {0, 0};
    }
    return {*pq.cbegin(), *pq.crbegin()};
}

int main(int argc, char** argv) {
    setup_io();
    for (auto& item : test_cases) {
        auto result_vector = solution(item);
        for (auto& i : result_vector) {
            std::cout << i << "  ";
        }
        std::cout << "\n";
    }

    return 0;
}