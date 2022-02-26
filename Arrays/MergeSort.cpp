#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int r) {
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

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
}

int main() {

    int arr[] = {1,-1,2,-2,3,-3,4,-4,5,-5,6,-6,7,-7,8,-8,9,-9};

    mergeSort(arr, 0, 17);

    for (int i = 0; i < 18; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}