
// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".
//https://leetcode.com/problems/add-binary/description/

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    int pa = a.size() - 1;
    int pb = b.size() - 1;
    int carry = 0;
    string result;
    while(pa >= 0 || pb >= 0) {
        int val_a = 0;
        int val_b = 0;
        if (pa >= 0) {
            val_a = a[pa] - '0';
        } else {
            val_a  = 0;
        }
        if (pb >= 0) {
            val_b = b[pb] - '0';
        } else {
            val_b = 0;
        }

        int temp = val_a + val_b + carry;
        if (temp >= 2) {
            carry = 1;
            result.insert(result.begin(), temp % 2 + '0');
        } else {
            carry = 0;
            result.insert(result.begin(), temp + '0');
        }
        pa--;
        pb--;
    }
    if (carry == 1) {
        result.insert(result.begin(), '1');
    }
    return result;
}

void test1() {
    string a = "100";
    string b = "11";
    string c = addBinary(a, b);
    printf("result1: %s\n", c.c_str());
}

void test2() {
    string a = "0";
    string b = "110";
    string c = addBinary(a, b);
    printf("result2: %s\n", c.c_str());
}

void test3() {
    string a = "101";
    string b = "1";
    string c = addBinary(a, b);
    printf("result3: %s\n", c.c_str());
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}



