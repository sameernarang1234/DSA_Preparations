#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

bool isCyclicUtil(vector<vector<int>> graph, vector<bool> &visited, int curr, int prev) {
    visited[curr] = true;
    if (graph[curr].empty()) {
        return false;
    }

    for (int i = 0; i < graph[curr].size(); i++) {
        if (!visited[graph[curr][i]]) {
            if (isCyclicUtil(graph, visited, graph[curr][i], curr)) {
                return true;
            }
            continue;
        }
        if (graph[curr][i] != prev)
            return true;
    }

    return false;
}

bool isCyclic(vector<vector<int>> graph, vector<bool> visited) {
    int N = graph.size();
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, visited, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, e;

    cin >> n; cin >> e;

    vector<vector<int>> graph;
    vector<bool> visited;
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        graph.push_back(arr);

        visited.push_back(false);
    }

    for (int i = 0; i < e; i++) {
        int start, end;

        cin >> start; cin >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    string isCyc = (isCyclic(graph, visited))? "TRUE":"FALSE";

    cout << isCyc << endl;
}