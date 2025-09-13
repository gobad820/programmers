#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> arr{3,1, 2};

bool stackMaker(int max_num) {
    std::stack<int> stk;
    int j = 0,i = 1;
    while(i <= max_num){
        stk.emplace(i++);
        while(!stk.empty() && stk.top() == arr[j]){
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}

int main(int argc, char const* argv[]) {
    /* code */
    auto result = stackMaker(*std::max_element(arr.begin(), arr.end())) == true
                      ? "YES"
                      : "NO";
    std::cout << result << "\n";

    return 0;
}
