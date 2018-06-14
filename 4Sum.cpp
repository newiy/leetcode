// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//https://leetcode.com/problems/4sum/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    vector<int> row;
    if (nums.size() < 4) return result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int low = j + 1;
            int high = nums.size() - 1;
            while(low < high) {
                int sum = nums[low] + nums[high] + nums[i] + nums[j];
                if (sum == target) {
                    row.clear();
                    row.push_back(nums[i]);
                    row.push_back(nums[j]);
                    row.push_back(nums[low]);
                    row.push_back(nums[high]);
                    result.push_back(row);
                    while(low < high && nums[low] == nums[low + 1]) low++;
                    while(low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
            
        }
    }
    return result;
}

void test1(){
    vector<int> nums;
    vector<vector<int> > result;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    result = fourSum(nums, 0);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }    
}

void test2(){
    vector<int> nums;
    vector<vector<int> > result;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    result = fourSum(nums, 0);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }    
}



int main(){
    //test1();
    test2();
    return 0;
}



