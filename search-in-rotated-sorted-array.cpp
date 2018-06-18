// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
    
#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1;
    while(left + 1 < right) {
        int mid = (right - left) / 2 + left;
        if (nums[mid] == target) return mid;
        if (nums[left] < nums[mid]) {
            if (nums[left] <= target && target <= nums[mid])
                right = mid;
            else
                left = mid;
        } else {
            if (nums[mid] <= target && target <= nums[right])
                left = mid;
            else
                right = mid;
        }
    }
    if (nums[left] == target) return left;
    if (nums[right] == target) return right;
    return -1;
}

void test1(){
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int result = search(nums, 0);
    printf("search result %d\n", result);
}

void test2(){
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    int result = search(nums, 3);
    printf("search result %d\n", result);
}


int main(){
    //test1();
    test2();
    return 0;
}



