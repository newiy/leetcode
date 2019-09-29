//https://leetcode.com/problems/longest-palindrome/
// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    int res = 0;
    bool mid = false;
    unordered_map<char, int> m;
    for(char c : s) {
        m[c]++;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        res += it->second;
        if (res % 2 == 1) {
            res--;
            mid = true;
        }
    }
    return mid ? (res + 1) : res;
}

int main() {
  printf("%d\n", longestPalindrome("abccccdd"));
	return 0;
}
