// https://leetcode.com/problems/add-two-numbers/description/

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbersClean(ListNode* l1, ListNode* l2) {    
    ListNode *result = NULL;
    ListNode *cur = result;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL) {
        int l1_val = (l1 != NULL) ? l1->val : 0;
        int l2_val = (l2 != NULL) ? l2->val : 0;
        // do sum
        int temp = l1_val + l2_val + carry;
        if (temp >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        temp %= 10;
        ListNode *node = new ListNode(temp);
        if (result == NULL) {
            cur = node;
            result = cur;
        }
        else {
            cur->next = node;
            cur = cur->next;
        }
        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }
    if (carry == 1) {
        cur->next = new ListNode(1);
    }
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
    ListNode *result = NULL;
    ListNode *cur = result;
    int carry = 0;
    
    while (l1 != NULL && l2 != NULL) {
        
        // do sum
        int temp = l1->val + l2->val + carry;
        if (temp >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        temp %= 10;
        ListNode *node = new ListNode(temp);
        if (result == NULL) {
            cur = node;
            result = cur;
        }
        else {
            cur->next = node;
            cur = cur->next;
        }
        l1 = l1->next;
        l2 = l2->next;
        
    }
    
    while (l1 != NULL) {
        int temp = l1->val + carry;
        if (temp >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        temp %= 10;
        ListNode *node = new ListNode(temp);
        if (result == NULL) {
            cur = node;
            result = cur;
        }
        else {
            cur->next = node;
            cur = cur->next;
        }
        l1 = l1->next;
    }
    
    while (l2 != NULL) {
        int temp = l2->val + carry;
        if (temp >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        temp %= 10;
        ListNode *node = new ListNode(temp);
        if (result == NULL) {
            cur = node;
            result = cur;
        }
        else {
            cur->next = node;
            cur = cur->next;
        }
        l2 = l2->next;
    }
    
    if (carry == 1) {
        cur->next = new ListNode(1);
    }
    
    return result;
}

void printList(ListNode *l) {
    while(l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    // test 3+4 = 7
    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(4);
    printList(l1);
    printList(l2);
    ListNode* result = addTwoNumbersClean(l1, l2);
    printList(result);

    // test 38+48 = 761
    l1 = new ListNode(3);
    l1->next = new ListNode(8);
    l2 = new ListNode(4);
    l2->next = new ListNode(8);
    printList(l1);
    printList(l2);
    result = addTwoNumbersClean(l1, l2);
    printList(result);
    cout << endl;

    // test 83+84 = 68
    l1 = new ListNode(8);
    l1->next = new ListNode(3);
    l2 = new ListNode(8);
    l2->next = new ListNode(4);
    printList(l1);
    printList(l2);
    result = addTwoNumbersClean(l1, l2);
    printList(result);
    cout << endl;

    
    // test 0+168 = 168
    l1 = new ListNode(0);
    l2 = new ListNode(1);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);
    printList(l1);
    printList(l2);
    result = addTwoNumbers(l1, l2);
    printList(result);
    cout << endl;

    
    // test 94+168 = 019
    l1 = new ListNode(9);
    l1->next = new ListNode(4);
    l2 = new ListNode(1);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);
    printList(l1);
    printList(l2);
    result = addTwoNumbers(l1, l2);
    printList(result);
    cout << endl;

    return 0;
}
