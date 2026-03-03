#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int i = 0;
    char stack[10000];
    int top = -1;

    while (s[i] != '\0') {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        else {
            if (top == -1)
                return false;

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
        i++;
    }

    return top == -1;
}
