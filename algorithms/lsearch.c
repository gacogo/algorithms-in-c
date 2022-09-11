#include <stdio.h>
#include <string.h>
#include <assert.h>
void *lsearch(void *, void *, int, int, int (*cmpfn)(void *, void *));

int intcmp(void *, void *);

int stringcmp(void *, void *);

void *lsearch(void *search_key, void *db, int elem_size, int len, int (*cmpfn)(void *, void *)){

	for(int i=0; i<len; i++){
		void *tracker = (char *)db+ i*elem_size;
		if (cmpfn(tracker, search_key)==0){
			return tracker;
		}

	}
	return NULL;
}

//compare ints
int intcmp(void *pa, void *pb){
	int a = *(int *)pa;
	int b = *(int *)pb;

	return a - b;
}
//to compare strings.
int stringcmp(void *str1, void *str2){

	char *s1 = *(char **)str1;
	char *s2 = *(char **)str2;

	return strcmp(s1, s2);
}



int main(int argc, char **argv){

	int key = 10;

	int db[] ={1, 2, 3, 4, 19, 10, 103, 1072};

	int *found = lsearch(&key, &db, sizeof(int), sizeof(db)/sizeof(int), intcmp);
	
	assert(found == (db+5));
	printf("passed");
	return 0;
}



	
