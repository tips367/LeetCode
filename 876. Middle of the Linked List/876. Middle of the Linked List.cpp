/* Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.

Note: The number of nodes in the given list will be between 1 and 100.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
    }
    return slow;
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

    /* Let us create a linked list to test the functions
    Created lists shall be a: 1->2->3->4->5 */
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    std::cout << "Given Linked List is : ";
    printList(a);

    ListNode* middle = middleNode(a);
    std::cout << "Node " << middle->val << " from this list";

    return 0;
}