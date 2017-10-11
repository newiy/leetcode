// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

string conv(string s) {
    char cur = s[0];
    int count = 1;
    string result = "";
    for(int i = 1; i < s.size(); i++) {
//        printf("cur %c, s[%d] %c\n", cur, i, s[i]);
        if (cur == s[i]) {
            count++;
        } else {
            result.push_back(count+'0');
            result.push_back(cur);
            cur = s[i];
            count = 1;
        }
    }
    result.push_back(count+'0');
    result.push_back(cur);
    return result;
}

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    string result = "1";
    while(n > 1) {
        //printf("result (%d) %s\n", n, result.c_str());
        result = conv(result);
        n--;
    }
    return result;
}

int main() {
//    cout << conv("1112211"); // expect "312211"
    

    string result = countAndSay(4);
    printf("result %s\n", result.c_str());
    return 0;
}



