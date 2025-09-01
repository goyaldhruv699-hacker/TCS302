#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void push1(int *stk,int *top1,int *top2,int target) {
    if (*top1 < *top2 - 1) {
        stk[++(*top1)] = target;
    } else {
        printf("Stack Overflow in Stack1\n");
    }
}

void push2(int *stk,int *top1,int *top2,int target) {
    if (*top1 < *top2 - 1) {
        stk[--(*top2)] = target;
    } else {
        printf("Stack Overflow in Stack2\n");
    }
}

int pop1(int *stk,int *top1) {
    if (*top1 >= 0) {
        return stk[(*top1)--];
    } else {
        printf("Stack Underflow in Stack1\n");
        return -1;
    }
}

int pop2(int *stk,int *top2) {
    if (*top2 < MAX) {
        return stk[(*top2)++];
    } else {
        printf("Stack Underflow in Stack2\n");
        return -1;
    }
}

void display(int *stk,int *top1,int *top2) {
    int i;
    printf("Stack1: ");
    for (i = 0; i <= *top1; i++)
        printf("%d ", stk[i]);
    printf("\n");

    printf("Stack2: ");
    for (i = MAX - 1; i >= *top2; i--)
        printf("%d ", stk[i]);
    printf("\n");
}

int main() {
    int stk[MAX],choice,target;
    int top1 = -1;
    int top2 = MAX;
      
    printf("1 to push in stack 1\n2 to pop from stack 1\n3 to push in stack 2\n4 to pop from stack 2\n5 Exit\n");
    while(1){
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to be pushed: ");
                scanf("%d",&target);
                push1(stk,&top1,&top2,target);
                break;
            case 2:
                printf("Poped element(Stack 1): %d\n",pop1(stk,&top1));
                break;
            case 3:
                printf("Enter element to be pushed: ");
                scanf("%d",&target);
                push2(stk,&top1,&top2,target);
                break;
             case 4:
                printf("Poped element(Stack 2): %d\n",pop2(stk,&top2));
                break;
            case 5:
                 display(stk,&top1,&top2);
                 exit(0);
                 break;
            default:
                  printf("Incorrect Choice\n");
                  break;
        }
    }
    
    return 0;
}