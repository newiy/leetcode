// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.
//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *prev = head;
    ListNode *cur = head->next;
    while(cur != NULL) {
        if (prev->val == cur->val) {
            // duplicates
            prev->next = cur->next;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

void print(ListNode *l) {
    while(l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

void test1() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(1);
    l->next->next = new ListNode(1);
    l->next->next->next = new ListNode(2);
    print(l);
    print(deleteDuplicates(l));
}

void test2() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(3);
    print(l);
    print(deleteDuplicates(l));
}

int main() {
    test1();
    test2();
    return 0;
}



