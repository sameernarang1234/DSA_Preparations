#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int fibMemoUtil(int n, vector<int> &memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibMemoUtil(n-1, memo) + fibMemoUtil(n-2, memo);
    return memo[n];
}

int fibonacciMemo(int n) {
    vector<int> memo;
    for (int i = 0; i <= n; i++) {
        memo.push_back(-1);
    }
    return fibMemoUtil(n, memo);
}

int fibonacciDP(int n) {
    int dp[n+1];

    for (int i = 0; i <= n; i++) {
        if (i <= 1) {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {

    cout << fibonacci(10) << endl;
    cout << fibonacciMemo(10) << endl;
    cout << fibonacciDP(10) << endl;

    return 0;
}