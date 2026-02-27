#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct Node* newNode;

        if (l1->data <= l2->data) {
            newNode = createNode(l1->data);
            l1 = l1->next;
        } else {
            newNode = createNode(l2->data);
            l2 = l2->next;
        }

        if (result == NULL) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining elements
    while (l1 != NULL) {
        tail->next = createNode(l1->data);
        tail = tail->next;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        tail->next = createNode(l2->data);
        tail = tail->next;
        l2 = l2->next;
    }

    return result;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    // Merge lists
    struct Node* merged = mergeLists(list1, list2);

    // Print merged list
    printList(merged);

    return 0;
}
