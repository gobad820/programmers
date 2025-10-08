//
// Created by pelikan on 2025-05-23
//

/*
 * 장점: LIS의 길이는 빠르게 O(NlgN)으로 찾을 수 있음
 * 단점: 원본 배열이 회손됨 -> trace가 되지 않음
 *      => trace가 필요할 때는 O(N^2)의 방법을 사용해야 함
 *
 *//

#include <iostream>
int n, lis[1001], length, num;

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    // NLogN으로 최대 증가 부분 수열을 찾을 수 있음
    for (auto i = 0; i < n; ++i) {
        std::cin >> num;
        // std::lower_bound return less value than target from [lis,lis+length)
        auto lower_pos = std::lower_bound(lis, lis + length, num);
        if (*lower_pos == 0) { length++; }
        *lower_pos = num;
        std::cout << *lower_pos <<"\n";
        for (auto j = 0; j < n; ++j) {
            std::cout << lis[j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << length << "\n";
    return 0;
}
