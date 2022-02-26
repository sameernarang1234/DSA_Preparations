#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

void findPathUtil(vector<vector<int>> m, int n, int i, int j, vector<vector<bool>> visited, vector<string> &paths, string path) {
    visited[i][j] = true;
    if (i == n-1 && j == n-1) {
        paths.push_back(path);
        return;
    }
    if (i+1 < n && m[i+1][j] && !visited[i+1][j]) {
        findPathUtil(m, n, i+1, j, visited, paths, path+"D");
    }
    if (i-1 >= 0 && m[i-1][j] && !visited[i-1][j]) {
        findPathUtil(m, n, i-1, j, visited, paths, path+"U");
    }
    if (j+1 < n && m[i][j+1] && !visited[i][j+1]) {
        findPathUtil(m, n, i, j+1, visited, paths, path+"R");
    }
    if (j-1 >= 0 && m[i][j-1] && !visited[i][j-1]) {
        findPathUtil(m, n, i, j-1, visited, paths, path+"L");
    }

    visited[i][j] = false;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> paths;
    vector<vector<bool>> visited;
    for (int i = 0; i < n; i++) {
        vector<bool> v;
        for (int j = 0; j < n; j++) {
            v.push_back(false);
        }
        visited.push_back(v);
    }

    findPathUtil(m, n, 0, 0, visited, paths, "");

    return paths;
}

int main() {

    vector<vector<int>> matrix = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    vector<string> paths = findPath(matrix, 4);
    
    cout << paths.size() << endl;
    for (int i = 0; i < paths.size(); i++) {
        cout << paths[i] << " ";
    }
    cout << endl;

    return 0;
}