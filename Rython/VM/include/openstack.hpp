#ifndef RYTHON_OPENSTACK_HPP
#define RYTHON_OPENSTACK_HPP
#include <cstdlib>
#include <iostream>
#include "../include/table.hpp"


struct Stack {
    Stack* head;
    int value;
    Stack* tail;
};

Stack* createStack(HashTable* line);
void Push(Stack* head, Hashtable* line;
void Pop(Stack* head);
int getTail(Stack* stack);
void getStack(Stack* stack);

#endif // RYTHON_OPENSTACK_HPP
