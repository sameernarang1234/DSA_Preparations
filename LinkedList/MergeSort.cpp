#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

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

void sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l+r)/2;
    sort(arr, l, mid);
    sort(arr, mid+1, r);

    merge(arr, l, mid, r);
}

Node* mergeSort(Node* head) {
    int size = 0;
    Node* curr = head;

    while (curr != NULL) {
        size++;
        curr = curr -> next;
    }

    int arr[size];
    curr = head;
    int index = 0;
    while (curr != NULL) {
        arr[index] = curr -> data;
        index++;
        curr = curr -> next;
    }

    sort(arr, 0, size-1);

    index = 0;
    curr = head;
    while (curr != NULL) {
        curr -> data = arr[index];
        index++;
        curr = curr -> next;
    }

    return head;
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(-1);
    Node* node3 = new Node(2);
    Node* node4 = new Node(-2);
    Node* node5 = new Node(3);
    Node* node6 = new Node(-3);
    Node* node7 = new Node(4);
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    node5 -> next = node6;
    node6 -> next = node7;

    node1 = mergeSort(node1);

    Node* temp = node1;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}