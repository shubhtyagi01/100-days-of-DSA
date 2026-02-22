#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    if (b == 0) return 1;       // Base case: a^0 = 1
    if (b < 0) return 0;        // Optional: handle negative powers if needed
    return a * power(a, b - 1); // Recursive call
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", power(a, b));
    return 0;
}
