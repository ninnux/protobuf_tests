#include <stdio.h>
#include "array.pb-c.h"
#define MAX_MSG_SIZE 4096

int main (int argc, const char * argv[]) 
{
    //FMessage *msg;
    Tutorial__Array *array;
    char c; int i=0; int k=0;
    uint8_t buf[MAX_MSG_SIZE]; // Input data container for bytes
    
    while (fread(&c,1,1,stdin) != 0)
    {
        if (i >= MAX_MSG_SIZE)
        {
            fprintf(stderr,"message too long for allocated buffer\n");
            return 1;
        }
        buf[i++] = c;
    }
    
    array = tutorial__array__unpack(NULL,i,buf); // Deserialize the serialized input
    if (array == NULL)
    {
        fprintf(stderr,"error unpacking incoming message\n");
        return 1;
    }
    for (i = 0; i < array->n_sets; i++){
    	for (k = 0; k < array->sets[i]->n_entries; k++){
       		printf ("%d %s %d\n", array->sets[i]->timestamp,array->sets[i]->entries[k]->key,array->sets[i]->entries[k]->value);
        }
    }
    
    tutorial__array__free_unpacked(array,NULL);
    
    return 0;
}
