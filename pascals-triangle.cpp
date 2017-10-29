// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//https://leetcode.com/problems/pascals-triangle/description/

#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    vector<int> row;
    
    if(numRows == 0) {
        return result;
    }
    row.push_back(1);
    result.push_back(row);
    for (int i = 1; i < numRows; i++) {
        row.clear();
        row.push_back(1);
        for(int j = 1; j <= i - 1; j++) {
            row.push_back(result[i - 1][j - 1] + result[i - 1][j]); // todo comments
        }
        row.push_back(1);
        result.push_back(row);
    }
    return result;
}

void print(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void test1() {
    vector<vector<int> > result = generate(5);
    print(result);
}


int main() {
    test1();
    
    return 0;
}



