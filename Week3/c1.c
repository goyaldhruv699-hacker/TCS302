#include <stdio.h>
#include <stdlib.h>
#define max 10
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

int Pop(int stk[], int *top)
{
    int item;
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        item = stk[*top];
        *top = *top - 1;
        return item;
    }
}

void IsEmpty(int *top)
{
    if (*top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

void Size(int *top)
{
    printf("Size of Stack = %d\n", *top + 1);
}

void Print(int stk[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            printf("%d  ", stk[i]);
        }
        printf("\n");
    }
}

int main()
{
    int stk[max];
    int top = -1;
    int choice, target, item;

    printf("\n1) Push\n2) Pop\n3) IsEmpty\n4) Size\n5) Print\n6) Exit\n");
    while (1)
    {
        printf("Enter a Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element to push: ");
            scanf("%d", &target);
            Push(stk, &top, target);
            break;
        case 2:
            item = Pop(stk, &top);
            printf("Item deleted = %d\n", item);
            break;
        case 3:
            IsEmpty(&top);
            break;
        case 4:
            Size(&top);
            break;
        case 5:
            Print(stk, &top);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Incorrect Choice\n");
            break;
        }
    }

    return 0;
}
