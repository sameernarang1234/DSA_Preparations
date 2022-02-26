#include <bits/stdc++.h>

using namespace std;

void merge(vector<vector<int>> &arr, int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;

    vector<int> a1[n1];
    vector<int> a2[n2];

    for (int i = 0; i < n1; i++) {
        a1[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++) {
        a2[i] = arr[mid+1+i];
    }

    int i = 0; int j = 0; int k = l;
    while (i < n1 && j < n2) {
        if (a1[i][2] < a2[j][2]) {
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

void mergeSort(vector<vector<int>> &graph, int l, int r) {
    if (l >= r) {
        return;
    }

    int mid = (l+r)/2;
    mergeSort(graph, l, mid);
    mergeSort(graph, mid+1, r);

    merge(graph, l, mid, r);
}

vector<vector<int>> sort(vector<vector<int>> graph) {
    vector<vector<int>> res = graph;
    mergeSort(res, 0, res.size()-1);
    return res;
}

int findParent(int parent[], int child) {
    int par = child;
    while (par != parent[par]) {
        par = parent[par];
    }
    return par;
}

vector<vector<int>> KruskalMST(vector<vector<int>> graph) {
    int n = graph.size();
    vector<vector<int>> sortedGraph = sort(graph);

    vector<vector<int>> mst;

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int v1 = sortedGraph[i][0];
        int v2 = sortedGraph[i][1];
        int wt = sortedGraph[i][2];

        if (findParent(parent, v1) != findParent(parent, v2)) {
            mst.push_back(sortedGraph[i]);
            parent[v2] = v1;
        }
    }

    return mst;
}

int main() {

    vector<vector<int>> graph = {
        {0,1,4},
        {0,7,8},
        {1,7,11},
        {1,2,8},
        {2,8,2},
        {2,5,4},
        {2,3,7},
        {3,5,14},
        {3,4,9},
        {4,5,10},
        {5,6,2},
        {6,8,6},
        {6,7,1},
        {7,8,7}
    };

    vector<vector<int>> mst = KruskalMST(graph);

    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i][0] << " " << mst[i][1] << " " << mst[i][2] << endl;
    }

    return 0;
}