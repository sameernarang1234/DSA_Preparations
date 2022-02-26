#include <bits/stdc++.h>

using namespace std;

bool givenSumSubset(int n, int arr[], int sum) {
    if (sum == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }

    return givenSumSubset(n-1, arr, sum-arr[n-1]) || givenSumSubset(n-1, arr, sum);
}

int givenSumSubsetMemoUtil(int n, int arr[], int sum, vector<vector<int>> &memo) {

    if (sum == 0) {
        return 1;
    }
    if (n == 0 || sum < 0) {
        return 0;
    }

    if (memo[n][sum] != -1) {
        return memo[n][sum];
    }

    memo[n][sum] = givenSumSubsetMemoUtil(n-1, arr, sum-arr[n-1], memo) || givenSumSubsetMemoUtil(n-1, arr, sum, memo);
    return memo[n][sum];
}

bool givenSumSubsetMemo(int n, int arr[], int sum) {
    vector<vector<int>> memo;
    for (int i = 0; i <= n; i++) {
        vector<int> v;
        for (int j = 0; j <= sum; j++) {
            v.push_back(-1);
        }
        memo.push_back(v);
    }
    return (givenSumSubsetMemoUtil(n, arr, sum, memo) == 1)? true : false;
}

bool givenSumSubsetDP(int n, int arr[], int sum) {
    int dp[n+1][sum+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (i == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
    }

    return (dp[n][sum] == 1)? true : false;
}

int main() {

    int arr1[] = {4, 1, 10, 12, 5, 2};
    int N = sizeof(arr1) / sizeof(arr1[0]);
    int sum = 9;

    cout << givenSumSubset(N, arr1, sum) << endl;
    cout << givenSumSubsetMemo(N, arr1, sum) << endl;
    cout << givenSumSubsetDP(N, arr1, sum) << endl;

    int arr2[] = {1, 8, 2, 5};
    N = sizeof(arr2) / sizeof(arr2[0]);
    sum = 4;

    cout << givenSumSubset(N, arr2, sum) << endl;
    cout << givenSumSubsetMemo(N, arr2, sum) << endl;
    cout << givenSumSubsetDP(N, arr2, sum) << endl;

    return 0;
}