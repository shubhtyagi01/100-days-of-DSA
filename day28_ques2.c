
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalf = reverseList(slow);

    struct ListNode* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
