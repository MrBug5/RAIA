#include "../include/openstack.hpp"

Stack* createStack(HashTable* value) {
    Stack* stack = (Stack*) malloc(sizeof(stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->value = value;

    return stack;
}

void Push(Stack* head, HashTable* value) {
    Stack* temp = createStack(value);
    if (head->tail == NULL) {
        temp->head = head;
        head->tail = temp;
    } else {
        head = head->tail;
        head->tail = temp;
    }
}

HashTable* getTail(Stack* stack) { return stack->tail->value; };

    void getStack(Stack* stack) {
        printf("################################################### STACK ###################################################\n");
        while (stack != NULL) {
        printTable(stack->value);
        // getStack(stack->tail);
        stack = stack->tail;
    }
    printf("#############################################################################################################\n");


}


void freeStack(Stack* head) {
    while (head != NULL) {
        free(head->head);
        free(head->value);
        free(head->tail);
    }

    free(head);
}
