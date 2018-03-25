// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/


#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            result += (prices[i] - prices[i - 1]);
        }
        
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



