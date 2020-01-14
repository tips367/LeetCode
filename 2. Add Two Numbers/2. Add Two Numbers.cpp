/*
You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order
and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 0 -> 8
Explanation : 342 + 465 = 807.
*/

#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
};

//Utility function
void append(struct ListNode** head_ref, int new_data)
{
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* last = *head_ref;
    new_node->val = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

//Utility function
void printList(ListNode* node)
{
    while (node->next != NULL)
    {
        std::cout << node->val << "->";
        node = node->next;
    }
    std::cout << node->val << std::endl;
}

/*
// 1. Simple approach (Runtime 20 ms)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* result = NULL;
    int carry = 0, sum;
    while (l1 != NULL && l2 != NULL)
    {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        append(&result, sum % 10);
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        sum = l1->val + carry;
        carry = sum / 10;
        append(&result, sum % 10);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        sum = l2->val + carry;
        carry = sum / 10;
        append(&result, sum % 10);
        l2 = l2->next;
    }
    if (carry > 0)
        append(&result, carry);
    return result;
}
*/

// 2. Another approach (Runtime 8 ms)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* result = tempNode;
    int carry = 0, sum = 0;
    while (l1 != NULL && l2 != NULL)
    {
        tempNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode = tempNode->next;
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        tempNode->val = sum % 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = l1 ? l1 : l2;
    while (l1 != NULL)
    {
        tempNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode = tempNode->next;
        sum = l1->val + carry;
        carry = sum / 10;
        tempNode->val = sum % 10;
        l1 = l1->next;
    }
    if (carry > 0)
    {
        tempNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode = tempNode->next;
        tempNode->val = 1;
    }
    tempNode->next = NULL;
    //struct ListNode *toFree = result;
    result = result->next;
    //free(toFree);
    return result;
}

int main()
{
    struct ListNode* l1 = NULL;
    append(&l1, 2);
    append(&l1, 4);
    append(&l1, 3);
    printList(l1);
    struct ListNode* l2 = NULL;
    append(&l2, 5);
    append(&l2, 6);
    append(&l2, 4);
    printList(l2);

    struct ListNode* res = addTwoNumbers(l1, l2);
    printList(res);
    return 0;
}


