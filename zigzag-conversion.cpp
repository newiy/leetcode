// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//https://leetcode.com/problems/zigzag-conversion/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;
string convert(string s, int numRows) {
    string result = "";
    vector<string> r(numRows);
    int size = s.size();
    if(size == 0 || numRows == 1 || numRows > size)
        return s;
    int dir = 0, count = 0;
    for(int i = 0; i < size; i++){
        r[count] += s[i];
        if(dir == 0){
            count++;
            if(count == numRows-1){
                dir = 1;
            }
        }
        else if(dir == 1){
            count--;
            if(count == 0){
                dir = 0;
            }
        }
    }
    for(int i = 0; i < numRows; i++){
        result += r[i];
    }
    return result;
}

void test1(){
    string s = "PAYPALISHIRING";
    string res = convert(s, 4);
    printf("%s\n", res.c_str());
}

void test2(){
    string s = "PAYPALISHIRING";
    string res = convert(s, 1);
    printf("%s\n", res.c_str());
}

int main(){
    test1();
    test2();
    return 0;
}




