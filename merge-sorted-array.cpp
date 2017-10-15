// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
//https://leetcode.com/problems/merge-sorted-array/description/

// time complexity: O(m+n), space complexity: O(m+n)

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    
    while(i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (i >= 0) {
        nums1[k] = nums1[i];
        i--;
        k--;
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

void merge_slow(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result;
    int p1 = 0;
    int p2 = 0;
    while(p1 < m && p2 < n) {
        if(nums1[p1] < nums2[p2]) {
            result.push_back(nums1[p1]);
            p1++;
        } else {
            result.push_back(nums2[p2]);
            p2++;
        }
    }
    while (p2 < n) {
        result.push_back(nums2[p2]);
        p2++;
    }
    while (p1 < m) {
        result.push_back(nums1[p1]);
        p1++;
    }
    nums1.clear();
    // nums1 = result;
    nums1.insert(nums1.begin(), result.begin(), result.end()); // append result to begnning of nums1
}

void print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void test1() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    print(v);
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(6);
    print(v1);
    merge(v, 3, v1, 3);
    print(v);
}

void test2() {
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    
//     print(v);
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(6);
    print(v1);
    merge(v, 0, v1, 3);
    print(v);
}

int main() {
//     test1();
     test2();
    
    return 0;
}



