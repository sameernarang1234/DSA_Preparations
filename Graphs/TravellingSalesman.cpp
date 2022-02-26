#include <bits/stdc++.h>

using namespace std;

int tsp(int **graph, int V, int curr, int count, vector<bool> visited, int start) {
    visited[curr] = true;

    if (count == 1) {
        return graph[curr][start];
    }

    int minSum = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (graph[curr][i] != 0 && !visited[i]) {
            int sum = graph[curr][i];
            sum += tsp(graph, V, i, count-1, visited, start);
            if (sum < minSum) {
                minSum = sum;
            }
        }
    }

    return minSum;
}

int main() {

    int N, E;

    cin >> N >> E;

    int **graph = new int*[N];
    vector<bool> visited;
    for (int i = 0; i < N; i++) {
        graph[i] = new int[N];
        visited.push_back(false);
        for (int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int start, end, wt;

        cin >> start >> end >> wt;
        graph[start][end] = wt;
        graph[end][start] = wt;
    }

    int start;
    cin >> start;

    cout << tsp(graph, N, start, N, visited, start) << endl;

    return 0;
}