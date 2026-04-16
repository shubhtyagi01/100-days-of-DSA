#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // Hash map using arrays (since C has no built-in map)
    // Stores first occurrence of a sum
    int hash[1000];
    
    // Initialize all values as -1
    for(int i = 0; i < 1000; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            max_length = i + 1;
        }

        // Handle negative index by shifting
        int index = sum + 500;

        if(hash[index] == -2) {
            hash[index] = i;  // store first occurrence
        } else {
            int length = i - hash[index];
            if(length > max_length) {
                max_length = length;
            }
        }
    }

    return max_length;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLen(arr, n);
    printf("%d\n", result);

    return 0;
}
