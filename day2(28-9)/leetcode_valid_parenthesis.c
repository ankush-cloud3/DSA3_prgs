#include <stdio.h>
char result[100];
int top=-1;
char pop(){
    return result[top--];
}
void push(char ch){
    result[++top]=ch;
}
int main() {
    while(1){
    char exp[100],flag=0;
    printf("enter the expression :- ");
    scanf("%s",exp);
    int i=0;
    while(exp[i]!='\0'){
        char ch = exp[i];
        if(ch =='(')
            push(')');
        else if(ch =='[')
            push(']');
        else if(ch =='{')
            push('}');
        else if(top==-1 || ch!=pop()){
            flag=1;
            printf("False");
            break;}
        i++;
    }
    if(flag==0){
        if(top==-1)
            printf("True");
        else
            printf("False");
    }
    printf("\n\n");
    }
    return 0;
}
