#include <stdio.h>
#include "Stack_using_LinkedList.c"

int main()
{
    char *exp = "[a+{b-c)*(d+e)}]";
    int i = 0;
    stack s;
    init(&s);
    int error = 0;
    while(exp[i] != '\0') 
    {
        char ch = exp[i];
        if(ch == '[' || ch == '{' || ch == '(')
        {
            push(&s, ch);
        } else if(ch == ']' || ch == '}' || ch == ')'){
            if(ch == ']' && peek(&s) == '[') {
                pop(&s);
            } else if(ch == '}' && peek(&s) == '{') {
                pop(&s);
            } else if(ch == ')' && peek(&s) == '(') {
                pop(&s);
            } else {
                error = 1;
            }
        }
        i++;
    }
    if(!isEmpty(&s) || error == 1) {
        printf("Brackets are mismatch\n");
    } else {
        printf("Brackets are matching\n");
    }
}