#include <iostream>
#include <vector>
#include <stack>

std::vector<int> anyBiggerElement(std::vector<int> numbers)
{
    std::stack<int> stk;
    std::vector<int> answer(numbers.size(),-1);
    for (size_t i = 0; i < numbers.size(); i++)
    {
        while (!stk.empty() && numbers[stk.top()] < numbers[i])
        {
            answer[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.emplace(i);
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> numbers{2, 1, 2, 4, 3, 1};
    auto result = anyBiggerElement(numbers);
    for (auto &i : result)
    {
       std::cout << i << " "; 
    }
    return 0;
}
