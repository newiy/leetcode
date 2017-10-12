
// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.
//https://leetcode.com/problems/plus-one/description/
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int index = digits.size() - 1;
    int carry = 1;
    while(index >= 0) {
        int temp = digits[index] + carry;
        if(temp >= 10) {
            carry = 1;
            digits[index] = temp % 10;
        } else {
            carry = 0;
            digits[index] = temp;
        }
        index--;
    }
    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

void print(vector<int>& digits) {
    for (int i = 0; i < digits.size(); i++) {
        printf("%d ", digits[i]);
    } 
    printf("\n");
}

void test1() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(9);
    plusOne(v);
    print(v);
}

void test2() {
    vector<int> v;
    v.push_back(9);
    v.push_back(9);
    v.push_back(9);
    plusOne(v);
    print(v);    
}

void test3() {
    vector<int> v;
    v.push_back(0);
    plusOne(v);
    print(v);    
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}



