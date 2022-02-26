#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    if (str1[m-1] == str2[n-1]) {
        return editDist(str1, str2, m-1, n-1);
    }

    return 1 + min(editDist(str1, str2, m-1, n-1), editDist(str1, str2, m-1, n), editDist(str1, str2, m, n-1));
}

int editDistMemoUtil(string str1, string str2, int m, int n, vector<vector<int>> &memo) {
    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (m == 0) {
        memo[m][n] = n;
        return memo[m][n];
    }
    if (n == 0) {
        memo[m][n] = m;
        return memo[m][n];
    }


    if (str1[m-1] == str2[n-1]) {
        memo[m][n] = editDistMemoUtil(str1, str2, m-1, n-1, memo);
        return memo[m][n];
    }

    memo[m][n] = 1 + min(editDistMemoUtil(str1, str2, m-1, n-1, memo), editDistMemoUtil(str1, str2, m, n-1, memo), editDistMemoUtil(str1, str2, m-1, n, memo));
    return memo[m][n];
}

int editDistMemo(string str1, string str2, int m, int n) {
    vector<vector<int>> memo;
    for (int i = 0; i <= m; i++) {
        vector<int> v;
        for (int j = 0; j <= n; j++) {
            v.push_back(-1);
        }
        memo.push_back(v);
    }

    return editDistMemoUtil(str1, str2, m, n, memo);
}

int editDistanceDP(string str1, string str2, int m, int n) {
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (j == 0) {
                dp[i][j] = i;
                continue;
            }
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main() {

    string s11 = "geek", s12 = "gesek";
    cout << editDist(s11, s12, s11.size(), s12.size()) << endl;
    cout << editDistMemo(s11, s12, s11.size(), s12.size()) << endl;
    cout << editDistanceDP(s11, s12, s11.size(), s12.size()) << endl;

    string s21 = "gfg", s22 = "gfg";
    cout << editDist(s21, s22, s21.size(), s22.size()) << endl;
    cout << editDistMemo(s21, s22, s21.size(), s22.size()) << endl;
    cout << editDistanceDP(s21, s22, s21.size(), s22.size()) << endl;


    return 0;
}