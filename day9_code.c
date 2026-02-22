#include <stdio.h>
#include <string.h>

int main() {
    char str[1001]; // assuming max length 1000
    scanf("%s", str);

    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        // Swap str[i] and str[n-i-1]
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    printf("%s\n", str);
    return 0;
}
