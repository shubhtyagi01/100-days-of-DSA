#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Pointers to keep track of the queue boundaries
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element (Enqueue)
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to the new node
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    // Add the new node at the end and update rear
    rear->next = newNode;
    rear = newNode;
}

// Function to display the queue
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    // Input number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Input elements and enqueue them
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(value);
        }
    }

    // Output the final queue
    display();

    return 0;
}
