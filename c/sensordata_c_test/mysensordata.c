#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ELEMENTS 22

typedef struct element { 
    uint8_t valuetype; 
    uint8_t value; 
} element;

typedef struct myset { 
    uint32_t timeref; 
    element* elements[ELEMENTS]; 
} myset;


int main(int argc, char** argv){
	char string[70];
	myset** sensordata;
	myset* ms;
	ms=malloc(sizeof(myset));
	ms->timeref=atoi(argv[1]);
	int i=0;
	for(i=0;i<ELEMENTS;i++){
	   element* el;
	   el=malloc(sizeof(element));	
	   el->valuetype=atoi(argv[2]);
	   el->value=5*i;
	   ms->elements[i]=el;
	}

	myset* ms2;
	ms2=malloc(sizeof(myset));
	ms2->timeref=atoi(argv[3]);
	int q=0;
	for(q=0;q<ELEMENTS;q++){
	   element* el;
	   el=malloc(sizeof(element));	
	   el->valuetype=atoq(argv[2]);
	   el->value=7*q;
	   ms2->elements[q]=el;
	}

	sensordata=malloc(sizeof(myset)+sizeof(element)*ELEMENTS*2);
	sensordata[0]=ms;
	sensordata[1]=ms2;
	//printf("timeref=%u\n",sensordata[0]->timeref);
	memcpy(string,sensordata,sizeof(element)*ELEMENTS);
	//printf("sizeof mys:%lu\n",sizeof(element)*ELEMENTS);
	//printf("string:%s\n",(char*) string);
	printf("string:%s-\n",(char*) string);
	printf("string len:%lu",strlen(string));

	myset** copy;
	copy=malloc(sizeof(myset)+sizeof(element)*ELEMENTS);
	bzero(copy,sizeof(myset)+sizeof(element)*ELEMENTS);
	memcpy(copy,string,sizeof(myset)+sizeof(element)*ELEMENTS);
	printf("timeref=%u\n",copy[0]->timeref);
	int k=0;
	for(k=0;k<ELEMENTS;k++){
		printf("element %d=%d\n",k,copy[0]->elements[k]->value);
	}
	printf("timeref=%u\n",copy[1]->timeref);
	int j=0;
	for(j=0;j<ELEMENTS;j++){
		printf("element %d=%d\n",j,copy[1]->elements[j]->value);
	}
	return 0;

}
