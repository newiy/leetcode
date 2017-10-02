// Given a string, find the length of the longest substring without repeating characters.

// Examples:

// Given "abcabcbb", the answer is "abc", which the length is 3.

// Given "bbbbb", the answer is "b", with the length of 1.

// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

void printMap(unordered_map<char, int> mymap) {
    cout << "print";
    for (auto it : mymap) 
        std::cout << " " << it.first << ":" << it.second<<endl;
    cout<<endl;
}

int lengthOfLongestSubstring(string s) {
    int start = 0;
    int end = 1;
    if (s.size() <= 1) {
        return s.size();
    }
    // int len = 1; // assume len(s)>=1 // len is always = end - start?
    int max_len = 1;
    int start_save = 0;
    int end_save = 0;
    unordered_map<char, int> mp;
    mp[s[start]] = 1;
    while (end < s.size()) {
        //printMap(mp);
        if (mp.find(s[end]) == mp.end() || (mp[s[end]] == 0)) { // s[end] doesn't exist in current slide window
            //printf("end %d\n", end);
            mp[s[end]] = 1;
            end++;
        } else {    //duplicate
            //printf("exist:end %d\n", end);
            while(s[start] != s[end]) {
                mp[s[start]] = 0;
                start++;
            }
            start++;
            end++;
        }
        // max_len = max(len, max_len);
        //printf("start %d, end %d\n", start, end);
        int len = end - start;
        if (len > max_len) { // save max len, and the corresponding start and end position
            start_save = start;
            end_save = end;
            max_len = len;
        }
        
    }
    printf("start_save %d, end_save %d\n", start_save, end_save);
    cout << "longest substr: " << s.substr(start_save, max_len) << endl;
    return max_len;
}

int main() {
    // test 3
     string str = "abc";
     int result = lengthOfLongestSubstring(str);
     cout << result << endl;
    
    // test 3
     str = "abcabcbb";
     result = lengthOfLongestSubstring(str);
     cout << result << endl;
    
    // test 3
    str = "pwwkew";
    result = lengthOfLongestSubstring(str);
    cout << result << endl;
    
    // test, 1
    str = "bbbbb";
    result = lengthOfLongestSubstring(str);
    cout << result << endl;
    
    // test,5 
    str = "tmmzuxt";
    result = lengthOfLongestSubstring(str);
    cout << result << endl;
    
    return 0;
}
