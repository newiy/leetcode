//Write a function to find the longest common prefix string amongst an array of strings.if
//https://leetcode.com/problems/longest-common-prefix/description/

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
  
using namespace std;



int shortest_str_size(vector<string>& strs) {
    int length = INT_MAX;
    if (strs.empty()) {
        return 0;
    }
    for(int i = 0; i < strs.size(); i++) {
        length = (length > strs[i].size() ? strs[i].size() : length);
    }
    return length;
}

string longestCommonPrefix(vector<string>& strs) {
    string result;
    
    int length = shortest_str_size(strs);
    
    
    for (int i = 0; i < length; i++) {
        int temp = strs[0][i];
        int all_equals = 1;
        for(int j = 1; j < strs.size(); j++) {
            if (temp != strs[j][i]) {
                all_equals = 0;
                break; // early termination
            }    
        }
        if (all_equals == 0) {
            return result; // early termination
        } else {
            result.push_back(temp);
        }
    }
    return result;
    
}


int main() {
    vector<string> strs;
    string s1 = "apple";
    string s2 = "ape";
    string s3 = "april";
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    printf("%s\n", longestCommonPrefix(strs).c_str()); // expect "ap"
    
    s1 = "apple";
    strs.clear();
    strs.push_back(s1);
    printf("%s\n", longestCommonPrefix(strs).c_str());
   
    //test empty string array, expect ''
    strs.clear();
    printf("common string is %s\n",longestCommonPrefix(strs).c_str());
    
    // test non-empty string array with empty strings, expect ''
    s1 = "";
    s2 = "";
    s3 = "";
    strs.clear();
    strs.push_back(s1);
    strs.push_back(s2);
    strs.push_back(s3);
    printf("common string is '%s'\n",longestCommonPrefix(strs).c_str());
    return 0;
}

// camel case: strSize, snake case: str_size

