#include <stdio.h>
#include "fmessage.pb-c.h"
#define MAX_MSG_SIZE 4096

int main (int argc, const char * argv[]) 
{
    FMessage *msg;
    char c; int i=0;
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
    
    msg = fmessage__unpack(NULL,i,buf); // Deserialize the serialized input
    if (msg == NULL)
    {
        fprintf(stderr,"error unpacking incoming message\n");
        return 1;
    }
    for (i = 0; i < msg->n_a; i++)
       printf ("%d\n", msg->a[i]->value);
    
    fmessage__free_unpacked(msg,NULL);
    
    return 0;
}
