// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?
// https://leetcode.com/problems/linked-list-cycle/description/


#include <vector>
#include <queue>
#include <string>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    if (head->next == NULL) return false;
    ListNode *fast = head->next->next;
    ListNode *slow = head;
    while(fast != NULL) {
        if (fast == slow) {
            return true;
        }
        slow = slow->next;
        if (fast->next != NULL) {
            fast = fast->next->next;
        } else {
            return false;
        }
    }
    return false;
}


void test1() {
    ListNode *node1 = new ListNode(0);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(0);
    ListNode *node5 = new ListNode(1);
    ListNode *node6 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node1;
    printf("has cycle? %s\n", hasCycle(node1) ? "YES" : "NO");
}

void test2() {
    ListNode *node1 = new ListNode(0);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    node1->next = node2;
    node2->next = node3;
    printf("has cycle? %s\n", hasCycle(node1) ? "YES" : "NO");
}

void test3() {
    ListNode *node1 = new ListNode(0);
    printf("has cycle? %s\n", hasCycle(node1) ? "YES" : "NO");
}


int main() {
    test1();
    test2();
    test3();
    return 0;
}



