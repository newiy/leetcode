// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
//https://leetcode.com/problems/excel-sheet-column-title/description/


#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

string convertToTitle(int n) {
    string result;
    while (n > 0) {
        result.insert(result.begin(), (n - 1) % 26 + 65);
        n = (n - 1) / 26;
    }  
    return result;
}


int main(){
    printf("convert %d to title: %s\n", 28, convertToTitle(28).c_str());
    printf("convert %d to title: %s\n", 1, convertToTitle(1).c_str());
    return 0;
}




