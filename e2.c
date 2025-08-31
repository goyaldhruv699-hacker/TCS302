#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CAPACITY 280
typedef struct
{
    int arr[CAPACITY];
    int front;
    int rear;
    int size;
    int capacity;
} Queue;
void Create(Queue *q, int capacity)
{
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
bool IsEmpty(Queue *q)
{
    return (q->size == 0);
}
void EnQueue(Queue *q, int k)
{
    if (q->size == q->capacity)
    {
        printf("Queue Overflow!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = k;
    q->size++;
}
int DeQueue(Queue *q)
{
    if (IsEmpty(q))
    {
        return -1;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}
void PrintQueue(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0, idx = q->front; i < q->size; i++)
    {
        printf("%d", q->arr[idx]);
        if (i < q->size - 1)
            printf(" ");
        idx = (idx + 1) % q->capacity;
    }
    printf("\n");
}
void ReverseQueue(Queue *q)
{
    int stack[CAPACITY];
    int top = -1;
    while (!IsEmpty(q))
    {
        stack[++top] = DeQueue(q);
    }
    while (top >= 0)
    {
        EnQueue(q, stack[top--]);
    }
}
int main()
{
    Queue q;
    Create(&q, CAPACITY);
    int choice, value;
    while (1)
    {
        printf("Press:\n1 to insert\n2 to exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            scanf("%d", &value);
            EnQueue(&q, value);
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    printf("Initial Queue : ");
    PrintQueue(&q);
    ReverseQueue(&q);
    printf("Reverse Queue : ");
    PrintQueue(&q);
    return 0;
}
