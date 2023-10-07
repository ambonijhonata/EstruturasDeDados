#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    Node* top;
};

void initialize(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int item) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Falha empilhar item.");
        exit(1);
    }

    node->data = item;
    node->next = stack->top;
    stack->top = node;        
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Não foi possível remover o elemento: Pilha vazia.");
        exit(1);
    }

    Node* temp = stack->top;
    int item = temp->data;
    stack->top = temp->next;
    free(temp);

    return item;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro ao buscar item: Pilha vazia.");
        exit(1);
    }

    return stack->top->data;
}

void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Elementos da pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printStack(&stack);
    printf("\n");

    int item1 = pop(&stack);
    int item2 = pop(&stack);

    printStack(&stack);
    printf("\n");

    printf("Peek: %d\n", peek(&stack));

    clear(&stack);
    printStack(&stack);
}