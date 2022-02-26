#include <bits/stdc++.h>

using namespace std;

class Graph {
    public:
    int start;
    int end;
    int wt;

    Graph(int start, int end, int wt) {
        this->start = start;
        this->end = end;
        this->wt = wt;
    }
};

void topologicalSort(vector<vector<int>> graph, vector<bool> &visited, stack<int> &st, int curr) {
    cout << curr << endl;
    visited[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
        if (graph[curr][i] != 0 && !visited[i]) {
            topologicalSort(graph, visited, st, i);
        }
    }

    st.push(curr);
}

vector<int> longestPath(vector<vector<int>> graph, int src) {
    vector<bool> visited;
    for (int i = 0; i < graph.size(); ++i) {
        visited.push_back(false);
    }
    stack<int> st;

    topologicalSort(graph, visited, st, src);
    cout << "AFTER" << endl;

    vector<int> topoSort;
    while (!st.empty()) {
        topoSort.push_back(st.top());
        st.pop();
    }

    vector<int> dist;
    for (int i = 0; i < graph.size(); ++i) {
        int d = INT_MIN;
        dist.push_back(d);
    }
    dist[src] = 0;

    for (int i = src; i < dist.size(); ++i) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] != 0 && dist[i]+graph[i][j] > dist[j]) {
                dist[j] = dist[i] + graph[i][j];
            }
        }
    }

    return dist;
}

vector<vector<int>> createGraph(vector<Graph> graph, int V) {
    vector<vector<int>> matrix;
    for (int i = 0; i < V; i++) {
        vector<int> v;
        for (int j = 0; j < V; j++) {
            v.push_back(0);
        }
        matrix.push_back(v);
    }

    for (int i = 0; i < graph.size(); i++) {
        int start = graph[i].start;
        int end = graph[i].end;
        int wt = graph[i].wt;

        matrix[start][end] = wt;
    }

    return matrix;
}

int main() {

    vector<Graph> g;

    g.push_back(Graph(0, 1, 5));
    g.push_back(Graph (0, 2, 3));
    g.push_back(Graph (1, 3, 6));
    g.push_back(Graph (1, 2, 2));
    g.push_back(Graph (2, 4, 4));
    g.push_back(Graph (2, 5, 2));
    g.push_back(Graph (2, 3, 7));
    g.push_back(Graph (3, 5, 1));
    g.push_back(Graph (3, 4, -1));
    g.push_back(Graph (4, 5, -2));

    vector<vector<int>> graph = createGraph(g, 6);

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> path = longestPath(graph, 1);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}