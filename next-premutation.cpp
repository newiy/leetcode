// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
// https://leetcode.com/problems/next-permutation/description/
    
#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
}

void reverse(vector<int>& nums, int i, int j) {
    while(i < j) {
        swap(nums, i++, j--);
    }
    return;
}

void nextPermutation(vector<int>& nums) {
    int firstSmall = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            firstSmall = i;
            break;
        }
    }
    if (firstSmall == -1) {
        reverse(nums, 0, nums.size() - 1);
        return;
    }
    int firstLarge = -1;
    for (int i = nums.size() - 1; i > firstSmall; i--) {
        if (nums[i] > nums[firstSmall]) {
            firstLarge = i;
            break;
        }
    }
    swap(nums, firstSmall, firstLarge);
    reverse(nums, firstSmall + 1, nums.size() - 1);
    return;
}

void test1(){
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void test2(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main(){
    test1();
    test2();
    return 0;
}



