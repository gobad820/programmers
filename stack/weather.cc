#include <iostream>
#include <vector>
#include <stack>
std::vector<int> answer(8);
std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
{
    std::stack<int> stk;
    for (int i = 0; i < temperatures.size(); i++){
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
            answer[stk.top()] = (i-stk.top());
            stk.pop();
        }
        stk.emplace(i);
    }
    return answer;
}


int main(int argc, char const *argv[])
{
    std::vector<int> tmp{73, 74, 75, 71, 69, 72, 76, 73};
    auto ans = dailyTemperatures(tmp);
    for (auto &i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}
