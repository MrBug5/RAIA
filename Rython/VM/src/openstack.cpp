#include "../include/openstack.hpp"

Stack* createStack(int value) {
    Stack* stack = (Stack*) malloc(sizeof(stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->value = value;

    return stack;
}

void Push(Stack* head, int value) {
    Stack* temp = createStack(value);
    if (head->tail == NULL) {
        temp->head = head;
        head->tail = temp;
    } else {
        head = head->tail;
        head->tail = temp;
    }
}

int getTail(Stack* stack) { return stack->tail->value; };

void getStack(Stack* stack) {
    if (stack != NULL) {
        getStack(stack->tail);
    }
    // TODO: printTable(on the last table on the stack)
}
