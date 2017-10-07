//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//https://leetcode.com/problems/merge-two-sorted-lists/description/

// topics: linked list, merge sort

#include <vector>
#include <unordered_map>
#include <string>
#include <limits.h> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* result = NULL; // points to the first node in result if result != null; otherwise null
    ListNode* cur = result;  // points to the last node in result if result != null; otherwise null
    
    
    // handle corner cases first, or
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) { // append node of small value to result
            if (result == NULL) { // handle first node in result
                cur = l1;
                result = l1;
                l1 = l1->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
        } else {
            if (result == NULL) { // handle first node in result
                cur = l2;
                result = l2;
                l2 = l2->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
    }
    
    // append remaining of l1 to result
    if (l1 != NULL) {\
        cur->next = l1;
    }
    
    // append remaining of l2 to result
    if (l2 != NULL) {
        cur->next = l2;
    }
    return result;
}


int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);
    printList(l1);
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    printList(l2);
    ListNode *result = mergeTwoLists(l1, l2);
    printList(result);

    
    // test null cases
    ListNode *l3 = NULL;
    ListNode *l4 = new ListNode(2);
    result = mergeTwoLists(l3, l4);
    printList(result);
    
    ListNode *l5 = NULL;
    result = mergeTwoLists(l3, l5);
    printList(result);
    return 0;
}



