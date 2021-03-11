#include <stdio.h>
#include "ADTVector.h"

#define getName(var)  #var

void ret_vec_stats(Vector vec){

    printf("\nSize of Vector: %d\n", vector_size(vec));

    int nullvalues = 0;

    for(int i = 0; i < vector_size(vec); i++){
        printf("Return vector at position %d: %p\n", i+1, vector_get_at(vec,i));
        if(vector_get_at(vec,i) == NULL){
            nullvalues++;
        }
    }

    printf("\nFound %d null positions in Vector \"%s\"\n", nullvalues, getName(vec));
    

}


int main(void){

    Vector vec = vector_create(3, NULL);

    ret_vec_stats(vec);

    vector_destroy(vec);
}