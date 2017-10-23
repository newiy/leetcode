// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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

// use a dummy tree node as level break
TreeNode dummy = TreeNode(0);

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > result;
    if (root == NULL) {
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    // q.push(new TreeNode('#'));
    q.push(&dummy);
    
    // keep values in cur level
    vector<int> v_row;
    
    //int level = 0;

    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        
        // debug code
        //cout << cur->val << endl;
//         if (level >= 3) {
//             break;
//         }
        
        if (cur == &dummy) {
            //level++;
            // cur level is done
            result.push_back(v_row);
            if(q.empty()) {
                break;
            }
            q.push(&dummy);
            v_row.clear();
        } else {
            // new node in cur level
            v_row.push_back(cur->val);
            if (cur->left != NULL) {
                q.push(cur->left);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
            }
        }
        
        
//         v_row.push(cur->val);
        
//         if (cur != NULL) {
//             q.push(cur->left);
//         }
//         if (cur != NULL) {
//             q.push(cur->right);
//         }
//         if (q.front()->val == '#') {
//             v.push_back(v_row);
//             q.pop();
//         }
    }
    reverse(result.begin(), result.end());
    return result;
}

void print(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        vector<int> temp = v[i];
        for (int j = 0; j < temp.size(); j++) {
            printf("%d ", temp[j]);
        }
        printf("\n");
    }
}

void test1() {
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    vector<vector<int> > v = levelOrderBottom(t1);
    print(v);
}

void test2() {
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->left->left = new TreeNode(15);
    t1->left->left->left = new TreeNode(7);
    vector<vector<int> > v = levelOrderBottom(t1);
    print(v);
}


int main() {
    test1();
    test2();
    return 0;
}



