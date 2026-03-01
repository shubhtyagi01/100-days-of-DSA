#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if (len1 > len2) {
        while (diff--)
            head1 = head1->next;
    } else {
        while (diff--)
            head2 = head2->next;
    }

    // Traverse both together
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;

    scanf("%d", &n);

    int arr1[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);

    int arr2[m];
    for (i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    // Create first list
    for (i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr1[i]);
        if (head1 == NULL)
            head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    // Create second list
    for (i = 0; i < m; i++) {
        struct Node* newNode = createNode(arr2[i]);
        if (head2 == NULL)
            head2 = tail2 = newNode;
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // Manually create intersection if values match
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1) {
        temp2 = head2;
        while (temp2) {
            if (temp1->data == temp2->data) {
                tail2->next = temp1;  // Create intersection
                break;
            }
            temp2 = temp2->next;
        }
        if (temp2)
            break;
        temp1 = temp1->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
