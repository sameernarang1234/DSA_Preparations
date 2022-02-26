#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height) {
    int i = 0, j = height.size()-1;
    int max_area = INT_MIN;

    while (i < j) {
        int area = min(height[i], height[j])*(j-i);
        if (area > max_area) {
            max_area = area;
        }

        if (height[i] > height[j]) {
            j--;
        }
        else {
            i++;
        }
    }

    return max_area;
}

int main() {
    return 0;
}