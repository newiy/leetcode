// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.
// https://leetcode.com/problems/valid-palindrome/description/


#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int convert_to_number(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (c-65);
    } else if(c >= 'a' && c <= 'z') {
        return (c-97);
    } else if (c >= '0' && c <= '9'){
        return c;
    } else {
        printf("shouldn't be here, %c\n", c);
    }
    return -1;
}

bool isPalindrome(string s) {
    if (s.size() == 0) {
        return true;
    }
    int head = 0;
    int tail = s.size() - 1;
    while (head < tail) {
        while(!isalnum(s[head])) {head++;}
        while(!isalnum(s[tail])) {tail--;}
        if (head >= tail)
            return true;
        int a = convert_to_number(s[head]);
        int b = convert_to_number(s[tail]);
        if (a != b)
            return false;
        head++;
        tail--;
    }
    return true;
}


void test1() {
    string s = "A man, a plan, a canal: Panama";
    printf("result is %d\n", isPalindrome(s));
}

void test2() {
    string s = "1a2";
    printf("result is %d\n", isPalindrome(s));
}

void test3() {
    string s = "!!!";
    printf("result is %d\n", isPalindrome(s));
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}



