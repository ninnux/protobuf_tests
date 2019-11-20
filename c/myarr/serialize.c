
//syntax = "proto2";
//
//package tutorial;
//
//message entry {
//  required string key = 1;
//  required int32 value = 2;
//}
//
//message myset {
//  required int32 timestamp = 1;
//  repeated entry entries = 2;
//}
//
//message array {
//  repeated myset sets = 1;
//}


#include <stdio.h>
#include <stdlib.h>
#include "array.pb-c.c"

int main (int argc, const char * argv[]) 
{
  Tutorial__Array array = TUTORIAL__ARRAY__INIT;
  Tutorial__Myset **sets;
  Tutorial__Entry **entries;
  void *buf;
  unsigned len,i;
  sets = malloc (sizeof (Tutorial__Myset *)); //one insert at once
  entries = malloc (sizeof (Tutorial__Entry *)); //one insert at once

  sets[0]=malloc(sizeof(Tutorial__Myset));
  tutorial__myset__init (sets[0]);
  entries[0]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries[0]);

  sets[0]->timestamp=1574244029;
  entries[0]->key[0]='t';
  entries[0]->key[1]='e';
  entries[0]->key[2]='m';
  entries[0]->key[3]='p';
  entries[0]->key[3]='\0';
  entries[0]->value=10;

  sets.n_entries=1;
  sets.entries=entries
  array.n_sets = 1;
  array.sets =sets;

  len = tutorial__array__get_packed_size (&array); // This is the calculated packing length
  buf = malloc (len);                     // Allocate memory
  tutorial__array__pack (&array, buf);             // Pack msg, including submessages

  fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
  fwrite (buf, len, 1, stdout);           // Write to stdout to allow direct command line piping
    
  free(sets[0]); 
  free(entries[0]); 
  free(sets); 
  free(entries); 
  return 0;
}
