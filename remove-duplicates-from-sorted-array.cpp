
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h> 

using namespace std;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }
//    int i = 0;
    //int count = 1; // count of distinct elements
    int prev = 0; // index of last distinct element before current
    int cur = 1; // current check index
    while (cur < nums.size()) {
        printf("prev: nums[%d]=%d, cur: nums[%d]=%d\n", prev, nums[prev], cur, nums[cur]);
        if (nums[prev] != nums[cur]) {
            // swap prev+1 and cur
            // count++;
            swap(&nums[prev + 1], &nums[cur]);
            //nums[prev + 1] = nums[cur];
            prev = prev + 1;
        }
        cur++;
    }

    return prev + 1;
}


void print_call_with_pointer(int *a) {
    *a = 11;
    printf("a: %d\n", *a);
}


void print_call_with_reference(int &a) {
    a = 9;
    printf("a: %d\n", a);
}

int main2() {
    int a = 10;
    print_call_with_pointer(&a);
    print_call_with_reference(a);
    
    return 0;
}

int main() {
    int i = 0;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int result = removeDuplicates(v);
    
    while(i < v.size()) {
        printf("%d ", v[i]);
        i++;
    }
    printf("\n");
    return 0;
}



