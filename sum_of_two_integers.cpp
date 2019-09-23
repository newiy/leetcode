//https://leetcode.com/problems/sum-of-two-integers/
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = -2, b = 3
// Output: 1

#include <iostream>
using namespace std;

int getSum(int a, int b){
  if (b == 0) return a;
  int sum = a ^ b;
  uint carry = (uint)(a & b) << 1;
  return getSum(sum, (int)carry);
}

int main() {
	printf("%d\n", getSum(2,3));
  printf("%d\n", getSum(1,-2));
  
	return 0;
}
