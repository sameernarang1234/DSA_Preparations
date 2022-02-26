#include <bits/stdc++.h>
#include <vector>

using namespace std;

void minTimeForEachJob(vector<vector<int>> graph, vector<int> &minTime, int curr, int time, vector<bool> &visited) {
    visited[curr] = true;
    if (time > minTime[curr]) {
        minTime[curr] = time;
    }
    if (graph[curr].empty()) {
        return;
    }

    int N = graph[curr].size();
    for (int i = 0; i < N; i++) {
        int next = graph[curr][i];
        minTimeForEachJob(graph, minTime, next, time+1, visited);
    }
}

int main() {

    int N, E;

    cin >> N >> E;
    
    vector<vector<int>> graph;
    for (int i = 0; i <= N; i++) {
        vector<int> v = {};
        graph.push_back(v);
    }

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
    }

    vector<int> minTime;
    vector<bool> visited;
    for (int i = 0; i <= N; i++) {
        minTime.push_back(0);
        visited.push_back(false);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            minTimeForEachJob(graph, minTime, i, 0, visited);
    }

    for (int i = 1; i <= N; i++) {
        cout << minTime[i] << " ";
    }
    cout << endl;

    return 0;
}