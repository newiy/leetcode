// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"
//https://leetcode.com/problems/longest-palindromic-substring/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
string res = "";

void helper(string s, int left, int right) {
    string cur = "";
    while((left >= 0 && right < s.length()) && (s[left] == s[right])) {
        left--;
        right++;
    }
    cur = s.substr(left + 1, right - left - 1);
    if (res.length() < cur.length())
    res = cur;
}

string longestPalindrome(string s) {
    for (int i = 0; i < s.length(); i++) {
        helper(s, i, i);
        helper(s, i, i + 1);
    }
    return res;
}


void test1(){
    string s = "ababc";
    string res = longestPalindrome(s);
    printf("%s\n", res.c_str());
}


int main(){
    test1();
    return 0;
}




