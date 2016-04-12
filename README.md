#Generic Sentinel Linked List
##A Sentinel Linked List implemenation in C

### *Implemented by Francesco Saverio Zuppichini*

###How to use it
```
#include "sentinel_linked_list_int.h"
```
In your source file 
####Create a new array
```
sll *my_sll = sll_init(sizeof(<your_type>));
```

####Use the API method 
All the API method are defined in *sentinel_linked_list_int.h*
#####Create an Sentinel Linked List of integer
```
sll *int_sll = sll_init(sizeof(int));
```

####Append an element:

```
sll_append(int_sll, &<your_int>);
```

####Pop an element:
#####Front pop
```
 sll_pop_front(<your_sll>);

```
#####Back pop
```
sll_pop_back(<your_sll>)
```
Every pop method returns the node popped


####Remove an element

```
sll_remove(<your_sll>,&<your_key>)
```

It returns the element removed

####Get an element:

```
sll_get(<your_sll>,&<your_key>);
```
It returns the getted element

####Destroy the list
```
sll_destroy(<your_sll>);
```
####Mapping the list
You can perfom an *action* function on every evelement by calling:

```
sll_map(<your_list>,&<your_function>);

```

The signature of the function must be 

```
void <your_action_function>(void *)
```

Example:
Assume you have a SLL of integer an you want to double every element, create a function:

```
void double_data(void *node){
    *get_data(node,int) *=2;
}

```
And call the map method:

```
sll_print(<your_int_sll>, &my_print);
```
####Get data from a node
The macro *get_data*  returns the casted pointer to the data of a given node

```
get_data(<node>,<type>)
```

Example:
Assume we have a node with a *int* data, we can print it like that:

```
printf("%i\n",*get_data(node,int));
```


