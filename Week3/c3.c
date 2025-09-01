#include <stdio.h>
#include <string.h>
#define max 15
void Push(int stk[], int *top, int target)
{
    if (*top == max - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        *top = *top + 1;
        stk[*top] = target;
    }
}
void Pop(int *top)
{
    int item;
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        *top = *top - 1;
    }
}
int main()
{
    char str[max];
    int stk[max];
    int top = -1;
    int len, maxx = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    Push(stk, &top, -1);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            Push(stk, &top, i);
        }
        else
        {
            Pop(&top);
            if (top == -1)
            {
                Push(stk, &top, i);
            }
            else
            {
                len = i - stk[top];
                if (maxx < len)
                {
                    maxx = len;
                }
            }
        }
    }
    printf("Length of the longest valid paranthes is substring = %d", maxx);

    return 0;
}
