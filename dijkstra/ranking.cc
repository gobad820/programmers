#include <bits/stdc++.h>

using std::vector;

int dist[150][150];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = INT_MAX;  // No Edge
        }
    }

    for (const auto& game : results) {
        int winner = game.front();
        int looser = game.back();
        dist[winner][looser] = 1;
        dist[looser][winner] = -1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                } else if (dist[i][k] == -1 && dist[k][j] == -1) {
                    dist[i][j] = -1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (std::find(std::begin(dist[i]), std::end(dist[i]), INT_MAX) ==
            std::end(dist[i])) {
            answer++;
        }
    }
    return answer;
}