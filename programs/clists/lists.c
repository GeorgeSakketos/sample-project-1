#include <stdio.h>
#include <stdlib.h>
#include "ADTList.h"

#define getName(var)  #var

void list_stats(List list){

    printf("\nSize of list %s : %d\n", getName(list), list_size(list));
}

int main(void){
    List alist = list_create(free);;

    list_stats(alist);

    list_destroy(alist);
}