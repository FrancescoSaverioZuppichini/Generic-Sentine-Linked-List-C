//
//  main.c
//  GenericSentinelLinkedList
//
//  Created by Francesco  on 11/04/16.
//  Copyright © 2016 Francesco Saverio Zuppichini. All rights reserved.
//

#include <stdio.h>
#include "sentinel_linked_list_int.h"

void double_data(void *node){
    sll_node *curr = (sll_node*) node;
    *(int*) curr->data *= 2;
}

void my_print(void *node){

    printf("%i\n", *(int*)((sll_node*)node)->data);
}

int main(int argc, const char * argv[]) {
    int i;
    
    /* example of a int linked list */
    sll *int_sll = sll_init(sizeof(int));
    /* populate the list */
    while(i<50){
        sll_append(int_sll, &i);
        i++;
    }
    sll_map(int_sll,&double_data);
    sll_print(int_sll, &my_print);
    while(i>0){
        sll_pop(int_sll);
        i--;
    }
    sll_print(int_sll, &my_print);
    sll_destroy(int_sll);
    
    return 0;
}
