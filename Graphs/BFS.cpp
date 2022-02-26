#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    
    vector<int> arr;
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        q.push(INT_MIN);
        while (q.front() != INT_MIN) {
            int curr = q.front();
            q.pop();

            arr.push_back(curr);

            for (int i = 0; i < adj[curr].size(); i++) {
                if (!visited[adj[curr][i]]) {
                    visited[adj[curr][i]] = true;
                    q.push(adj[curr][i]);
                }
            }
        }
        q.pop();
    }
    
    return arr;
}

int main() {
    vector<int> adj[4];

    adj[0] = {1,2,3};
    adj[1] = {};
    adj[2] = {4};
    adj[3] = {};
    adj[4] = {};

    vector<int> v = bfsOfGraph(5, adj);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}