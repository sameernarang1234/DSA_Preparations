#include <bits/stdc++.h>
#include <vector>

using namespace std;

void dfs(int V, vector<int> adj[], int curr, vector<int> &v, bool visited[]) {
        if (adj[curr].empty()) {
            return;
        }
        v.push_back(curr);
        
        for (int i = 0; i < adj[curr].size(); i++) {
            if (!visited[adj[curr][i]]) {
                visited[adj[curr][i]] = true;
                dfs(V, adj, adj[curr][i], v, visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v;
        bool visited[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        
        visited[0] = true;
        dfs(V, adj, 0, v, visited);
        
        return v;
    }

int main() {
    
}