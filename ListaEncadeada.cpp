#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void initializeList(Node** list) {
    *list = NULL; 
}

void addAtEnd(struct Node** list, int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    
    if (node == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        exit(1);
    }
    
    node->data = data;
    node->next = NULL;

    if (*list == NULL) {
        *list = node;
    }
    else
    {
        struct Node* aux = *list;
        while (aux->next)
        {
            aux = aux->next;
        }
        aux->next = node;
    }        
    
}

bool updateList(Node** list, int oldData, int newData) {
    struct Node* current = *list;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool deleteElement(Node** list, int data) {
    struct Node* before = *list;
    struct Node* current = *list;

    while (current != NULL) {
        
        if (current->data == data) {
            before->next = current->next;
            free(current);
            return true;
        }
        before = current;
        current = current->next;
    }
    return false;
}

void clear(Node** list) {
    Node* current = *list;
    Node* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *list = NULL;
}

void printList(Node** list) {    
    struct Node* current = *list;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    *list = NULL;
}

int main() {
    
    Node* list;
    initializeList(&list);

    addAtEnd(&list, 1);
    addAtEnd(&list, 2);
    addAtEnd(&list, 3);

    printList(&list);
    printf("\n");

    updateList(&list, 2, 4);
    printList(&list);
    printf("\n");

    deleteElement(&list, 4);
    printList(&list);
    printf("\n");
    
    addAtEnd(&list, 5);
    addAtEnd(&list, 6);

    updateList(&list, 5, 7);
    printList(&list);
    printf("\n");

    clear(&list);
    printList(&list);    

    return 0;
}
