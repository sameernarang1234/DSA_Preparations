#include <bits/stdc++.h>

using namespace std;

int minJumpsUtil(int arr[], int n, int i, int jumps) {
    if (i >= n || arr[i] == 0) {
        return -1;
    }
    if (i == n-1) {
        return jumps;
    }
    int min = INT_MAX;
    for (int j = 1; j <= arr[i]; j++) {
        int jump = minJumpsUtil(arr, n, i+j, jumps+1);
        if (jump == -1) {
            continue;
        }
        if (jump < min) {
            min = jump;
        }
    }
    
    if (min == INT_MAX) {
        return -1;
    }
    return min;
}

int minJumps(int arr[], int n){
    return minJumpsUtil(arr, n, 0, 0);
}

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << minJumps(arr, 11) << endl;
    return 0;
}