// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

// [show hint]

// Related problem: Reverse Words in a String II

// Credits:
// Special thanks to @Freezen for adding this problem and creating all test cases.
//https://leetcode.com/problems/rotate-array/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(vector<int>& nums, int k) {
    int i = 0;
    k = k % nums.size();
    for (i = 0; i < nums.size() / 2; i++) {
        swap(&nums[i], &nums[nums.size() - i - 1]);
    }
    for (i = 0; i < k / 2; i++) {
        swap(&nums[i], &nums[k - i - 1]);
    }
    for (i = k; i < k + (nums.size() - k) / 2; i++) {
        swap(&nums[i], &nums[nums.size() - i + k - 1]);
        
    }
}

void print_vector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void test1(){
    vector<int> v;
    for (int i = 1; i < 8; i++) {
        v.push_back(i);
    }
    print_vector(v);
    rotate(v, 3);
    print_vector(v);
    
}

void test2(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    print_vector(v);
    rotate(v, 3);
    print_vector(v);
}


int main(){
    //test1();
    test2();
    return 0;
}




