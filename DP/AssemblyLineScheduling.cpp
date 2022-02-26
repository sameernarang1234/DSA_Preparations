#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int schedulingDP(vector<vector<int>> a, vector<vector<int>> t, vector<int> e, vector<int> x) {
    int n = a[0].size(); 
    int dp[n];

    int index = a[0].size()-1;
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) {
            dp[i] = min(a[0][i]+x[0], a[1][i]+x[1]);
            continue;
        }
        if (i == 0) {
            dp[i] = dp[i+1] + min(e[0]+a[0][i], e[1]+a[1][i]);
            continue;
        }
        dp[i] = dp[i+1] + min(a[0][i], a[1][i], a[0][i]+t[0][i+1], a[1][i]+t[1][i+1]);
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[0];
}

int schedulingUtil(vector<vector<int>> a, vector<vector<int>> t, vector<int> x, int line, int curr) {
    if (curr == a[line].size()-1) {
        return a[line][curr] + x[line];
    }

    int newline = (line == 0)?1:0;

    int t1 = a[line][curr] + t[line][curr+1] + schedulingUtil(a, t, x, newline, curr+1);
    int t2 = a[line][curr] + schedulingUtil(a, t, x, line, curr+1);

    return min(t1, t2);
}

int scheduling(vector<vector<int>> a, vector<vector<int>> t, vector<int> e, vector<int> x) {
    int t1 = e[0] + schedulingUtil(a, t, x, 0, 0);
    int t2 = e[1] + schedulingUtil(a, t, x, 1, 0);
    return min(t1, t2);
}

int main() {

    vector<vector<int>> a = {{4, 5, 3, 2}, 
                            {2, 10, 1, 4}}; 
    vector<vector<int>> t = {{0, 7, 4, 5}, 
                            {0, 9, 2, 8}}; 
    vector<int> e = {10, 12}, x = {18, 7}; 
  
    cout << scheduling(a, t, e, x) << endl;
    cout << schedulingDP(a, t, e, x) << endl;

    return 0;
}