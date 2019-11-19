
//syntax="proto2";
//
//message Submessage {
//  required int32 value=1;
//}
//
//message FMessage {
//  repeated Submessage a=1;
//}


#include <stdio.h>
#include <stdlib.h>
#include "fmessage.pb-c.h"

int main (int argc, const char * argv[]) 
{
  FMessage msg = FMESSAGE__INIT;
  Submessage **subs;
  void *buf;
  unsigned len,i;
  subs = malloc (sizeof (Submessage*) * (argc-1));
  for (i = 1; i < argc; i++)
  {
    subs[i-1] = malloc (sizeof (Submessage));
    submessage__init (subs[i-1]);
    subs[i-1]->value = atoi(argv[i]);
    //free(subs[i-1]);
  }    
  msg.n_a = argc-1;
  msg.a = subs;
  len = fmessage__get_packed_size (&msg); // This is the calculated packing length
  buf = malloc (len);                     // Allocate memory
  fmessage__pack (&msg, buf);             // Pack msg, including submessages

  fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
  fwrite (buf, len, 1, stdout);           // Write to stdout to allow direct command line piping
    
  free(buf); // Free the allocated serialized buffer
  for (i = 1; i < argc; i++)
    free (subs[i-1]);
  free (subs); 
  return 0;
}
