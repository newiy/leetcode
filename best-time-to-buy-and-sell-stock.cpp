// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Example 1:
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5

// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
// Example 2:
// Input: [7, 6, 4, 3, 1]
// Output: 0

// In this case, no transaction is done, i.e. max profit = 0.
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/


#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int diff = 0;
    
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min) {
            min = prices[i];
        } else {
            diff = max(diff, prices[i] - min);
        }
    }
    return diff;
}

void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void test1() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(arr, arr + sizeof(arr) / sizeof(int));
    print(prices);
    printf("max profit: %d\n", maxProfit(prices));
}

void test2() {
    int arr[] = {7, 6, 4, 3, 1};
    vector<int> prices(arr, arr + sizeof(arr) / sizeof(int));
    print(prices);
    printf("max profit: %d\n", maxProfit(prices));
}


int main() {
    test1();
    test2();
    return 0;
}



