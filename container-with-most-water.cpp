// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.
// https://leetcode.com/problems/container-with-most-water/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
int maxArea(vector<int>& height) {
    int result = 0;
    int l = 0; 
    int r = height.size() - 1;
    while(l < r) {
        result = max(result, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    return result;
}

void test1(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(2);
    printf("%d\n", maxArea(v));
}



int main(){
    test1();

    return 0;
}




