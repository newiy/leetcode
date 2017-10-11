
// https://leetcode.com/problems/implement-strstr/description/
// Implement strStr().

// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h> 

using namespace std;


int strStr2(string haystack, string needle) {
    int h = 0;
    int n = 0;
    int h_head = 0;
    
    if (needle.size() > haystack.size()) {
        return -1;
    }
    
    if (needle.empty()) {
        return 0;
    }
    
    for (h = h_head; h < haystack.size(); ) {
        if (haystack[h] == needle[n]) {
            h++;
            n++;
            if (n == needle.size()) {
                return h_head;
            }
        } else {
            n = 0;
            h_head++;
            h = h_head;
        }
    }

    return -1;
}
                

vector<int> KMPpreprocessing(string s) {
    int n = s.size();
    vector<int> match(n,-1);
    int j = -1;
    for(int i=1; i<n; i++) {
        while(j>=0 && s[i]!=s[j+1]) j = match[j];
        if(s[i]==s[j+1]) j++;
        match[i] = j;
    }
    for (int i = 0; i < match.size(); i++) {
        printf("%d ", match[i]);
    }
    return match;
}


int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    if(haystack.empty()) return -1;
    int m = haystack.size(), n = needle.size();
    vector<int> match = KMPpreprocessing(needle);
    int j = -1;
    
    for(int i = 0; i < m; i++) {
        while(j >= 0 && haystack[i] != needle[j + 1]) j = match[j];
        if(haystack[i] == needle[j + 1]) j++;
        if(j == n-1) {
            return (i - n + 1);
        }
    }
    return -1;

}

int main() {
//     string h = "adbue";
//     string n = "bu";
    
    string h = "participate in parachute";
    string n = "abacababc";
    
//     h = "abcbce";
//     n = "bce";
    printf("index %d\n", strStr(h, n));
    return 0;
}



