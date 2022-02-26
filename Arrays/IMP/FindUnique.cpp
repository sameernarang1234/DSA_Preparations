#include <bits/stdc++.h>

using namespace std;

int findUnique(vector<int> arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        res ^= arr[i];
    }
    return res;
}

int main() {

    vector<int> arr = {1,2,3,4,5,6,1,2,3,4,5,6,7};

    cout << findUnique(arr) << endl;

    return 0;
}