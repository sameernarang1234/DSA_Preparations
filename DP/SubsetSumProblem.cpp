#include <bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> arr, int K, int n) {
    if (K == 0) {
        return 1;
    }
    if (K < 0) {
        return 0;
    }
    if (K > 0 && n == 0) {
        return 0;
    }

    return subsetSum(arr, K-arr[n-1], n-1) + subsetSum(arr, K, n-1);
}

int main() {

    int sum1 = 9;
    vector<int> arr1 = {4, 1, 10, 12, 5, 2};
    cout << subsetSum(arr1, sum1, arr1.size()) << endl;
    
    int sum2 = 4;
    vector<int> arr2 = {1, 8, 2, 5}
    ;
    cout << subsetSum(arr2, sum2, arr2.size()) << endl;

    return 0;
}