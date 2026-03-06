#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(char *s) {
    int n = strlen(s);
    int *stack = (int *)malloc(sizeof(int) * (n + 1));
    int top = -1;
    long num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
            if (op == '+') {
                stack[++top] = (int)num;
            } else if (op == '-') {
                stack[++top] = (int)(-num);
            } else if (op == '*') {
                stack[top] = stack[top] * (int)num;
            } else if (op == '/') {
                stack[top] = stack[top] / (int)num;
            }

            op = s[i];
            num = 0;
        }
    }

    int ans = 0;
    while (top >= 0) {
        ans += stack[top--];
    }

    free(stack);
    return ans;
}
