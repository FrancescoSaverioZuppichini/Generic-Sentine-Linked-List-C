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
    *sll_get_data(node,int) *=2;
}

void my_print(void *node){

    printf("%i\n",*sll_get_data(node,int));
}

void string_print(void *node){
    
    printf("%s\n",sll_get_data(node,char));

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
        sll_pop_front(int_sll);
        i--;
    }
    sll_print(int_sll, &my_print);
    sll_destroy(int_sll);
    
    /* example of a string linked list */
    sll *string_sll = sll_init(sizeof(char *));
    char * str1 = "ciao";
    char * str2 = "come";
    char * str3 = "stai?";
    
    sll_append(string_sll, str1);
    sll_append(string_sll, str2);
    sll_append(string_sll, str3);
    
    sll_print(string_sll, &string_print);
    
    sll_destroy(string_sll);
    

    return 0;
}
