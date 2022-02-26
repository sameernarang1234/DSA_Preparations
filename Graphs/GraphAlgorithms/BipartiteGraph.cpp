#include <bits/stdc++.h>

using namespace std;

bool isBipartiteUtil(vector<int> adj[], int curr, vector<int> &color) {
    if (color[curr] == 0) {
        color[curr] = 1;
    }

    for (int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        if (color[next] == color[curr]) {
            return false;
        }
        if (color[next] == 0) {
            color[next] = (-1)*color[curr];
            if(!isBipartiteUtil(adj, next, color)) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color;
    for (int i = 0; i < V; i++) {
        color.push_back(0);
    }

    return isBipartiteUtil(adj, 0, color);
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<int> graph[V];
    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    if (isBipartite(V, graph)) {
        cout << "IS BIPARTITE" << endl;
    }
    else {
        cout << "NOT BIPARTITE" << endl;
    }

    return 0;
}