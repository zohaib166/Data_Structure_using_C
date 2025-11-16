#include "Stack_using_LinkedList.c"
#ifndef STD
#include <stdio.h>
#include <string.h>
#endif


int preced(char ch) {
    // 1 is lowest and 3 is highest
    if(ch == '+' || ch == '-') {
        return 1;              //Precedence of + or - is 1
    } else if(ch == '*' || ch == '/') {
        return 2;            //Precedence of * or / is 2
    } else if(ch == '^') {
        return 3;            //Precedence of ^ is 3
    } else {
        return 0;
   }
}

int isalphabet(char a)
{
    if(a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z')
        return 1;
    else 
        return 0;
}

int main()
{
    char infix[] = "A+B-C/E*F^G^H";
    int size = strlen(infix);
    
    char postfix[size+1];
    stack s;
    init(&s);
    int pfidx = 0; //index of postfix string
    for(int i=0;i<size;i++)
    {
        
        char curr = infix[i];
        
        if(isalphabet(curr))
        {
            
            postfix[pfidx++] = curr;
        } else {
            
            if(curr == '(') {
                push(&s, curr);
                
            } else if(curr == ')') {
                while(!isEmpty(&s) && peek(&s)!='(') {
                    postfix[pfidx++] = peek(&s);
                    pop(&s);
                    
                }
                pop(&s); //remove the opening bracket in the stack
               
            } else {
                while(!isEmpty(&s) && preced(curr) <= preced(peek(&s))) {
                    if(curr=='^' && peek(&s)=='^')
                        break;
                    postfix[pfidx++] = peek(&s);
                    pop(&s);
                    
                }
                push(&s, curr);
                
            }
            
        }
 
        
    }
    while(!isEmpty(&s)) {
        postfix[pfidx++] = peek(&s);
        pop(&s);
   
    }

    postfix[pfidx] = '\0';
    
    printf("Postfix String: %s",postfix);
}