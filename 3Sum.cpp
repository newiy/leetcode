// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//https://leetcode.com/problems/3sum/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
vector<vector<int> > threeSum(vector<int> & nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> row;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int low = i + 1;
        int high = nums.size() - 1;
        int temp = 0 - nums[i];
        while(low < high) {
            if (nums[low] + nums[high] == temp) {
                row.clear();
                row.push_back(nums[i]);
                row.push_back(nums[low]);
                row.push_back(nums[high]);
                result.push_back(row);
                while(low < high && nums[low] == nums[low + 1]) {
                    low++;
                }
                while(low < high && nums[high] == nums[high - 1]) {
                    high--;
                }
                low++;
                high--;
            } else if (nums[low] + nums[high] < temp){
                low++;
            } else {
                high--;
            }
        }
    }
    return result;
}

void test1(){
    vector<int> v;
    vector<vector<int> > result;
    v.push_back(-1);
     v.push_back(0);
     v.push_back(1);
     v.push_back(2);
     v.push_back(-1);
     v.push_back(-4);
     result = threeSum(v);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}



int main(){
    test1();

    return 0;
}



