// https://leetcode.com/problems/roman-to-integer/description/
// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
using namespace std;


int conv(char a) {
    if (a == 'I')
        return 1;
    else if (a == 'V')
        return 5;
    else if (a == 'X')
        return 10;
    else if (a == 'L')
        return 50;
    else if (a == 'C')
        return 100;
    else if (a == 'D')
        return 500;
    else if (a == 'M')
        return 1000;
}

int romanToInt(string s) {
    int i = 0;
    int result = 0;
    int prev = 0;
    
    while(i < s.size()) {
        if (prev < conv(s[i])) {
            result = result + conv(s[i]) - 2 * prev;
        } else {
            result += conv(s[i]);
        }
        prev = conv(s[i]);
        i++;
    }
    return result;
}

int main() {
    string s = "III";
    printf("%d\n", romanToInt(s));
    
    s = "IV";
    printf("%d\n", romanToInt(s));
    
    s = "VI";
    printf("%d\n", romanToInt(s));
    
    s = "XCIX";
    printf("%d\n", romanToInt(s));

    return 0;
}
