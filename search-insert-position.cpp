// https://leetcode.com/problems/search-insert-position/description/
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h> 

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size(); 
    int mid = 0;
    while(left < right) {
        mid = left + (right - left) / 2;
        //printf("left %d, right %d, mid %d\n", left, right, mid);
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return right;
}


int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    
    //int result = searchInsert(v, 5);
    //int result = searchInsert(v, 2);
    //int result = searchInsert(v, 7);
    int result = searchInsert(v, 0);
    printf("%d\n", result);
    return 0;
}



