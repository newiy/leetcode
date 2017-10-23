// Given a binary tree, find its maximum depth.

// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


void test1() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    printf("result %d\n", maxDepth(t1));
}

void test2() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(3);
    t1->left->right = new TreeNode(3);
    t1->left->right->left = new TreeNode(3);
    printf("result %d\n", maxDepth(t1));
}

void test3() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(3);
    t2->right = new TreeNode(2);
    //printf("result %d\n", isMirror(t1, t2));
}

void test4() {
    TreeNode *t1 = new TreeNode(1);
    t1->right = new TreeNode(3);
    t1->right->left = new TreeNode(2);
    printf("result %d\n", maxDepth(t1));
}

void test5() {
    TreeNode *t1 = new TreeNode(1);
    
    //printf("result %d\n", isMirror(t1, t2));
}

int main() {
    test1();
    test2();
    test4();
    return 0;
}



