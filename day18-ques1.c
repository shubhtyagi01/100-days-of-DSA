#include <stdio.h>

int main() {
    int n;

    // Read number of elements
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    int temp[n];

    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
