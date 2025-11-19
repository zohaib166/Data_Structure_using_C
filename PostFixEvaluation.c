#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- Stack Implementation ---
int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// --- Postfix Evaluation Function ---
int evaluatePostfix(char* exp) {
    // We use " " (space) as the delimiter
    char *token = strtok(exp, " ");

    while (token != NULL) {
        // 1. Check if the token is a number
        // (isdigit checks the first char, or handles negative numbers if you expand logic)
        if (isdigit(token[0])) {
            // Convert string to integer and push
            push(atoi(token));
        }
        // 2. If it's not a number, it's an operator
        else {
            int val2 = pop(); // The top element is the SECOND operand
            int val1 = pop(); // The element below it is the FIRST operand

            switch (token[0]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default:  printf("Unknown operator: %s\n", token); exit(1);
            }
        }
        // Move to the next token
        token = strtok(NULL, " ");
    }

    // The final result is the only item left
    return pop();
}

int main() {
    // Note: Must use char[] because strtok modifies the string
    char expression[] = "10 2 3 * + 5 -"; 
    
    printf("Postfix Expression: %s\n", expression);
    
    // We pass a copy because strtok destroys the original string for printing purposes
    // But here, we just evaluate it directly.
    int result = evaluatePostfix(expression);
    
    printf("Result: %d\n", result);

    return 0;
}