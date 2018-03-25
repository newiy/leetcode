//Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//https://leetcode.com/problems/single-number/description/

#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}


void test1() {
    vector<int> vect{ 10, 10, 2, 4, 5, 4, 5 }; 
    printf("result is %d\n", singleNumber(vect));
}

void test2() {

}



int main() {
    test1();
    //test2();
    return 0;
}



