#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50
char stk[max];
void push(int *top, char target)
{
    if (*top == max - 1)
        printf("Stack Overflow\n");
    else
        stk[++*(top)] = target;
}
void traverse(int *top)
{
    if (*top == -1)
        printf("Stack empty\n");
    else
    {
        for (int i = *top; i >= 0; i--)
            printf("%c", stk[i]);
    }
}
void recursion(char *str, int sizeStr)
{
    if (sizeStr < 0)
        return;
    printf("%c", str[sizeStr]);
    recursion(str, sizeStr - 1);
}
int main()
{
    char str[max];
    int top = -1;
    printf("Enter: ");
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char target = str[i];
        push(&top, target);
    }
    printf("Reverse(Without Recursion): ");
    traverse(&top);
    printf("\nReverse(Recursion): ");
    recursion(str, len);
    return 0;
}
