#include <bits/stdc++.h>

using namespace std;

int longestLengthPathUtil(vector<vector<int>> graph, vector<bool> &visited, vector<bool> &visited2, int curr) {
    visited[curr] = true;
    visited2[curr] = true;

    int max = 0;
    for (int i = 0; i < graph[curr].size(); i++) {
        if (graph[curr][i] != 0 && !visited2[i]) {
            int length = graph[curr][i] + longestLengthPathUtil(graph, visited, visited2, i);
            if (length > max) max = length;
        }
    }

    visited2[curr] = false;

    return max;
}

int longestLengthPath(vector<vector<int>> graph) {
    vector<bool> visited;
    int V = graph.size();
    for (int i = 0; i < V; i++) {
        visited.push_back(false);
    }

    vector<bool> visited2 = visited;
    int max = INT_MIN;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            int length = longestLengthPathUtil(graph, visited, visited2, i);
            if (length > max) {
                max = length;
            }
        }
    }

    return max;
}

// int pathMoreThanK(vector<vector<int>> graph, int K) {
//     vector<bool> visited;
//     int V = graph.size();
//     for (int i = 0; i < V; i++) {
//         visited.push_back(false);
//     }


//     for (int i = 0; i < V; i++) {
//         if (!visited[i]) {

//         }
//     }
// }

void createGraph(vector<vector<int>> &graph, vector<vector<int>> g) {
    for (int i = 0; i < g.size(); i++) {
        int start = g[i][0];
        int end = g[i][1];
        int wt = g[i][2];

        graph[start][end] = wt;
        graph[end][start] = wt;
    }
}

int main() {

    int V = 9;

    vector<vector<int>> graph;
    for (int i = 0; i < V; i++) {
        vector<int> v;
        for (int j = 0; j < V; j++) {
            v.push_back(0);
        }
        graph.push_back(v);
    }

    vector<vector<int>> g;

    g.push_back({0, 1, 4});
    g.push_back({0, 7, 8});
    g.push_back({1, 2, 8});
    g.push_back({1, 7, 11});
    g.push_back({2, 3, 7});
    g.push_back({2, 8, 2});
    g.push_back({2, 5, 4});
    g.push_back({3, 4, 9});
    g.push_back({3, 5, 14});
    g.push_back({4, 5, 10});
    g.push_back({5, 6, 2});
    g.push_back({6, 7, 1});
    g.push_back({6, 8, 6});
    g.push_back({7, 8, 7});

    createGraph(graph, g);

    cout << longestLengthPath(graph) << endl;

    return 0;
}