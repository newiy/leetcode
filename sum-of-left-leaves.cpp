// https://leetcode.com/problems/sum-of-left-leaves/
// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return 0;
    int result = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (t->left && (!t->left->left && !t->left->right)) {
            result += t->left->val;
        }
        if (t->left) {
            q.push(t->left);
        }
        if (t->right) {
            q.push(t->right);
        }
    }
    return result;
}

void print(TreeNode* root) {
    if (root == NULL) return;
    print(root->left);
    printf("%d ", root->val);
    print(root->right);
}

int main() {
    TreeNode* t = new TreeNode(3);
    t->left = new TreeNode(9);
    t->right = new TreeNode(20);
    t->right->left = new TreeNode(15);
    t->right->right = new TreeNode(7);
    printf("%d\n", sumOfLeftLeaves(t));
    
	  return 0;
}
