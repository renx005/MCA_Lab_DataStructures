#include <stdio.h>

#define MAX 50

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack operations
void push1(int val) {
    if (top1 == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack1[++top1] = val;
}

int pop1() {
    return (top1 == -1) ? -1 : stack1[top1--];
}

int peek1() {
    return (top1 == -1) ? -1 : stack1[top1];
}

void push2(int val) {
    if (top2 == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack2[++top2] = val;
}

int pop2() {
    return (top2 == -1) ? -1 : stack2[top2--];
}

int peek2() {
    return (top2 == -1) ? -1 : stack2[top2];
}

// Function to read elements into stack1
void read(int n) {
    int val;
    int i;
    printf("Enter %d elements:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &val);
        push1(val);
    }
}

// Function to sort elements using two stacks
void sort() {
    while (top1 != -1) {
        int temp = pop1();

        while (top2 != -1 && peek2() > temp) {
            push1(pop2());
        }

        push2(temp);
    }
}

// Display the sorted elements from stack2
void display() {
	int i;
    printf("Sorted elements in ascending order:\n");
    for ( i = 0; i <= top2; i++) {
        printf("%d ", stack2[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    read(n);

    printf("Before sorting:\n");
    for ( i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    sort();

    display();

    return 0;
}

