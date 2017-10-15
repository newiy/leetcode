// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.
//https://leetcode.com/problems/climbing-stairs/description/

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 1 || n == 0) return 1;
    int b = 2;
    int a = 1;
    int result = 0;
    for (int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
        printf("result %d, b %d, a %d \n", result, b, a);
    }
    return b;
}

void test1() {
    printf("%d\n", climbStairs(5));
}

void test2() {
    printf("%d\n", climbStairs(2));
}

int main() {
    test1();
    test2();
    return 0;
}



