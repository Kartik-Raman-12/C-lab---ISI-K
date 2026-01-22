#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int intCmp(void *A, void *B){
	return *((int *)A) - *((int *)B);
}

int strCmp(void *A, void *B){
	char *s1 = *(char **)A;
	char *s2 = *(char **)B;

	return(strcmp(s1,s2));
}

int lSearch(void *A, void *key, int elemSize, int arraySize,  int(*cmp)(void *, void *)){
	int i;
	char *base;

	base = (char *)A;


	for(i = 0; i < arraySize; i++){
		if( cmp(key, base + i * elemSize) == 0)
			return i;
	}
	return -1;
}

int main(int argc, char **argv){

	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	char *S[10] ={"The", "Quick", "Brown", "Fox", "Jumps", "Over", "Lazy", "Dogs", "Cats", "Birds"};
	int intkey= 13;
	char *strKey;
	int found;

	if(argc != 3) { printf("usage: %s string <string>\n OR \n %s int <int>\n ", argv[0], argv[0]);
		exit(0);
	}

	if(strcmp(argv[1],"string") != 0 && strcmp(argv[1],"int") != 0){
		 printf("usage: %s string <string>\n OR \n %s int <int>\n ", argv[0], argv[0]);
		 exit(0);
	}

	if(strcmp(argv[1], "string") == 0 ){
		strKey = strdup(argv[2]);
		found = lSearch((void *)S, (void *)&strKey, sizeof(char *), 10, strCmp);
		if(found == -1) printf(" The key %s not found \n", strKey);
		else printf("The key %s found at index %d\n", strKey, found);
	}

	else if(strcmp(argv[1], "int") == 0 ){
		intkey = atoi(argv[2]); /* No checking done to ensure it argv[i] is endeed an integer */
                found = lSearch((void *)A, (void *)&intkey, sizeof(int), 10, intCmp); 
	        if( found == -1) printf(" The key %d not found\n", intkey);
	        else printf("The key %d found at index %d\n",intkey, found);
	}
	else 
		 printf("usage: %s string <string>\n OR \n %s int <int>\n ", argv[0], argv[0]);

}

