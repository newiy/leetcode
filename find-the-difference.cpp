// https://leetcode.com/problems/find-the-difference/
// Given two strings s and t which consist of only lowercase letters.

// String t is generated by random shuffling string s and then add one more letter at a random position.

// Find the letter that was added in t.


#include <iostream>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) {
    char result = 0;
    for (char c : s) {
        result ^= c;
    }
    for (char c : t) {
        result ^= c;
    }
    return result;
}
    
// char findTheDifference(string s, string t) {
//     unordered_map<char, int> m;
//     for(char c : s) m[c]++;
//     for(char c : t) {
//       if (--m[c] < 0) return c;
//     }
// }

int main() {
  string s = "abcd";
  string t = "adcbe";
	printf("%c\n", findTheDifference(s, t));
  
	return 0;
}
