
// Given an array and a value, remove all instances of that value in place and return the new length.

// Do not allocate extra space for another array, you must do this in place with constant memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example:
// Given input array nums = [3,2,2,3], val = 3

// Your function should return length = 2, with the first two elements of nums being 2.

//https://leetcode.com/problems/remove-element/description/

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

int removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;
    if (nums.empty()) {
        return 0;
    }
    while ((nums[i] != val) && (i < nums.size())) { // move i to the first index of target val
        i++;
    }
    
    for(j = i + 1; j < nums.size(); j++) {
        if (nums[j] != val) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return i;
}

int main() {
    vector<int> v;
    //43321, 3
//     v.push_back(4);
//     v.push_back(3);
//     v.push_back(3);
//     v.push_back(2);
//     v.push_back(1);
    
    //empty test
//    v.clear();
    
    //3
    v.clear();
    v.push_back(3);
    printf("length %d\n", removeElement(v, 3));
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}



