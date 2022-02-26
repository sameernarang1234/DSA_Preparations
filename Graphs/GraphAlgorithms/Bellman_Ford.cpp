#include <bits/stdc++.h>

using namespace std;

int dfs(int **graph, int n, vector<bool> &visited, int sum, int curr, int prev) {
    visited[curr] = true;

    for (int i = 0; i < n; ++i) {
        if (graph[curr][i] != 0 && i != prev && visited[i]) {
            if (sum + graph[curr][i] < 0) {
                return 1;
            }
        }
        if (graph[curr][i] != 0 && !visited[i]) {
            if (dfs(graph, n, visited, sum+graph[curr][i], i, curr) != 0) {
                return 1;
            }
        }
    }

    return 0;
}

int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
    vector<bool> visited;
    for (int i = 0; i < n; ++i) {
        visited.push_back(false);
    }

    int **graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges.size(); ++i) {
        int start = edges[i][0];
        int end = edges[i][1];
        int wt = edges[i][2];

        graph[start][end] = wt;
        graph[end][start] = wt;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(graph, n, visited, 0, i, -1) != 0) {
            return 1;
        }
    }

    return 0;
}

int main() {

    vector<vector<int>> edges = {{0,1,-1},{1,2,-2},{2,0,-3}};

    cout << isNegativeWeightCycle(3, edges) << endl;

    vector<vector<int>> edges2 = {{0,1,-1},{1,2,-2},{2,0,3}};

    cout << isNegativeWeightCycle(3, edges2) << endl;

    return 0;
}