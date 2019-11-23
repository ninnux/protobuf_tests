
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
#include "array.pb-c.h"

int main (int argc, const char * argv[]) 
{
  Tutorial__Array array = TUTORIAL__ARRAY__INIT;
  Tutorial__Myset **sets;
  void *buf;
  unsigned len,i;
  // malloc per puntatori
  sets = malloc (sizeof (Tutorial__Myset *)*2); //one insert at once

  //definisco i set per l'array 
  array.n_sets = 2;
  array.sets =sets;

  //creo il primo  set
  sets[0]=malloc(sizeof(Tutorial__Myset));
  tutorial__myset__init (sets[0]);
  // riempio il set di dati 
  sets[0]->timestamp=1574244029;

  // definisco le entries per il set
  Tutorial__Entry **entries;
  entries = malloc (sizeof (Tutorial__Entry *)*3); //one insert at once
  sets[0]->n_entries=3;
  sets[0]->entries=entries;

  // riempio le entries di dati
  entries[0]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries[0]);
  entries[0]->key=malloc(sizeof(char)*5);
  sprintf(entries[0]->key,"temp");
  entries[0]->value=10;

  entries[1]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries[1]);
  entries[1]->key=malloc(sizeof(char)*5);
  sprintf(entries[1]->key,"pres");
  entries[1]->value=1013;

  entries[2]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries[2]);
  entries[2]->key=malloc(sizeof(char)*4);
  sprintf(entries[2]->key,"bat");
  entries[2]->value=42;

  //creo il secondo  set
  sets[1]=malloc(sizeof(Tutorial__Myset));
  tutorial__myset__init (sets[1]);
  // riempio il set di dati 
  sets[1]->timestamp=1574244329;

  // definisco le entries per il set
  Tutorial__Entry **entries2;
  entries2 = malloc (sizeof (Tutorial__Entry *)*2); //one insert at once

  sets[1]->n_entries=2;
  sets[1]->entries=entries2;

  // riempio le entries di dati
  entries2[0]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries2[0]);
  entries2[0]->key=malloc(sizeof(char)*5);
  sprintf(entries2[0]->key,"temp");
  entries2[0]->value=10;

  entries2[1]=malloc(sizeof(Tutorial__Entry));
  tutorial__entry__init (entries2[1]);
  entries2[1]->key=malloc(sizeof(char)*5);
  sprintf(entries2[1]->key,"pres");
  entries2[1]->value=1013;

  //impacchetto tutto
  len = tutorial__array__get_packed_size (&array); // This is the calculated packing length
  buf = malloc (len);                     // Allocate memory
  tutorial__array__pack (&array, buf);             // Pack msg, including submessages
  //via!!
  fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
  fwrite (buf, len, 1, stdout);           // Write to stdout to allow direct command line piping

  //dealloco  
  free(sets[0]); 
  free(entries[0]); 
  free(entries[1]); 
  free(entries[2]); 
  free(entries2[0]); 
  free(entries2[1]); 
  free(sets); 
  free(entries); 
  free(entries2); 
  return 0;
}
