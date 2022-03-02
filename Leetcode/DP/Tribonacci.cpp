#include <bits/stdc++.h>

using namespace std;

int tribonacciDP(int n) {
    int dp[n+1];

    for (int i = 0; i <= n; i++) {
        if (i <= 1) {
            dp[i] = i;
            continue;
        }
        if (i == 2) {
            dp[i] = 1;
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {

    cout << tribonacciDP(4) << endl;
    cout << tribonacciDP(25) << endl;

    return 0;
}