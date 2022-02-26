#include <bits/stdc++.h>

using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long sum = arr[i];
        for (int j = i+1; j < n; j++) {
            if (arr[j] > 0) {
                sum += arr[j];
                continue;
            }
            if (arr[j] < 0 && j < n-1 && ((-1)*arr[j]) < arr[j+1]) {
                sum += arr[j];
                continue;
            }
            break;
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() {

    int arr1[] = {1,2,3,-2,5};
    int arr2[] = {-1,-2,-3,-4,-5};
    int arr3[] = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubarraySum(arr1, 5) << endl;
    cout << maxSubarraySum(arr2, 5) << endl;
    cout << maxSubarraySum(arr3, 9) << endl;

    return 0;
}