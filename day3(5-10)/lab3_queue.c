#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear==MAX-1)
    {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = val;
}

void dequeue()
{
    if (front==-1 || front>rear)
    {
        printf("Queue empty\n");
        return;
    }
    int ele=queue[front];
    front++;
    printf("The element popped is %d\n",ele);
}



void display()
{
    if (front==-1 || front>rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements : ");
    for (int i = front; i <= rear; i++)
        printf("%d\t", queue[i]);
    printf("\n");
}


int main()
{
    int choice, val;
    while (1)
    {
        printf("\nQueue operations :-\n");
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
