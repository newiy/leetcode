//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
        return NULL;
    }
    int mid = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    if (mid > 0) {
        vector<int> nums1(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(nums1);
    }
    if (mid < nums.size() - 1) {
        vector<int> nums2(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(nums2);
    }
    return root;
}

void print(TreeNode *t) {
    if(t == NULL) return;
    print(t->left);
    printf("%d ", t->val);
    print(t->right);
}

void test1() {
    int arr[] = {1,2};
    vector<int> v (arr, arr + sizeof(arr)/sizeof(int));
    TreeNode *t = sortedArrayToBST(v);
    print(t);
    printf("done\n");
}

void test2() {
    int arr[] = {1,2, 3, 4, 5, 6, 7};
    vector<int> v (arr, arr + sizeof(arr)/sizeof(int));
    TreeNode *t = sortedArrayToBST(v);
    print(t);
    printf("done\n");
}


void print_vector(vector<int> v) {
    printf("\n----\n");
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n----\n");
}

int main() {
     //test1();
    test2();
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
    
//     vector<int> v2(v.begin(), v.begin() + 1);
//     print_vector(v2);
    
//     vector<int> v3(v.begin(), v.begin() + 0);
//     print_vector(v3);
    
    return 0;
}



