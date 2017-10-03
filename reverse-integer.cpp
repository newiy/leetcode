// https://leetcode.com/problems/reverse-integer/description/
// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
using namespace std;


int reverse(int x) {
    int sign = 0;
    int result = 0;
    if (x == INT_MIN) {
        return 0;
    }
    if (x < 0) {
        sign = 1;
        x = -x;
    }
    
    //cout << x << endl;
    while(x > 0) {
        //cout << x << endl;
        int temp = x % 10;
        if (result > (INT_MAX - temp) / 10)
            return 0;

        result = result * 10 + temp; // overflow means result * 10 + temp > INT_MAX
        //printf("result is %d\n", result);
        if (result < 0) {
            printf("overflow\n");
            return 0; //overflow
        }
        x = x/10;
        
    }
    if (sign == 1) {
        result = -result;
    }
    return result;
}


// wrong way to calcualte absolute value of x
// int abs(int x) {
//     if (x == INT_MIN) {
//         return 0;
    
//     if (x < 0) {
//         return -x;
//     } else {
//         return x;
//     }
// }

int main() {
    int x = 0;
    
    x = 0;
    cout << reverse(x) << endl;
    x = 123;
    cout << reverse(x) << endl;
    x = -123;
    cout << reverse(x) << endl;
    
    x = INT_MAX;
    cout << x << endl;
    cout << reverse(x) << endl;
    
//     if x < 0, then -x >0 ? only if x!= int_min
    x = INT_MIN;
    cout << x << endl;
    cout << reverse(x) << endl;
    
    x = 1534236469;
    cout << x << endl;
    cout << reverse(x) << endl;
    cout << INT_MAX;
    return 0;
}
