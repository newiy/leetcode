// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
// https://leetcode.com/problems/min-stack/description/

#include <vector>
#include <stack>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (minS.empty() || minS.top() >= x) {
            minS.push(x);
        }
        S.push(x);
    }
    
    void pop() {
        if (S.top() == minS.top()) {
            minS.pop();
        }
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
    stack<int> minS;
    stack<int> S;
};


void test1() {
    MinStack *obj = new MinStack();
    obj->push(3);
    obj->push(1);
    obj->push(2);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    printf("top: %d, min: %d\n", param_3, param_4);
}

void test2() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    printf("min:%d\n", minStack->getMin());   //--> Returns -3.
    minStack->pop();
    printf("top %d\n", minStack->top());      //--> Returns 0.
    printf("min:%d\n", minStack->getMin());   //--> Returns -2.
}

void test3() {
    MinStack *minStack = new MinStack();
    minStack->push(2147483646);
    minStack->push(2147483646);
    minStack->push(2147483647);
    printf("top:%d\n", minStack->top());   
    minStack->pop();
    printf("min:%d\n", minStack->getMin());
    minStack->pop();
    printf("min:%d\n", minStack->getMin());
    minStack->pop();
    minStack->push(2147483647);
    printf("top %d\n", minStack->top());      
    printf("min:%d\n", minStack->getMin());   
    minStack->push(-2147483648);
}



int main() {
    test1();
	test2();
    test3();
    return 0;
}

