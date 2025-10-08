#include <bits/stdc++.h>

// 자주 사용하는 네임스페이스 및 타입 별칭
using std::map;
using std::string;
using std::vector;

// 입출력 속도 향상
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// ------------------- 전역 변수, 함수 등 선언 -------------------
int n;
vector<vector<int>> tree(60);
int answer = 0;
void deleteNode(int node) {
    if (tree[node].empty()) {
        return;
    }
    for (auto& item : tree[node]) {
        deleteNode(item);
    }
    tree[node].clear();
}

void checkLeafNode(int node) {
    if (tree[node].empty()) {
        answer++;
        return;
    }
    for (auto& item : tree[node]) {
        checkLeafNode(item);
    }
}
// -----------------------------------------------------------

void solution() {
    // 여기에 문제 풀이 코드를 작성하세요.
    std::cin >> n;
    int node;
    int root = -1; // root가 항상 0번 노드라는 보장이 없음
    for (int i = 0; i < n; i++) {
        std::cin >> node;
        if (node == -1) {
            root = i;
            continue;
        }
        tree[node].emplace_back(i);
    }
    int m;
    std::cin >> m;
    if (m == root) {
        answer = 0;
    } else {
        deleteNode(m);
        for (int i = 0; i < n; i++) {
            if (tree[i].empty()) {
                continue;
            }
            if (tree[i].front() == m) {
                tree[i].erase(tree[i].begin());
                break;
            } else if (tree[i].back() == m) {
                tree[i].erase(tree[i].end() - 1);
                break;
            }
        }
        checkLeafNode(root);
    }
    std::cout << answer;
}

int main(int argc, char** argv) {
    setup_io();

    int t = 1;
    // cin >> t; // 여러 테스트 케이스를 위한 코드
    while (t--) {
        solution();
    }

    return 0;
}