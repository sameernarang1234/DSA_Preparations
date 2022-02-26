#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    
    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++) {
        a1[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++) {
        a2[i] = arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            arr[k] = a1[i];
            k++; i++;
        }
        else {
            arr[k] = a2[j];
            k++; j++;
        }
    }
    while (i < n1) {
        arr[k] = a1[i];
        k++; i++;
    }
    while (j < n2) {
        arr[k] = a2[j];
        k++; j++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
}

int findDuplicate(vector<int> nums) {
    mergeSort(nums, 0, nums.size()-1);

    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] == nums[i+1]) {
            return nums[i];
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1,3,4,2,2};

    cout << findDuplicate(arr) << endl;
}