#include <bits/stdc++.h>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    if (n <= 0 || W <= 0) {
        return 0;
    }
    
    int x = 0;
    if (W >= wt[n-1])
        x = val[n-1] + knapsack(W-wt[n-1], wt, val, n-1);
    int y = knapsack(W, wt, val, n-1);

    if (x > y) return x;
    return y;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsackDP(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (j >= wt[i-1])
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main() {

    int N = 3, W = 4, values1[] = {1,2,3}, weight1[] = {4,5,1};
    cout << knapsack(W, weight1, values1, N) << endl;
    cout << knapsackDP(W, weight1, values1, N) << endl;

    N = 3; W = 3; int values2[] = {1,2,3}, weight2[] = {4,5,6};
    cout << knapsack(W, weight2, values2, N) << endl;
    cout << knapsackDP(W, weight2, values2, N) << endl;

    return 0;
}