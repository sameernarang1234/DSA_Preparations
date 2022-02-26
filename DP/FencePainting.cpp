#include <bits/stdc++.h>

using namespace std;

long long countWaysUtil(int n, int k, vector<int> fence, int nextColor) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    long long ways = 0;
    for (int i = 0; i < k; i++) {
        if (i != nextColor) {
            fence[n-1] = i;
            ways += countWaysUtil(n-1, k, fence, i);
            fence[n-2] = i;
            ways += countWaysUtil(n-2, k, fence, i);
        }
    }
    return ways;
}

long long countWays(int n, int k) {
    vector<int> fence;
    for (int i = 0; i < n; i++) {
        fence.push_back(-1);
    }
    return countWaysUtil(n, k, fence, -1);
}

int main() {

    cout << countWays(2, 3) << endl;

    return 0;
}