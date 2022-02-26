#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxGoldDP(vector<vector<int>> M) {
    int dp[M.size()][M[0].size()];

    
    for (int j = M[0].size() - 1; j >= 0; j--) {
        for (int i = 0; i < M.size(); i++) {
            if (j == M[i].size()-1) {
                dp[i][j] = M[i][j];
                continue;
            }
            if (i == 0 && i == M.size()-1) {
                dp[i][j] = M[i][j] + dp[i][j+1];
                continue;
            }
            if (i == 0) {
                dp[i][j] = M[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
                continue;
            }
            if (i == M.size()-1) {
                dp[i][j] = M[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
                continue;
            }
            dp[i][j] = M[i][j] + max(dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]);
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < M.size(); i++) {
        if (dp[i][0] > max) {
            max = dp[i][0];
        }
    }
    return max;
}

int maxGoldUtil(vector<vector<int>> M, int i, int j) {
    if ((i < 0 || i >= M.size()) || (j < 0 || j >= M[i].size())) {
        return 0;
    }

    if (j+1 < M[i].size()) {
        int max = M[i][j] + maxGoldUtil(M, i, j+1);
        if (i-1 >= 0) {
            int g1 = M[i][j] + maxGoldUtil(M, i-1, j+1);
            if (g1 > max) {
                max = g1;
            }
        }
        if (i+1 < M.size()) {
            int g2 = M[i][j] + maxGoldUtil(M, i+1, j+1);
            if (g2 > max) {
                max = g2;
            }
        }
        return max;
    }
    return M[i][j];
}

int maxGold(vector<vector<int>> M) {
    int max = INT_MIN;
    for (int i = 0; i < M.size(); i++) {
        int gold = maxGoldUtil(M, i, 0);
        if (gold > max) {
            max = gold;
        }
    }
    return max;
}

int main() {

    vector<vector<int>> mat = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
    
    cout << maxGold(mat) << endl;
    cout << maxGoldDP(mat) << endl;

    mat = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
    
    cout << maxGold(mat) << endl;
    cout << maxGoldDP(mat) << endl;

    mat = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
    
    cout << maxGold(mat) << endl;
    cout << maxGoldDP(mat) << endl;

    return 0;
}