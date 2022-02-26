#include <bits/stdc++.h>
// 1 2 3 4 5 7 6 8 9
using namespace std;

void findOrder(string dict[], int N, int K) {
    vector<char> v;
    map<char, int> mp;

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < dict[i].size() && j < dict[i+1].size(); j++) {
            if (dict[i][j] != dict[i+1][j]) {
                if (v.empty() || (mp.find(dict[i][j]) == mp.end() && mp.find(dict[i+1][j]) == mp.end())) {
                    mp[dict[i][j]] = v.size();
                    v.push_back(dict[i][j]);
                    mp[dict[i+1][j]] = v.size();
                    v.push_back(dict[i+1][j]);
                }
                else if (mp.find(dict[i][j]) != mp.end() && mp.find(dict[i+1][j]) == mp.end()) {
                    mp[dict[i+1][j]] = v.size();
                    v.push_back(dict[i+1][j]);
                }
                else if (mp.find(dict[i][j]) == mp.end() && mp.find(dict[i+1][j]) != mp.end()) {
                    v.insert(v.begin()+mp[dict[i+1][j]], dict[i][j]);
                    mp[dict[i][j]] = mp[dict[i+1][j]];
                    for (int k = mp[dict[i][j]]+1; k < v.size(); k++) {
                        mp[v[k]] = k;
                    }
                }
                else if (mp[dict[i+1][j]] < mp[dict[i][j]]) {
                    int pos1 = mp[dict[i+1][j]];
                    int pos2 = mp[dict[i][j]];
                    v.erase(v.begin()+pos2);
                    v.erase(v.begin()+pos1);
                    v.insert(v.begin()+pos1, dict[i][j]);
                    v.insert(v.begin()+pos2, dict[i+1][j]);
                }
                break;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    string dict[5] = {"baa","abcd","abca","cab","cad"};

    findOrder(dict, 5, 4);

    string dict2[3] = {"caa","aaa","aab"};

    findOrder(dict2, 3, 3);

    return 0;
}