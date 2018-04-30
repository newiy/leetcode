// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?
//https://leetcode.com/problems/reverse-bits/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;


uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    uint32_t last_bit = 0;
    for (int i = 0; i < 32; i++) {
        last_bit = n & 0x1;
        result |= (last_bit << (31 - i));
        n = n >> 1;
    }
    return result;
}

void test1(){
    printf("%d\n", reverseBits(43261596));
}


int main(){
    test1();
    return 0;
}




