/*
6. Write a linear time algorithm to decide if a linked list contains a cycle or not.
*/



#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        // Empty list or list with only one node cannot have a cycle
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) {
            // If 'fast' or 'fast->next' becomes nullptr, there's no cycle
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    // If the loop terminates, it means a cycle is detected
    return true;
}

// Helper function to create a linked list with a cycle for testing
ListNode* createLinkedListWithCycle() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Create a cycle here

    return head;
}

int main() {
    ListNode* head = createLinkedListWithCycle();

    bool has_cycle = hasCycle(head);

    if (has_cycle) {
        std::cout << "The linked list contains a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not contain a cycle." << std::endl;
    }

    // Remember to free the allocated memory
    ListNode* current = head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
