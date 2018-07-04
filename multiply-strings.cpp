// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//https://leetcode.com/problems/multiply-strings/description/


#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if (num1.size() == 0 || num2.size() == 0) {
        return "0";
    }
    string result;
    vector<int> v(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = product + v[p2];
            v[p1] += sum / 10;
            v[p2] = sum % 10;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!(v[i] == 0 && result.size() == 0)) {
            result += (v[i] + '0');
        }
    }
    if (result.size() == 0) return "0";
    return result;
}

void test1(){
    string num1 = "123";
    string num2 = "456";
    printf("%s\n", multiply(num1, num2).c_str());
}
    
void test2(){
    string num1 = "2";
    string num2 = "3";
    printf("%s\n", multiply(num1, num2).c_str());
}


int main(){
    test1();
    //test2();
    return 0;
}



