// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

// Return the quotient after dividing dividend by divisor.

// The integer division should truncate toward zero.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Note:

// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
// https://leetcode.com/problems/divide-two-integers/description/
    
#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

long divider(long d1, long d2) {
    if (d1 < d2) return 0;
    long sum = d2;
    long mul = 1;
    while(sum + sum <= d1) {
        sum += sum;
        mul += mul;
    }
    return mul + divider(d1 - sum, d2);
}

int divide(int dividend, int divisor) {
    int sign = 1;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    
    long ldividend = abs((long)dividend);
    long ldivisor = abs((long)divisor);
    if (ldividend < ldivisor) return 0;
    long long result = divider(ldividend, ldivisor);
    if(result > INT_MAX) {
        if (sign == 1)
            return INT_MAX;
        else 
            return INT_MIN;
    }
    return (int)(sign * result);
}

void test1(){
    printf("%d\n", divide(8, 4));
}

void test2() {
    printf("%d\n", divide(-2147483648, -1));
}


int main(){
    test1();
    test2();
    return 0;
}



