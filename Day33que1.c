/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

code:

```c id="y2k8fd">
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    return stack[top--];
}

int prec(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

int main(){
    char infix[100];
    scanf("%s",infix);
    int i;
    for(i=0;i<strlen(infix);i++){
        char c=infix[i];
        if(isalnum(c)){
            printf("%c",c);
        }else if(c=='('){
            push(c);
        }else if(c==')'){
            while(top!=-1 && stack[top]!='(')
                printf("%c",pop());
            pop();
        }else{
            while(top!=-1 && prec(stack[top])>=prec(c))
                printf("%c",pop());
            push(c);
        }
    }
    while(top!=-1)
        printf("%c",pop());
    return 0;
}

