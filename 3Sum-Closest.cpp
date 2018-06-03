// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// https://leetcode.com/problems/3sum-closest/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int result = nums[0] + nums[1] + nums[nums.size() - 1];
    for (int i = 0; i < nums.size() - 1; i++) {
        int start = i + 1;
        int end = nums.size() - 1;
        while(start < end) {
            int sum = nums[start] + nums[end] + nums[i];
            if (sum < target) {
                start++;
            } else {
                end--;
            }
            if (abs(result - target) > abs(sum - target)) {
                result = sum;
            }
        }
    }
    return result;
}

void test1(){
    vector<int> v;
    int result;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-4);
    result = threeSumClosest(v, 1);
    printf("result is %d\n", result);
}



int main(){
    test1();

    return 0;
}



