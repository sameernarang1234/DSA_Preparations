#include <bits/stdc++.h>

using namespace std;

void numIslandsUtil(vector<vector<char>> grid, vector<vector<bool>> &visited, int i, int j) {
    visited[i][j] = true;
    int N = grid.size();
    int M = grid[i].size();

    if (i+1 < N && grid[i+1][j] != '0' && !visited[i+1][j]) {
        numIslandsUtil(grid, visited, i+1, j);
    }
    if (i-1 >= 0 && grid[i-1][j] != '0' && !visited[i-1][j]) {
        numIslandsUtil(grid, visited, i-1, j);
    }
    if (j+1 < M && grid[i][j+1] != '0' && !visited[i][j+1]) {
        numIslandsUtil(grid, visited, i, j+1);
    }
    if (j-1 >= 0 && grid[i][j-1] != '0' && !visited[i][j-1]) {
        numIslandsUtil(grid, visited, i, j-1);
    }
    if (i+1 < N && j+1 < M && grid[i+1][j+1] != '0' && !visited[i+1][j+1]) {
        numIslandsUtil(grid, visited, i+1, j+1);
    }
    if (i+1 < N && j-1 >= 0 && grid[i+1][j-1] != '0' && !visited[i+1][j-1]) {
        numIslandsUtil(grid, visited, i+1, j-1);
    }
    if (i-1 >= 0 && j+1 < M && grid[i-1][j+1] != '0' && !visited[i-1][j+1]) {
        numIslandsUtil(grid, visited, i-1, j+1);
    }
    if (i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] != '0' && !visited[i-1][j-1]) {
        numIslandsUtil(grid, visited, i-1, j-1);
    }
}

int numIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited;

    for (int i = 0; i < n; i++) {
        vector<bool> v;
        for (int j = 0; j < m; j++) {
            v.push_back(false);
        }
        visited.push_back(v);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '0' && !visited[i][j]) {
                count++;
                numIslandsUtil(grid, visited, i, j);
            }
        }
    }
    return count;
}

int main() {

    vector<vector<char>> grid1 = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
    cout << numIslands(grid1) << endl;

    vector<vector<char>> grid2 = {{'0','1','1','1','0','0','0'},{'0','0','1','1','0','1','0'}};
    cout << numIslands(grid2) << endl;

    return 0;
}