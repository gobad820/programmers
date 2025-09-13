#include <iostream>
#include <stack>

bool isValid(std::string s)
{
    std::stack<char> stk;
    for (auto &item : s)
    {
        if (item == '(' || item == '[' || item == '{')
        {
            stk.emplace(item);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main(int argc, char const *argv[])
{
    std::string s;
    std::cin >> s;
    std::cout << isValid(s) << std::endl;
    std::cout << "TESTING";
    return 0;
}
