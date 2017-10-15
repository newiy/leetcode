nclude <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

int mySqrt(int x) {
    long a = 1;
    int right = 0;
    // int left = 1;
    if (x == 0) return 0;
    while(1) {
        a = a * 2;
        if (x == a * a) {
            return a;
        } else if (x < a * a) {
            right = a;
            break;
        }
    }
    //printf("a=%d, (a/2)^2=%d < %d < a^2=%d\n", a, (a/2) * (a/2), x, a*a);
    // int mid = 0;
    int left = a/2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        long temp = (long)mid * mid; // cast to long explicitly otherwise will overflow int
        //printf("mid=%d, mid^2=%ld, x=%d\n", mid, temp, x);
        if (temp == x) {
            return mid;
        } else if (temp < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        //printf("left %d, right %d, mid %d\n", left, right, mid);
    }
    return right;
}

void test1() {
    int x = 35;//5
    printf("result 1: %d\n", mySqrt(x));
}

void test2() {
    int x = 36;//6
    printf("result 2: %d\n", mySqrt(x));
}

void test3() {
    int x = 12;//3
    printf("result 3: %d\n", mySqrt(x));
}

void test4() {
    int x = 2147395599; // 2147395599;
    printf("sqrt(%d)=%d\n", x, mySqrt(x));
}

int main() {
//     test1();
//     test2();
//     test3();
    test4();
    return 0;
}



