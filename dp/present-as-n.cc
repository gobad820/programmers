#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::set;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
// 숫자 N과 number가 주어질 때, N과 사칙연산만을 사용해서 표현할 수 있는 방법 중
// 사용회수의 최소값
int N, number;
map<int, set<long long>> dp;  // <숫자 사용 횟수, 만든 수의 조합>
string temp_str;
// 초기화, 기저조건, 메모이제이션, 로직
int dynamic() {
    dp[1].insert(N);
    for (int i = 2; i < 9; i++) {
        for (int j = 1; j < i; j++) {
            for (const auto& fst : dp[j]) {
                for (const auto& snd : dp[i - j]) {
                    dp[i].insert(fst + snd);
                    dp[i].insert(fst * snd);
                    dp[i].insert(fst - snd);
                    if (snd) {
                        dp[i].insert(fst / snd);
                    }
                }
            }
        }
        temp_str += std::to_string(N);
        dp[i].insert(std::stoll(temp_str));
        if (dp[i].count(number)) {
            return i;
        }
    }
    return -1;
}

// N을 count번 연결한 수 만들기 (N, NN, NNN...)
long long makeRepeatedN(int count) {
    long long result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + N;
    }
    return result;
}

// 올바른 Top-down DP 구현
set<long long> topDownDynamic(int count) {
    // 1. 기저조건 (Base Condition)
    if (count == 1) {
        return {N};  // N 하나만 사용 가능
    }
    if (count > 8 || count <= 0) {
        return {};  // 불가능한 경우
    }

    // 2. 메모이제이션 체크 (Memoization)
    if (dp.count(count)) {
        return dp[count];
    }

    // 3. 로직 (Logic) - 여기서 재귀 호출!
    set<long long> result;

    // 3-1. 사칙연산으로 조합
    for (int i = 1; i < count; i++) {
        auto leftSet = topDownDynamic(i);           // 🔄 재귀 호출!
        auto rightSet = topDownDynamic(count - i);  // 🔄 재귀 호출!

        for (const auto& left : leftSet) {
            for (const auto& right : rightSet) {
                result.insert(left + right);  // 덧셈
                result.insert(left - right);  // 빼기
                result.insert(right - left);  // 빼기 (순서 바꿈)
                result.insert(left * right);  // 곱셈

                if (right != 0) {
                    result.insert(left / right);  // 나누기
                }
                if (left != 0) {
                    result.insert(right / left);  // 나누기 (순서 바꿈)
                }
            }
        }
    }

    // 3-2. N을 count번 연결한 수 추가 (5, 55, 555...)
    result.insert(makeRepeatedN(count));

    // 4. 메모이제이션 저장 후 반환
    return dp[count] = result;
}

// Top-down으로 답 찾기
int findAnswerTopDown() {
    dp.clear();  // 초기화

    for (int count = 1; count <= 8; count++) {
        auto numbers = topDownDynamic(count);
        if (numbers.count(number) > 0) {
            return count;
        }
    }
    return -1;
}

// -----------------------------------------------------------

void solution(int N, int number) {
    // 여기에 문제 풀이 코드를 작성하세요.
    // Top-down 방식 사용
    std::cout << findAnswerTopDown();
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        std::cin >> N >> number;
        solution(N, number);
    }

    return 0;
}