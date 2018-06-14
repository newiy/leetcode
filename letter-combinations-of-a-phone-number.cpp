// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
void dfs(const string& digits, const vector<vector<char> >& d,
         int l, string &cur, vector<string>& res)
{
    if (l == digits.size()) {
        res.push_back(cur);
        return;
    }
    for (const char c : d[digits[l] - '0']) {
        cur.push_back(c);
        dfs(digits, d, l + 1, cur, res);
        cur.pop_back();
    }
    
}

  

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0) {
        return res;
    }
    int l = 0;
    string cur = "";
    vector<vector<char> > d(10);
    d[0] = {' '};
    d[1] = {};
    d[2] = {'a', 'b', 'c'};
    d[3] = {'d', 'e', 'f'};
    d[4] = {'g', 'h', 'i'};
    d[5] = {'j', 'k', 'l'};
    d[6] = {'m', 'n', 'o'};
    d[7] = {'p', 'q', 'r', 's'};
    d[8] = {'t', 'u', 'v'};
    d[9] = {'w', 'x', 'y', 'z'};
    
    
    dfs(digits, d, l, cur, res);
    return res;
    
}

void test1(){
    vector<string> result;
    string digits = "23";
    result = letterCombinations(digits);
    for (int i = 0; i < result.size(); i++) {
        printf("%s ", result[i].c_str());
    }
    printf("\n");
}



int main(){
    test1();

    return 0;
}



