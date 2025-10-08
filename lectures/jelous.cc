//
// Created by pelikan on 2025-05-21
//

#include <bits/stdc++.h>

/*
 * N명의 친구들과 M가지 서로 다른 색상 중 하나를 가진 형광펜을 나눈다.
 * 각 친구는 한 가지 색상의 형광펜을 가질 수 있으며, 여러 색상 형광펜 동시에 갖는건 불가능
 * 큰돌은 질투심(갖고 있는 형관펜의 수)을 최소화
 * 질투심이 최소가 되도록 형광펜을 친구들에게 나눠주는 프로그램
 * 모든 형광펜을 다 나눠주어야 하며 형관펜을 받지 못하는 학생은 있어 노상관
 *
 */
std::size_t n, m, result = SIZE_T_MAX;
std::vector<std::size_t> arr;


bool search(std::size_t estimate_val) {
    std::size_t ret = 0;
    for (std::size_t i = 0; i < m; i++) {
        ret += arr[i] / estimate_val;
        if (arr[i] % estimate_val) ret++;
    }
    return ret <= n;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    std::size_t left = 1u, right = 0u, mid;

    for (std::size_t i = 0; i < m; i++) {
        std::cin >> arr[i];
        right = std::max(right, arr[i]);
    }

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (search(mid)) {
            result = std::min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    std::cout << result << "\n";
    return 0;
}
