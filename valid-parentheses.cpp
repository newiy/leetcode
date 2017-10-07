//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//https://leetcode.com/problems/valid-parentheses/description/

// topics: stack

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h> 
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else {
            if (sta.empty()) {
                return false;
            }
            
            if (   (s[i] == ')' && sta.top() == '(') 
                || (s[i] == ']' && sta.top() == '[') 
                || (s[i] == '}' && sta.top() == '{') ){
                sta.pop();
            } else {
                return false;
            }
        
        }
    }
    if (sta.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s = "{}[]()";
    printf("%d\n", isValid(s));
    s = "{[]}";
    printf("%d\n", isValid(s));
    s = "{[}()";
    printf("%d\n", isValid(s));
    s = "";
    printf("%d\n", isValid(s));
    s = "(()";
    printf("%d\n", isValid(s));
    s = "]";
    printf("%d\n", isValid(s));
    return 0;
}



