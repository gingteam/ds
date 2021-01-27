#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    int data[MAX];
} Stack;

void init(Stack &s) {
    s.top = -1;
}

int isEmpty(Stack s) {
    return (s.top == -1);
}

int isFull(Stack s) {
    return (s.top == MAX);
}

void push(Stack &s, int x) {
    if (isFull(s)) {
        printf("Mang da day\n");

        return;
    }

    s.data[++s.top] = x;
}

void pop(Stack &s) {
    if (isEmpty(s)) {
        printf("Mang rong\n");

        return;
    }

    --s.top;
}

void peek(Stack s) {
    if (isEmpty(s)) {
        printf("Khong co phan tu nao\n");

        return;
    }

    for (int i = 0; i <= s.top; i++) {
        printf("%5d", s.data[i]);
    }
}

int main() {
    Stack a;
    init(a);

    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);

    pop(a);
    pop(a);

    peek(a);

    return 0;
}
