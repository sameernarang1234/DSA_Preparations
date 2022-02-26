#include <bits/stdc++.h>

using namespace std;

void DFSTraversal(vector<vector<int>> graph, stack<int> &st, int curr, vector<bool> visited) {
    visited[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next]) {
            DFSTraversal(graph, st, next, visited);
        }
    }

    st.push(curr);
}

vector<vector<int>> getTransposeGraph(vector<vector<int>> graph) {
    vector<vector<int>> transpose;
    for (int i = 0; i < graph.size(); ++i) {
        vector<int> row;
        transpose.push_back(row);
    }

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            int curr = graph[i][j];
            transpose[curr].push_back(i);
        }
    }

    return transpose;
}

void DFS(vector<vector<int>> graph, int curr, vector<bool> &visited) {
    visited[curr] = true;

    cout << curr << " ";

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next]) {
            DFS(graph, next, visited);
        }
    }
}

void printSCCs(vector<vector<int>> graph) {
    stack<int> st;
    vector<bool> visited;
    for (int i = 0; i < graph.size(); ++i) {
        visited.push_back(false);
    }
    DFSTraversal(graph, st, 0, visited);

    vector<vector<int>> transpose = getTransposeGraph(graph);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!visited[curr]) {
            DFS(transpose, curr, visited);
            cout << endl;
        }
    }
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph;
    vector<bool> visited;

    for (int i = 0; i < V; ++i) {
        vector<int> v;
        graph.push_back(v);
        visited.push_back(false);
    }

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    printSCCs(graph);
    return 0;
}