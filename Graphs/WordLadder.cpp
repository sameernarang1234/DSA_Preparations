#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int findDiff(string word1, string word2) {
    int count = 0;
    int N1 = word1.size();
    int N2 = word2.size();
    
    int i = 0;

    while (i < N1 && i < N2) {
        if (word1[i] != word2[i]) {
            count++;
        }
        i++;
    }
    if (i < N1) {
        return count+(N1-i);
    }
    if (i < N2) {
        return count+(N2-i);
    }
    return count;
}

int ladderLengthUtil(string beginWord, string endWord, vector<string> wordList, int i, int count) {
    if (beginWord == endWord) {
        return count;
    }
    if (i >= wordList.size()) {
        return -1;
    }

    int min = INT_MAX;
    if (findDiff(beginWord, wordList[i]) == 1) {
        int length = ladderLengthUtil(wordList[i], endWord, wordList, i+1, count+1);
        if (length < min && length >= 0) {
            min = length;
        }
    }
    int length = ladderLengthUtil(beginWord, endWord, wordList, i+1, count);
    if (length < min && length >= 0) {
        min = length;
    }

    if (min == INT_MAX) {
        return -1;
    }
    return min;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int N = wordList.size();
    bool isPresent = false;
    for (int i = 0; i < N; i++) {
        if (endWord == wordList[i]) {
            isPresent = true;
            break;
        }
    }

    if (!isPresent) {
        return -1;
    }

    return ladderLengthUtil(beginWord, endWord, wordList, 0, 1);
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}