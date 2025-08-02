#include <stdio.h>
#define maxsize 100;

int main()
{
    int stack[maxsize];
    int top = -1;
    void push(int value, int *top, int stack[])
    {
        if (*top == maxsize - 1)
        {
            printf("Stack is full");
            return;
        }
        else
        {
            *top++;
            stack[*top] = value;
        }
    }

    void pop(, int *top, int stack[])
    {
        if (*top == -1)
        {
            printf("Stack is empty");
            return;
        }
        else
        {

            printf("%d", stack[*top]);
            *top--;
        }
    }

    int peck(int *top, int stack[])
    {
        if (*top == -1)
            ;
        return -1;
    }
    else
    {
        return stack[*top];
    }
    int main()
    {
        int a;
        printf("press 1 \n press 2 \n press 3 \n");
        scanf("%d", &a);
        switch (a)
        {
        case 1;
            printf("push ");
            break;
            case 2:
            printf("pop ");
            break;
        case 3:
            printf("top ");
            break;

        default:
            printf("not valid");
            break;
        }
    }

    return 0;
}