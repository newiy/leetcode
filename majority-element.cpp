// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.
    
//https://leetcode.com/problems/majority-element/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    int result = 0;
    int cnt = 0;
    for (int num : nums) {
        if (cnt == 0) {
            result = num;
            cnt++;
        } else {
            if (num == result) {
                cnt++;
            } else {
                cnt--;
            }
        }
    }
    return result;
}

void test1()
{
    vector<int> vc;
    vc.push_back(2);
    vc.push_back(1);
    vc.push_back(3);
    vc.push_back(1);
    vc.push_back(1);
    printf("%d\n", majorityElement(vc));
}


int main(){
    test1();
    return 0;
}




