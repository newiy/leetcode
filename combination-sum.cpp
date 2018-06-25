// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
// https://leetcode.com/problems/combination-sum/description/
    
#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

void helper(vector<vector<int>>&res, vector<int>& solution, vector<int>& candidates, int target, int start) 
{
    if (target < 0) return;
    if (target == 0) {
        res.push_back(solution);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        solution.push_back(candidates[i]);
        helper(res, solution, candidates, target - candidates[i], i);
        solution.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.size() == 0) return result;
    vector<int> solution;
    helper(result, solution, candidates, target, 0);
    return result;
}

void test1(){
    vector<int> cand;
    cand.push_back(2);
    cand.push_back(3);
    cand.push_back(6);
    cand.push_back(7);
    vector<vector<int>> result = combinationSum(cand, 7);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
    
void test2(){
    vector<int> cand;
    cand.push_back(2);
    cand.push_back(3);
    cand.push_back(5);
    vector<vector<int>> result = combinationSum(cand, 8);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}


int main(){
    test1();
    test2();
    return 0;
}



