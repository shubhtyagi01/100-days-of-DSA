#include <stdio.h>
#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i, value;

    // Read number of elements to push
    scanf("%d", &n);

    // Push elements into stack
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        if(top < MAX - 1) {
            stack[++top] = value;  // Push operation
        }
    }

    // Read number of pops
    scanf("%d", &m);

    // Pop elements from stack
    for(i = 0; i < m; i++) {
        if(top >= 0) {
            top--;   // Pop operation
        }
    }

    // Print remaining elements from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
