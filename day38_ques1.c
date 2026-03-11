#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX - 1);
}

void push_front(int value) {
    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

int getFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[front];
}

int getBack() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    return deque[rear];
}

int size() {
    if (isEmpty())
        return 0;
    return rear - front + 1;
}

void clearDeque() {
    front = rear = -1;
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    printf("Deque elements: ");
    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    printf("After popping:\n");
    display();

    clearDeque();

    printf("After clear:\n");
    display();

    return 0;
}
