#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Node *makeNode(int x) {
    Node *a = (Node *) malloc(sizeof(Node));
    a->data = x;
    return a;
}

void init(Stack &s) {
    s.top = NULL;
}

int isEmpty(Stack s) {
    return (s.top == NULL);
}

void push(Stack &s, int x) {
    Node *pre = s.top;
    s.top = makeNode(x);
    s.top->next = pre;
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        printf("Danh sach rong\n");

        return;
    }

    Node *pre = s.top->next;
    // Giai phong bo nho
    free(s.top);
    s.top = pre;
}

void peek(Stack s) {
    if (isEmpty(s)) {
        printf("Danh sach trong\n");

        return;
    }

    Node *tmp = s.top;
    do {
        printf("%5d", tmp->data);
        tmp = tmp->next;
    } while(tmp != NULL);
}

int main() {
    Stack a;
    init(a);

    push(a, 5);
    push(a, 6);
    push(a, 7);

    pop(a);
    pop(a);

    peek(a);

    return 0;
}
