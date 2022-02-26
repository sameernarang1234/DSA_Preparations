#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n*fact(n-1);
}

int BinomialCoeff(int n, int r) {
    if (n < r && n == 0) {
        return 0;
    }
    if (n == r || r == 0) {
        return 1;
    }

    int dp[n+1][r+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= r; j++) {
            if (i < j || i == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (i == j || j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    return dp[n][r];
}

int PermutationCoefficient(int n, int r) {
    int factR = fact(r);
    int nCr = BinomialCoeff(n, r);

    return factR*nCr;
}

int main() {

    cout << PermutationCoefficient(10, 2) << endl;
    cout << PermutationCoefficient(10, 3) << endl;
    cout << PermutationCoefficient(10, 0) << endl;
    cout << PermutationCoefficient(10, 1) << endl;

    return 0;
}