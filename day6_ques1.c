#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n <= 0) return 0; // Empty array
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0; // Index of last unique element
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j]; // Move unique element forward
        }
    }

    // Print unique elements
    for (int k = 0; k <= i; k++) {
        if (k > 0) printf(" ");
        printf("%d", arr[k]);
    }
    printf("\n");

    return 0;
}
