#include <stdio.h>

#define MAX 50

int stack[MAX], top = -1;

void push(int pos) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = pos;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int isEmpty() {
    return (top == -1);
}

int main() {
    int arr[50], n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            push(i);  // Push the position onto the stack
        }
    }

    if (isEmpty()) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at positions (top to bottom):\n", key);
        while (!isEmpty()) {
            printf("Position: %d\n", pop());
        }
    }

    return 0;
}

