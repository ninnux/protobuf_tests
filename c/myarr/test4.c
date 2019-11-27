
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.pb-c.h"



int test4(){
  Tutorial__Array array = TUTORIAL__ARRAY__INIT;
  myarray_init(&array);


  Tutorial__Myset *set0;
  set0= malloc (sizeof (Tutorial__Myset)); //one insert at once

  myarray_add_set(&array,set0,1574244029);
  myarray_add_entry(&array,set0,"temp",19);
  myarray_add_entry(&array,set0,"pres",1013);
  myarray_add_entry(&array,set0,"batt",42);
  myarray_add_entry(&array,set0,"wind",223);

  //printf("key: %s\n", set0->entries[set0->n_entries-1]->key);
  //printf("key: %s\n", array.sets[array.n_sets-1]->entries[set0->n_entries-1]->key);

  Tutorial__Myset *set1;
  set1= malloc (sizeof (Tutorial__Myset)); //one insert at once
  myarray_add_set(&array,set1,1574244329);
  myarray_add_entry(&array,set1,"batt",42);
  myarray_add_entry(&array,set1,"wind",223);


  Tutorial__Myset *set2;
  set2= malloc (sizeof (Tutorial__Myset)); //one insert at once
  myarray_add_set(&array,set2,1574244629);
  myarray_add_entry(&array,set2,"temp",19);
  myarray_add_entry(&array,set2,"pres",1013);

  Tutorial__Myset *set3;
  set3= malloc (sizeof (Tutorial__Myset)); //one insert at once
  myarray_add_set(&array,set3,1574244929);
  myarray_add_entry(&array,set3,"temp",19);
  myarray_add_entry(&array,set3,"pres",1013);
  myarray_add_entry(&array,set3,"batt",42);
  myarray_add_entry(&array,set3,"wind",223);

  print_all(&array);

  char *buffer;
  serialize(&array,&buffer);
  printf("buffer:%s\n",buffer);

  ////impacchetto(&array);
  //char buffer[1024];
  //if(serialize(&array,buffer)==0){
  //  printf("buf:%s\n",buffer);
  //  printf("len:%d\n",strlen(buffer));
  //}else{
  //  printf("error");
  //}
  int i,k;
  printf("lunghezza buf:%d\n",strlen((char*)buffer));
  Tutorial__Array *array2;
  //array2=tutorial__array__unpack(NULL,strlen((char*)buffer),(uint8_t *)buffer);
  //Tutorial__Array *parray2=&array2;
  //deserialize(&parray2,buffer);

  array2 = tutorial__array__unpack(NULL,strlen(buffer),buffer); // Deserialize the serialized input

  Tutorial__Myset *set4;
  set4= malloc (sizeof (Tutorial__Myset)); //one insert at once
  myarray_add_set(array2,set4,55555555);
  myarray_add_entry(array2,set4,"temp",55);
  myarray_add_entry(array2,set4,"pres",5555);
  myarray_add_entry(array2,set4,"batt",55);
  myarray_add_entry(array2,set4,"wind",555);


  if (array2 == NULL)
     {
         fprintf(stderr,"error unpacking incoming message\n");
         return 1;
     }
  for (i = 0; i < array2->n_sets; i++){
      for (k = 0; k < array2->sets[i]->n_entries; k++){
              printf ("%d %s %d\n", array2->sets[i]->timestamp,array2->sets[i]->entries[k]->key,array2->sets[i]->entries[k]->value);
      }
  }
  
//print_all(&array2);
  //dealloco(&array);
  return 0;
}

int main (int argc, const char * argv[]) 
{
 test4();
}
