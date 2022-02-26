#include <bits/stdc++.h>

using namespace std;

int lcsRecursive(string str1, string str2, int n, int m) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (str1[n-1] == str2[m-1]) {
        return 1 + lcsRecursive(str1, str2, n-1, m-1);
    }

    return max(lcsRecursive(str1, str2, n, m-1), lcsRecursive(str1, str2, n-1, m));
}

int lcsMemoUtil(string str1, string str2, int n, int m, vector<vector<int>> &memo) {
    if (n == 0 || m == 0) {
        memo[n][m] == 0;
        return 0;
    }

    if (memo[n][m] != -1) {
        return memo[n][m];
    }

    if (str1[n-1] == str2[m-1]) {
        return 1 + lcsMemoUtil(str1, str2, n-1, m-1, memo);
    }

    return max(lcsMemoUtil(str1, str2, n-1, m, memo), lcsMemoUtil(str1, str2, n, m-1, memo));
}

int lcsMemo(string str1, string str2, int n, int m) {
    vector<vector<int>> memo;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < m; j++) {
            v.push_back(-1);
        }
        memo.push_back(v);
    }

    return lcsMemoUtil(str1, str2, n, m, memo);
}

int main() {
    return 0;
}