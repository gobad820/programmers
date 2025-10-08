//
// Created by pelikan on 2025-05-22
//

#include <algorithm>
#include <iostream>
#include <vector>
int n, number_of_highlighters, ret = INT32_MIN, idx;
std::vector<int> a(1001), v;
int prev_list[1100], cnt[1100];

void go(int idx) {
    if (idx == -1) {
        return;
    }
    v.emplace_back(a[idx]);
    go(prev_list[idx]);
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    for (auto i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::fill(std::begin(prev_list), std::end(prev_list), -1);
    std::fill(std::begin(cnt), std::end(cnt), 1);
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < i; ++j) {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }
    go(idx);
    std::reverse(v.begin(), v.end());
    for (const auto &item : v) {
        std::cout << item << " ";
    }
    return 0;
}
