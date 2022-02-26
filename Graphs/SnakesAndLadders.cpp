#include <bits/stdc++.h>

using namespace std;

struct queueEntry {
    int v;
    int dist;
};

int minDist(int *move, int N) {
    bool *visited = new bool[N];

    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    queue<queueEntry> q;
    queueEntry s = {0, 0};
    q.push(s);

    visited[0] = true;

    queueEntry qe;

    while (!q.empty()) {
        qe = q.front();
        
        if (qe.v == N-1) {
            break;
        }

        q.pop();
        int v = qe.v;
        for (int i = v+1; i <= v+6; i++) {
            queueEntry next;
            next.dist = qe.dist+1;

            if (move[i] != -1) {
                next.v = move[i];
            }
            else {
                next.v = i;
            }
            q.push(next);
        }
    }

    return qe.dist;
}

int snakesAndLadders(vector<vector<int>> &board) {
    int N = board.size()*board.size();

    int *move = new int[N];

    int index = 0;
    for (int i = 0; i < board.size(); i++) {
        if (i%2 == 0) {
            for (int j = 0; j < board.size(); j++) {
                move[index++] = board[i][j];
            }
        }
        else {
            for (int j = board.size()-1; j >= 0; j--) {
                move[index++] = board[i][j];
            }
        }
    }

    return minDist(move, N);
}

int main() {

    vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};

    cout << snakesAndLadders(board) << endl;

    return 0;
}