// Given two binary trees, write a function to check if they are equal or not.

// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

//https://leetcode.com/problems/same-tree/description/

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


bool isMirror(TreeNode *p, TreeNode *q) {
    // termination condition: p == NULL || q == NULL
    if(p == NULL && q == NULL) {
        return true;
    } else {
        if (p == NULL || q == NULL) {
            return false;
        }
    }
    
    // recursion
    // p != NULL && q != NULL
    return ((p->val == q->val) && 
             isMirror(p->right, q->left) && 
             isMirror(p->left, q->right));   
}


bool isSameTree(TreeNode* p, TreeNode* q) {
    // termination condition: p == NULL || q == NULL
    if(p == NULL && q == NULL) {
        return true;
    } else {
        if (p == NULL || q == NULL) {
            return false;
        }
    }
    
    // recursion
    // p != NULL && q != NULL
    return ((p->val == q->val) && 
             isSameTree(p->left, q->left) && 
             isSameTree(p->right, q->right));
}

void test1() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    printf("result %d\n", isSameTree(t1, t2));
}

void test2() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    printf("result %d\n", isSameTree(t1, t2));
}

void test3() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(3);
    t2->right = new TreeNode(2);
    printf("result %d\n", isMirror(t1, t2));
}

void test4() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    printf("result %d\n", isMirror(t1, t2));
}

void test5() {
    TreeNode *t1 = new TreeNode(1);
    
    TreeNode *t2 = new TreeNode(1);
    
    printf("result %d\n", isMirror(t1, t2));
}

int main() {
    test3();
    test4();
    test5();
    return 0;
}



