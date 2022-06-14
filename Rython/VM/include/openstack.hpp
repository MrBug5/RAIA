#ifndef RYTHON_OPENSTACK_HPP
#define RYTHON_OPENSTACK_HPP
#include <cstdlib>
#include <cstdio>

struct Stack {
    Stack* head;
    int value;
    Stack* tail;
};

Stack* createStack(int value);
void Push(Stack* head, int value);
void Pop(Stack* head);
int getTail(Stack* stack);
void getStack(Stack* stack);

#endif // RYTHON_OPENSTACK_HPP
