//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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

int minDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL)
        return minDepth(root->right) + 1;
    else if (root->right == NULL)
        return minDepth(root->left) + 1;
    else
        return (min(minDepth(root->left), minDepth(root->right)) + 1);
}

void print(TreeNode *t) {
    if(t == NULL) return;
    print(t->left);
    printf("%d ", t->val);
    print(t->right);
}

void test1() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->right = new TreeNode(2);
    bool result = minDepth(v);
    printf("result %d\n", result);
}

void test2() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    bool result = minDepth(v);
    printf("result %d\n", result);
}

void test3() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    v->right = new TreeNode(3);
    v->right->left = new TreeNode(4);
    int result = minDepth(v);
    printf("result %d\n", result);
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}



