#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int (*cmpfunc)(void*, int, int);

int intCmp( void *A, int i, int j){
	return (*((int *)A + i) - *((int *)A+j));
}


int stringCompare( void *A, int i, int j){
	char *s1, *s2;

	s1 = *((char **)A + i);
	s2 = *((char **)A + j);
	return(strcmp(s1,s2));
}

void gSwap(void *A, void *B, int size){
	char *buffer;

	buffer = (char *)malloc(size * sizeof(char));
	assert( buffer != NULL);

	memcpy(buffer, A, size);
	memcpy(A, B, size);
	memcpy(B, buffer, size);
	free(buffer);
}

void bubbleSort(void *A, int arraySize, int elemSize, cmpfunc cf){

	int i,j;

	for(i=0; i< arraySize - 1; i++ ){
		for(j = i+1 ; j < arraySize; j++){
		       if(cf(A,i,j) > 0)
		          gSwap((char *)A + i * elemSize, (char *)A + j * elemSize, elemSize);
		}
	}
}	

void main(){
	int i, arraySize=10;
	int A[10] = {10,9,8,7,6,5,4,3,2,1};
	char *B[10] = {"long", "live", "the", "revolution", "zz", "za", "abz","haru", "naren", "robi"};

	bubbleSort( (void *)A, arraySize, sizeof(int), intCmp); // sorting an array of integers
	
	for(i=0; i< arraySize; i++)
		printf("%d ", A[i]);

	printf("\n");

	bubbleSort((void *)B, arraySize, sizeof(char *), stringCompare); // sorting an array of strings
       for(i = 0; i < arraySize; i++)
	       printf("%s \n", B[i]);

              	       
}
