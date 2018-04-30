// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.
//https://leetcode.com/problems/house-robber/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
int rob(vector<int>& nums) {
    vector<int> result;
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    result.push_back(nums[0]);
    result.push_back(max(nums[0], nums[1]));
    for (int i = 2; i < nums.size(); i++) {
        result.push_back(max(nums[i] + result[i - 2], result[i - 1]));
    }
    return result.back();
}


void test1(){
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(9);
    v.push_back(3);
    v.push_back(1);
    int result = rob(v);
    printf("result is %d\n", result);
}

void test2(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    int result = rob(v);
    printf("result is %d\n", result);
}


int main(){
    test2();
    return 0;
}




