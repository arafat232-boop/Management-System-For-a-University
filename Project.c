#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 100

struct Student
{
    char name[50];
    char purpose[100];
};

struct Student queue[size];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;

    else
        return false;
}

bool isFull()
{
    if (rear == size - 1)
        return true;
    else
        return false;
}

int enqueue(char name[], char purpose[])
{
    if (isFull())
    {
        printf("Queue is full. Cannot add more students.\n");
        return ;
    }

    if (isEmpty())
    {
        front = rear= 0;
    
    }
    else
    {
        rear++;
    }

    strcpy(queue[rear].name, name);
    strcpy(queue[rear].purpose, purpose);

    printf("%s is added to the queue for %s.\n", name, purpose);
    return 0;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. No student to serve.\n");
        return ;
    }

    printf("Served: %s (%s).\n", queue[front].name, queue[front].purpose);

    if (front == rear)
    {
        front=rear = -1;
        
    }
    else
    {
        front++;
    }
    //return 0;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current Queue:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%s (%s)\n", queue[i].name, queue[i].purpose);
    }
}

int main()
{
    int choice;
    char name[50], purpose[100];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Serve Student\n");
        printf("3. View Current Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Queue is full. Cannot add more students.\n");
                break;
            }
            printf("Enter student's name: ");
            scanf(" %[^\n]s", name); 
            printf("Enter purpose : ");
            scanf(" %[^\n]s", purpose);
            enqueue(name, purpose);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program. \n");
            return 0;
        default:
            printf("Input is incorrect. Please try again.\n");
        }
    }
}
