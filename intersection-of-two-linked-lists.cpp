// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 0, len2 = 0;
    ListNode *A, *B;
    A = headA;
    B = headB;
    while(A != NULL) {
        len1++;
        A = A->next;
    }
    while(B != NULL) {
        len2++;
        B = B->next;
    }
    A = headA;
    B = headB;
    while(A != NULL && B != NULL) {
        if (len1 > len2) {
            len1--;
            A = A->next;
        }
        if (len1 < len2) {
            len2--;
            B = B->next;
        }
        if(len1 == len2) {
            if(A->val == B->val) {
                return A;
            }
            A = A->next;
            B = B->next;
        }
    }
    return NULL;
}

void print(ListNode *n) {
    while(n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

int main(){
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(5);
    ListNode *n5 = new ListNode(6);
    ListNode *n6 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n6->next = n3;

    print(n1);
    print(n6);

    ListNode *result = getIntersectionNode(n1, n6);
    print(result);
    return 0;
}




