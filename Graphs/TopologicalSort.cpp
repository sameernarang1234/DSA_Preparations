#include <bits/stdc++.h>

using namespace std;

void topologicalSort(int V, vector<int> graph[], int curr, vector<int> &visited, stack<int> &st) {
    visited[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next])
            topologicalSort(V, graph, next, visited, st);
    }

    st.push(curr);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> visited;
    for (int i = 0; i < V; ++i) {
        visited.push_back(false);
    }

    stack<int> st;
    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            topologicalSort(V, adj, i, visited, st);
    }

    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;

        adj[start].push_back(end);
    }

    vector<int> res = topoSort(V, adj);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}