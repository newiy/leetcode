// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
// https://leetcode.com/problems/generate-parentheses/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
void helper(vector<string> &result, string &row, int left, int right)
{
    if (left > right) {
        return;
    }
    if (left == 0 && right == 0) {
        result.push_back(row);
    }
    if (left > 0) {
        row.push_back('(');
        helper(result, row, left - 1, right);
        row.pop_back();
    }
    if (right > 0) {
        row.push_back(')');
        helper(result, row, left, right - 1);
        row.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string row;
    helper(result, row, n, n);
    return result;
}

void test1(){
    vector<string> result = generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        printf("%s\n", result[i].c_str());
    }
}


int main(){
    test1();
    return 0;
}



