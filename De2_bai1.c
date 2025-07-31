#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct String {
    char string[100];
} Str;

typedef struct Stack {
    Str *str;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->str = (Str*)malloc(capacity * sizeof(Str));
    return stack;
}

void push(Stack *stack, Str str) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack full\n");
        return;
    }
    stack->top++;
    stack->str[stack->top] = str;
}

Str pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack empty\n");
        Str empty = { "" };
        return empty;
    }
    return stack->str[stack->top--];
}

void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack empty\n");
    } else {
        for (int i = stack->top; i >= 0; i--) {
            printf("%s\n", stack->str[i].string);
        }
    }
}

void clear(Stack *stack) {
    stack->top = -1;
}

int main() {
    int choice = 0;
    Stack* Copy = createStack(100);
    Stack* Redo = createStack(100);
    Stack* History = createStack(100);
    char str[100];

    do {
        printf("\n1. Copy\n");
        printf("2. Paste\n");
        printf("3. UNDO\n");
        printf("4. REDO\n");
        printf("5. Hien thi\n");
        printf("6. EXIT\n");
        printf("Moi ban nhap lua chon: \n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Moi ban nhap copy: ");
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = 0;
                Str string;
                strcpy(string.string, str);
                push(Copy, string);
                push(History, string);
                clear(Redo);
                break;

            case 2:
                if (Copy->top != -1) {
                    printf("Paste: %s\n", Copy->str[Copy->top].string);
                } else {
                    printf("Ban chua copy\n");
                }
                break;

            case 3:
                if (Copy->top == -1) {
                    printf("Khong the UNDO\n");
                } else {
                    Str undone = pop(Copy);
                    push(Redo, undone);
                }
                break;

            case 4:
                if (Redo->top == -1) {
                    printf("Khong the REDO\n");
                } else {
                    Str redone = pop(Redo);
                    push(Copy, redone);
                }
                break;

            case 5:
                display(History);
                break;

            default:
                printf("Moi ban nhap lai \n");
                break;
        }
    } while (choice != 6);


    return 0;
}
