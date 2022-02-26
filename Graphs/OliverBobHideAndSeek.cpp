#include <bits/stdc++.h>

using namespace std;

void findDistance(int **graph, int V, int curr, int destination, vector<bool> visited, int &dist, int count) {
    visited[curr] = true;

    if (curr == destination && count < dist) {
        dist = count;
        return;
    }

    int min = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (graph[curr][i] != 0 && !visited[i]) {
            findDistance(graph, V, i, destination, visited, dist, count+1);
        }
    }
}

bool findOliver(int **graph, int V, int start, int end, int direction) {

    vector<bool> visited;
    for (int i = 0; i < V; i++) {
        visited.push_back(false);
    }

    int distOliver; findDistance(graph, V, 0, end, visited, distOliver, 0);
    int distBob; findDistance(graph, V, 0, start, visited, distBob, 0);

    if (direction == 1) {
        if (distOliver > distBob)
            return true;
        return false;
    }
    else {
        if (distOliver < distBob)
            return true;
        return false;
    }
}

int main() {

    int V;
    cin >> V;

    int **graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
    }

    for (int i = 0; i < V-1; i++) {
        int start, end;
        cin >> start >> end;

        graph[start-1][end-1] = 1;
        graph[end-1][start-1] = 1;
    }

    int T;
    cin >> T;

    vector<bool> res;

    for (int i = 0; i < T; i++) {
        int direction, x, y;
        cin >> direction >> x >> y;

        if (findOliver(graph, V, y, x, direction)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}