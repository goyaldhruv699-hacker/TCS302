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
bool IsFull(Queue *q)
{
    return (q->size == q->capacity);
}
void EnQueue(Queue *q, int k)
{
    if (IsFull(q))
    {
        printf("Queue Overflow! Cannot insert %d\n", k);
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
    printf("Queue - ");
    int idx = q->front;
    for (int i = 0; i < q->size; ++i)
    {
        printf("%d", q->arr[idx]);
        if (i < q->size - 1)
            printf(" ");
        idx = (idx + 1) % q->capacity;
    }
    printf("\n");
}
int Size(Queue *q)
{
    return q->size;
}
int main()
{
    Queue q;
    Create(&q, CAPACITY);
    int choice;
    while (1)
    {
        printf("Press:\n1 to enqueue\n2 to dequeue\n3 to calculate size\n4 to exit\n");
        if (scanf("%d", &choice) != 1)
            break;
        if (choice == 1)
        {
            int value;
            if (scanf("%d", &value) != 1)
                break;
            EnQueue(&q, value);
            PrintQueue(&q);
        }
        else if (choice == 2)
        {
            int removed = DeQueue(&q);
            if (removed == -1)
            {
                printf("Queue Underflow! Cannot dequeue\n");
            }
            else
            {
                PrintQueue(&q);
            }
        }
        else if (choice == 3)
        {
            printf("Size = %d\n", Size(&q));
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
