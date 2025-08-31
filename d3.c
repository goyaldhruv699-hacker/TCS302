#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100

void push(int stk[], int *top, int target)
{
    if (*top == max - 1)
        printf("Stack Overflow\n");
    else
        stk[++*(top)] = target;
}

int pop(int stk[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stk[(*top)--];
}
int main()
{
    char str[max];
    printf("Input string: ");
    scanf(" %[^\n]", str);

    int stk[max], target = 0;
    int top = -1;
    int len = strlen(str);
    int num1, num2;
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        if (isdigit(str[i]))
        {
            int num = 0;
            while (isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            push(stk, &top, num);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (top < 1)
            {
                printf("Error: Not enough operands for '%c'\n", str[i]);
                return 1;
            }
            int num1 = pop(stk, &top);
            int num2 = pop(stk, &top);
            switch (str[i])
            {
            case '+':
                push(stk, &top, num2 + num1);
                break;
            case '-':
                push(stk, &top, num2 - num1);
                break;
            case '*':
                push(stk, &top, num2 * num1);
                break;
            case '/':
                if (num1 == 0)
                {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                push(stk, &top, num2 / num1);
                break;
            }
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("%d", pop(stk, &top));
    return 0;
}
