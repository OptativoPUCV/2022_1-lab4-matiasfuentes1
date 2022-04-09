#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {


int indice ;
indice = hash(key ,map ->capacity);
while (map -> buckets [indice] != NULL){
    indice = (indice + 1)% map -> capacity;
}
 
 map -> buckets[indice] = createPair (key , value);
 map->size++;
 map->current = indice;
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)

}

HashMap * createMap(long capacity) {
    HashMap * crearmaps = (HashMap *) malloc(sizeof(HashMap));
    crearmaps -> buckets = malloc(sizeof(Pair*)*capacity);
    crearmaps -> size = 0;
    for(int i = 0 ; i < capacity; i++){
        crearmaps -> buckets [i] = NULL;
    }
    crearmaps -> capacity = capacity;
    crearmaps -> current = -1;
    return crearmaps;
}

void eraseMap(HashMap * map,  char * key) {  

   //int indice = hash(key,map->capacity);


}

Pair * searchMap(HashMap * map,  char * key) {   

    int indice ;
    int aux;
   

     indice = hash(key , map -> capacity);

    for(int i = 0 ; i < map -> capacity ; i++){
        aux = (indice + i) % map -> capacity;
        if( map -> buckets[aux] == NULL){
            return map->buckets[aux]->value;
        }
        if(!strcmp(map->buckets[aux]->key,key)){
        return map->buckets[aux]->value;
        }
    }
    return NULL;
}

Pair * firstMap(HashMap * map) {
int indice = 0;
    while(map->buckets[indice]==NULL){
        indice=(indice+1)% map->capacity;
    }
    map->current = indice;
    return map ->buckets[indice];
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
