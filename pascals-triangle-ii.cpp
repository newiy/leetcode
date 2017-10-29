// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> result;
    vector<int> prev_row;
    result.push_back(1);
    
    for (int i = 1; i <= rowIndex; i++) {
        result.clear();
        result.push_back(1);
        for (int j = 1; j <= i - 1; j++) {
            result.push_back(prev_row[j - 1] + prev_row[j]);
        }
        result.push_back(1);
        prev_row = result;
    }
    return result;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void test1() {
    vector<int> result = getRow(4);
    print(result);
}


int main() {
    test1();
    
    return 0;
}



