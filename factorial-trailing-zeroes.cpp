// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.
//https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int trailingZeroes(int n) {
    long int base = 5;
    int result = 0;
    while(n >= base) {
        result += n/base;
        base *= 5;
    }
    return result;
}

void test1()
{
    printf("%d\n", trailingZeroes(5));
    printf("%d\n", trailingZeroes(6));
}


int main(){
    test1();
    return 0;
}




