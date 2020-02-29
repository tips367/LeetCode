/*
Sort a linked list in O(n log n) time using constant space complexity.

Example:

Input: 4->2->1->3
Output: 1->2->3->4
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void frontBackSplit(ListNode* source, ListNode** frontRef, ListNode** backRef)
{
    ListNode* slow;
    ListNode* fast;
    slow = source;
    fast = source->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

ListNode* mergeTwoSortedList(ListNode* a, ListNode* b)
{
    ListNode dummy(-1);
    ListNode* tail = &dummy;
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }
    return dummy.next;
}

ListNode* sortList(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;
    ListNode* a;
    ListNode* b;
    frontBackSplit(head, &a, &b);
    a = sortList(a);
    b = sortList(b);
    head = mergeTwoSortedList(a, b);
    return head;
}

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
    ListNode* a = NULL;

    /* Let us create a unsorted linked lists to test the functions
    Created lists shall be a: 4->2->3->1 */
    push(&a, 1);
    push(&a, 3);
    push(&a, 2);
    push(&a, 4);

    std::cout << "Unsorted Linked List is : \n";
    printList(a);

    a = sortList(a);

    std::cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}