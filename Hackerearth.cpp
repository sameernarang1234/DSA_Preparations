#include<bits/stdc++.h>
using namespace std;

int playground (int N, int M, int Q, vector<vector<int> > A) {
   // Write your code here
    vector<vector<int> > matrix;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < M; j++) {
            v.push_back(2);
            if (j < M-1) {
                v.push_back(0);
            }
        }
        matrix.push_back(v);
        if (i < N-1) {
            vector<int> v2;
            for (int j = 0; j < ((2*M)-1); j++) {
                v2.push_back(0);
            }
            matrix.push_back(v2);
        }
    }

    for (int i = 0; i < A.size(); i++) {
        int j1 = A[i][0];
        int i1 = A[i][1];
        int j2 = A[i][2];
        int i2 = A[i][3];

        j1 = (j1 == 1)? 0 : (2*j1)-2;
        i1 = (i1 == 1)? 0 : (2*i1)-2;
        j2 = (j2 == 1)? 0 : (2*j2)-2;
        i2 = (i2 == 1)? 0 : (2*i2)-2;

        cout << i1 << " " << j1 << endl;
        cout << i2 << " " << j2 << endl;

        if (i1 == i2) {
            int index = min(j1, j2);
            if (i1 < 2*N-2) {
                for (int j = min(j1, j2); j <= max(j2, j1); j += 2) {
                    matrix[i1+1][j] = 1;
                    index += 2;
                }
            }
            else {
                for (int j = min(j1, j2); j <= max(j2, j1); j += 2) {
                    matrix[i1-1][j] = 1;
                    index += 2;
                }
            }
        }
        if (j1 == j2) {
            int index = min(i1, i2);
            if (j1 < 2*M-2) {
                for (int j = min(i1, i2); j <= max(i2, i1); j += 2) {
                    matrix[j][j1+1] = 1;
                    index += 2;
                }
            }
            else {
                for (int j = min(i1, i2); j <= max(i2, i1); j += 2) {
                    matrix[j][j1-1] = 1;
                    index += 2;
                }
            }
        }
    }

    vector<vector<bool>> visited;
    for (int i = 0; i < matrix.size(); i++) {
        vector<bool> v;
        for (int j = 0; j < matrix[i].size(); j++) {
            v.push_back(false);
        }
        visited.push_back(v);
    }

    cout << endl << "MATRIX:" << endl << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "INSIDE PROGRAM" << endl;
    int count = 0;
    for (int i = 0; i < matrix.size(); i += 2) {
        for (int j = 0; j < matrix[i].size(); j += 2) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                count++;
                queue<pair<int, int> > q;
                pair<int, int> p; p.first = i; p.second = j;
                q.push(p);
                while (!q.empty()) {
                    cout << "INSIDE FIRST WHILE" << endl;
                    q.push({-1,-1});
                    while (q.front().first != -1) {
                        cout << "INSIDE SECOND WHILE" << endl;
                        pair<int, int> curr = q.front();
                        q.pop();
                        int i = curr.first, j = curr.second;
                        cout << i << " " << j << endl;

                        if (i < N && matrix[i+1][j] == 0 && !visited[i+2][j]) {
                            cout << "INSIDE 1" << endl;
                            visited[i+2][j] = true;
                            pair<int, int> p2; p2.first = i+2; p2.second = j;
                            q.push(p2);
                        }
                        if (i > 0 && matrix[i-1][j] == 0 && !visited[i-2][j]) {
                            cout << "INSIDE 2" << endl;
                            visited[i-2][j] = true;
                            pair<int, int> p2; p2.first = i-2; p2.second = j;
                            q.push(p2);
                        }
                        if (j < M && matrix[i][j+1] == 0 && !visited[i][j+2]) {
                            cout << "INSIDE 3" << endl;
                            visited[i][j+2] = true;
                            pair<int, int> p2; p2.first = i; p2.second = j+2;
                            q.push(p2);
                        }
                        if (j > 0 && matrix[i][j-1] == 0 && !visited[i][j-2]) {
                            cout << "INSIDE 4" << endl;
                            visited[i][j-2] = true;
                            pair<int, int> p2; p2.first = i; p2.second = j-2;
                            q.push(p2);
                        }
                    }
                    q.pop();
                }
            }
        }
    }

    return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        int Q;
        cin >> Q;
        vector<vector<int> > A(Q, vector<int>(4));
        for (int i_A = 0; i_A < Q; i_A++)
        {
        	for(int j_A = 0; j_A < 4; j_A++)
        	{
        		cin >> A[i_A][j_A];
        	}
        }

        int out_;
        out_ = playground(N, M, Q, A);
        cout << out_;
        cout << "\n";
    }
}