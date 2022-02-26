#include <bits/stdc++.h>

using namespace std;

int findMin(int arr[], int N, bool visited[]) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] < min && !visited[i]) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prepareGraphMatrix(vector<vector<int>> graph, int N, int** graphMatrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graphMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        int start = graph[i][0];
        int end = graph[i][1];
        int wt = graph[i][2];

        graphMatrix[start][end] = wt;
        graphMatrix[end][start] = wt;
    }
}

void PrimMST(vector<vector<int>> graph, int V) {

    for (int i = 0; i < graph.size(); i++) {
        cout << graph[i][0] << " " << graph[i][1] << " " << graph[i][2] << endl;
    }

    cout << endl;

    int **graphMatrix = new int*[V];

    for (int i = 0; i < V; i++) {
        graphMatrix[i] = new int[V];
    }

    prepareGraphMatrix(graph, V, graphMatrix);
    
    bool visited[V];
    int weights[V];
    int parent[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for (int i = 0; i < V-1; i++) {
        int minIndex = findMin(weights, V, visited);
        if (minIndex < 0) {
            break;
        }
        visited[minIndex] = true;
        for (int j = 0; j < V; j++) {
            if (graphMatrix[minIndex][j] > 0 && !visited[j] && graphMatrix[minIndex][j] < weights[j]) {
                weights[j] = graphMatrix[minIndex][j];
                parent[j] = minIndex;
            }
        }
        // for (int j = 0; j < V; j++) {
        //     cout << weights[j] << " ";
        // }
        // cout << endl;
        // for (int j = 0; j < V; j++) {
        //     cout << parent[j] << " ";
        // }
        // cout << endl << endl;
    }

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " " << i << " " << weights[i] << endl; 
    }
    
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

    PrimMST(graph, 9);

    return 0;
}