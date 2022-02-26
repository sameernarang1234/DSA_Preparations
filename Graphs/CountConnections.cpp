#include <bits/stdc++.h>
#include <vector>

using namespace std;

int countConnections(vector<vector<int>> graph) {
    int count = 0;
    for (int i = 0; i < graph.size(); i++) {
        count += graph[i].size();
    }
    return count/2;
}

int main() {
    int N, E;

    cin >> N >> E;

    vector<vector<int>> graph;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        graph.push_back(v);
    }

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    vector<bool> visited;
    for (int i = 0; i < N; i++) {
        visited.push_back(false);
    }

    cout << countConnections(graph) << endl;

    return 0;
}