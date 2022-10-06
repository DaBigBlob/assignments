#include<stdio.h>
#include<stdlib.h>

typedef data_t int; //any kind of data; here int for example;

typedef struct elm {
    data_t data;
    struct elm* next;
} vec_t;

vec_t* vec_build(data_t* list) {
    vec_t* head = malloc(sizeof(vec_t)); if (!head) return(NULL);
    vec_t* tmp = head;
    for (unsigned long i = 0; i<(sizeof(list)/sizeof(data_t)); i++) { 
        tmp->data = list[i];
        tmp->next = malloc(sizeof(vec_t)); if (!(tmp->next)) return(NULL);
        tmp = tmp->next;
    }
    free(tmp);
    return(head);
}

int free_vec(vec_t* vector) {
    //im bored will do latr
}

int vec_insert(data_t data, vec_t* vector, unsigned long index) {
    
}

int main() {
    int* vec = m

    return(0);
}
