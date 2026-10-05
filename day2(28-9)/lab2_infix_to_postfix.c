#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;
int precedence(char ch)
{
    if (ch=='+' || ch=='-') return 1;
    else if (ch=='*' || ch=='/' || ch=='%') return 2;
    else if (ch=='^') return 3;
    else return -1;
}
int isempty()
{
    return top==-1?1:0;
}
int main()
{
    char post[MAX],infix[MAX];
    printf("Enter the infix expression :- ");
    scanf("%s",infix);
    int i =0,j=0;
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(isalnum(ch))
            post[j++]=ch;
        else if(ch=='(')
            stack[++top]=ch;
        else if(ch==')')
        {
            while(!isempty() && stack[top]!='(')
            {
                post[j++]=stack[top--];
            }
            if (!isempty()) top--;
        }

        else
        {
            while (!isempty() && stack[top] != '(' && (precedence(ch) < precedence(stack[top]) ||
                    (precedence(ch) == precedence(stack[top]) && ch != '^')))
                post[j++]=stack[top--];
            stack[++top]=ch;
        }
        i++;
    }
    while(!isempty())
    {
        post[j++]=stack[top--];
    }
    post[j]='\0';
    printf("the postfix expression is %s\n",post);

return 0;
}
