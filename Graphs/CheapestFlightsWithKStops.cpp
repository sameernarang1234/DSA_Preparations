#include <bits/stdc++.h>

using namespace std;

void modifiedDikjstra(int **graph, int n, vector<int> &weights, int curr, int prev, int dst, int k, int &finalWt) {
    if (k < 0) {
        return;
    }

    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (graph[curr][i] != 0) {
            if (weights[curr]+graph[curr][i] < weights[i]) {
                weights[i] = weights[curr]+graph[curr][i];
            }
            if (i == dst && weights[dst] < finalWt) {
                finalWt = weights[dst];
                continue;
            }
            modifiedDikjstra(graph, n, weights, i, curr, dst, k-1, finalWt);
            if (finalWt == INT_MAX) {
                weights[i] = INT_MAX;
            }
        }
    }
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    int **graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < flights.size(); i++) {
        int start = flights[i][0];
        int end = flights[i][1];
        int wt = flights[i][2];

        graph[start][end] = wt;
    }
    
    vector<int> weights;
    for (int i = 0; i < n; i++) {
        weights.push_back(INT_MAX);
    }

    weights[src] = 0;

    int dstWt = INT_MAX;
    modifiedDikjstra(graph, n, weights, src, -1, dst, k, dstWt);

    if (dstWt == INT_MAX) {
        return -1;
    }
    return dstWt;
}

int main() {

    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3;
    int src = 0, dst = 2, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    flights = {{0,1,100},{1,2,100},{0,2,500}};
    n = 3;
    src = 0; dst = 2; k = 0;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    n = 4;
    src = 0; dst = 3; k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}