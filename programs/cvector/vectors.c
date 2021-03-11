#include <stdio.h>
#include <stdlib.h>
#include "ADTVector.h"

#define getName(var)  #var

void ret_vec_stats(Vector vec){

    printf("\nSize of Vector: %d\n", vector_size(vec));

    int nullvalues = vector_size(vec);

    for(int i = 0; i < vector_size(vec); i++){
        int* num = vector_get_at(vec,i);
        if(vector_get_at(vec,i) != NULL){
            printf("Vector at position %d: %d\n", i+1, *num);
            nullvalues--;
        }
        else
            printf("Vector at position %d: nil\n", i+1);
    }

    printf("\nFound %d null position/s in Vector \"%s\"\n", nullvalues, getName(vec));
    

}


int main(void){

    Vector vec = vector_create(3, NULL);

    int* pointer = malloc(sizeof(int));
    *pointer = 10;

    vector_set_at(vec, 0, pointer);

    int* pointer2 = malloc(sizeof(int));
    *pointer2 = 20;

    vector_insert_last(vec, pointer2);

    ret_vec_stats(vec);

    vector_destroy(vec);

    free(pointer);
    free(pointer2);
}