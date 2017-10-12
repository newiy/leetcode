
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, 
// Given s = "Hello World",
// return 5.
#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int index = s.size() - 1;
    int count = 0;
    if(s.empty()) {
        return 0;
    }
    while(s[index] == ' ') {
        index--;
    }
    while (index >= 0) {
        if(s[index] != ' ') {
            count++;
        } else {
            //printf("index %d\n", index);
            break;
        }
        index--;
    }
    return count;
}

void test1() {
    string s = "  hello  ";
    printf("%d\n", lengthOfLastWord(s));
}

void test2() {
    
}

int main() {
    //string s = "Hello World";
    
    //string s = "  ";
//     string s = "hello  ";
//     printf("%d\n", lengthOfLastWord(s));
    test1();
    return 0;
}



