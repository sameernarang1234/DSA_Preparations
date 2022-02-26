#include <bits/stdc++.h>

using namespace std;

long long maxSum(int arr[], int n, int i) {
    if (i == n-1) {
        if (arr[i] < 0) {
            return 0;
        }
        return arr[i];
    }

    long long sum1 = arr[i] + maxSum(arr, n, i+1);
    long long sum2 = maxSum(arr, n, i+1);

    if (sum1 > sum2) {
        return sum1;
    }
    return sum2;
}

long long maxSubarraySum(int arr[], int n) {
    return maxSum(arr, n, 0);
}

int main() {
    int arr[] = {1,2,3,-2,5};
    cout << maxSubarraySum(arr, 5) << endl;
    return 0;
}