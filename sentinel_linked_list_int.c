//
//  sentinel_linked_list_int.c
//  SentinelLinkedList
//
//  Created by Francesco  on 07/04/16.
//  Copyright © 2016 Francesco Saverio Zuppichini. All rights reserved.
//

#include "sentinel_linked_list_int.h"

sll * sll_init(){
    
    sll *new_sll = malloc(sizeof(sll));
    sll_node *sentinel_node = malloc(sizeof(sll_node));
    
    if(!new_sll || !sentinel_node)
        return NULL;
    
    new_sll->head = sentinel_node;
    new_sll->tail = sentinel_node;
    
    return new_sll;
}

void sll_append(sll * this, int el){
    sll_node *new_node;
    
    new_node = malloc(sizeof(sll_node));
    
    if(!new_node)
        return;
    
    new_node->data = el;
    this->tail->next = new_node;
    new_node->prev = this->tail;
    this->tail = new_node;
    this->tail->next = this->head;
    this->head->prev = new_node;
    
    this->size++;
    
}

sll_node * sll_remove(sll * this, int el){
    sll_node *to_remove;
    
    to_remove = sll_get(this, el);
    if(!to_remove)
        return NULL;
    to_remove->prev->next = to_remove->next;
    to_remove->next->prev = to_remove->prev;
    
    return to_remove;
}

sll_node * sll_pop(sll *this){
    sll_node *to_pop;
    
    if(this->size == 0)
        return NULL;
    
    to_pop = this->tail;
    
    to_pop->next->prev = to_pop->prev;
    to_pop->prev->next = this->head;
    
    this->tail = to_pop->prev;
    
    this->size--;
    
    return to_pop;
}


void inner_print(void * node_to_print){
    
    printf("%i\n", ((sll_node*)node_to_print)->data);
}

void sll_print(const sll * this, void (*custom_print)(void*)){
    
    if(!custom_print)
        sll_map(this,inner_print);
    else    
        sll_map(this, custom_print);
}

void sll_map(const sll * this, void (*f)(void *)){
    sll_node * pos;
    
    for(pos = this->head->next; pos != this->head; pos = pos->next){
        f(pos);
    }
}

sll_node *sll_get(const sll * this, int el){
    sll_node * pos;
    
    for(pos = this->head->next; pos != this->head; pos = pos->next){
        if(pos->data == el)
            break;
    }
    
    if(pos != this->head)
        return pos;
    
    return NULL;
}


void sll_destroy(const sll * this){
    
    sll_map(this,free);
    
}