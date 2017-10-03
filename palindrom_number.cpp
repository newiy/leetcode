//Determine whether an integer is a palindrome. Do this without extra space.
//https://leetcode.com/problems/palindrome-number/description/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
using namespace std;


bool isPalindrome(int x) {
    if (x < 0) return false;
    int save_x = x;
    int result = 0;
    while (x > 0) {
        if (result > (INT_MAX - x % 10) / 10) {
            // reverse of a palin should never overflow => overflow should not be palin
            return false;
        }
        result = result * 10 + x % 10;
        x /= 10;
        
    }
    return save_x == result;
}

int main() {
    int x = 0;
    
    // test 0
    x = 0;
    cout << isPalindrome(x) << endl;
    
    // test positive non-palin
    x = 123;
    cout << isPalindrome(x) << endl;
    
    // test positive palin
    x = 808;
    cout << isPalindrome(x) << endl;
    
    // test nagative
    x = -123;
    cout << isPalindrome(x) << endl;
    
    
    // test overflow
    x = INT_MAX;
    cout << isPalindrome(x) << endl;
    
    
    // test nagative
    x = INT_MIN;
    cout << isPalindrome(x) << endl;
  
    // test overflow
    x = 1534236469;
    cout << isPalindrome(x) << endl;

    return 0;
}
