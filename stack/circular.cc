#include <iostream>
#include <stack>
#include <vector>

std::vector<int> circ{5,5,5,5};
std::vector<int> solution(std::vector<int> c){
    std::vector<int> answer(circ.size() , -1);
    std::stack<int> stk;
    for (size_t i = 0; i < c.size() * 2; i++)
    {
        while (!stk.empty() && c[stk.top()] < c[i%c.size()]){
            answer[stk.top()] = c[i%c.size()];
            stk.pop();
        }
        stk.emplace(i%c.size());
    }
    return answer;
}

int main(int argc, char const *argv[]){
    auto result = solution(circ);
    for (auto &i : result)
    {
        std::cout << i << " ";
    }

    return 0;
}
