class Solution {
public:
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL)
            return;

        Node *slow = head, *fast = head;
        bool hasCycle = false;

        // Step 1: Detect cycle (Floyd's Algorithm)
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If no cycle, return
        if (!hasCycle)
            return;

        // Step 2: Find start of loop
        slow = head;

        if (slow == fast) {
            // Loop starts at head
            while (fast->next != slow)
                fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove loop
        fast->next = NULL;
    }
};
