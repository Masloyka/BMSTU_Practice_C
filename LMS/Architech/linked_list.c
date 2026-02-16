#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
// // Реализуйте на основе лекции
// typedef struct Node{
//     int value;
//     struct Node* next;
// }Node;

// // Реализуйте на основе лекции
// typedef struct LinkedList{
//     Node* head;
//     Node* tail;
//     size_t size;
// }LinkedList;

Node* NewNode(const int value) {
    // Реализуйте на основе лекции
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedList* InitList() {
    // Реализуйте на основе лекции
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Node* GetAt(LinkedList* self, size_t index) {
    // Реализуйте функцию получения элемента по индексу
    Node* get_node = malloc(sizeof(Node));
    if (self->size <= index){
        return get_node;
    }
    if (index == 0){
        get_node->value = self->head->value;
        get_node->next = self->head->next;
        return get_node;
    }
    if (index == self->size){
        get_node->value = self->tail->value;
        get_node->next = self->tail->next;
        return get_node;
    }

    get_node->value = self->head->value;
    get_node->next = self->head->next;
    for (size_t i = 0; i < index; ++i){
        get_node = get_node->next;
    }
    return get_node;

}

void PushBack(LinkedList* self, Node* node) {
    // Реализуйте на основе лекции
    if (!self->head){
        self->head = node;
        self->tail = node;
    } else {
        self->tail->next = node;
        self->tail = node;
    }
    self->size++;
}

void PushFront(LinkedList* self, Node* node) {
    // Реализуйте на основе лекции
    if (!self->head){
        self->head = node;
        self->tail = node;
        node->next = NULL;
    } else{
        node->next = self->head;
        self->head = node;
    }
    self->size++;
}

Node* PopBack(LinkedList* self) {
    // Возьмите вашу реализацию
    if (!self->head) {
        return NULL;  
    }
    
    Node* node = self->tail;  
    
    if (self->head == self->tail) {
        self->head = NULL;
        self->tail = NULL;
    } else {
        Node* current = self->head;
        while (current->next != self->tail) {
            current = current->next;
        }
        self->tail = current;
        self->tail->next = NULL;
    }
    
    self->size--;
    node->next = NULL;
    return node;
}

Node* PopFront(LinkedList* self) {
    // Реализуйте самостоятельно
    if (!self->head){
        return NULL;
    }

    Node* node = self->head;
    if (self->head == self->tail){
        self->head = NULL;
        self->tail = NULL;
    } else{
        self->head = node->next;
    }
    self->size--;
    node->next = NULL;
    return node;
}

void InsertAt(LinkedList* self, size_t index, Node* node){
    if (self->size < index){
        return;
    }
    if (index == 0){
        PushFront(self, node);
        return;
    }
    if (index == self->size){
        PushBack(self, node);
        return;
    }

    Node* current = self->head;
    for (size_t i = 0; i < index - 1; ++i){
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    self->size++;
}


void RemoveAt(LinkedList* self, size_t index)  {
    // Заготовку функции возьмите в лекции
    // Не забудьте обработать 2 новых случая
    if (self->size <= index || self->size == 0){
        return;
    }

    if (index == 0){
        Node* old_head = self->head;
        self->head = old_head->next;
        if (self->size == 1){
            self->tail = NULL;
        }
        free(old_head);
        self->size--;
        return;
    }

    if (index == self->size-1){
        Node* old_tail = self->tail;
        Node* current = self->head;
        while (current->next != self->tail){
            current = current->next;
        }
        self->tail = current;
        self->tail->next = NULL;
        free(old_tail);
        self->size--;
        return;
    }

    Node* current = self->head;
    for (size_t i = 0; i < index-1; ++i){
        current = current->next;
    }
    Node* node_to_remove = current->next;
    current->next = node_to_remove->next;
    free(node_to_remove);
    self->size--;
}

void PrintList(LinkedList* self)  {
    // Реализуйте на основе лекции по своему желанию.
    // В данном задании она не будет тестироваться.
    Node* current = self->head;
    printf("{\n");
    printf("size: %zu\n", self->size);
    printf("items: [\n");
    int index = 0;
    while (current){
        printf(
            "{index: %d, value: %d}\n",
            index++,
            current->value
        );
        current = current->next;
    }
    printf("]\n");
}

void FreeList(LinkedList* self) {
    // Реализуйте на основе лекции
    Node* next_address;
    for (size_t i = 0; i < self->size; ++i){
        next_address = self->head->next;
        free(self->head);
        self->head = next_address;
    }
    self->head = NULL;
    self->tail = NULL;
    self->size = 0;
}

// Функцию main в данном задании реализовывать нет необходимости.
