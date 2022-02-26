#include <bits/stdc++.h>

using namespace std;

bool waterJugProblemUtil(int X, int Y, int i, int j, int d, vector<vector<bool>> &visited, vector<vector<int>> &res) {
    // cout << i << " " << j << endl;
    visited[i][j] = true;
    bool isValid = false;

    if ((i == d && j == 0) || (i == 0 && j == d)) {
        vector<int> v; v.push_back(i); v.push_back(j);
        res.push_back(v);
        return true;
    }

    if (i == 0 && !visited[X][j]) {
        isValid = waterJugProblemUtil(X, Y, X, j, d, visited, res);
    }
    if (!isValid && j == 0 && !visited[i][Y]) {
        isValid = waterJugProblemUtil(X, Y, i, Y, d, visited, res);
    }
    if (!isValid && i == X && !visited[0][j]) {
        isValid = waterJugProblemUtil(X, Y, 0, j, d, visited, res);
    }
    if (!isValid && j == Y && !visited[i][0]) {
        isValid = waterJugProblemUtil(X, Y, i, 0, d, visited, res);
    }
    if (!isValid && (i+d <= X && j-d >= 0) && !visited[i+d][j-d]) {
        isValid = waterJugProblemUtil(X, Y, i+d, j-d, d, visited, res);
    }
    if (!isValid && (i-d >= 0 && j+d <= Y) && !visited[i-d][j+d]) {
        isValid = waterJugProblemUtil(X, Y, i-d, j+d, d, visited, res);
    }
    if (!isValid && (i >= Y-j) && !visited[i-(Y-j)][Y]) {
        isValid = waterJugProblemUtil(X, Y, i-(X-j), Y, d, visited, res);
    }
    if (!isValid && (i < Y-j) && !visited[0][j+i]) {
        isValid = waterJugProblemUtil(X, Y, 0, j+i, d, visited, res);
    }
    if (!isValid && (j >= X-i) && !visited[X][j-(X-i)]) {
        isValid = waterJugProblemUtil(X, Y, X, j-(X-i), d, visited, res);
    }
    if (!isValid && (j < X-i) && !visited[i+j][0]) {
        isValid = waterJugProblemUtil(X, Y, i+j, 0, d, visited, res);
    }

    // visited[i][j] = false;

    if (isValid) {
        vector<int> v; v.push_back(i); v.push_back(j);
        res.push_back(v);
    }

    return isValid;
}

vector<vector<int>> waterJugProblem(int X, int Y, int d) {
    vector<vector<bool>> visited;
    for (int i = 0; i <= X; i++) {
        vector<bool> v;
        for (int j = 0; j <= Y; j++) {
            v.push_back(false);
        }
        visited.push_back(v);
    }

    vector<vector<int>> res;
    bool x = waterJugProblemUtil(X, Y, 0, 0, d, visited, res);

    return res;
} 

int main() {

    vector<vector<int>> res = waterJugProblem(4, 3, 2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}