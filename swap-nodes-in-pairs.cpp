// Given a linked list, swap every two adjacent nodes and return its head.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Note:

// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, only nodes itself may be changed.
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include <vector>
#include <stack>
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

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *n1 = dummy;
    ListNode *n2 = head;
    while(n2 != NULL && n2->next != NULL) {
        ListNode *n3 = n2->next->next;
        n1->next = n2->next;
        n2->next->next = n2;
        n2->next = n3;
        n1 = n2;
        n2 = n2->next;
    }
    return dummy->next;
}

void printList(ListNode* head)
{
    ListNode *n = head;
    while(n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

void test1(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printList(n1);
    printList(swapPairs(n1));
}


int main(){
    test1();
    return 0;
}



