/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing
together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1. Using dummy node

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode dummy(-1);
    ListNode* tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (l1 == NULL)
        {
            tail->next = l2;
            break;
        }
        if (l2 == NULL)
        {
            tail->next = l1;
            break;
        }
        if (l1->val <= l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    return dummy.next;
}

// 2. Using Recursion
/*
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* result = NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val)
    {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }
    return result;
} */

/* Utility Function to insert a node at
the beginging of the linked list */
void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = new ListNode(0);

    /* put in the data */
    new_node->val = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Utility Function to print nodes in a given linked list */
void printList(ListNode* node)
{
    while (node->next != NULL)
    {
        std::cout << node->val << "->";
        node = node->next;
    }
    std::cout << node->val << std::endl;
}

// Driver code
int main()
{
    /* Start with the empty list */
    ListNode* res = NULL;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;

    /* Let us create two sorted linked lists
    to test the functions
    Created lists, l1: 1->2->4, l2: 1->3->4 */
    push(&l1, 4);
    push(&l1, 2);
    push(&l1, 1);

    std::cout << "Linked List L1 : \n";
    printList(l1);

    push(&l2, 4);
    push(&l2, 3);
    push(&l2, 1);

    std::cout << "Linked List L2 : \n";
    printList(l2);

    res = mergeTwoLists(l1, l2);

    std::cout << "Merged Linked List is: \n";
    printList(res);

    return 0;
}
