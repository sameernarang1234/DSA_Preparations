#include <bits/stdc++.h>

using namespace std;

int friendsPairings(int n) {
    int ways = 1;
    if (n >= 1) {
        ways = friendsPairings(n-1);
    }
    if (n >= 2) {
        ways += (n-1) * friendsPairings(n-2);
    }

    return ways;
}

int friendsPairingsMemoUtil(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n];
    }
    
    int ways = 1;

    if (n >= 1) {
        ways = friendsPairingsMemoUtil(n-1, memo);
    }
    if (n >= 2) {
        ways += (n-1) * friendsPairingsMemoUtil(n-2, memo);
    }

    memo[n] = ways;
    return ways;
}

int friendsPairingsMemo(int n) {
    int memo[n+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    return friendsPairingsMemoUtil(n, memo);
}

int friendsPairingsDP(int n) {
    int dp[n+1];

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            dp[i] = 1;
            continue;
        }
        if (i >= 2) {
            dp[i] = dp[i-1] + (i-1) * dp[i-2];
            continue;
        }
        dp[i] = dp[i-1];
    }

    return dp[n];
}

int main() {

    cout << friendsPairings(3) << endl;
    cout << friendsPairingsMemo(3) << endl;
    cout << friendsPairingsDP(3) << endl;

    return 0;
}