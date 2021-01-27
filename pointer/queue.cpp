#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Node *makeNode(int x) {
    Node *a = (Node *) malloc(sizeof(Node));
    a->data = x;
    a->next = NULL;
    return a;
}

void init(Queue &q) {
    q.front = q.rear = NULL;
}

void push(Queue &q, int x) {
    Node *a = makeNode(x);
    if (q.front == NULL) {
        q.front = q.rear = a;

        return;
    }

    q.rear->next = a;
    q.rear = a;
}

void pop(Queue &q) {
    if (q.front == NULL) {
        printf("Danh sach rong\n");

        return;
    }

    Node *oldNode = q.front;
    q.front = q.front->next;
    free(oldNode);
}

void seek(Queue q) {
    if (q.front == NULL) {
        printf("Danh sach rong\n");

        return;
    }

    Node *tmp = q.front;
    do {
        printf("%5d", tmp->data);
        tmp = tmp->next;
    } while(tmp != NULL);
}

int main() {
    Queue q;
    init(q);

    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);

    pop(q);

    seek(q);

    return 0;
}
