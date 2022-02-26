#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

void dfs(vector<vector<int>> graph, int curr, vector<bool> &visited, map<int, bool> &vertices) {
    visited[curr] = true;
    vertices[curr] = true;
    if (graph[curr].empty()) {
        return;
    }

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next]) {
            dfs(graph, next, visited, vertices);
        }
    }
}

pair<int, int> countConnections(vector<vector<int>> graph, int start, vector<bool> &visited) {
    int N = graph.size();


    map<int, bool> vertices;
    dfs(graph, start, visited, vertices);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (vertices.find(i) != vertices.end()) {
            count += graph[i].size();
        }
    }

    return pair<int, int>(count/2, vertices.size());
}

int makeConnected(int n, vector<vector<int>> &connections) {
    vector<bool> visited;

    for (int i = 0; i < n; ++i) {
        visited.push_back(false);
    }

    vector<vector<int>> graph;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        graph.push_back(v);
    }
    for (int i = 0; i < connections.size(); i++) {
        int start = connections[i][0];
        int end = connections[i][1];
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int excess = 0;
    int islands = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            islands++;
            pair<int, int> data = countConnections(graph, i, visited);
            excess += (data.first - (data.second-1));
        }
    }

    if (islands > 1) {
        if (excess >= (islands-1)) {
            return islands-1;
        }
        return -1;
    }
    return 0;
}

int main() {

    vector<vector<int>> connections1 = {{0,1}, {0,2}, {1,2}};
    int n1 = 4;

    cout << makeConnected(n1, connections1) << endl;

    vector<vector<int>> connections2 = {{0,1}, {0,2}, {0,3}, {1,2}, {1,3}};
    int n2 = 6;

    cout << makeConnected(n2, connections2) << endl;

    vector<vector<int>> connections3 = {{0,1}, {0,2}, {0,3}, {1,2}};
    int n3 = 6;

    cout << makeConnected(n3, connections3) << endl;

    return 0;
}