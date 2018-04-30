// Given a column title as appear in an Excel sheet, return its corresponding column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//https://leetcode.com/problems/excel-sheet-column-number/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int titleToNumber(string s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result = result * 26 + s[i] - 65 + 1;
    }
    return result;
}

void test1()
{
    printf("%d\n", titleToNumber("A"));
    printf("%d\n", titleToNumber("AB"));
}


int main(){
    test1();
    return 0;
}




