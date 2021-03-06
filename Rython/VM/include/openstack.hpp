#ifndef RYTHON_OPENSTACK_HPP
#define RYTHON_OPENSTACK_HPP
#include <cstdlib>
#include <iostream>
#include "../include/token.hpp"


struct Stack {
    Stack* head;
    HashTable* value;
    Stack* tail;
};

Stack* createStack(HashTable* line);
void Push(Stack* head, HashTable* line);
void Pop(Stack* head);
HashTable* getTail(Stack* head);
void getStack(Stack* head);
void freeStack(Stack* head);

#endif // RYTHON_OPENSTACK_HPP
