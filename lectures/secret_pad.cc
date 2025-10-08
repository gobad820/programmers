//
// Created by pelikan on 2025-05-21
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<int> v, q;
int input_iter, question_iter;

std::string binarySearch(const std::vector<int>& v, const int target) {
  auto left = 0u;
  if (v.empty()) return "큰돌이는 기억 못해!";
  auto right = v.size() - 1;

  while (left <= right) {
    auto mid = left + (right - left) / 2;
    if (v[mid] < target) {
      left = mid + 1;
    } else if (v[mid] > target) {
      right = mid - 1;
    } else {
      return "큰돌이는 기억해!";
    }
  }
  return "큰돌이는 까먹었어!";
}

std::vector<std::string> solution(std::vector<int>& v, std::vector<int>& q) {
  std::vector<std::string> answer;
  std::sort(v.begin(), v.end());
  for (const auto& target : q) {
    answer.emplace_back(binarySearch(v, target));
  }
  return answer;
}

void input() {
  std::cin >> input_iter;
  int t;
  while (input_iter--) {
    std::cin >> t;
    v.emplace_back(t);
  }
  std::cin >> question_iter;
  while (question_iter--) {
    std::cin >> t;
    q.emplace_back(t);
  }
}

int main(int argc, char* argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  input();
  std::vector<std::string> answer = solution(v, q);
  for (const auto& item : answer) {
    std::cout << item << '\n';
  }
  return 0;
}