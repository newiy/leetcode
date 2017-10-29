//Given a binary tree, determine if it is height-balanced.
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//https://leetcode.com/problems/balanced-binary-tree/description/

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

int getHeight(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }
    int left = getHeight(root->left);
    if (left == -1) {
        return -1;
    }
    int right = getHeight(root->right);
    if(right == -1) {
        return -1;
    }
    if(abs(left - right) > 1) {
        return -1;
    }
    printf("left %d, right %d\n", left, right);
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
    if (getHeight(root) == -1) {
        return false;
    } else {
        return true;
    }
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
    bool result = isBalanced(v);
    printf("result %d\n", result);
}

void test2() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    bool result = isBalanced(v);
    printf("result %d\n", result);
}

void test3() {
    TreeNode *v = new TreeNode(0);
    v->left = new TreeNode(1);
    v->left->left = new TreeNode(2);
    v->right = new TreeNode(3);
    bool result = isBalanced(v);
    printf("result %d\n", result);
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}



