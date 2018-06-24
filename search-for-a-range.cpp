// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//https://leetcode.com/problems/search-for-a-range/description/
    
#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int searchFirst(vector<int>& nums, int target)
{
    int head = 0;
    int tail = nums.size() - 1;
    while(head + 1 < tail) {
        int mid = (tail - head) / 2 + head;
        if (target > nums[mid]) {
            head = mid;
        } else {
            tail = mid;
        }
    }
    if (nums[head] == target) return head;
    if (nums[tail] == target) return tail;
    return -1;
}

int searchLast(vector<int>& nums, int target)
{
    int head = 0;
    int tail = nums.size() - 1;
    while(head + 1 < tail) {
        int mid = (tail - head) / 2 + head;
        if (target < nums[mid]) {
            tail = mid;
        } else {
            head = mid;
        }
    }
    if (nums[tail] == target) return tail;
    if (nums[head] == target) return head;
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    if (nums.size() == 0) return result;
    result[0] = searchFirst(nums, target);
    if (result[0] == -1) {
        return result;
    }
    result[1] = searchLast(nums, target);
    if (result[1] == -1) {
        return result;
    }
    return result;
}

void test1(){
    vector<int> nums;
    vector<int> result;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    result = searchRange(nums, 8);
    printf("search range [%d, %d]\n", result[0], result[1]);
}

void test2(){
    vector<int> nums;
    vector<int> result;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    result = searchRange(nums, 6);
    printf("search range [%d, %d]\n", result[0], result[1]);
}

void test3(){
    vector<int> nums;
    vector<int> result;
    nums.push_back(2);
    nums.push_back(2);
    result = searchRange(nums, 2);
    printf("search range [%d, %d]\n", result[0], result[1]);
}


int main(){
    test1();
    test2();
    test3();
    return 0;
}



