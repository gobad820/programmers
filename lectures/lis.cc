//
// Created by pelikan on 2025-05-22
//

#include <iostream>
#include <vector>
#include <algorithm>
unsigned int n, t, cnt[1050], ret = 0u;
std::vector<int> a,v;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    while (n--) {
        std::cin >> t;
        a.emplace_back(t);
    }
    v.emplace_back(a[0]);
    for (auto it = a.begin(); it != a.end(); ++it) {
        auto max_value = 0u;
        for (auto in = a.begin(); in < it; ++in) {
            if (*in < *it && cnt[in-a.begin()] <cnt[it-a.begin()]) {
                std::cout << *in << " ";
                if (std::find(v.begin(), v.end(), *in) == v.end()) {
                    v.emplace_back(*in);
                }
                max_value++;
            }
        }
        std::cout << "\n";
        cnt[it-a.begin()] = ++max_value;
        ret = std::max(cnt[it - a.begin()], ret);
    }
    for (const auto& item: v) {
        std::cout << item << " ";
    }
    return 0;
}
