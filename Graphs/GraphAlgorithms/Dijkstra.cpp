#include <bits/stdc++.h>
#include <vector>

using namespace std;

int findLeast(int V, int* arr, vector<bool> visited, int* result) {
    int min = INT_MAX;
    int minNode = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && arr[i] > 0 && result[i] < min) {
            min = arr[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstraUtil(int V, int **graph, int curr, int* result, vector<bool> &visited) {
    visited[curr] = true;

    for (int i = 0; i < V; i++) {
        if (graph[curr][i] > 0 && !visited[i]) {
            if (result[curr]+graph[curr][i] < result[i]) {
                result[i] = result[curr]+graph[curr][i];
            }
        }
    }

    int next = findLeast(V, graph[curr], visited, result);
    if (next != -1)
        dijkstraUtil(V, graph, next, result, visited);
}

void dijkstra(int V, int **graph, int S, int* result) {
    for (int i = 0; i < V; i++) {
        result[i] = INT_MAX;
    }
    result[S] = 0;
    vector<bool> visited;
    for (int i = 0; i < V; i++) {
        visited.push_back(false);
    }

    dijkstraUtil(V, graph, S, result, visited);
}

int main() {
    int N, E;
    cin >> N >> E;

    int **graph = new int*[N];
    for (int i = 0; i < N; i++) {
        graph[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
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

    int S;
    cin >> S;

    int *minTree = new int[N];

    dijkstra(N, graph, S, minTree);

    for (int i = 0; i < N; i++) {
        cout << minTree[i] << " ";
    }
    cout << endl;
    return 0;
}