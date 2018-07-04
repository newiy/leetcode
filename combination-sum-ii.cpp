// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//https://leetcode.com/problems/combination-sum-ii/description/

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
        if ((i != start) && (candidates[i] == candidates[i - 1])) continue;
        solution.push_back(candidates[i]);
        helper(res, solution, candidates, target - candidates[i], i + 1);
        solution.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.size() == 0) return result;
    vector<int> solution;
    sort(candidates.begin(), candidates.end());
    helper(result, solution, candidates, target, 0);
    return result;
}

void test1(){
    vector<int> cand;
    cand.push_back(10);
    cand.push_back(1);
    cand.push_back(2);
    cand.push_back(7);
    cand.push_back(6);
    cand.push_back(1);
    cand.push_back(5);
    vector<vector<int>> result = combinationSum(cand, 8);
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
    cand.push_back(5);
    cand.push_back(2);
    cand.push_back(1);
    cand.push_back(2);
    vector<vector<int>> result = combinationSum(cand, 5);
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



