#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
};

typedef struct {
	Node* front;
	Node* rear;
} Queue;

void initialize(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

bool isEmpty(Queue* queue) {
	return (queue->front == NULL);
}

void enqueue(Queue* queue, int item) {
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		printf("Erro ao enfilear.");
		exit(1);
	}

	node->data = item;
	node->next = NULL;

	if (isEmpty(queue)) {
		queue->front = queue->rear = node;
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Erro: Pilha vazia");
		exit(3);
	}

	Node* temp = queue->front;
	int item = temp->data;

	queue->front = temp->next;

	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	free(temp);
	return item;
}

void destroy(Queue* queue) {
	while (!isEmpty(queue))
	{
		dequeue(queue);
	}
}

int main() {
	Queue queue;
	initialize(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);

	printf("%d", dequeue(&queue));
	printf("%d", dequeue(&queue));

}