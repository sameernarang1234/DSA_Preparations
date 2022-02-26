#include <bits/stdc++.h>

using namespace std;

int MatrixChainOrder(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k+1, j) + p[i-1]*p[k]*p[j];
        if (count < min) {
            min = count;
        }
    }

    return min;
}

int MatrixChainOrderMemoUtil(int p[], int i, int j, vector<vector<int>> &memo) {
    if (i == j) {
        memo[i][j] = 0;
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        int count = MatrixChainOrderMemoUtil(p, i, k, memo) + MatrixChainOrderMemoUtil(p, k+1, j, memo) + p[i-1]*p[k]*p[j];
        if (count < min) {
            min = count;
        }
    }

    memo[i][j] = min;
    return min;
}

int MatrixChainOrderMemo(int p[], int start, int size) {
    vector<vector<int>> memo;
    for (int i = 0; i <= size; i++) {
        vector<int> v;
        for (int j = 0; j <= size; j++) {
            v.push_back(-1);
        }
        memo.push_back(v);
    }

    return MatrixChainOrderMemoUtil(p, start, size, memo);
}

int MatrixChainOrderDP(int p[], int start, int size) {
    if (start == size) {
        return 0;
    }

    int dp[size+1][size+1];
    for (int i = start; i <= size; i++) {
        for (int j = start; j <= size; j++) {
            if (i >= j) {
                dp[i][j] = 0;
                continue;
            }
            int min = INT_MAX;
            for (int k = i; k < j; k++) {
                int count = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if (count < min)
                    min = count;
            }
            dp[i][j] = min;
        }
    }

    return dp[start][size];
}

int main() {

    int arr[] = { 1, 2, 3, 4, 3 };
    int size = 5;

    cout << MatrixChainOrder(arr, 1, size-1) << endl;
    cout << MatrixChainOrderMemo(arr, 1, size-1) << endl;
    cout << MatrixChainOrderDP(arr, 1, size-1) << endl;

    return 0;
}