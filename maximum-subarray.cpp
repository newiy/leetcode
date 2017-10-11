
// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//                                0,1, 2,3, 4,5,6, 7, 8
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//https://leetcode.com/problems/maximum-subarray/description/
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int result = nums[0];
    int start = 0;
    int end = 0;
    int sum = 0;
    while ((start < nums.size()) && (end < nums.size())){
        
        sum += nums[end];
        //printf("start %d, end %d\n", start, end);
        result = max(result, sum);

        if (sum <= 0) {
            end++;
            start = end;
            sum = 0;
        } else { // sum > 0
            //printf("start %d, end %d, sum %d\n", start, end, sum);
            
            end++;
            result = max(sum, result);
        }
    }
    return result;
}

void test1() { 
    vector<int> v; // expect 6
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);
    cout << maxSubArray(v)<< endl;
    
}

void test2() {
    vector<int> v; // expect -2
    v.push_back(-2);
     cout << maxSubArray(v) << endl;
}

int main() {
    test1();
    test2();
    return 0;
}



