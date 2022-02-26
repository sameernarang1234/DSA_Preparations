#include <bits/stdc++.h>

using namespace std;

long long int coinChangeDP(int S[], int m ,int n) {
    int dp[n+1][m];
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int x = (i-S[j] >= 0)? dp[i-S[j]][j] : 0;
            int y = (j-1 >= 0)? dp[i][j-1] : 0;

            dp[i][j] = x + y;
        }
    }

    return dp[n][m-1];
}

long long int coinChangeRecursive(int S[], int m, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }
    if (m <= 0 && n >= 1) {
        return 0;
    }

    return coinChangeRecursive(S, m-1, n) + coinChangeRecursive(S, m, n-S[m-1]);
}

int main() {

    int n = 4, m = 3;
    int S1[] = {1,2,3};

    cout << coinChangeRecursive(S1,m,n) << endl;
    cout << coinChangeDP(S1,m,n) << endl;

    n = 10; m = 4; int S2[] = {2,5,3,6};

    cout << coinChangeRecursive(S2,m,n) << endl;
    cout << coinChangeDP(S2,m,n) << endl;

    return 0;
}