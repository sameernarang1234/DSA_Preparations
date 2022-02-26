#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> intervals) {
    bool isOverlap[intervals.size()];

    for (int i = 0; i < intervals.size(); i++) {
        isOverlap[i] = false;
    }

    vector<vector<int>> res;
    
    for (int i = 0; i < intervals.size(); i++) {
        int min = intervals[i][0];
        int max = intervals[i][1];

        bool overlap = false;
        for (int j = i+1; j < intervals.size(); j++) {
            if (!isOverlap[j]) {
                if (intervals[j][0] < min && intervals[j][1] >= min-1) {
                    cout << "INSIDE 1" << endl;
                    overlap = true;
                    isOverlap[j] = true;
                    min = intervals[j][0];
                }
                if (intervals[j][1] > max && intervals[j][0] <= max+1) {
                    cout << "INSIDE 2" << endl;
                    overlap = true;
                    isOverlap[j] = true;
                    max = intervals[j][1];
                }
                if ((intervals[j][0] <= max && intervals[j][0] >= min) && (intervals[j][1] <= max && intervals[j][1] >= min)) {
                    overlap = true;
                    isOverlap[j] = true;
                }
            }
        }

        if (overlap) {
            vector<int> res1;
            res1.push_back(min);
            res1.push_back(max);
            res.push_back(res1);
            isOverlap[i] = true;
        }
    }

    for (int i = 0; i < intervals.size(); i++) {
        if (!isOverlap[i]) {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int main() {

    vector<vector<int>> arr = {{2,3}, {4,5}, {6,7}, {8,9}, {1,10}};

    vector<vector<int>> res = merge(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    cout << endl;

    arr = {{1,4}, {1,4}};

    res = merge(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    cout << endl;

    arr = {{1,4}, {2,3}};

    res = merge(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}