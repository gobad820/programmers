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

// -----------------------------------------------------------

vector<int> solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    const int d_size = 9;
    vector<int> dwarfs(d_size);
    for (int& dwarf : dwarfs) {
        std::cin >> dwarf;
    }
    int sum = std::accumulate(dwarfs.begin(), dwarfs.end(), 0);
    for (int i = 0; i < d_size && dwarfs.size() == d_size; i++) {
        for (int j = 0; j < d_size; j++) {
            if (sum - (dwarfs[i] + dwarfs[j]) == 100 && i != j) {
                auto first_it = dwarfs.begin() + std::max(i, j);
                auto second_it = dwarfs.begin() + std::min(i, j);
                dwarfs.erase(first_it);
                dwarfs.erase(second_it);
                break;
            }
        }
    }
    std::sort(dwarfs.begin(), dwarfs.end());
    return dwarfs;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        auto answer = solution();
        for (const auto& dwarf : answer) {
            std::cout << dwarf << "\n";
        }
    }

    return 0;
}