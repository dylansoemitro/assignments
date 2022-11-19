
#include<stdio.h>
#include<stdlib.h>

struct brace{
    char brace;
    int line;
    int column;   
};

struct stack{
    struct brace *array;
    int top;
    int size;
};

void push(struct stack *stack, struct brace brace){
    if(stack->top == stack->size-1){
        printf("Stack is full");
        return;
    }
    stack->top++;
    stack->array[stack->top] = brace;
}


struct brace pop(struct stack *stack){
    if(stack->top == -1){
        printf("Stack is empty\n");
        struct brace empty = {'\0', -1, -1};
        return empty;
    }
    else{
        struct brace res = stack->array[stack->top];
        stack->top--;
        return res;
    }
}

int main(int argc, char *argv[]) {
    if(argc!=2){
        printf("Usage: ./match_braces <filename>\n");
    }
    FILE* infile = NULL;
    infile = fopen(argv[1], "r");
    if(infile == NULL){
        printf("Error opening file.\n");
        exit(1);
    }
    
    int line = 1;
    int column = 0;
    struct stack stack;
    stack.size = 256;
    stack.top = -1;
    struct brace s[256];
    stack.array = s;
    char ch;
    while ((ch = fgetc(infile)) != EOF) {
        if(ch == '\n'){
            line++;
            column = 0;
        }
        else if(ch == '{'){
            struct brace open;
            open.brace = ch;
            open.line = line;
            open.column = column;
            push(&stack, open);
        }
        else if(ch == '}'){
            struct brace popped = pop(&stack);
            if(popped.brace != '{'){
                printf("Unmatched braces on Line %d and Column %d\n", line, column);
            }
            else{
                printf("Found matching braces: (%d,%d) -> (%d, %d)\n",  popped.line, popped.column, line, column);
            }
        }
        column++;
        }
    
    while(stack.top != -1){
        printf("Unmatched braces on Line %d and Column %d\n", stack.array[stack.top].line, stack.array[stack.top].column);
        pop(&stack);
    }

    fclose(infile);
    return 0;
}

