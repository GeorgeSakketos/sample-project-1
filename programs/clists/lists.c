/* IF I HAVENT COMMENTED ON SOMETHING 
IT MEANS I WAS TOO LAZY TO DO SO. CHEERS */

#include <stdio.h>
#include <stdlib.h>
#include "ADTList.h"

#define getName(var)  #var

void list_stats(List list){

    printf("\nSize of List %s : %d\n", getName(list), list_size(list));

    ListNode anode = list_first(list);

    for (int i = 0; i < list_size(list); i++){
        int* lsnode = list_node_value(list, anode);
        printf("Node %d: %d\n", i+1, *lsnode);
        anode = list_next(list, anode);
    }

}

void list_test_values(List list){

    int* value = malloc(sizeof(int));
    *value = 10;

    int* value2 = malloc(sizeof(int));
    *value2 = 12;

    list_insert_next(list, LIST_BOF, value);
    list_insert_next(list, LIST_BOF, value2);

}

int main(void){
    List alist = list_create(free);  //Initialising an empty list

    list_test_values(alist); // Calls a function that containes all the values to be tested, also helps keeps things in order UwU .

    list_stats(alist);

    list_destroy(alist);  //List goes sayonara (it gets destroyed).
}