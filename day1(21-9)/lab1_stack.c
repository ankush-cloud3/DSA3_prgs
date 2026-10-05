#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int top=-1;
int stack[MAX];
void pop()
{
    if (top==-1)
    {
        printf("UNDERFLOW : Stack is empty\n");
        return;
    }
    int ele = stack[top];
    top--;

    printf("Element popped = %d\n",ele);
}
void push(int ele)
{
    if (top==MAX-1)
    {
        printf("OVERFLOW : Stack is full\n");
        return;
    }
    top++;
    stack[top]=ele;
}
void print_ele()
{
    printf("\nStack elements :- \n");
    for(int i=top; i>=0; i--)
        printf("%d\t",stack[i]);
    printf("\n");
}
int main()
{
    int choice,ele;
    while(1)
    {
        printf("\nThe stack operations are as follows :-\n1)Push\t2)Pop\t3)Print elements\t4)Exit program\nEnter your choice :- ");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted :- ");
            scanf("%d",&ele);
            push(ele);
            break;

        case 2:
            pop();
            break;
        case 3:
            print_ele();
            break;
        case 4:
            printf("\n\nExiting out of the program......");
            exit(0);
        default :
            printf("Invalid choice\nPlease enter the correct option.\n");

        }
    }
    return 0;
}
