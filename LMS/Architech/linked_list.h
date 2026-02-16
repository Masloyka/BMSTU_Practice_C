#pragma once
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;


typedef struct LinkedList{
    Node* head;
    Node* tail;
    size_t size;
}LinkedList;

Node* NewNode(const int value);
LinkedList* InitList();
Node* GetAt(LinkedList* self, size_t index);
void PushBack(LinkedList* self, Node* node);
void PushFront(LinkedList* self, Node* node);
Node* PopBack(LinkedList* self);
Node* PopFront(LinkedList* self);
void InsertAt(LinkedList* self, size_t index, Node* node);
void RemoveAt(LinkedList* self, size_t index);
void PrintList(LinkedList* self);
void FreeList(LinkedList* self);
