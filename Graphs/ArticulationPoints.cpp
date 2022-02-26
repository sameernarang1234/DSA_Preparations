#include <bits/stdc++.h>

using namespace std;

bool checkBackEdge(vector<vector<int>> graph, int curr, int prev, vector<bool> &visited, vector<bool> notAncestor) {
    visited[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (notAncestor[next]) {
            return false;
        }
        if (!visited[next] && next != prev) {
            if (!checkBackEdge(graph, next, prev, visited, notAncestor)) {
                return false;
            }
        }
    }

    return true;
}

void dfs(vector<vector<int>> graph, vector<bool> &visited, int curr, int prev) {
    cout << curr << endl;
    if (curr == prev) {
        return;
    }
    visited[curr] = true;
    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next]) {
            dfs(graph, visited, next, prev);
            break;
        }
    }
}

vector<int> articulationPointsUtil(vector<vector<int>> graph, vector<bool> &visited, vector<bool> notAncestor, int curr, int level, vector<int> &res, map<int, bool> &mp) {
    // cout << curr << endl;
    visited[curr] = true;
    if (level == 0) {
        vector<bool> vis;
        for (int i = 0; i < graph.size(); ++i) {
            vis.push_back(false);
        }
        vis[curr] = true;
        if (!graph[curr].empty())
            dfs(graph, vis, graph[curr][0], curr);
        for (int i = 0; i < graph[curr].size(); i++) {
            int child = graph[curr][i];
            if (!vis[child] && mp.find(child) == mp.end()) {
                res.push_back(curr);
                mp[curr] = true;
                break;
            } 
        }
    }
    else {
        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            if (!visited[next]) {
                vector<bool> visited2 = visited;
                if(checkBackEdge(graph, next, curr, visited2, notAncestor) && mp.find(curr) == mp.end()) {
                    res.push_back(curr);
                    mp[curr] = true;
                }
            }
        }
    }
    notAncestor[curr] = true;

    for (int i = 0; i < graph[curr].size(); ++i) {
        int next = graph[curr][i];
        if (!visited[next]) {
            articulationPointsUtil(graph, visited, notAncestor, next, level+1, res, mp);
        }
    }
}

vector<int> articulationPoints(vector<vector<int>> graph) {
    vector<bool> visited, notAncestor;
    int N = graph.size();
    for (int i = 0; i < N; ++i) {
        visited.push_back(false);
        notAncestor.push_back(false);
    }

    vector<int> res;
    map<int, bool> mp;
    articulationPointsUtil(graph, visited, notAncestor, 0, 0, res, mp);
    return res;
}

int main() {

    int V, E;

    cin >> V >> E;

    vector<vector<int>> graph;

    for (int i = 0; i < V; i++) {
        vector<int> v;
        graph.push_back(v);
    }

    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    vector<int> ap = articulationPoints(graph);

    for (int i = 0; i < ap.size(); i++) {
        cout << ap[i] << " ";
    }
    cout << endl;

    return 0;
}