#include <bits/stdc++.h>

using namespace std;

int BinomialCoeffDP(int n, int r) {
    if (n < r || n == 0) {
        return 0;
    }
    int dp[n+1][r+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= r; j++) {
            if (i == 0 || i < j) {
                dp[i][j] = 0;
            }
            else if (j == 0 || i == j) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    return dp[n][r];
}

int main() {

    cout << BinomialCoeffDP(3, 2) << endl;

    return 0;
}