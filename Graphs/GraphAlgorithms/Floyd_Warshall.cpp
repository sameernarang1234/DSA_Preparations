#include <bits/stdc++.h>

using namespace std;

void floydWarshall(vector<vector<int>> &matrix) {
    int V = matrix.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][k] != -1 && matrix[k][j] != -1) {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
}

int main() {

    vector<vector<int>> matrix = {{0,1,43},{1,0,6},{-1,-1,0}};

    floydWarshall(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}