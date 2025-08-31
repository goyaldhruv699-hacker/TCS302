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
} Deque;
void Create(Deque *d, int capacity)
{
    d->capacity = capacity;
    d->front = 0;
    d->rear = -1;
    d->size = 0;
}
bool isEmpty(Deque *d)
{
    return d->size == 0;
}

bool isFull(Deque *d)
{
    return d->size == d->capacity;
}
void insertFront(Deque *d, int x)
{
    if (isFull(d))
    {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    d->front = (d->front - 1 + d->capacity) % d->capacity;
    d->arr[d->front] = x;
    d->size++;
    if (d->size == 1)
        d->rear = d->front;
}
void insertEnd(Deque *d, int x)
{
    if (isFull(d))
    {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    d->rear = (d->rear + 1) % d->capacity;
    d->arr[d->rear] = x;
    d->size++;
    if (d->size == 1)
        d->front = d->rear;
}
int deleteFront(Deque *d)
{
    if (isEmpty(d))
    {
        return -1;
    }
    int item = d->arr[d->front];
    d->front = (d->front + 1) % d->capacity;
    d->size--;
    if (d->size == 0)
    {
        d->front = 0;
        d->rear = -1;
    }
    return item;
}
int deleteEnd(Deque *d)
{
    if (isEmpty(d))
    {
        return -1;
    }
    int item = d->arr[d->rear];
    d->rear = (d->rear - 1 + d->capacity) % d->capacity;
    d->size--;
    if (d->size == 0)
    {
        d->front = 0;
        d->rear = -1;
    }
    return item;
}
void printFront(Deque *d)
{
    if (isEmpty(d))
    {
        printf("Deque is empty\n");
        return;
    }
    for (int i = 0; i < d->size; ++i)
    {
        int idx = (d->front + i) % d->capacity;
        if (i)
            printf(" ");
        printf("%d", d->arr[idx]);
    }
    printf("\n");
}
void printEnd(Deque *d)
{
    if (isEmpty(d))
    {
        printf("Deque is empty\n");
        return;
    }
    for (int i = 0; i < d->size; ++i)
    {
        int idx = (d->rear - i + d->capacity) % d->capacity;
        if (i)
            printf(" ");
        printf("%d", d->arr[idx]);
    }
    printf("\n");
}
int main()
{
    Deque d;
    Create(&d, CAPACITY);
    int choice, value;
    while (1)
    {
        printf("Press:\n1 insert at front\n2 insert at end\n3 delete from front\n4 delete from end\n5 to exit\n");
        if (scanf("%d", &choice) != 1)
            break;
        if (choice == 1)
        {
            if (scanf("%d", &value) != 1)
                break;
            insertFront(&d, value);
        }
        else if (choice == 2)
        {
            if (scanf("%d", &value) != 1)
                break;
            insertEnd(&d, value);
        }
        else if (choice == 3)
        {
            int removed = deleteFront(&d);
            if (removed == -1)
                printf("Deque Underflow! Cannot delete from front\n");
        }
        else if (choice == 4)
        {
            int removed = deleteEnd(&d);
            if (removed == -1)
                printf("Deque Underflow! Cannot delete from end\n");
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    printf("Contents of queue from front - \n");
    printFront(&d);
    printf("Contents of queue from end - \n");
    printEnd(&d);
    return 0;
}
