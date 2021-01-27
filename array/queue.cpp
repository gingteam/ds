#include <stdio.h>

#define MAX 100

typedef struct {
    int size, front, rear;
    int data[MAX];
} Queue;

void init(Queue &q) {
    q.size = q.front = 0;
    q.rear = -1;
}

int isEmpty(Queue s) {
    return (s.size == 0);
}

int isFull(Queue s) {
    return (s.size == MAX);
}

void push(Queue &q, int x) {
    if (isFull(q)) {
        printf("Danh sach day\n");

        return;
    }

    q.data[(++q.rear)%MAX] = x;
    ++q.size;
}

void pop(Queue &q) {
    if (isEmpty(q)) {
        printf("Danh sach rong\n");

        return;
    }

    ++q.front %= MAX;
    --q.size;
}

void peek(Queue q) {
    if (isEmpty(q)) {
        printf("Danh sach rong\n");

        return;
    }

    for (int i = 0; i < q.size; i++) {
        printf("%5d", q.data[(q.front++)%MAX]);
    }
}

int main() {
    Queue q;
    init(q);

    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);

    pop(q);

    peek(q);

    printf("\nFront: %d, Rear: %d\n", q.front, q.rear);

    return 0;
}
