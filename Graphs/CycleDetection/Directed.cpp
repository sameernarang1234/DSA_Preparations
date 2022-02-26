#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

bool isCyclicUtil(vector<vector<int>> graph, vector<bool> visited, bool *visited2, int curr) {
    visited[curr] = true;
    visited2[curr] = true;

    if (graph[curr].empty()) {
        return false;
    }

    for (int i = 0; i < graph[curr].size(); i++) {
        if (!visited[graph[curr][i]]) {
            if (isCyclicUtil(graph, visited, visited2, graph[curr][i])) {
                return true;
            }
            continue;
        }
        return true;
    }

    visited[curr] = false;

    return false;
}

bool isCyclePresent(vector<vector<int>> graph, vector<bool> visited) {
    int N = visited.size();
    
    bool visited2[N];
    for (int i = 0; i < N; i++) {
        visited2[i] = false;
    }

    for (int i = 0; i < N; i++) {
        if (!visited2[i]) {
            if (isCyclicUtil(graph, visited, visited2, i)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N = 0, E = 0;

    cin >> N;
    cin >> E;

    vector<vector<int>> graph;

    for (int i = 0; i < N; i++) {
        vector<int> curr;
        graph.push_back(curr);
    }

    vector<bool> visited;
    for (int i = 0; i < N; i++) {
        visited.push_back(false);
    }

    for (int i = 0; i < E; i++) {
        int start;
        int end;

        cin >> start; cin >> end;

        graph[start].push_back(end);
    }

    string isCyclic = (isCyclePresent(graph, visited))? "TRUE":"FALSE";

    cout << isCyclic << endl;

    return 0;
}