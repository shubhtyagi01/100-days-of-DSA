#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = (long long *)malloc(n * sizeof(long long));
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long sum = 0;
    long long count = 0;

    // Create hash array for prefix sums
    // Using simple approach: store prefix sums in another array
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    prefix[0] = 0;

    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // Count pairs of equal prefix sums
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(prefix[i] == prefix[j]) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    free(arr);
    free(prefix);

    return 0;
}
