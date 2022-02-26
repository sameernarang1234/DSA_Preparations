#include <bits/stdc++.h>

using namespace std;

int equalSumSubsetRec(int N, int arr[], int s1, int s2) {
    if (N == 0) {
        if (s1 == s2) {
            return 1;
        }
        return 0;
    }
    if (s2 > s1) {
        return 0;
    }
    if (s2 == s1) {
        return 1;
    }

    return equalSumSubsetRec(N-1, arr, s1-arr[N-1], s2+arr[N-1]) || equalSumSubsetRec(N-1, arr, s1, s2);
}

int equalSumSubsetMemoUtil(int N, int arr[], int s1, int s2, int memo[]) {
    if (N == 0) {
        if (s1 == s2) {
            return 1;
        }
        return 0;
    }

    if (memo[N] != -1) {
        return memo[N];
    }

    if (s1 < s2) {
        memo[N] = 0;
        return 0;
    }
    if (s1 == s2) {
        memo[N] = 1;
        return 1;
    }

    memo[N] = equalSumSubsetMemoUtil(N, arr, s1-arr[N-1], s2+arr[N-1], memo) || equalSumSubsetMemoUtil(N-1, arr, s1, s2, memo);
    return memo[N];
}

int equalSumSubsetMemo(int N, int arr[], int s1, int s2) {
    int memo[N+1];
    for (int i = 0; i <= N; i++) {
        memo[i] = -1;
    }
    return equalSumSubsetMemoUtil(N, arr, s1, s2, memo);
}

int equalPartition(int N, int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return equalSumSubsetMemo(N, arr, sum, 0);
}

int main() {

    int N = 4;
    int arr1[] = {1, 5, 11, 5};
    cout << equalPartition(N, arr1) << endl;

    N = 3;
    int arr2[] = {1, 3, 5};
    cout << equalPartition(N, arr2) << endl;
    return 0;
}