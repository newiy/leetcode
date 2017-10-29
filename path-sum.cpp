//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//https://leetcode.com/problems/path-sum/description/

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


bool isLeaf(TreeNode *root) {
    return root && root->left == NULL && root->right == NULL;
}

bool hasPathSum(TreeNode* root, int sum) {
    
    if(root == NULL) {
        return false;
    }
    
    if (root->val == sum && isLeaf(root)) {
        return true;
    }
    
    bool ret =  hasPathSum(root->left, sum - root->val) || 
            hasPathSum(root->right, sum - root->val);
    
    // printf("called with node-val: %d, sum: %d, ret: %d\n", root->val, sum, ret);
    
    return ret;
}

void print(TreeNode *t) {
    if(t == NULL) return;
    print(t->left);
    printf("%d ", t->val);
    print(t->right);
}

void test0() {
    TreeNode *v = new TreeNode(1);
    v->left = new TreeNode(2);
    bool result = hasPathSum(v, 1);
    printf("result %d\n", result);
    
}

void test1() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->right = new TreeNode(2);
    bool result = hasPathSum(v, 2);
    printf("result %d\n", result);
}

void test2() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    bool result = hasPathSum(v,1);
    printf("result %d\n", result);
}

void test3() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    v->right = new TreeNode(3);
    v->right->left = new TreeNode(4);
    bool result = hasPathSum(v,3);
    printf("result %d\n", result);
}


int main() {
    test2(); // expect false
    
    return 0;
}



